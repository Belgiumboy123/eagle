/*
 *  Game.cpp
 *  Eagle2
 *
 *  Created by Brecht Moulin on 8/14/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Game.h"
#include "Actor.h"
#include "GraphicsUtility.h"
#include "InputManager.h"
#include "SDL_timer.h"
#include <iostream>

using std::vector;
using std::string;
using std::map;
using std::cout;
using std::endl;

namespace{
	//game loop constants
	const int TICKS_PER_SECOND = 25;
    const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
    const int MAX_FRAMESKIP = 5;
	
	const int sword1 = 0;
	const int sword2 = 1;
}


Game::Game(): running(false),player(0) {

	imagefiles.push_back( "/Users/bmoulin/Desktop/sword.tga" );
	imagefiles.push_back( "/Users/bmoulin/Desktop/sword2.tga");
	
	init();
}

void Game::init(){

	player = new Actor();
	Graphics::LoadPlayerImg( player->imageID );
	Graphics::LoadImages(imagefiles, images);
	im = new InputManager();
	
	std::cout << "Game Initialization complete" << std::endl;
}

void Game::handleInput(){}

void Game::doRenderScene(){
	
	Graphics::StartDrawing();
	
	vector<Actor*>::iterator it = Actors.begin();
	for( ; it != Actors.end(); ++it){
		
		const Actor& actor = **it;
		
		if( actor.shield ){ //actor has shield on
			
			int x = actor.pos_x +actor.imageType->w/2;
			int y = actor.pos_y + actor.imageType->h/2;
			int r = actor.imageType->w/2;
			
			Graphics::RenderCircle( x,y,r);
		}
		
		if( (int)actor.position%2 == 1 ){
			
			DrawWeapon(actor);
		}
		
		Graphics::RenderActor
		(
			actor.imageID,
			actor.position/actor.imageType->cols,
			actor.direction/actor.imageType->rows,
			actor.imageType->per_w,
			actor.imageType->per_h,
			actor.pos_x,
			actor.pos_y,
			actor.imageType->w,
			actor.imageType->h
		);
		
		if( (int)actor.position%2 == 0){
				
			DrawWeapon( actor );
		}
	}
	
	Graphics::EndDrawing();
}

void Game::DrawWeapon(const Actor& actor){

	if( actor.attacking ){
		
	}else{
		cout << "drawing sword" << endl;
		Graphics::RenderObject(images[actor.sword],actor.pos_x,actor.pos_y,actor.imageType->w/4,actor.imageType->h/3);	
	}
	
}

void Game::startGameLoop(){
	
	setupLevel();
	
	running = true;
	int loops = 0;
	double interpolation;
	long next_game_tick = SDL_GetTicks();
	while (running){
		
		loops =0;
		while(SDL_GetTicks() > next_game_tick && loops < MAX_FRAMESKIP){
			
			handleInput();
			doGameStep();
			++loops;
			next_game_tick += SKIP_TICKS;
		}
		
		interpolation = (double)(SDL_GetTicks() + SKIP_TICKS - next_game_tick)/SKIP_TICKS;
		doRenderScene();
	} 
}

Game::~Game(){

	if( player ) delete player;
	if( im ) delete im;
	std::cout << "Game deconstructor" << std::endl; 
}
