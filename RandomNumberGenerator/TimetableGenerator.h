#pragma once
#include "timetableScore.h"
#ifndef TIMETABLEGENERATOR_H
#define TIMETABLEGENERATOR_H

void attachTeacherToGroup();
void clearGlobals();
void SaveTimetable();
void LoadTimetable();
std::vector<timetableScore> optimiseTimetable(int generations, std::vector<timetableScore>& population, bool initalPopCheck, int populationSize, int elitismNum, int addtionalPop, int maxMutation);
void loadConfig();
#endif