/*
 *  Actor.cpp
 *  Eagle2
 *
 *  Created by Brecht Moulin on 8/14/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Actor.h"

using std::endl;

ImageType::ImageType(){
	
	w_T=0;
	h_T=0;
	cols=0;
	rows=0;
	w=0.0f;
	h=0.0f;
	per_w = 0.0f;
	per_h = 0.0f;
}

ImageType::ImageType( int _w_T, int _h_T, int _rows, int _cols): 

	w_T( _w_T ),
	h_T( _h_T ),
	rows( _rows),
	cols( _cols ),
	w( (float)w_T / cols ),
	h( (float)h_T / rows ),
	per_w( 1.0f/cols ),
	per_h( 1.0f/rows)
{}

Actor::Actor(){

	imageID = 0;
	pos_x =0; // x pixel position on screen
	pos_y =0; // y pixel position on screen
	direction =0.0f; // which way char is facing [0-3] toward, left, right, away   
	position =0.0f; //  which motion in step  [0-2]
	sword = -1;  //-1 no sword
	attacking = false;
	shield = false; 
}

ostream &operator<<(ostream &stream, ImageType imageType){
	
	stream << "w_T: " << imageType.w_T << ", " << "h_T: " <<  imageType.h_T <<", " << "rows: " << imageType.rows << ", "  << endl;
	stream << "cols: " << imageType.cols << ", " <<  "w: " << imageType.w << ", " << "h: " <<imageType.h << endl;
	return stream;
}
ostream &operator<<(ostream &stream, Actor actor){

	stream << "pos_x: " << actor.pos_x << ", pos_y: " << actor.pos_y << ", direction: " << actor.direction << ", position: ";
	stream << actor.position << ", sword: " << actor.sword << ", shield: " << actor.shield << endl;
	stream << actor.imageType;
	return stream;
}

