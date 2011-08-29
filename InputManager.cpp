/*
 *  InputManager.cpp
 *  Eagle2
 *
 *  Created by Brecht Moulin on 8/15/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "InputManager.h"
#include "SDL_events.h"
#include <iostream>
using std::cout;
using std::endl;

const int InputManager::NUM_KEYS = 333;

InputManager::InputManager(){

	m_paKeysUp = new bool[NUM_KEYS];
	m_paKeysDown = new bool[NUM_KEYS];
	
	for( int i = 0; i<NUM_KEYS; ++i){
		
		m_paKeysUp[i] = false;
		m_paKeysDown[i] = false;
	}
}

InputManager::~InputManager(){

	if(m_paKeysUp) delete m_paKeysUp;
	if(m_paKeysDown) delete m_paKeysDown;
}

std::pair<const bool*,const bool*> InputManager::GetInput(){
	
	//Capture and save all key releases and presses
	SDL_Event event;
	while (SDL_PollEvent(&event)){ 
		switch (event.type){
			case SDL_KEYUP: //key release
				m_paKeysUp[event.key.keysym.sym] = true;
				m_paKeysDown[event.key.keysym.sym] = false;
				
				//cout << "key release " << event.key.keysym.sym << endl;
				break;
				
			case SDL_KEYDOWN: //key press
				m_paKeysDown[event.key.keysym.sym] = true;
				m_paKeysUp[event.key.keysym.sym] = false;
				
				//cout << "key press " << event.key.keysym.sym << endl;
				break;
		} //end of event type switch
	}// end of while
	
	//return current keys
	return std::make_pair( m_paKeysUp, m_paKeysDown);
}

/**
 * reset all released keys back to false
 */
void InputManager::ClearInput(){

	for( int i = 0; i<NUM_KEYS; ++i){
	
		m_paKeysUp[i] = false;
	}
}