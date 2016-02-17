#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>
#include "Timetable.h"
//#include <algorithm>    // std::find
#ifndef MYLIB_H
#define MYLIB_H
extern std::vector<std::string> subjects;
extern std::vector<int> hoursSubject;
extern std::vector<std::string> groupNames; //class names
extern std::vector<std::vector<std::string>> teacherNames;	//teachers names with respect to subject
extern std::vector<std::vector<std::string>> roomNames; //room names with respect to subject
extern std::vector<std::vector<std::string>> subjectsTaken; //subjects taken with respect to class's(groupNames)
extern std::vector<std::vector<std::string>> attachedTeachers; //store the groups with there attached teacher for each subject so every other position is a subject then the teacher
extern std::vector<Timetable> Timetables;	//stores the timetables for each group
#endif
