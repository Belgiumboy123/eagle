/*
 *  ImageLoader.h
 *  Eagle2
 *
 *  Created by Brecht Moulin on 8/14/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <map>
#include <vector>

namespace Graphics{

	/**
	 * Load up the player image
	 *
	 * Could move this into general image loader
	 */
	void LoadPlayerImg(unsigned int& imageID);

	/**
	 * Load all images where file in imagefiles corresponds to index of map
	 */
	bool LoadImages(const std::vector<std::string>& imagefiles, std::vector<unsigned int>& images);
	
	/**
	 * Render given texture with given coords, and given image partition
	 */
	void RenderActor(
					   const unsigned int& texID, 
					   const float& texPosx, 
					   const float& texPosy,
					   const float& texSizex,
					   const float& texSizey,
					   const int& xpos, 
					   const int& ypos, 
					   const int& w,
					   const int& h);
	
	/** Render circle */
	void RenderCircle( const float& x, const float& y, const float& r );
	
	void StartDrawing();
	void EndDrawing();
}

#endif
