#include "mylib.h"
#include <time.h>
#include "TimetableGenerator.h"



void Generate(){
	int groupCount = 0;
	int totalHours = 25;		//total hours taught each week 
	int periodCount = 0;		//stores current period number being allocated
	srand(time(0));				//seed random number based on time

	std::vector<std::vector<int>> hoursPerSubjectGroup; // stores the current number of hours each group has for each subject

	// fills the hoursPerSubjectGroup Vector so it is the correct size for the current timetable arrangement
	std::vector<std::string>::const_iterator iter, iter2;
	for (iter = groupNames.begin(); iter != groupNames.end(); ++iter) {		//iterates through the groupNames vector
		std::vector<int> temp;
		for (iter2 = subjects.begin(); iter2 != subjects.end(); ++iter2) {	//iterate through subjects vector
			temp.push_back(0);
		}
		hoursPerSubjectGroup.push_back(temp);
	}

	while (groupCount < groupNames.size()) {		// while there are still remaining groups without a timetable
		std::vector<std::string> tempPeriods;	//stores subject periods for groups
		while (periodCount < totalHours) {		//while there are still unallocated periods
			std::vector<std::string> currentTeachers;	//store the teachers who are teaching this period already
			int Rnum = rand();
			int num = (Rnum % subjects.size());		//get a random number between  0 and the total number of (subjects-1)  tick
			//_RPT1(0, "The test variable is %d\n", num);
			std::vector<std::string> subjectsTakenByCurrentGroup = subjectsTaken[groupCount]; //gets the subjects taken by the current group   tick
			if (std::find(subjectsTakenByCurrentGroup.begin(), subjectsTakenByCurrentGroup.end(), subjects[num]) !=subjectsTakenByCurrentGroup.end()) {			//check to make sure the current subject is taken by the current group
				std::vector<int> tempHoursPerSubjectGroup = hoursPerSubjectGroup[groupCount];
				if (hoursSubject[num] <= tempHoursPerSubjectGroup[num]) { //if max number of hours for that subject for that class is not met 
					std::vector<std::string> tempTeachers = teacherNames[num];		//get all the teachers for the current subject
					int num2 = (Rnum % tempTeachers.size());	// get a random number between 0 and total number of teachers for the current subject
					std::vector<std::string>::iterator it = std::find(currentTeachers.begin(), currentTeachers.end(), tempTeachers[num2]); // returns currentTeachers.end() if the teacher is avaliable
					while (it != currentTeachers.end()) {		//check to see if the randomly selected teacher is avaliable 
						int Rnum2 = rand();
						num2 = (Rnum2 % tempTeachers.size());	// get a random number between 0 and total number of teachers for the current subject
						it = std::find(currentTeachers.begin(), currentTeachers.end(), tempTeachers[num2]);
						periodCount = 26;
						groupCount = 5;
					}
				}
			}

		}
	}
}

void DefaultValues() {
	 subjects = { "Maths", "English", "French","Geography","PE","I.C.T","Economics","Science","History","Art" };	//subject names

	 /*			std::vector<std::string>::const_iterator itertest;

			for (itertest = subjectsTakenByCurrentGroup.begin(); itertest != subjectsTakenByCurrentGroup.end(); ++itertest) {		//iterates through the subjects vector

			std::string str = *itertest;
			_RPT1(0, "The test variable is %s\n", str.c_str());  //prints to output

			}

	 }*/
	 hoursSubject = {6,6,4,4,2,5,4,6,4,3};		//hours taught per subject

     groupNames = {"7A","7B","8A","8B"}; //class names

	 std::vector<std::string> temp = { "Mr Maths1","Miss Maths2", "Dr Maths3" }, temp2 = { "M1","M2","M3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr English1","Miss English2", "Dr English3" };
	 temp2 = {"E1,E2,E3"};
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr French1","Miss French2", "Dr French3" };
	 temp2 = { "F1,F2,F3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr Geography1","Miss Geography2", "Dr Geography3" };
	 temp2 = { "G1,G2,G3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr PE1","Miss PE2", "Dr PE3" };
	 temp2 = { "P1,P2,P3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr ICT1","Miss ICT2", "Dr ICT3" };
	 temp2 = { "I1,I2,I3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr Eco1","Miss Eco2", "Dr Eco3" };
	 temp2 = { "Ec1,Ec2,Ec3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr Sci1","Miss Sci2", "Dr Sci" };
	 temp2 = { "S1,S2,S3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr Hist1","Miss Hist2", "Dr Hist3" };
	 temp2 = { "H1,H2,H3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr Art1","Miss Art2", "Dr Art3" };
	 temp2 = { "A1,A2,A3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);

	 temp = {"Maths","English","Economics","PE"};
	 subjectsTaken.push_back(temp);
	 temp = {"Science","English","History","French"};
	 subjectsTaken.push_back(temp);
	 temp = { "Geography","Maths","History","Art" };
	 subjectsTaken.push_back(temp);
	 temp = { "French","Science","History","PE" };
	 subjectsTaken.push_back(temp);
}