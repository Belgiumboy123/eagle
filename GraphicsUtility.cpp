/*
 *  ImageLoader.cpp
 *  Eagle2
 *
 *  Created by Brecht Moulin on 8/14/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "GraphicsUtility.h"
#include "SDL_image.h"
#include "SDL_opengl.h"
#include <string>
#include <iostream>
#include <math.h>

using std::map;
using std::string;
using std::vector;
using std::endl;
using std::cout;

//anonymous namespace, functions for this file only
namespace {
	
	/**
	 * Load image from given file into given texture id
	 */
	void loadImage( const string& imageFile, GLuint& textureID ){
		
		SDL_Surface *surface = 0;
		
		if ( (surface = IMG_Load(imageFile.c_str())) ) 
		{ 
			glGenTextures( 1, &textureID );
			glBindTexture( GL_TEXTURE_2D, textureID );
			
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
			glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA8, surface->w, surface->h, 0, GL_BGRA, GL_UNSIGNED_BYTE,
						  surface->pixels);
		}
		
		if( surface )
			SDL_FreeSurface( surface);
	}	
	
	
	//////////////////////
	//image paths
	//
	//Make relative part of app package
	/////////////////////
	
	const string playerImage = "/Users/bmoulin/Desktop/image3.tga";

  const GLfloat player_shield[4] = {0.4f, 1.0f, 0.2f, 0.25f};
  const int sections = 20;
  const float twoPi = 2*3.14159265;
}

void Graphics::LoadPlayerImg(unsigned int& imageID){
	
	loadImage( playerImage, imageID);
}

bool Graphics::LoadImages(const vector<string>& imagefiles, vector<unsigned int>& images){

	images.clear();
	images.resize( imagefiles.size() );
	cout << imagefiles.size() << endl;
	vector<unsigned int>::iterator it = images.begin();
	vector<string>::const_iterator it2 = imagefiles.begin();
	
	for( ; it != images.end() && it2 != imagefiles.end(); ++it,++it2 ){
		
		loadImage( *it2, *it );
	}
	std::cout << "LoadImages successful" << std::endl;
	return true;
}

/**
 * xpos and ypos are lower left corner. pixel position on screen
 */
void Graphics::RenderActor(
							 const unsigned int& texID, 
							 const float& texPosx, 
							 const float& texPosy,
							 const float& texSizex,
							 const float& texSizey,
							 const int& xpos, 
							 const int& ypos, 
							 const int& w,
							 const int& h)
{	
	glPushMatrix();
	
	glEnable (GL_TEXTURE_2D);
          	
	//set up transparency
	glEnable( GL_BLEND );
	glDisable(GL_DEPTH_TEST);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0f,1.0f,1.0f,0.0f);
	
	glBindTexture( GL_TEXTURE_2D, texID );
   	
	glBegin (GL_QUADS);
	glTexCoord2f (texPosx, texPosy);					
	glVertex2i (xpos,ypos);
	glTexCoord2f (texPosx+texSizex, texPosy);		
	glVertex2i (xpos+w,ypos);
	glTexCoord2f (texPosx+texSizex, texPosy+texSizey);  
	glVertex2i (xpos+w,ypos+h);
	glTexCoord2f (texPosx, texPosy+texSizey);	
	glVertex2i (xpos,ypos+h);
	glEnd ();
	
	glDisable(GL_BLEND);
	glDisable( GL_TEXTURE_2D );
	glPopMatrix();
}


void Graphics::RenderCircle( const float& x, const float& y, const float& r){
  
	glPushMatrix();
	glTranslatef( x, y, 0 );	
	glEnable( GL_BLEND );
	
	glBegin( GL_TRIANGLE_FAN );
	glColor4fv( player_shield );
	glVertex2f( 0, 0 );
	for( int i = 0; i<= sections;i++){
		glVertex2f( r * cos(i* twoPi / sections), r* sin( i*twoPi/sections));
	}
	glEnd();
	glDisable(GL_BLEND);
	glPopMatrix();
}

void Graphics::StartDrawing(){
	
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Graphics::EndDrawing(){

	SDL_GL_SwapBuffers();
}