/*
 *  Logger.h
 *  Eagle2
 *
 *  Created by Brecht Moulin on 8/14/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger {
public:
    static Logger* getLog();
	void destroy();
    void Log(std::string message);
	void clean();
	~Logger();
private:
    static Logger* pInstance;
	std::ofstream out;
	Logger();
};	


/**
 * Usage:
 *
 * Logger* myLogger = getLog();
 * myLogger->Log("my message ");
 *
 */

#endif
