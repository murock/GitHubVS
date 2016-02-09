#include "mylib.h"


std::vector<std::string> subjects;	//subject names
std::vector<int> hoursSubject;		//hours taught per subject
std::vector<std::string> groupNames; //class names
std::vector<std::vector<std::string>> teacherNames;	//teachers names with respect to subject
std::vector<std::vector<std::string>> roomNames; //room names with respect to subject
std::vector<std::vector<std::string>> subjectsTaken; //subjects taken with respect to class's(groupNames)
std::vector<std::vector<std::string>> attachedTeachers; //store the groups with there attached teacher for each subject so every other position is a subject then the teacher so subjects are even teachers are odd
std::vector<Timetable> Timetables;	//stores the timetables for each group

