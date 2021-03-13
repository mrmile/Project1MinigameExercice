#pragma once

// -------------------------------------------------------------------------
// Awesome simple game with SDL
// Lesson 2 - Input Events
//
// SDL API: http://wiki.libsdl.org/APIByCategory
// -------------------------------------------------------------------------

#include <stdio.h>			// Required for: printf()
#include <stdlib.h>			// Required for: EXIT_SUCCESS
#include <math.h>			// Required for: sinf(), cosf()

// Include SDL libraries
#include "SDL/include/SDL.h"				// Required for SDL base systems functionality
#include "SDL_image/include/SDL_image.h"	// Required for image loading functionality
#include "SDL_mixer/include/SDL_mixer.h"	// Required for audio loading and playing functionality


// Define libraries required by linker
// WARNING: Not all compilers support this option and it couples 
// source code with build system, it's recommended to keep both 
// separated, in case of multiple build configurations
//#pragma comment(lib, "SDL/lib/x86/SDL2.lib")
//#pragma comment(lib, "SDL/lib/x86/SDL2main.lib")
//#pragma comment(lib, "SDL_image/lib/x86/SDL2_image.lib")
//#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

// -------------------------------------------------------------------------
// Defines, Types and Globals
// -------------------------------------------------------------------------
#define SCREEN_WIDTH		1280
#define SCREEN_HEIGHT		 720

#define MAX_KEYBOARD_KEYS	 256
#define MAX_MOUSE_BUTTONS	   5
#define JOYSTICK_DEAD_ZONE  8000

#define SHIP_SPEED			  14
#define MAX_SHIP_SHOTS		  32
#define SHOT_SPEED			  21
#define SCROLL_SPEED		  10

enum WindowEvent
{
	WE_QUIT = 0,
	WE_HIDE,
	WE_SHOW,
	WE_COUNT
};

enum KeyState
{
	KEY_IDLE = 0,		// DEFAULT
	KEY_DOWN,			// PRESSED (DEFAULT->DOWN)
	KEY_REPEAT,			// KEEP DOWN (sustained)
	KEY_UP				// RELEASED (DOWN->DEFAULT)
};

struct Projectile
{
	int x, y;
	bool alive;
};

// Global context to store our game state data
struct GlobalState
{
	int GeneralFPS;

	// Game Parts
	enum GameScene
	{
		TitleScreen = 0,
		LevelScenes
	};
	GameScene scene = LevelScenes;

	enum Levels
	{
		OtherScene = 0,
		Level_1,
		Level_2,
		Level_3,

		LevelEnd,
		FinalLevelEnd
	};
	Levels level = Level_3;

	// Window and renderer
	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;

	// Input events
	KeyState* keyboard;
	KeyState mouse_buttons[MAX_MOUSE_BUTTONS];
	int mouse_x;
	int mouse_y;
	SDL_Joystick* gamepad;
	int gamepad_axis_x_dir;
	int gamepad_axis_y_dir;
	bool window_events[WE_COUNT];

	// Texture variables
	SDL_Texture* background1;
	SDL_Texture* background2;
	SDL_Texture* background3;

	SDL_Texture* player;
	SDL_Texture* boss;
	SDL_Texture* shot;

	SDL_Texture* fuzzBall;
	SDL_Texture* DownRightArrow;
	SDL_Texture* DownLeftArrow;
	SDL_Texture* UpRightArrow;
	SDL_Texture* UpLeftArrow;
	SDL_Texture* RedTurtle;
	SDL_Texture* GreenTurtle1;
	SDL_Texture* GreenTurtle1and2;
	SDL_Texture* BrownGoomba;
	SDL_Texture* BlueGoomba;
	SDL_Texture* GreyGoomba;
	SDL_Texture* BuzzyBeetle;
	SDL_Texture* HammerBrother;

	SDL_Texture* CheckPoint;
	SDL_Texture* GoalPoint;
	SDL_Texture* FireWork;

	SDL_Texture* Coin;
	SDL_Texture* QuestionBlock;
	SDL_Texture* BrickBlock;

	int background_width;

	// Audio variables
	Mix_Music* titleScreen;
	Mix_Music* levelWin;
	Mix_Music* overworld;
	Mix_Music* cave;
	Mix_Music* castle;

	Mix_Chunk* fx_shoot;
	Mix_Chunk* bossAttack;
	Mix_Chunk* breakBlock;
	Mix_Chunk* bulletShot;
	Mix_Chunk* checkPointAndGoal;
	Mix_Chunk* clap;
	Mix_Chunk* coin;
	Mix_Chunk* defeat;
	Mix_Chunk* fireworks;
	Mix_Chunk* kick;
	Mix_Chunk* playerExplode;
	Mix_Chunk* stomp;

	// Game elements

	//Boss
	typedef struct Boss
	{
		int boss_x;
		int boss_y;

		int frame_x;
		int frame_y;
		int frame_w;
		int frame_h;

		int BossFPS;
	} Boss;

	Boss castleBoss;

	//Entities (interactive level things with player)

	//Player
	typedef struct Player
	{
		int player_x;
		int player_y;

		int frame_x;
		int frame_y;
		int frame_w;
		int frame_h;

		int PlayerFPS;
	} Player;

	Player bullet;

	Projectile shots[MAX_SHIP_SHOTS];
	int last_shot;

	//Tileset

	int scroll;
};