/*
 *  Eagle.cpp
 *  Eagle2
 *
 *  Created by Brecht Moulin on 8/14/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Eagle.h"
#include "Actor.h"
#include "GraphicsUtility.h"
#include "InputManager.h"
#include <iostream>
#include "SDL_keysym.h"
#include <utility>
#include "Eagle_Constants.h"

using std::cout;
using std::endl;

namespace{
	
	const int dHor = 2;
	const int dVer = 1;
	
	const int UP = SDLK_w;
	const int DOWN = SDLK_s;
	const int RIGHT = SDLK_d;
	const int LEFT = SDLK_a;
	const int SHIELD = SDLK_i;
	const int ATTACK = SDLK_j;
	
	
}

Eagle::Eagle(): Game() {}


Eagle::~Eagle(){}

void Eagle::doGameStep(){}

void Eagle::setupLevel(){

	velX = 0;
	velY = 0;
	
	player->position = 1;
	player->direction = 3;
	player->pos_x = 400;
	player->pos_y = 200;
	player->imageType = &Standard;
	player->sword = 0;
	player->shield = false;
	player->attacking = false;
	//std::cout << *player;
	Actors.push_back( player );
}

void Eagle::handleInput(){

	//get input
	std::pair<const bool*, const bool*> input = im->GetInput();
	const bool* keysUp = input.first;
	const bool* keysDown = input.second;
	
	//handle input
	if( keysUp[SDLK_ESCAPE] ){
	
		cout << "escape pressed" << endl;
		running = false;
		return;
	}
	
	//RELEASED
	
	if( keysUp[UP] ){ //UP
	
		velY =0;
	}
	
	if( keysUp[DOWN]){ //DOWN
	
		velY =0;
	}
	
	if( keysUp[LEFT]){ //LEFT
		
		velX =0;
	}
	
	if( keysUp[RIGHT]){ //RIGHT
		
		velX =0;
	}
	
	if( keysUp[SHIELD]){
	
		player->shield = false;
	}
	
	///// PRESSED
	
	if( keysDown[UP] ){ //UP
		
		velY = -dVer;
	}
	
	if( keysDown[DOWN]){ //DOWN
		
		velY = dVer;
	}
	
	if( keysDown[LEFT]){ //LEFT
		
		velX = -dHor;
	}
	
	if( keysDown[RIGHT]){ //RIGHT
		
		velX = dHor;
	}
	
	if( keysDown[SHIELD]){
	
		player->shield = true;
	}
	
	if( velX == 0 && velY == 0 )
		player->position = 1;
	else{
		(int)++player->position%3;
	}
	
	if( !player->attacking ){//dont change direction when player is attacking
		if (velX > 0) player->direction = 2; //right
		if (velX < 0) player->direction = 1; //left
		if (velY > 0) player->direction = 0; //up
		if (velY < 0) player->direction = 3; //down
	}
	
	player->pos_x += velX;
	player->pos_y += velY;
	
	//cout << "New Position " << endl;
	//cout << velX << " " << velY << endl;
	//cout << player->pos_x << " " << player->pos_y << endl << endl;
	
	//clear input for next game loop iteration
	im->ClearInput();
}






