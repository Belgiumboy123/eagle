#include <iostream>
#include "Logger.h"

#include "SDL.h"
#include "SDL_opengl.h"
#include "SDL_image.h"
#include "Eagle.h"

using namespace std;

void deleteImages(){

	//glDeleteTextures( 1, &guy );
}

void glInit(const int& w, const int& h){

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,640,480,0, -1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLoadIdentity();
}

Uint32 timer_callback(Uint32 interval, void *param);


void CleanUp(){

	Logger* myLog = Logger::getLog();
	myLog->destroy();
	SDL_Quit();
}

int main(int argc, char *argv[]){
	
	if( (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)) < 0 ){
		
		cout << "Unable to init SDL" << endl;
		exit(0);
	}
	atexit(CleanUp);
	
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	
	SDL_Surface* screen = SDL_SetVideoMode( 1000, 600, 0, SDL_OPENGL   );
	
	if( screen == NULL ){
		
		cout << "Couldn't create screen" << endl;
		exit(0);
	}
	
	glInit(screen->w,screen->h);
	cout << "Finished with sdl / opengl init" << endl;
	
	Game* game = new Eagle();
	game->startGameLoop();
	
	delete game;
	return 0;
}
