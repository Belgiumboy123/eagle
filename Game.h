/*
 *  Game.h
 *  Eagle2
 *
 *  Created by Brecht Moulin on 8/14/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#ifndef GAME_H
#define GAME_H

#include <vector>
//#include <map>
#include <string>

class Actor;
class InputManager;

class Game{

public:	
	Game();
	virtual void init();
	virtual void handleInput();
	virtual void doGameStep() =0;
	virtual void setupLevel() =0;
	virtual void doRenderScene();
	void startGameLoop();
	
	virtual ~Game();
	
protected:
	
	//Actors
	Actor* player;
	std::vector<Actor*> Actors;
	
	//image info containters
	std::vector<unsigned int> images;
	std::vector<std::string> imagefiles;
	
	//Input
	InputManager* im;
	
	//variables needed for game loop
	bool running;
};

#endif