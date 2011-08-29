/*
 *  Eagle.h
 *  Eagle2
 *
 *  Created by Brecht Moulin on 8/14/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Game.h"

class Eagle : public Game{

private:
	
	int velX;
	int velY;
	
public:
	
	Eagle();
	~Eagle();
	void doGameStep();
	void setupLevel();
	void handleInput();
};