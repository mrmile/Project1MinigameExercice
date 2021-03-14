#pragma once


#include "MainHeader.h"
#include "MainFunctionsHeader.h"
#include "Level_1.h"
#include "Level_2.h"
#include "Level_3.h"
#include "Player.h"

//COLLISIONS ARE NOT IMPLEMENTED YET AND ITS INTERACTIONS WITH THE PLAYER ARE NOT FULLY IMPLEMENTED !!!

void DownRightArrow_MechanicsDefinition(GlobalState& state, int x, int y)
{
	if (state.DownRightArrow_Entity.entityLife == 1)
	{
		state.DownRightArrow_Entity.entityFrame_x = 52; state.DownRightArrow_Entity.entityFrame_y = 8; state.DownRightArrow_Entity.entityFrame_w = 20; state.DownRightArrow_Entity.entityFrame_h = 44;

		state.DownRightArrow_Entity.entity_x = x; state.DownRightArrow_Entity.entity_y = y;
	}
	if (state.DownRightArrow_Entity.entityLife == 0)
	{
		state.DownRightArrow_Entity.entityFrame_x = 52; state.DownRightArrow_Entity.entityFrame_y = 33; state.DownRightArrow_Entity.entityFrame_w = 20; state.DownRightArrow_Entity.entityFrame_h = 44;

		state.UpRightArrow_Entity.entity_x = x; state.DownRightArrow_Entity.entity_y--;
	}
	if (state.DownRightArrow_Entity.entityLife == 0 && state.DownRightArrow_Entity.entityFPS < 1)
	{
		Mix_PlayChannel(-1, state.clap, 0);
	}

}

void DownRightArrow_DrawDefinition(GlobalState& state, SDL_Rect rec, SDL_Rect rec2, int x, int y)
{
	rec.x = state.DownRightArrow_Entity.entity_x; rec.y = state.DownRightArrow_Entity.entity_y; rec.w = state.DownRightArrow_Entity.entity_w * 4; rec.h = state.DownRightArrow_Entity.entity_h * 4;
	rec2.x = state.DownRightArrow_Entity.entityFrame_x; rec2.y = state.DownRightArrow_Entity.entityFrame_y; rec2.w = state.DownRightArrow_Entity.entityFrame_w; rec2.h = state.DownRightArrow_Entity.entityFrame_h;

	SDL_RenderCopy(state.renderer, state.DownRightArrow, &rec2, &rec);
}

//---------------------------------------------------------------------

void UpRightArrow_MechanicsDefinition(GlobalState& state, int x, int y)
{
	if (state.UpRightArrow_Entity.entityLife == 1)
	{
		state.UpRightArrow_Entity.entityFrame_x = 76; state.UpRightArrow_Entity.entityFrame_y = 8; state.UpRightArrow_Entity.entityFrame_w = 20; state.UpRightArrow_Entity.entityFrame_h = 44;

		state.UpRightArrow_Entity.entity_x = x; state.UpRightArrow_Entity.entity_y = y;
	}
	if (state.UpRightArrow_Entity.entityLife == 0)
	{
		state.UpRightArrow_Entity.entityFrame_x = 76; state.UpRightArrow_Entity.entityFrame_y = 33; state.UpRightArrow_Entity.entityFrame_w = 20; state.UpRightArrow_Entity.entityFrame_h = 44;

		state.UpRightArrow_Entity.entity_x = x; state.UpRightArrow_Entity.entity_y--;
	}
	if (state.UpRightArrow_Entity.entityLife == 0 && state.UpRightArrow_Entity.entityFPS < 1)
	{
		Mix_PlayChannel(-1, state.clap, 0);
	}
	
}

void UpRightArrow_DrawDefinition(GlobalState& state, SDL_Rect rec, SDL_Rect rec2, int x, int y)
{
	rec.x = state.UpRightArrow_Entity.entity_x; rec.y = state.UpRightArrow_Entity.entity_y; rec.w = state.UpRightArrow_Entity.entity_w * 4; rec.h = state.UpRightArrow_Entity.entity_h * 4;
	rec2.x = state.UpRightArrow_Entity.entityFrame_x; rec2.y = state.UpRightArrow_Entity.entityFrame_y; rec2.w = state.UpRightArrow_Entity.entityFrame_w; rec2.h = state.UpRightArrow_Entity.entityFrame_h;

	SDL_RenderCopy(state.renderer, state.UpRightArrow, &rec2, &rec);
}

