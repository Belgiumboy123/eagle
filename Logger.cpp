/*
 *  Logger.cpp
 *  Eagle2
 *
 *  Created by Brecht Moulin on 8/14/11.
 *
 */

#include "Logger.h"
#include <iostream>
using std::ofstream;
using std::string;

Logger* Logger::pInstance = NULL;

Logger* Logger::getLog(){
	
	if(pInstance == NULL){
		pInstance = new Logger();
	}
	return pInstance;
}

Logger::Logger(){ 
	
	 out.open("/Library/Application Support/Run Log/log.txt");
}

/**
 * Create time stamp and print message to file
 */
void Logger::Log( string msg ){

	out <<msg << std::endl;
}

void Logger::destroy(){

	std::cout << "Logger::destroy called" << std::endl;
	if( pInstance ) 
		delete pInstance;
	if( out.is_open() )
		out.close();	
}

Logger::~Logger(){
	std::cout << "Logger deconstructor called" << std::endl;
}
