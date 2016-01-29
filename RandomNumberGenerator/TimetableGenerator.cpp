#include "mylib.h"
#include <time.h>

/*extern std::vector<std::string> subjects;
extern std::vector<int> hoursSubject;
extern std::vector<std::string> groupNames; //class names
extern std::vector<std::vector<std::string>> teacherNames;	//teachers names with respect to subject
extern std::vector<std::vector<std::string>> roomNames; //room names with respect to subject
extern std::vector<std::vector<std::string>> subjectsTaken; //subjects taken with respect to class's(groupNames)
std::vector<std::vector<std::string>> timetables; //stores the timetables for each class*/

void Generate(){
	int groupCount = 0;
	int totalHours = 25;		//total hours taught each week 
	int periodCount = 0;		//stores current period number being allocated
	srand(time(0));				//seed random number based on time

	while (groupCount < groupNames.size()) {		// while there are still remaining groups without a timetable
		std::vector<std::string> tempPeriods;	//stores subject periods for groups
		while (periodCount < totalHours) {		//while there are still unallocated periods
			int Rnum = rand();
			/*std::vector<std::string> temp = subjectsTaken[groupCount] could use this to get size, may have to check the below code gives the size of the vector within the vector */
			int num = (Rnum % subjectsTaken[groupCount].size());		//get a random number between  0 and the number of subjects that group takes
			if ()

		}
	}
}