#pragma once

#include "MainHeader.h"
#include "MainFunctionsHeader.h"
#include "Level_1.h"
#include "Level_2.h"
#include "Level_3.h"
#include "Player.h"



void IntersectsWith(GlobalState& state)
{
	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.DownRightArrow_Entity.entityFrame_x ||
		state.bullet.playerFrame_x > state.DownRightArrow_Entity.entityFrame_x + state.DownRightArrow_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.DownRightArrow_Entity.entityFrame_y ||
		state.bullet.playerFrame_y > state.DownRightArrow_Entity.entityFrame_y + state.DownRightArrow_Entity.entityFrame_h)
	{
		state.DownRightArrow_Entity.entityLife = 1;
		//No colisiona
	}
	else if(state.bullet.playerFrame_x + state.bullet.playerFrame_w > state.DownRightArrow_Entity.entityFrame_x ||
		state.bullet.playerFrame_x < state.DownRightArrow_Entity.entityFrame_x + state.DownRightArrow_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.DownRightArrow_Entity.entityFrame_y ||
		state.bullet.playerFrame_y < state.DownRightArrow_Entity.entityFrame_y + state.DownRightArrow_Entity.entityFrame_h)
	{
		state.UpRightArrow_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------
	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.DownRightArrow_Entity.entityFrame_x ||
		state.bullet.playerFrame_x > state.DownRightArrow_Entity.entityFrame_x + state.DownRightArrow_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.DownRightArrow_Entity.entityFrame_y ||
		state.bullet.playerFrame_y > state.DownRightArrow_Entity.entityFrame_y + state.DownRightArrow_Entity.entityFrame_h)
	{
		state.DownRightArrow_Entity.entityLife = 1;
		//No colisiona
	}
	else if(state.bullet.playerFrame_x + state.bullet.playerFrame_w > state.UpRightArrow_Entity.entityFrame_x ||
		state.bullet.playerFrame_x < state.UpRightArrow_Entity.entityFrame_x + state.UpRightArrow_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.UpRightArrow_Entity.entityFrame_y ||
		state.bullet.playerFrame_y < state.UpRightArrow_Entity.entityFrame_y + state.UpRightArrow_Entity.entityFrame_h)
	{
		state.UpRightArrow_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.DownLeftArrow_Entity.entityFrame_x ||
		state.bullet.playerFrame_x > state.DownLeftArrow_Entity.entityFrame_x + state.DownLeftArrow_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.DownLeftArrow_Entity.entityFrame_y ||
		state.bullet.playerFrame_y > state.DownLeftArrow_Entity.entityFrame_y + state.DownLeftArrow_Entity.entityFrame_h)
	{
		state.DownLeftArrow_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x + state.bullet.playerFrame_w > state.DownLeftArrow_Entity.entityFrame_x ||
		state.bullet.playerFrame_x < state.DownLeftArrow_Entity.entityFrame_x + state.DownLeftArrow_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.DownLeftArrow_Entity.entityFrame_y ||
		state.bullet.playerFrame_y < state.DownLeftArrow_Entity.entityFrame_y + state.DownLeftArrow_Entity.entityFrame_h)
	{
		state.DownLeftArrow_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.UpLeftArrow_Entity.entityFrame_x ||
		state.bullet.playerFrame_x > state.UpLeftArrow_Entity.entityFrame_x + state.UpLeftArrow_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.UpLeftArrow_Entity.entityFrame_y ||
		state.bullet.playerFrame_y > state.UpLeftArrow_Entity.entityFrame_y + state.UpLeftArrow_Entity.entityFrame_h)
	{
		state.UpLeftArrow_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x + state.bullet.playerFrame_w > state.UpLeftArrow_Entity.entityFrame_x ||
		state.bullet.playerFrame_x < state.UpLeftArrow_Entity.entityFrame_x + state.UpLeftArrow_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.UpLeftArrow_Entity.entityFrame_y ||
		state.bullet.playerFrame_y < state.UpLeftArrow_Entity.entityFrame_y + state.UpLeftArrow_Entity.entityFrame_h)
	{
		state.UpLeftArrow_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.FlyingRedTurtle_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.FlyingRedTurtle_Entity.entityFrame_x +
		                                                          state.FlyingRedTurtle_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.FlyingRedTurtle_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.FlyingRedTurtle_Entity.entityFrame_y +
		                                                          state.FlyingRedTurtle_Entity.entityFrame_h)
	{
		                                                          state.FlyingRedTurtle_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x + 
		state.bullet.playerFrame_w > 
		                                                          state.FlyingRedTurtle_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.FlyingRedTurtle_Entity.entityFrame_x +
		                                                          state.FlyingRedTurtle_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.FlyingRedTurtle_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.FlyingRedTurtle_Entity.entityFrame_y +
		                                                          state.FlyingRedTurtle_Entity.entityFrame_h)
	{
		                                                          state.FlyingRedTurtle_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.FuzzBall_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.FuzzBall_Entity.entityFrame_x +
		                                                          state.FuzzBall_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.FuzzBall_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.FuzzBall_Entity.entityFrame_y +
		                                                          state.FuzzBall_Entity.entityFrame_h)
	{
		                                                          state.FuzzBall_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.FuzzBall_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.FuzzBall_Entity.entityFrame_x +
		                                                          state.FuzzBall_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.FuzzBall_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.FuzzBall_Entity.entityFrame_y +
		                                                          state.FuzzBall_Entity.entityFrame_h)
	{
		                                                          state.FuzzBall_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.GreenTurtle1_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.GreenTurtle1_Entity.entityFrame_x +
		                                                          state.GreenTurtle1_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.GreenTurtle1_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.GreenTurtle1_Entity.entityFrame_y +
		                                                          state.GreenTurtle1_Entity.entityFrame_h)
	{
		                                                          state.GreenTurtle1_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >                         
		                                                          state.GreenTurtle1_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.GreenTurtle1_Entity.entityFrame_x +
		                                                          state.GreenTurtle1_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.GreenTurtle1_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.GreenTurtle1_Entity.entityFrame_y +
		state.FuzzBall_Entity.entityFrame_h)
	{
		                                                          state.GreenTurtle1_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.BrownGoomba_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.BrownGoomba_Entity.entityFrame_x +
		                                                          state.BrownGoomba_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.BrownGoomba_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.BrownGoomba_Entity.entityFrame_y +
		                                                          state.BrownGoomba_Entity.entityFrame_h)
	{
		                                                          state.BrownGoomba_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.BrownGoomba_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.BrownGoomba_Entity.entityFrame_x +
		                                                          state.BrownGoomba_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.BrownGoomba_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.BrownGoomba_Entity.entityFrame_y +
		                                                          state.BrownGoomba_Entity.entityFrame_h)
	{
		                                                          state.BrownGoomba_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.BlueGoomba_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.BlueGoomba_Entity.entityFrame_x +
		                                                          state.BlueGoomba_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.BlueGoomba_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.BlueGoomba_Entity.entityFrame_y +
		                                                          state.BlueGoomba_Entity.entityFrame_h)
	{
		                                                          state.BlueGoomba_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.BlueGoomba_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.BlueGoomba_Entity.entityFrame_x +
		                                                          state.BlueGoomba_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.BlueGoomba_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.BlueGoomba_Entity.entityFrame_y +
		                                                          state.BlueGoomba_Entity.entityFrame_h)
	{
		                                                          state.BlueGoomba_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.GreyGoomba_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.GreyGoomba_Entity.entityFrame_x +
		                                                          state.GreyGoomba_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.GreyGoomba_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.GreyGoomba_Entity.entityFrame_y +
		                                                          state.GreyGoomba_Entity.entityFrame_h)
	{
		                                                          state.GreyGoomba_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.GreyGoomba_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.GreyGoomba_Entity.entityFrame_x +
		                                                          state.GreyGoomba_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.GreyGoomba_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.GreyGoomba_Entity.entityFrame_y +
		                                                          state.GreyGoomba_Entity.entityFrame_h)
	{
		                                                          state.GreyGoomba_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.BuzzyBeetle_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.BuzzyBeetle_Entity.entityFrame_x +
		                                                          state.BuzzyBeetle_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.BuzzyBeetle_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.BuzzyBeetle_Entity.entityFrame_y +
		                                                          state.BuzzyBeetle_Entity.entityFrame_h)
	{
		state.GreyGoomba_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.BuzzyBeetle_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.BuzzyBeetle_Entity.entityFrame_x +
		                                                          state.BuzzyBeetle_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.BuzzyBeetle_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.BuzzyBeetle_Entity.entityFrame_y +
		                                                          state.BuzzyBeetle_Entity.entityFrame_h)
	{
		                                                          state.BuzzyBeetle_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.HammerBrother_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.HammerBrother_Entity.entityFrame_x +
		                                                          state.HammerBrother_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.HammerBrother_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.HammerBrother_Entity.entityFrame_y +
		                                                          state.HammerBrother_Entity.entityFrame_h)
	{
		                                                          state.HammerBrother_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.HammerBrother_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.HammerBrother_Entity.entityFrame_x +
		                                                          state.HammerBrother_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.HammerBrother_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.HammerBrother_Entity.entityFrame_y +
		                                                          state.HammerBrother_Entity.entityFrame_h)
	{
		                                                          state.HammerBrother_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.Hammer_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.Hammer_Entity.entityFrame_x +
		                                                          state.Hammer_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.Hammer_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.Hammer_Entity.entityFrame_y +
		                                                          state.Hammer_Entity.entityFrame_h)
	{
		                                                          state.Hammer_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.Hammer_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.Hammer_Entity.entityFrame_x +
		                                                          state.Hammer_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.Hammer_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.Hammer_Entity.entityFrame_y +
		                                                          state.Hammer_Entity.entityFrame_h)
	{
		                                                          state.Hammer_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.CheckPoint_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.CheckPoint_Entity.entityFrame_x +
		                                                          state.CheckPoint_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.CheckPoint_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.CheckPoint_Entity.entityFrame_y +
		                                                          state.CheckPoint_Entity.entityFrame_h)
	{
		                                                          state.CheckPoint_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.CheckPoint_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.CheckPoint_Entity.entityFrame_x +
		                                                          state.CheckPoint_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.CheckPoint_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.CheckPoint_Entity.entityFrame_y +
		                                                          state.CheckPoint_Entity.entityFrame_h)
	{
		                                                          state.CheckPoint_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.GoalPoint_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.GoalPoint_Entity.entityFrame_x +
		                                                          state.GoalPoint_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.GoalPoint_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.GoalPoint_Entity.entityFrame_y +
		                                                          state.GoalPoint_Entity.entityFrame_h)
	{
		                                                          state.GoalPoint_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.GoalPoint_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.GoalPoint_Entity.entityFrame_x +
		                                                          state.GoalPoint_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.GoalPoint_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.GoalPoint_Entity.entityFrame_y +
		                                                          state.GoalPoint_Entity.entityFrame_h)
	{
		                                                          state.GoalPoint_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.GoalPointBar_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.GoalPointBar_Entity.entityFrame_x +
		                                                          state.GoalPointBar_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.GoalPointBar_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.GoalPointBar_Entity.entityFrame_y +
		                                                          state.GoalPointBar_Entity.entityFrame_h)
	{
		                                                          state.GoalPointBar_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.GoalPointBar_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.GoalPointBar_Entity.entityFrame_x +
		                                                          state.GoalPointBar_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.GoalPointBar_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.GoalPointBar_Entity.entityFrame_y +
		                                                          state.GoalPointBar_Entity.entityFrame_h)
	{
		                                                          state.GoalPointBar_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.FireWork_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.FireWork_Entity.entityFrame_x +
		                                                          state.FireWork_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.FireWork_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.FireWork_Entity.entityFrame_y +
		                                                          state.FireWork_Entity.entityFrame_h)
	{
		                                                          state.FireWork_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.FireWork_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.FireWork_Entity.entityFrame_x +
		                                                          state.FireWork_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.FireWork_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.FireWork_Entity.entityFrame_y +
		                                                          state.FireWork_Entity.entityFrame_h)
	{
		                                                          state.FireWork_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.Coin_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.Coin_Entity.entityFrame_x +
		                                                          state.Coin_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.Coin_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.Coin_Entity.entityFrame_y +
		                                                          state.Coin_Entity.entityFrame_h)
	{
		                                                          state.Coin_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.Coin_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.Coin_Entity.entityFrame_x +
		                                                          state.Coin_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.Coin_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.Coin_Entity.entityFrame_y +
		                                                          state.Coin_Entity.entityFrame_h)
	{
		                                                          state.Coin_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.QuestionBlock_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.QuestionBlock_Entity.entityFrame_x +
		                                                          state.QuestionBlock_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.QuestionBlock_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.QuestionBlock_Entity.entityFrame_y +
		                                                          state.QuestionBlock_Entity.entityFrame_h)
	{
		                                                          state.QuestionBlock_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.QuestionBlock_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.QuestionBlock_Entity.entityFrame_x +
		                                                          state.QuestionBlock_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.QuestionBlock_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.QuestionBlock_Entity.entityFrame_y +
		                                                          state.QuestionBlock_Entity.entityFrame_h)
	{
		                                                          state.QuestionBlock_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.BrickBlock_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.BrickBlock_Entity.entityFrame_x +
		                                                          state.BrickBlock_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.BrickBlock_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.BrickBlock_Entity.entityFrame_y +
		                                                          state.BrickBlock_Entity.entityFrame_h)
	{
		                                                          state.BrickBlock_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.BrickBlock_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.BrickBlock_Entity.entityFrame_x +
		                                                          state.BrickBlock_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.BrickBlock_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.BrickBlock_Entity.entityFrame_y +
		                                                          state.BrickBlock_Entity.entityFrame_h)
	{
		                                                          state.BrickBlock_Entity.entityLife = 0;
		//Colisiona
	}

	//--------------------------------------------------------------------------

	if (state.bullet.playerFrame_x + state.bullet.playerFrame_w < state.BossShot_Entity.entityFrame_x ||
		state.bullet.playerFrame_x >                              state.BossShot_Entity.entityFrame_x +
		                                                          state.BossShot_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h < state.BossShot_Entity.entityFrame_y ||
		state.bullet.playerFrame_y >                              state.BossShot_Entity.entityFrame_y +
		                                                          state.BossShot_Entity.entityFrame_h)
	{
		                                                          state.BossShot_Entity.entityLife = 1;
		//No colisiona
	}
	else if (state.bullet.playerFrame_x +
		state.bullet.playerFrame_w >
		                                                          state.BossShot_Entity.entityFrame_x ||
		state.bullet.playerFrame_x <                              state.BossShot_Entity.entityFrame_x +
		                                                          state.BossShot_Entity.entityFrame_w ||
		state.bullet.playerFrame_y + state.bullet.playerFrame_h > state.BossShot_Entity.entityFrame_y ||
		state.bullet.playerFrame_y <                              state.BossShot_Entity.entityFrame_y +
		                                                          state.BossShot_Entity.entityFrame_h)
	{
		                                                          state.BossShot_Entity.entityLife = 0;
		//Colisiona
	}
}