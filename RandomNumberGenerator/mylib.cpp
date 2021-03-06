#include "mylib.h"


std::vector<std::string> subjects;	//subject names
std::vector<int> hoursSubject;		//hours taught per subject
std::vector<std::string> groupNames; //class names
std::vector<int> groupSizes; //Number of students per class
std::vector<std::vector<std::string>> teacherNames;	//teachers names with respect to subject
std::vector<std::vector<int>>teacherHours;	//hours taught for each teacher with respect to subject and teacherNames 
std::vector<std::vector<std::string>> roomNames; //room names with respect to subject
std::vector<std::vector<int>> roomCapacitys;	//room capacitys with respect to subject
std::vector<std::vector<std::string>> subjectsTaken; //subjects taken with respect to class's(groupNames)
std::vector<std::vector<std::string>> attachedTeachers; //store the groups with there attached teacher for each subject so every other position is a subject then the teacher so subjects are even teachers are odd
std::vector<Timetable> timetables;	//stores the timetables for each group
std::vector<std::vector<int>> teacherPreference;	//if 0 then pref morning if 1 then pref afternoon NEED TO IMPLEMENT ON GUI
std::vector<int> TESTselectionNumCount;
std::vector<timetableScore> populationGlobal;

