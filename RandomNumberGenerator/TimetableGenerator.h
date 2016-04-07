#pragma once
#include "timetableScore.h"
#ifndef TIMETABLEGENERATOR_H
#define TIMETABLEGENERATOR_H

void Generate();
void DefaultValues();
void AttachTeachertoGroup();
bool checkTimetable();
int ScoreTimetable(std::vector<Timetable>& currentTimetables);
void ClearGlobals();
void SaveTimetable1(std::string name);
void SaveTimetable();
void LoadTimetable();
void SaveTeachers();
std::vector<Timetable> GenerateV2();
int checkTimetableV2(std::vector<Timetable>& currentTimetables);
std::vector<timetableScore> optimiseTimetable(int maxIterations, std::vector<timetableScore>& population, bool initalPopCheck, int populationSize, int elitismNum, int addtionalPop, int maxMutation);
void testSelector();
void LoadConfig();
#endif