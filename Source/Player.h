#pragma once

#include "MainHeader.h"
#include "MainFunctionsHeader.h"
#include"Entity.h"


void PlayerMechanicsDefinition(GlobalState &state)
{
	state.bullet.PlayerFPS++;
	// L2: DONE 7: Move the ship with arrow keys
	if (state.bullet.PlayerFPS <= 5)
	{
		state.bullet.playerFrame_x = 8;
		state.bullet.playerFrame_y = 476;
		state.bullet.playerFrame_w = 18;
		state.bullet.playerFrame_h = 18;
	}
	else if (state.bullet.PlayerFPS > 5 && state.bullet.PlayerFPS <= 10)
	{
		state.bullet.playerFrame_x = 32;
		state.bullet.playerFrame_y = 476;
		state.bullet.playerFrame_w = 18;
		state.bullet.playerFrame_h = 18;
	}
	else if (state.bullet.PlayerFPS > 10)
	{
		state.bullet.playerFrame_x = 56;
		state.bullet.playerFrame_y = 476;
		state.bullet.playerFrame_w = 18;
		state.bullet.playerFrame_h = 18;
	}

	if (state.keyboard[SDL_SCANCODE_UP] == KEY_REPEAT && state.bullet.player_y > 0) state.bullet.player_y -= SHIP_SPEED;
	else if (state.keyboard[SDL_SCANCODE_DOWN] == KEY_REPEAT && state.bullet.player_y < (SCREEN_HEIGHT - 60)) state.bullet.player_y += SHIP_SPEED;

	if (state.keyboard[SDL_SCANCODE_LEFT] == KEY_REPEAT && state.bullet.player_x > 0)
	{
		state.bullet.PlayerFPS = 0;

		state.bullet.player_x -= SHIP_SPEED;
	}
	else if (state.keyboard[SDL_SCANCODE_RIGHT] == KEY_REPEAT && state.bullet.player_x < (SCREEN_WIDTH - 60)) state.bullet.player_x += SHIP_SPEED;

	// L2: DONE 8: Initialize a new shot when SPACE key is pressed
	if (state.keyboard[SDL_SCANCODE_SPACE] == KEY_DOWN)
	{

		if (state.last_shot == MAX_SHIP_SHOTS) state.last_shot = 0;

		state.shots[state.last_shot].alive = true;
		state.shots[state.last_shot].x = state.bullet.player_x + 35;
		state.shots[state.last_shot].y = state.bullet.player_y - 3;
		state.last_shot++;

		// L4: TODO 4: Play sound fx_shoot
		Mix_PlayChannel(-1, state.fx_shoot, 0);
	}

	// Update active shots
	for (int i = 0; i < MAX_SHIP_SHOTS; ++i)
	{
		if (state.shots[i].alive)
		{
			if (state.shots[i].x < SCREEN_WIDTH) state.shots[i].x += SHOT_SPEED;
			else state.shots[i].alive = false;
		}
	}
}

void DrawPlayerDefinition(GlobalState &state, SDL_Rect rec, SDL_Rect rec2)
{
	// Draw ship rectangle
	//DrawRectangle(state.ship_x, state.ship_y, 250, 100, { 255, 0, 0, 255 });

	// Draw ship texture
	
	rec.x = state.bullet.player_x; rec.y = state.bullet.player_y; rec.w = 60; rec.h = 60;

	SDL_RenderCopy(state.renderer, state.player, &rec2, &rec);

	// L2: DONE 9: Draw active shots
	rec2.x = 212; rec2.y = 480; rec2.w = 20; rec2.h = 16;
	rec.w = 64; rec.h = 64;
	for (int i = 0; i < MAX_SHIP_SHOTS; ++i)
	{
		if (state.shots[i].alive)
		{
			//DrawRectangle(state.shots[i].x, state.shots[i].y, 50, 20, { 0, 250, 0, 255 });
			rec.x = state.shots[i].x; rec.y = state.shots[i].y;
			SDL_RenderCopy(state.renderer, state.shot, &rec2, &rec);
		}
	}
}