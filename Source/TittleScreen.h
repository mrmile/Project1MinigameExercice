#pragma once

#include "MainHeader.h"
#include "MainFunctionsHeader.h"

void TitleScreenMechanicsDefinition(GlobalState& state)
{
	
}
void TitleScreenDrawDefinition(GlobalState& state, SDL_Rect rec, SDL_Rect rec2)
{
	rec.x = 0;
	rec.y = 0;
	rec.w = 1280;
	rec.h = 720;
	rec2.x = 0;
	rec2.y = 0;
	rec2.w = 1280;
	rec2.h = 720;
	SDL_RenderCopy(state.renderer, state.title, &rec2, &rec);
	
}