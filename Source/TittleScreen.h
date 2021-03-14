#pragma once

#include "MainHeader.h"
#include "MainFunctionsHeader.h"

void TitleScreenMechanicsDefinition(GlobalState& state)
{
	
}
void TitleScreenDrawDefinition(GlobalState& state, SDL_Rect rec, SDL_Rect rec2)
{
	
	state.background_width = 1280;
	SDL_RenderFillRect(state.renderer, &rec);
	SDL_RenderCopy(state.renderer, state.TitleScreen1, NULL, &rec);
	
}