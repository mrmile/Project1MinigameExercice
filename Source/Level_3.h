#pragma once


#include "MainHeader.h"
#include "MainFunctionsHeader.h"
#include "Player.h"
#include"Entity.h"

void Level_3MechanicsDefinition(GlobalState& state)
{
	
}

void Level_3DrawDefinition(GlobalState& state, SDL_Rect rec, SDL_Rect rec2)
{
	state.background_width = 3701;
	// Draw background and scroll
	state.scroll += SCROLL_SPEED;
	if (state.scroll >= state.background_width)	state.scroll = 0;

	

	SDL_RenderCopy(state.renderer, state.background3, NULL, &rec);
	rec.x += state.background_width;
	SDL_RenderCopy(state.renderer, state.background3, NULL, &rec);
}