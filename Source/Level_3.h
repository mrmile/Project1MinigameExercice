#pragma once


#include "MainHeader.h"
#include "MainFunctionsHeader.h"
#include "Player.h"


void Level_3MechanicsDefinition(GlobalState& state)
{

}

void Level_3DrawDefinition(GlobalState& state, SDL_Rect rec, SDL_Rect rec2)
{
	// Draw background and scroll
	state.scroll += SCROLL_SPEED;
	if (state.scroll >= 3701)	state.scroll = 0;

	// Draw background texture (two times for scrolling effect)
	// NOTE: rec rectangle is being reused for next draws

	SDL_RenderCopy(state.renderer, state.background, NULL, &rec);
	rec.x += 3701;
	SDL_RenderCopy(state.renderer, state.background, NULL, &rec);
}