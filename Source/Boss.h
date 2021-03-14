#pragma once

#include "MainHeader.h"
#include "MainFunctionsHeader.h"
#include"Entity.h"
#include "Level_3.h"

void BossMechanicsDefinition(GlobalState& state)
{
	state.castleBoss.BossFPS++;

	state.castleBoss.boss_x = 200;
	state.castleBoss.boss_y = 100;

	if (state.castleBoss.bossLife > 0)
	{
		if (state.castleBoss.BossFPS == 1)
		{
			state.castleBoss.bossLife--;
		}

		if (state.castleBoss.BossFPS <= 120)
		{
			state.castleBoss.boss_w = 100;
			state.castleBoss.boss_h = 100;

			state.castleBoss.bossFrame_w = 32;
			state.castleBoss.bossFrame_h = 44;

			if ((state.castleBoss.BossFPS / 5) % 2 == 0)
			{
				state.castleBoss.bossFrame_x = 168;
				state.castleBoss.bossFrame_y = 244;

			}
			else
			{
				state.castleBoss.bossFrame_x = 236;
				state.castleBoss.bossFrame_y = 244;
			}
		}
		if (state.castleBoss.BossFPS >= 120)
		{
			state.castleBoss.boss_x = state.castleBoss.boss_x - 50;
			state.castleBoss.boss_y = state.castleBoss.boss_y - 50;

			state.castleBoss.boss_w = 150;
			state.castleBoss.boss_h = 150;

			state.castleBoss.bossFrame_w = 56;
			state.castleBoss.bossFrame_h = 84;

			if (state.castleBoss.BossFPS <= 130 && state.castleBoss.BossFPS > 120)
			{
				state.castleBoss.bossFrame_x = 4;
				state.castleBoss.bossFrame_y = 104;

			}
			else if (state.castleBoss.BossFPS <= 140 && state.castleBoss.BossFPS > 130)
			{
				state.castleBoss.bossFrame_x = 64;
				state.castleBoss.bossFrame_y = 104;
			}
			else if (state.castleBoss.BossFPS <= 150 && state.castleBoss.BossFPS > 140)
			{
				state.castleBoss.bossFrame_x = 120;
				state.castleBoss.bossFrame_y = 104;
			}
			else if (state.castleBoss.BossFPS <= 160 && state.castleBoss.BossFPS > 150)
			{
				state.castleBoss.bossFrame_x = 176;
				state.castleBoss.bossFrame_y = 104;
			}
			else if (state.castleBoss.BossFPS <= 170 && state.castleBoss.BossFPS > 160)
			{
				state.castleBoss.bossFrame_w = 48;

				state.castleBoss.boss_w = 120;

				state.castleBoss.boss_y = state.castleBoss.boss_y - 5;

				state.castleBoss.bossFrame_x = 404;
				state.castleBoss.bossFrame_y = 104;
			}
			else if (state.castleBoss.BossFPS <= 180 && state.castleBoss.BossFPS > 170)
			{
				state.castleBoss.bossFrame_w = 44;
				state.castleBoss.bossFrame_h = 84;

				state.castleBoss.boss_w = 100;

				state.castleBoss.boss_y = state.castleBoss.boss_y - 10;

				state.castleBoss.bossFrame_x = 236;
				state.castleBoss.bossFrame_y = 96;
			}
			else if (state.castleBoss.BossFPS <= 190 && state.castleBoss.BossFPS > 180)
			{
				state.castleBoss.bossFrame_w = 40;
				state.castleBoss.bossFrame_h = 84;

				state.castleBoss.boss_w = 100;

				state.castleBoss.boss_y = state.castleBoss.boss_y - 10;

				state.castleBoss.bossFrame_x = 280;
				state.castleBoss.bossFrame_y = 96;
			}
			else if (state.castleBoss.BossFPS <= 200 && state.castleBoss.BossFPS > 190)
			{
				state.castleBoss.bossFrame_w = 40;
				state.castleBoss.bossFrame_h = 84;

				state.castleBoss.boss_w = 100;

				state.castleBoss.boss_y = state.castleBoss.boss_y - 10;

				state.castleBoss.bossFrame_x = 324;
				state.castleBoss.bossFrame_y = 96;
			}
			else if (state.castleBoss.BossFPS <= 210 && state.castleBoss.BossFPS > 200)
			{
				state.castleBoss.bossFrame_w = 40;
				state.castleBoss.bossFrame_h = 84;

				state.castleBoss.boss_w = 100;

				state.castleBoss.boss_y = state.castleBoss.boss_y - 10;

				state.castleBoss.bossFrame_x = 364;
				state.castleBoss.bossFrame_y = 96;
			}
			else if (state.castleBoss.BossFPS <= 220 && state.castleBoss.BossFPS > 210)
			{
				state.castleBoss.bossFrame_w = 48;

				state.castleBoss.boss_w = 120;

				state.castleBoss.boss_y = state.castleBoss.boss_y - 5;

				state.castleBoss.bossFrame_x = 404;
				state.castleBoss.bossFrame_y = 104;
			}
			else if (state.castleBoss.BossFPS <= 230 && state.castleBoss.BossFPS > 220)
			{
				state.castleBoss.BossFPS = 120;
				Mix_PlayChannel(-1, state.bossAttack, 0);
			}
		}
	}
	
	
}

void BossDrawDefinition(GlobalState& state, SDL_Rect rec, SDL_Rect rec2)
{
	rec.x = state.castleBoss.boss_x; rec.y = state.castleBoss.boss_y; rec.w = state.castleBoss.boss_w; rec.h = state.castleBoss.boss_h;
	rec2.x = state.castleBoss.bossFrame_x; rec2.y = state.castleBoss.bossFrame_y; rec2.w = state.castleBoss.bossFrame_w; rec2.h = state.castleBoss.bossFrame_h;

	SDL_RenderCopy(state.renderer, state.boss, &rec2, &rec);

}