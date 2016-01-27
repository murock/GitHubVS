#include "mylib.h"

std::vector<std::string> subjects;	//subject names
std::vector<int> hoursSubject;		//hours taught per subject
std::vector<std::string> groupNames; //class names
std::vector<std::vector<std::string>> teacherNames;	//teachers names with respect to subject
std::vector<std::vector<std::string>> roomNames; //room names with respect to subject
std::vector<std::vector<std::string>> subjectsTaken; //subjects taken with respect to class's(groupNames)