//---------------------------------------------------------------------

void DownLeftArrow_MechanicsDefinition(GlobalState& state, int x, int y)
{
	if (state.DownLeftArrow_Entity.entityLife == 1)
	{
		state.DownLeftArrow_Entity.entityFrame_x = 104; state.DownLeftArrow_Entity.entityFrame_y = 8; state.DownLeftArrow_Entity.entityFrame_w = 20; state.DownLeftArrow_Entity.entityFrame_h = 46;

		state.DownLeftArrow_Entity.entity_x = x; state.DownLeftArrow_Entity.entity_y = y;
	}
	if (state.DownLeftArrow_Entity.entityLife == 0)
	{
		state.DownLeftArrow_Entity.entityFrame_x = 104; state.DownLeftArrow_Entity.entityFrame_y = 33; state.DownLeftArrow_Entity.entityFrame_w = 20; state.DownLeftArrow_Entity.entityFrame_h = 46;

		state.DownLeftArrow_Entity.entity_x = x; state.DownLeftArrow_Entity.entity_y--;
	}
	if (state.DownLeftArrow_Entity.entityLife == 0 && state.DownLeftArrow_Entity.entityFPS < 1)
	{
		Mix_PlayChannel(-1, state.clap, 0);
	}
}

void DownLeftArrow_DrawDefinition(GlobalState& state, SDL_Rect rec, SDL_Rect rec2, int x, int y)
{
	rec.x = state.DownLeftArrow_Entity.entity_x; rec.y = state.DownLeftArrow_Entity.entity_y; rec.w = state.DownLeftArrow_Entity.entity_w * 4; rec.h = state.DownLeftArrow_Entity.entity_h * 4;
	rec2.x = state.DownLeftArrow_Entity.entityFrame_x; rec2.y = state.DownLeftArrow_Entity.entityFrame_y; rec2.w = state.DownLeftArrow_Entity.entityFrame_w; rec2.h = state.DownLeftArrow_Entity.entityFrame_h;

	SDL_RenderCopy(state.renderer, state.DownLeftArrow, &rec2, &rec);
}

//---------------------------------------------------------------------

void UpLeftArrow_MechanicsDefinition(GlobalState& state, int x, int y)
{
	
	if (state.UpLeftArrow_Entity.entityLife == 1)
	{
		state.UpLeftArrow_Entity.entityFrame_x = 136; state.UpLeftArrow_Entity.entityFrame_y = 8; state.UpLeftArrow_Entity.entityFrame_w = 20; state.UpLeftArrow_Entity.entityFrame_h = 44;

		state.UpLeftArrow_Entity.entity_x = x; state.UpLeftArrow_Entity.entity_y = y;
	}
	if (state.UpLeftArrow_Entity.entityLife == 0)
	{
		state.UpLeftArrow_Entity.entityFrame_x = 136; state.UpLeftArrow_Entity.entityFrame_y = 33; state.UpLeftArrow_Entity.entityFrame_w = 20; state.UpLeftArrow_Entity.entityFrame_h = 44;

		state.UpLeftArrow_Entity.entity_x = x; state.UpLeftArrow_Entity.entity_y--;
	}
	if (state.UpLeftArrow_Entity.entityLife == 0 && state.UpLeftArrow_Entity.entityFPS < 1)
	{
		Mix_PlayChannel(-1, state.clap, 0);
	}
}

void UpLeftArrow_DrawDefinition(GlobalState& state, SDL_Rect rec, SDL_Rect rec2, int x, int y)
{
	
	rec.x = state.UpLeftArrow_Entity.entity_x; rec.y = state.UpLeftArrow_Entity.entity_y; rec.w = state.UpLeftArrow_Entity.entity_w * 4; rec.h = state.UpLeftArrow_Entity.entity_h * 4;
	rec2.x = state.UpLeftArrow_Entity.entityFrame_x; rec2.y = state.UpLeftArrow_Entity.entityFrame_y; rec2.w = state.UpLeftArrow_Entity.entityFrame_w; rec2.h = state.UpLeftArrow_Entity.entityFrame_h;

	SDL_RenderCopy(state.renderer, state.UpLeftArrow, &rec2, &rec);
}

//---------------------------------------------------------------------

