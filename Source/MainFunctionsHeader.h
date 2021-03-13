#pragma once

#include "MainHeader.h"
#include "Player.h"
#include "Level_1.h"
#include "Level_2.h"
#include "Level_3.h"
#include "TitleScreen.h"
#include "LevelEnd.h"
#include"Entity.h"


// Global game state variable

GlobalState state;


// Functions Declarations and Definition
// -------------------------------------------------------------------------
void Start()
{
	// Initialize SDL internal global state
	SDL_Init(SDL_INIT_EVERYTHING);

	// Init input events system
	//if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0) printf("SDL_EVENTS could not be initialized! SDL_Error: %s\n", SDL_GetError());

	// Init window
	state.window = SDL_CreateWindow("Super Awesome Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	state.surface = SDL_GetWindowSurface(state.window);

	// Init renderer
	state.renderer = SDL_CreateRenderer(state.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(state.renderer, 100, 149, 237, 255);		// Default clear color: Cornflower blue

	// L2: DONE 1: Init input variables (keyboard, mouse_buttons)
	state.keyboard = (KeyState*)calloc(sizeof(KeyState) * MAX_KEYBOARD_KEYS, 1);
	for (int i = 0; i < MAX_MOUSE_BUTTONS; i++) state.mouse_buttons[i] = KEY_IDLE;

	// L2: DONE 2: Init input gamepad 
	// Check SDL_NumJoysticks() and SDL_JoystickOpen()
	if (SDL_NumJoysticks() < 1) printf("WARNING: No joysticks connected!\n");
	else
	{
		state.gamepad = SDL_JoystickOpen(0);
		if (state.gamepad == NULL) printf("WARNING: Unable to open game controller! SDL Error: %s\n", SDL_GetError());
	}

	// Init image system and load textures
	IMG_Init(IMG_INIT_PNG);
	state.background = SDL_CreateTextureFromSurface(state.renderer, IMG_Load("Assets/castle.png"));
	state.ship = SDL_CreateTextureFromSurface(state.renderer, IMG_Load("Assets/GeneralSpriteSheet.png"));
	state.shot = SDL_CreateTextureFromSurface(state.renderer, IMG_Load("Assets/GeneralSpriteSheet.png"));
	SDL_QueryTexture(state.background, NULL, NULL, &state.background_width, NULL);

	// L4: TODO 1: Init audio system and load music/fx
	Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	// EXTRA: Handle the case the sound can not be loaded!
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		printf("Mix_OpenAudio: %s\n", Mix_GetError());
		exit(2);
	}

	// L4: TODO 2: Start playing loaded music
	state.music = Mix_LoadMUS("Assets/castle.ogg");
	state.fx_shoot = Mix_LoadWAV("Assets/laser.wav");
	Mix_PlayMusic(state.music, -1);


	// Init game variables
	state.bullet.player_x = 100;
	state.bullet.player_y = SCREEN_HEIGHT / 2;
	state.last_shot = 0;
	state.scroll = 0;
}

// ----------------------------------------------------------------
void Finish()
{
	// L4: TODO 3: Unload music/fx and deinitialize audio system
	Mix_FreeMusic(state.music);

	// Unload textures and deinitialize image system
	SDL_DestroyTexture(state.background);
	SDL_DestroyTexture(state.ship);
	IMG_Quit();

	// L2: DONE 3: Close game controller
	SDL_JoystickClose(state.gamepad);
	state.gamepad = NULL;

	// Deinitialize input events system
	//SDL_QuitSubSystem(SDL_INIT_EVENTS);

	// Deinitialize renderer and window
	// WARNING: Renderer should be deinitialized before window
	SDL_DestroyRenderer(state.renderer);
	SDL_DestroyWindow(state.window);

	// Deinitialize SDL internal global state
	Mix_CloseAudio();
	SDL_Quit();
	Mix_Quit();

	// Free any game allocated memory
	free(state.keyboard);
}

// ----------------------------------------------------------------
bool CheckInput()
{
	// Update current mouse buttons state 
	// considering previous mouse buttons state
	for (int i = 0; i < MAX_MOUSE_BUTTONS; ++i)
	{
		if (state.mouse_buttons[i] == KEY_DOWN) state.mouse_buttons[i] = KEY_REPEAT;
		if (state.mouse_buttons[i] == KEY_UP) state.mouse_buttons[i] = KEY_IDLE;
	}

	// Gather the state of all input devices
	// WARNING: It modifies global keyboard and mouse state but 
	// its precision may be not enough
	//SDL_PumpEvents();

	// Poll any currently pending events on the queue,
	// including 'special' events like window events, joysticks and 
	// even hotplug events for audio devices and joysticks,
	// you can't get those without inspecting event queue
	// SDL_PollEvent() is the favored way of receiving system events
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0)
	{
		switch (event.type)
		{
		case SDL_QUIT: state.window_events[WE_QUIT] = true; break;
		case SDL_WINDOWEVENT:
		{
			switch (event.window.event)
			{
				//case SDL_WINDOWEVENT_LEAVE:
			case SDL_WINDOWEVENT_HIDDEN:
			case SDL_WINDOWEVENT_MINIMIZED:
			case SDL_WINDOWEVENT_FOCUS_LOST: state.window_events[WE_HIDE] = true; break;
				//case SDL_WINDOWEVENT_ENTER:
			case SDL_WINDOWEVENT_SHOWN:
			case SDL_WINDOWEVENT_FOCUS_GAINED:
			case SDL_WINDOWEVENT_MAXIMIZED:
			case SDL_WINDOWEVENT_RESTORED: state.window_events[WE_SHOW] = true; break;
			case SDL_WINDOWEVENT_CLOSE: state.window_events[WE_QUIT] = true; break;
			default: break;
			}
		} break;
		// L2: DONE 4: Check mouse events for button state
		case SDL_MOUSEBUTTONDOWN: state.mouse_buttons[event.button.button - 1] = KEY_DOWN; break;
		case SDL_MOUSEBUTTONUP:	state.mouse_buttons[event.button.button - 1] = KEY_UP; break;
		case SDL_MOUSEMOTION:
		{
			state.mouse_x = event.motion.x;
			state.mouse_y = event.motion.y;
		} break;
		case SDL_JOYAXISMOTION:
		{
			// Motion on controller 0
			if (event.jaxis.which == 0)
			{
				// X axis motion
				if (event.jaxis.axis == 0)
				{
					if (event.jaxis.value < -JOYSTICK_DEAD_ZONE) state.gamepad_axis_x_dir = -1;
					else if (event.jaxis.value > JOYSTICK_DEAD_ZONE) state.gamepad_axis_x_dir = 1;
					else state.gamepad_axis_x_dir = 0;
				}
				// Y axis motion
				else if (event.jaxis.axis == 1)
				{
					if (event.jaxis.value < -JOYSTICK_DEAD_ZONE) state.gamepad_axis_y_dir = -1;
					else if (event.jaxis.value > JOYSTICK_DEAD_ZONE) state.gamepad_axis_y_dir = 1;
					else state.gamepad_axis_y_dir = 0;
				}
			}
		} break;
		default: break;
		}
	}

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	// L2: DONE 5: Update keyboard keys state
	// Consider previous keys states for KEY_DOWN and KEY_UP
	for (int i = 0; i < MAX_KEYBOARD_KEYS; ++i)
	{
		// A value of 1 means that the key is pressed and a value of 0 means that it is not
		if (keys[i] == 1)
		{
			if (state.keyboard[i] == KEY_IDLE) state.keyboard[i] = KEY_DOWN;
			else state.keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (state.keyboard[i] == KEY_REPEAT || state.keyboard[i] == KEY_DOWN) state.keyboard[i] = KEY_UP;
			else state.keyboard[i] = KEY_IDLE;
		}
	}

	// L2: DONE 6: Check ESCAPE key pressed to finish the game
	if (state.keyboard[SDL_SCANCODE_ESCAPE] == KEY_DOWN) return false;

	// Check QUIT window event to finish the game
	if (state.window_events[WE_QUIT] == true) return false;

	return true;
}

