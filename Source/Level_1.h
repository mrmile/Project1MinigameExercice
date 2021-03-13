#pragma once


#include "MainHeader.h"
#include "MainFunctionsHeader.h"
#include "Player.h"
#include"Entity.h"

void Level_1MechanicsDefinition(GlobalState& state)
{
	Mix_PlayMusic(state.overworld, -1);
}

void Level_1DrawDefinition(GlobalState& state, SDL_Rect rec, SDL_Rect rec2)
{
	state.background_width = 6544;
	// Draw background and scroll
	state.scroll += SCROLL_SPEED;
	if (state.scroll >= state.background_width)	state.scroll = 0;



	SDL_RenderCopy(state.renderer, state.background1, NULL, &rec);
	rec.x += state.background_width;
	SDL_RenderCopy(state.renderer, state.background1, NULL, &rec);
}