void FuzzBall_MechanicsDefinition(GlobalState& state, int x, int y)
{
	if (state.FuzzBall_Entity.entityLife == 1)
	{
		state.FuzzBall_Entity.entityFrame_x = 8; state.FuzzBall_Entity.entityFrame_y = 8; state.FuzzBall_Entity.entityFrame_w = 32; state.FuzzBall_Entity.entityFrame_h = 32;

		state.FuzzBall_Entity.entity_x = x; state.FuzzBall_Entity.entity_y = y;
	}
	if (state.FuzzBall_Entity.entityLife == 0)
	{
		if ((state.FuzzBall_Entity.entityFPS / 5) % 2 == 0)
		{
			state.FuzzBall_Entity.entityFrame_x = 216; state.FuzzBall_Entity.entityFrame_y = 12; state.FuzzBall_Entity.entityFrame_w = 52; state.FuzzBall_Entity.entityFrame_h = 52;

			state.FuzzBall_Entity.entity_x = x; state.FuzzBall_Entity.entity_y = y;
		}
		else
		{
			state.FuzzBall_Entity.entityFrame_x = 216; state.FuzzBall_Entity.entityFrame_y = 12; state.FuzzBall_Entity.entityFrame_w = 52; state.FuzzBall_Entity.entityFrame_h = 52;

			state.FuzzBall_Entity.entity_x = x; state.FuzzBall_Entity.entity_y = y;
		}
		if (state.FuzzBall_Entity.entityFPS > 300)
		{
			state.FuzzBall_Entity.entityFrame_x = 420; state.FuzzBall_Entity.entityFrame_y = 12; state.FuzzBall_Entity.entityFrame_w = 0; state.FuzzBall_Entity.entityFrame_h = 0;

			state.FuzzBall_Entity.entity_x = x; state.FuzzBall_Entity.entity_y = y;
		}
	}
	if (state.FuzzBall_Entity.entityLife == 0 && state.FuzzBall_Entity.entityFPS < 1)
	{
		Mix_PlayChannel(-1, state.defeat, 0);
	}
}

void FuzzBall_DrawDefinition(GlobalState& state, SDL_Rect rec, SDL_Rect rec2, int x, int y)
{
	
	if (state.FuzzBall_Entity.entityLife == 1)
	{
		rec.x = state.FuzzBall_Entity.entity_x; rec.y = state.FuzzBall_Entity.entity_y; rec.w = state.FuzzBall_Entity.entityFrame_w; rec.h = state.FuzzBall_Entity.entityFrame_h = 52;
		rec2.x = state.FuzzBall_Entity.entityFrame_x; rec2.y = state.FuzzBall_Entity.entityFrame_y; rec2.w = state.FuzzBall_Entity.entityFrame_w; rec2.h = state.FuzzBall_Entity.entityFrame_h;
	}
	if (state.FuzzBall_Entity.entityLife == 0)
	{
		rec.w = SCREEN_WIDTH;
		rec.h = SCREEN_HEIGHT;
	}

	SDL_RenderCopy(state.renderer, state.fuzzBall, &rec2, &rec);
}

//---------------------------------------------------------------------

void FlyingRedTurtle_MechanicsDefinition(GlobalState& state, int x, int y)
{
	if (state.FlyingRedTurtle_Entity.entityLife == 1)
	{
		if ((state.FlyingRedTurtle_Entity.entityFPS / 5) % 2 == 0)
		{
			state.FlyingRedTurtle_Entity.entityFrame_x = 11; state.FlyingRedTurtle_Entity.entityFrame_y = 65; state.FlyingRedTurtle_Entity.entityFrame_w = 17; state.FlyingRedTurtle_Entity.entityFrame_h = 24;

			state.FlyingRedTurtle_Entity.entity_x = x; state.FlyingRedTurtle_Entity.entity_y = y;
		}
		else
		{
			state.FlyingRedTurtle_Entity.entityFrame_x = 28; state.FlyingRedTurtle_Entity.entityFrame_y = 64; state.FlyingRedTurtle_Entity.entityFrame_w = 17; state.FlyingRedTurtle_Entity.entityFrame_h = 24;

			state.FlyingRedTurtle_Entity.entity_x = x; state.FlyingRedTurtle_Entity.entity_y = y;
		}
	}
	if (state.FlyingRedTurtle_Entity.entityLife == 0)
	{
		state.FlyingRedTurtle_Entity.entityFrame_x = 96; state.FlyingRedTurtle_Entity.entityFrame_y = 72; state.FlyingRedTurtle_Entity.entityFrame_w = 17; state.FlyingRedTurtle_Entity.entityFrame_h = 17;

		state.FlyingRedTurtle_Entity.entity_x = x; state.FlyingRedTurtle_Entity.entity_y--;
	}
	if (state.FlyingRedTurtle_Entity.entityLife == 0 && state.FlyingRedTurtle_Entity.entityFPS < 1)
	{
		Mix_PlayChannel(-1, state.kick, 0);
	}

	state.FlyingRedTurtle_Entity.entity_x = x; state.FlyingRedTurtle_Entity.entity_y = y;
}

