/*
 *  Actor.h
 *  Eagle2
 *
 *  Created by Brecht Moulin on 8/14/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
using std::ostream;


struct ImageType{
	int w_T; //width of spritesheet
	int h_T; //height of spritesheet
	int rows; //# of rows in spritesheet
	int cols; //# of cols in spritesheet
	float w; //width of individual sprite
	float h; //height of individual sprite
	float per_w; //percentage width individual sprite vs spritesheet
	float per_h; //percentage width individual height vs spritesheet
	ImageType();
	ImageType( int _w_T, int _h_T, int _rows, int _cols);
};

/** Constant ImageType instances */
const ImageType Standard( 128,128,4,3);


/**
 * Holds all graphical variables needed to so it can rendered on screen
 *
 */
struct Actor{

	unsigned int imageID;
	int pos_x;
	int pos_y;
	float direction;
	float position;
	int sword;
	bool shield;
	ImageType imageType;
	Actor();
};

ostream &operator<<(ostream &stream, ImageType imageType);
ostream &operator<<(ostream &stream, Actor actor);

#endif