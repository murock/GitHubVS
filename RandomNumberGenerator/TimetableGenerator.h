#pragma once
#ifndef TIMETABLEGENERATOR_H
#define TIMETABLEGENERATOR_H

void Generate();
void DefaultValues();
void AttachTeachertoGroup();
bool checkTimetable();
void ScoreTimetable();
void ClearGlobals();
void SaveTimetable(std::string name);
void LoadTimetable();
void SaveTeachers();
#endif