// ----------------------------------------------------------------


//These two last functions are the ones that will be used to create and modify the levels, titlescreen and other game events such as transitions  <-- PLEASE READ !!!
void MoveStuff()
{
	
	switch (state.scene)
	{
		case state.TitleScreen:
		{
			TitleScreenMechanicsDefinition(state);

			break;
		}
		case state.LevelScenes:
		{
			PlayerMechanicsDefinition(state); //Define the player controls and the parameters for its animations together with its different states (alive, dead, etc)

			switch (state.level)
			{
				case state.Level_1:
				{
					Level_1MechanicsDefinition(state);

					break;
				}
				case state.Level_2:
				{
					Level_2MechanicsDefinition(state);

					break;
				}
				case state.Level_3:
				{
					Level_3MechanicsDefinition(state);

					break;
				}
				case state.LevelEnd:
				{
					LevelEndMechanicsDefinition(state);

					break;
				}
				case state.FinalLevelEnd: //Does the same as LevelEnd but returns to the titlescreen instead of the next level and prints the final player's score in the center of the screen
				{
					TitleScreenMechanicsDefinition(state);

					break;
				}

				default: break;
			}

			break;
		}
		default: break;
	}
	
}

// ----------------------------------------------------------------
void Draw()
{
	// Clear screen to Cornflower blue
	SDL_SetRenderDrawColor(state.renderer, 100, 149, 237, 255);
	SDL_RenderClear(state.renderer);

	

	// Draw background texture (two times for scrolling effect)
	// NOTE: rec rectangle is being reused for next draws
	SDL_Rect rec = { -state.scroll, 0, 3701, SCREEN_HEIGHT };
	SDL_Rect rec2 = { state.bullet.frame_x, state.bullet.frame_y, state.bullet.frame_w, state.bullet.frame_h };

	

	
	
	switch (state.scene)
	{
		case state.TitleScreen:
		{
			TitleScreenDrawDefinition(state, rec, rec2);

			break;
		}
		case state.LevelScenes:
		{
			

			switch (state.level)
			{
				case state.Level_1:
				{
					Level_1DrawDefinition(state, rec, rec2);


					DrawPlayerDefinition(state, rec, rec2); //Define the rectangles and the SDL drawing functions to draw the player and its different frames, effects, etc
					break;
				}
				case state.Level_2:
				{
					Level_2DrawDefinition(state, rec, rec2);


					DrawPlayerDefinition(state, rec, rec2); //Define the rectangles and the SDL drawing functions to draw the player and its different frames, effects, etc
					break;
				}
				case state.Level_3:
				{
					Level_3DrawDefinition(state, rec, rec2);


					DrawPlayerDefinition(state, rec, rec2); //Define the rectangles and the SDL drawing functions to draw the player and its different frames, effects, etc
					break;
				}
				case state.LevelEnd:
				{
					LevelEndnDrawDefinition(state, rec, rec2);

					break;
				}
				case state.FinalLevelEnd:
				{
					LevelEndnDrawDefinition(state, rec, rec2);

					break;
				}

				default: break;
			}

			break;
		}
		default: break;
	}

	// Finally present framebuffer
	SDL_RenderPresent(state.renderer);
}