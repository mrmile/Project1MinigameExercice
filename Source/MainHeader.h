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
#include "SDL_ttf/include/SDL_ttf.h"		//Requiered for font and writing funcitonality


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

	int coordinateX;
	int coordinateY;

	// Game Parts
	enum GameScene
	{
		TitleScreen = 0,
		LevelScenes
	};
	GameScene scene = TitleScreen;

	enum Levels
	{
		OtherScene = 0,
		Level_1,
		Level_2,
		Level_3,

		LevelEnd,
		FinalLevelEnd,
	};
	Levels level = OtherScene;

	// Window and renderer
	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;
	TTF_Font* font;
	SDL_Surface* message;
	SDL_Color white = { 255,255,255 };

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
	SDL_Texture* title;

	SDL_Texture* player;
	SDL_Texture* boss;
	SDL_Texture* bossShot;
	SDL_Texture* shot;

	SDL_Texture* fuzzBall;
	SDL_Texture* DownRightArrow;
	SDL_Texture* DownLeftArrow;
	SDL_Texture* UpRightArrow;
	SDL_Texture* UpLeftArrow;
	SDL_Texture* FlyingRedTurtle;
	SDL_Texture* GreenTurtle1;
	SDL_Texture* GreenTurtle1and2;
	SDL_Texture* BrownGoomba;
	SDL_Texture* BlueGoomba;
	SDL_Texture* GreyGoomba;
	SDL_Texture* BuzzyBeetle;
	SDL_Texture* HammerBrother;
	SDL_Texture* Hammer;

	SDL_Texture* CheckPoint;
	SDL_Texture* GoalPoint;
	SDL_Texture* GoalPointBar;
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
		//From game point of view
		int boss_x;
		int boss_y;
		int boss_w;
		int boss_h;

		//From image point of view
		int bossFrame_x;
		int bossFrame_y;
		int bossFrame_w;
		int bossFrame_h;

		int bossLife;
		int BossFPS;
	} Boss;

	Boss castleBoss;

	//Entities (interactive level things with player)

	typedef struct Entity
	{
		//From game point of view
		int entity_x;
		int entity_y;
		int entity_w;
		int entity_h;

		//From image point of view
		int entityFrame_x;
		int entityFrame_y;
		int entityFrame_w;
		int entityFrame_h;

		int entityLife;
		int entityFPS;
	} Entity;

	Entity BossShot_Entity;

	Entity DownRightArrow_Entity; //To use in all levels
	Entity UpRightArrow_Entity; //To use in all levels
	Entity DownLeftArrow_Entity; //To use in all levels
	Entity UpLeftArrow_Entity; //To use in all levels

	Entity FuzzBall_Entity; //To use in level 2 (Turns ON a disturbing colorchanging effect on the top layer when collided)
	Entity FlyingRedTurtle_Entity; //To use in all levels (Hides into shell when collided and falls)
	Entity GreenTurtle1_Entity; //To use in level 1 (Hides into shell when collided and falls)
	Entity GreenTurtle2_Entity; //To use in level 2 and 3 (Hides into shell when collided and falls)
	Entity BrownGoomba_Entity; //To use in level 1 (Gets crushed when collided and falls)
	Entity BlueGoomba_Entity; //To use in level 2 (Gets crushed when collided and falls)
	Entity GreyGoomba_Entity; //To use in level 3 (Gets crushed when collided and falls)
	Entity BuzzyBeetle_Entity; //To use in level 2 and 3 (Hides into shell when collided and falls)
	Entity HammerBrother_Entity; //To use in level 3 (Throws hammers that kill the player and Falls when collided)
	Entity Hammer_Entity; //To use in level 3 (Hammer thrown by HammerBrother that kills the player)

	Entity CheckPoint_Entity; //To use in all levels (Appears at the level half)
	Entity GoalPoint_Entity; //To use in all levels (Appears at the level end)
	Entity GoalPointBar_Entity; //To use in all levels (Appears with the GoalPoint and is broken when player goes accross it)
	Entity FireWork_Entity; //To use in all the level ends (appears once the level is finished)

	Entity Coin_Entity; //To use in all levels (player collects it)
	Entity QuestionBlock_Entity; //To use in all levels (player breaks it and collect a coin)
	Entity BrickBlock_Entity; //To use in all levels (player breaks it)

	//Tiles (interactive level things with player BUT NOT ANIMATED)

	typedef struct Tile
	{
		//From game point of view
		int boss_x;
		int boss_y;
		int boss_w;
		int boss_h;

		//From image point of view
		int tileFrame_x;
		int tileFrame_y;
		int tileFrame_w;
		int tileFrame_h;
	} Tile;

	Tile GreenPipeUp; //To use in level 1 and 2
	Tile GreenPipeDown; //To use in level 1 and 2
	Tile GreyPipeUp; //To use in level 3
	Tile GreyPipeDown; //To use in level 3

	Tile SmallGrassWallUp; //To use in level 1
	Tile GrassWallUp; //To use in level 1
	Tile SmallGrassWallDown; //To use in level 1
	Tile GrassWallDown; //To use in level 1

	Tile SmallPalmUp; //To use in level 1
	Tile PalmUp; //To use in level 1
	Tile SmallPalmDown; //To use in level 1
	Tile PalmDown; //To use in level 1
	
	Tile SmallCaveWallUp; //To use in level 2
	Tile CaveWallUp; //To use in level 2
	Tile SmallCaveWallDown; //To use in level 2
	Tile CaveWallDown; //To use in level 2

	Tile SmallCastleWallUp; //To use in level 3
	Tile CastleWallUp; //To use in level 3
	Tile SmallCastleWallDown; //To use in level 3
	Tile CastleWallDown; //To use in level 3
	Tile SmallCastleBlock; //To use in level 3
	Tile CastleBlock; //To use in level 3
	
	Tile BulletLauncher; //To use in all level start

	//Player
	typedef struct Player
	{
		int player_x;
		int player_y;

		int playerFrame_x;
		int playerFrame_y;
		int playerFrame_w;
		int playerFrame_h;

		int PlayerFPS;
	} Player;

	Player bullet;

	Projectile shots[MAX_SHIP_SHOTS];
	int last_shot;

	//Tileset

	int scroll;
};