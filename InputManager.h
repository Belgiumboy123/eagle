/*
 *  InputManager.h
 *  Eagle2
 *
 *  Created by Brecht Moulin on 8/15/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <utility>

class InputManager{

public:
	InputManager();
	~InputManager();
	
	std::pair<const bool*,const bool*> GetInput();
	void ClearInput();
	
	static const int NUM_KEYS;
	
private:	
	
	bool* m_paKeysUp;
	bool* m_paKeysDown;

};