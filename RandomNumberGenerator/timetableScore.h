#pragma once
#include <iostream>
#include <vector>
#include "Timetable.h"



#ifndef TIMETABLESCORE_H
#define TIMETABLESCORE_H

class timetableScore {
public:
	timetableScore();		// Default Constructor

	timetableScore(int, std::vector<Timetable>);	//Overload Constructor

	~timetableScore();		//Destructor

	int getScore() const;
	std::vector<Timetable> getTimetable() const;

	void setScore(int a);
	void setTimetable(std::vector<Timetable> b);
	


private:		//can't be accessed by outside files, can't be changed elsewhere
	int newScore;
	std::vector<Timetable> newTimetable;
};

#endif 