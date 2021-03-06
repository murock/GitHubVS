#pragma once
#include <iostream>
#include <string>
#include <vector>



#ifndef TIMETABLE_H
#define TIMETABLE_H

class Timetable {
public:
	Timetable();		// Default Constructor

	Timetable(std::string, std::vector<std::string>);	//Overload Constructor

	~Timetable();		//Destructor

	std::string getGroup() const;
	std::vector<std::string> getPeriods() const;


	void setGroup(std::string g);
	void setPeriods(std::vector<std::string> p);




private:		//can't be accessed by outside files, can't be changed elsewhere
	std::string newGroup;
	std::vector<std::string> newPeriods;
	int newScore;
};

#endif 