void FlyingRedTurtle_DrawDefinition(GlobalState& state, SDL_Rect rec, SDL_Rect rec2, int x, int y)
{
	rec.x = state.FlyingRedTurtle_Entity.entity_x; rec.y = state.FlyingRedTurtle_Entity.entity_y; rec.w = state.FlyingRedTurtle_Entity.entityFrame_w * 4; rec.h = state.FlyingRedTurtle_Entity.entity_h * 4;
	rec2.x = state.FlyingRedTurtle_Entity.entityFrame_x; rec2.y = state.FlyingRedTurtle_Entity.entityFrame_y; rec2.w = state.FlyingRedTurtle_Entity.entityFrame_w; rec2.h = state.FlyingRedTurtle_Entity.entityFrame_h;

	SDL_RenderCopy(state.renderer, state.FlyingRedTurtle, &rec2, &rec);
}

//---------------------------------------------------------------------

void GreenTurtle1_MechanicsDefinition(GlobalState& state, int x, int y)
{
	if (state.FlyingRedTurtle_Entity.entityLife == 1)
	{
		if ((state.GreenTurtle1_Entity.entityFPS / 5) % 2 == 0)
		{
			state.GreenTurtle1_Entity.entityFrame_x = 11; state.GreenTurtle1_Entity.entityFrame_y = 93; state.GreenTurtle1_Entity.entityFrame_w = 17; state.GreenTurtle1_Entity.entityFrame_h = 24;

			state.GreenTurtle1_Entity.entity_x = x; state.GreenTurtle1_Entity.entity_y = y;
		}
		else
		{
			state.GreenTurtle1_Entity.entityFrame_x = 28; state.GreenTurtle1_Entity.entityFrame_y = 93; state.GreenTurtle1_Entity.entityFrame_w = 17; state.GreenTurtle1_Entity.entityFrame_h = 24;

			state.GreenTurtle1_Entity.entity_x = x; state.GreenTurtle1_Entity.entity_y = y;
		}
	}
	if (state.FlyingRedTurtle_Entity.entityLife == 0)
	{
		state.GreenTurtle1_Entity.entityFrame_x = 28; state.GreenTurtle1_Entity.entityFrame_y = 93; state.GreenTurtle1_Entity.entityFrame_w = 17; state.GreenTurtle1_Entity.entityFrame_h = 17;

		state.GreenTurtle1_Entity.entity_x = x; state.GreenTurtle1_Entity.entity_y--;
	}
	if (state.FlyingRedTurtle_Entity.entityLife == 0 && state.FlyingRedTurtle_Entity.entityFPS < 1)
	{
		Mix_PlayChannel(-1, state.kick, 0);
	}
	
}

void GreenTurtle1_DrawDefinition(GlobalState& state, SDL_Rect rec, SDL_Rect rec2, int x, int y)
{
	rec.x = state.GreenTurtle1_Entity.entity_x; rec.y = state.GreenTurtle1_Entity.entity_y; rec.w = state.GreenTurtle1_Entity.entityFrame_w * 4; rec.h = state.GreenTurtle1_Entity.entity_h * 4;
	rec2.x = state.GreenTurtle1_Entity.entityFrame_x; rec2.y = state.GreenTurtle1_Entity.entityFrame_y; rec2.w = state.GreenTurtle1_Entity.entityFrame_w; rec2.h = state.GreenTurtle1_Entity.entityFrame_h;

	SDL_RenderCopy(state.renderer, state.GreenTurtle1, &rec2, &rec);
}

//---------------------------------------------------------------------

