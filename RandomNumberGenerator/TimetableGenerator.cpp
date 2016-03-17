#include "mylib.h"
#include <time.h>
#include "TimetableGenerator.h"
#include <random>

void ClearGlobals() {
	subjects.clear();
	hoursSubject.clear();
	groupNames.clear();
	teacherNames.clear();
	roomNames.clear();
	subjectsTaken.clear();
	attachedTeachers.clear();
	Timetables.clear();
}
/*
void AttachTeachertoGroup() {
	srand(time(0));

	for (int groupCount = 0; groupCount < groupNames.size(); groupCount++) {
		std::vector<std::string> subjectsTakenByCurrentGroup = subjectsTaken[groupCount]; //gets the subjects taken by the current group
		std::vector<std::string> teachersForGroup;
		for (int subjectCount = 0; subjectCount < subjectsTakenByCurrentGroup.size(); subjectCount++) {

			std::vector<std::string>::iterator it;
			it = find(subjects.begin(), subjects.end(), subjectsTakenByCurrentGroup[subjectCount]);
			int position = std::distance(subjects.begin(), it);

			std::vector<std::string> tempTeachers = teacherNames[position];		//get all the teachers for the current subject tick
			int Rnum = rand();														//generate random No
			int teacherNum = (Rnum % tempTeachers.size());							//random number between 0 and number of teachers for current subject
			teachersForGroup.push_back(subjectsTakenByCurrentGroup[subjectCount]);	//put the subject taken by current group into this groups vector
			teachersForGroup.push_back(tempTeachers[teacherNum]);					//put a random teacher who teachers the subject into the teachers for this groups vector
			std::string str = groupNames[groupCount], str2 = tempTeachers[teacherNum], str3 = subjectsTakenByCurrentGroup[subjectCount];
			_RPT1(0, "Group %s will be taught by %s for %s\n", str.c_str(),str2.c_str(),str3.c_str());  //prints to output

		}
		attachedTeachers.push_back(teachersForGroup);				//put in all the teachers assigned to that group into the attached teachers vector
	}

}*/

void AttachTeachertoGroup() {
	srand(time(0));
	std::vector<std::vector<int>>currentTeacherHours;
	//make the currentTeacherHours vector the correct size and initialise it with 0's
	for (int i = 0; i < subjects.size(); i++) {		//iterates through the subjects vector
		std::vector<int> temp;
		std::vector<std::string> currentSubjectTeachernames = teacherNames[i];
		for (int j = 0; j < currentSubjectTeachernames.size(); j++) {	//iterate through current teacher names vector
			temp.push_back(0);
		}
		currentTeacherHours.push_back(temp);
	}
	for (int groupCount = 0; groupCount < groupNames.size(); groupCount++) {
		std::vector<std::string> subjectsTakenByCurrentGroup = subjectsTaken[groupCount]; //gets the subjects taken by the current group
		std::vector<std::string> teachersForGroup;
		for (int subjectCount = 0; subjectCount < subjectsTakenByCurrentGroup.size(); subjectCount++) {
			std::vector<std::string>::iterator it;
			it = find(subjects.begin(), subjects.end(), subjectsTakenByCurrentGroup[subjectCount]);
			int position = std::distance(subjects.begin(), it);
			std::vector<std::string> tempTeachers = teacherNames[position];		//get all the teachers for the current subject 
			std::vector<int> tempHours = currentTeacherHours[position];			//get the current hours being taught by teacher
			std::vector<int> tempTeacherHours = teacherHours[position];			//get the maximum hours that can be taught by the subject teachers
			int Rnum = rand();														//generate random No
			int teacherNum = (Rnum % tempTeachers.size());							//random number between 0 and number of teachers for current subject
			tempHours[teacherNum] = tempHours[teacherNum] + hoursSubject[position];	//add the chosen subjects teacher hours to the tempHours being taught by the teacher
		//	_RPT1(0, "tempHours is %d tempteacherHours is %d\n", tempHours[teacherNum],tempTeacherHours[teacherNum]);  //prints to output
			while (tempHours[teacherNum] > tempTeacherHours[teacherNum]){			
				tempHours[teacherNum] = tempHours[teacherNum] - hoursSubject[position];	//subtract the chosen subjects teacher hours from the tempHours being taught by the teacher
				Rnum = rand();
				teacherNum = (Rnum % tempTeachers.size());	//get another teacher
				tempHours[teacherNum] = tempHours[teacherNum] + hoursSubject[position];
			}
			currentTeacherHours[position] = tempHours;
			teachersForGroup.push_back(subjectsTakenByCurrentGroup[subjectCount]);	//put the subject taken by current group into this groups vector
			teachersForGroup.push_back(tempTeachers[teacherNum]);					//put a random teacher who teachers the subject into the teachers for this groups vector
			std::string str = groupNames[groupCount], str2 = tempTeachers[teacherNum], str3 = subjectsTakenByCurrentGroup[subjectCount];
			_RPT1(0, "Group %s will be taught by %s for %s\n", str.c_str(), str2.c_str(), str3.c_str());  //prints to output
		}
		attachedTeachers.push_back(teachersForGroup);				//put in all the teachers assigned to that group into the attached teachers vector
	}
}


std::vector<std::string> AssignTimetable(int periodCount,std::vector<std::vector<std::string>> periodsArray, int groupCount, int subjectNum, std::vector<std::string> currentGroupsTeachers, int teacherPosition, std::vector<std::string> tempRoomNames, int roomNum) {

	std::vector<std::string> periods = periodsArray[groupCount];	//create periods vector from the periods array
	if (currentGroupsTeachers[teacherPosition] == "FreeTeacher") {
		periods.push_back("Free");		//save the free subject to the periods vector
		_RPT1(0, "Period: %d Group: %s Subject: %s Teacher: %s Room: %s\n", periodCount, groupNames[groupCount].c_str(), "Free", currentGroupsTeachers[teacherPosition].c_str(), tempRoomNames[roomNum].c_str());  //prints to output
	}
	else {
		periods.push_back(subjects[subjectNum]);		//save the subject to the periods vector
		_RPT1(0, "Period: %d Group: %s Subject: %s Teacher: %s Room: %s\n", periodCount, groupNames[groupCount].c_str(), subjects[subjectNum].c_str(), currentGroupsTeachers[teacherPosition].c_str(), tempRoomNames[roomNum].c_str());  //prints to output
	}
	periods.push_back(currentGroupsTeachers[teacherPosition]);	//save the teacher to the periods vector
	periods.push_back(tempRoomNames[roomNum]);		//save the room number to periods vector
	Timetable tempTimetable(groupNames[groupCount], periods);									
	Timetables[groupCount] = tempTimetable;
	return periods;
}


int checkMaxHoursReached(std::vector<int> tempHoursPerSubjectGroup, int groupCount, std::vector<std::string> currentTeachers) {	//check if the max hours have been reached for every subject for this group
	std::vector<std::string> subjectsTakenByGroup = subjectsTaken[groupCount];	//get the subjects taken by the group
	
	std::vector<int> availableSubjects;

	for (std::vector<std::string>::const_iterator iter = subjectsTakenByGroup.begin(); iter != subjectsTakenByGroup.end(); ++iter) {		//iterates through the subjects taken by the group
		std::vector<std::string>::iterator it;
		it = find(subjects.begin(), subjects.end(), *iter);	//find the subject in the subjects global vector
		int subjectNum = std::distance(subjects.begin(), it);	//return the position of the subject

		std::vector<std::string> currentGroupsTeachers = attachedTeachers[groupCount];	//gets the current groups set of teachers

		it = find(currentGroupsTeachers.begin(), currentGroupsTeachers.end(), subjects[subjectNum]);	//find the subject in the current groups teacher vector
		int teacherPosition = std::distance(currentGroupsTeachers.begin(), it);
		teacherPosition++;		//increment to teacher position



		if ((hoursSubject[subjectNum] > tempHoursPerSubjectGroup[subjectNum]) && (std::find(currentTeachers.begin(), currentTeachers.end(), currentGroupsTeachers[teacherPosition]) == currentTeachers.end())) {	//if subject remains with hours left to teach and teacher is avaliable
			availableSubjects.push_back(subjectNum);
		}
	}



		if (availableSubjects.size() == 0)
			return subjects.size()+1;
		else {
			int Rnum = rand();
			int rSubjectNum = (Rnum % availableSubjects.size());	//random number between 0 and the total number of stored subjectNums
			return availableSubjects[rSubjectNum];
		}



}

void Generate(){
	int groupCount = 0;
	int totalHours = 25;		//total hours taught each week 
	int periodCount = 0;		//stores current period number being allocated
	srand(time(0));				//seed random number based on time

	std::vector<std::vector<int>> hoursPerSubjectGroup; // stores the current number of hours each group has for each subject

	// fills the hoursPerSubjectGroup Vector so it is the correct size for the current timetable arrangement
	for (std::vector<std::string>::const_iterator iter = groupNames.begin(); iter != groupNames.end(); ++iter) {		//iterates through the groupNames vector
		std::vector<int> temp;
		for (std::vector<std::string>::const_iterator iter2 = subjects.begin(); iter2 != subjects.end(); ++iter2) {	//iterate through subjects vector
			temp.push_back(0);
		}
		hoursPerSubjectGroup.push_back(temp);
	}

	std::vector<std::vector<std::string>> periodsArray;
	// make the periodarray vector the correct size
	for (std::vector<std::string>::const_iterator iter = groupNames.begin(); iter != groupNames.end(); ++iter) {		//iterates through the groupNames vector
		std::vector<std::string> temp;
		periodsArray.push_back(temp);
	}

	//make timetables the correct size
	for (std::vector<std::string>::const_iterator iter = groupNames.begin(); iter != groupNames.end(); ++iter) {		//iterates through the groupNames vector
		Timetable temp;
		Timetables.push_back(temp);
	}


	while (periodCount < totalHours) {		//while there are still unallocated periods
		std::vector<std::string> currentTeachers;	//store the teachers who are teaching this period already
		std::vector<std::string> currentRooms;	//store the Rooms that are in use for this period already
		groupCount = 0;
		while (groupCount < groupNames.size()) {		// while there are still remaining groups without a timetable
			int freePeriodFlag = 0;			//indicates weather the current period for the group is a free or not
			std::vector<std::string> subjectsTakenByCurrentGroup = subjectsTaken[groupCount]; //gets the subjects taken by the current group   
			int Rnum = rand();
			int rSubjectNum = (Rnum % subjectsTakenByCurrentGroup.size());											//get a random number between  0 and the total number of (subjects-1) for that group

			std::vector<std::string>::iterator it;
			it = find(subjects.begin(), subjects.end(), subjectsTakenByCurrentGroup[rSubjectNum]);	//find the subject in the subjects global vector
			int subjectNum = std::distance(subjects.begin(), it);	//return the position of the subject

			std::vector<int> tempHoursPerSubjectGroup = hoursPerSubjectGroup[groupCount];					//create the tempHoursPerSubjectGroup 

			//check if max hours for that subject is reached 
			int testTimetable = checkMaxHoursReached(tempHoursPerSubjectGroup, groupCount, currentTeachers);
			if (testTimetable == (subjects.size() + 1)) {
				freePeriodFlag = 1;
			}
			else {
				subjectNum = testTimetable;
			}

			std::vector<std::string> currentGroupsTeachers = attachedTeachers[groupCount];	//gets the current groups set of teachers

			it = find(currentGroupsTeachers.begin(), currentGroupsTeachers.end(), subjects[subjectNum]);	//find the subject in the current groups teacher vector
			int teacherPosition = std::distance(currentGroupsTeachers.begin(), it);
			teacherPosition++;		//increment to teacher position

				//room selection
				std::vector<std::string> tempRoomNames = roomNames[subjectNum];					//get all rooms for current subject

				int roomNum = (Rnum % tempRoomNames.size());									//get a random number between 0 and total number of rooms for current subject
				std::vector<std::string>::iterator checkRoom = std::find(currentRooms.begin(), currentRooms.end(), tempRoomNames[roomNum]);	//get a random room

				//if current rooms has all rooms for subject then assign a free period
				int duplicateRoomCount = 0;
				for (std::vector<std::string>::const_iterator iter = tempRoomNames.begin(); iter != tempRoomNames.end(); ++iter) {		//iterates through the  rooms names for that subject
					if (std::find(currentRooms.begin(), currentRooms.end(), *iter) != currentRooms.end()) 							//check if the room is in the currentRooms vector
						duplicateRoomCount++;
					if (duplicateRoomCount == tempRoomNames.size()) {
						_RPT0(0, "All rooms in use for that subject, assigning free period\n");  //prints to output
						freePeriodFlag = 1;
					}
				}

				while ((checkRoom != currentRooms.end()) && (freePeriodFlag == 0)) {								//stay in this loop till you find a room which is avaliable, or if free then ignore this loop
					int Rnum3 = rand();
					roomNum = (Rnum3 % tempRoomNames.size());								// get a random number between 0 and total number of teachers for the current subject
					checkRoom = std::find(currentRooms.begin(), currentRooms.end(), tempRoomNames[roomNum]);	//get another random room
				}

				//end room selection					

				if (freePeriodFlag == 0) {	// assign chosen subject --(hoursSubject[subjectNum] > tempHoursPerSubjectGroup[subjectNum]) && 
					tempHoursPerSubjectGroup[subjectNum]++;										//increment the hour for that subject by 1
					hoursPerSubjectGroup.at(groupCount) = tempHoursPerSubjectGroup;		//save the updated vector to the hoursPerSubjectGroup vector

					currentRooms.push_back(tempRoomNames[roomNum]);			//save the selected room to the current rooms for that period vector
					currentTeachers.push_back(currentGroupsTeachers[teacherPosition]);								//put the current teacher into the currentteachers vector for this period
					periodsArray[groupCount] = AssignTimetable(periodCount, periodsArray, groupCount, subjectNum, currentGroupsTeachers, teacherPosition, tempRoomNames, roomNum);		//assign the timetable to the global timetable variable and save the periodsArray in its current state

					groupCount++;			//go to the next group
				}
				else if (freePeriodFlag == 1) {				// assign free period
				//	subjectNum = 10;		//make the subjectNum point to "Free"
					tempRoomNames[roomNum] = "FreeRoom";
					currentGroupsTeachers[teacherPosition] = "FreeTeacher";
					periodsArray[groupCount] = AssignTimetable(periodCount,periodsArray, groupCount, subjectNum, currentGroupsTeachers, teacherPosition, tempRoomNames, roomNum);	//assign the timetable to the global timetable variable and save the periodsArray in its current state
					groupCount++;			//go to the next group
				}		
		}
		periodCount++;			//go to next period
		_RPT1(0, "Period Count is %d\n", periodCount);  //prints to output
	}
}

bool checkDuplicates(std::vector<std::string> vec)
{
	std::sort(vec.begin(), vec.end());
	return std::unique(vec.begin(), vec.end()) == vec.end();
}


bool checkTimetable() {			//check all hours scheduled not too little or too many no double bookings of rooms/teachers/groups, returns 1 if not feasible

	std::vector<std::vector<int>> subjectHoursCheck;				// with subjects ordered how they were first typed in
	//make the subjectHoursCheck vector the correct size
	for (int i = 0; i < groupNames.size(); i++) {		//iterates through the groupNames vector
		std::vector<int> temp;
		std::vector<std::string> subjectsTakenCurrentGroup = subjectsTaken[i];
		for (int j = 0; j < subjectsTakenCurrentGroup.size(); j++) {	//iterate through subjects vector
			temp.push_back(0);
		}
		subjectHoursCheck.push_back(temp);
	}

	int totalHours = 25;
	int periodCount = 0;
	int feasible = 0;


	while (periodCount < totalHours) {		//while there are still unchecked periods

		std::vector<std::string> currentTeachers;		//stores current teachers for that period
		std::vector<std::string> currentRooms;			//store current rooms for that period

		int groupCount = 0;
		for (std::vector<Timetable>::const_iterator iter = Timetables.begin(); iter != Timetables.end(); ++iter) {			//iterate through Timetables vector
			Timetable currentTimetable = *iter;	//select the current timetable
			std::vector<std::string> periods = currentTimetable.getPeriods();	//get the period information for that group
		
			std::string currentTeacher = periods[(periodCount * 3 + 1)];		//get current teacher for that period

		
			std::string currentRoom = periods[(periodCount * 3 + 2)];		//get current room for that period

		
			std::string subject = periods[periodCount * 3];			//get current subject

			std::string freeCheck = "Free";
			if (subject != freeCheck)  {		// if its not a free period then check the subject hours 
				currentTeachers.push_back(currentTeacher);
				currentRooms.push_back(currentRoom);

				std::vector<std::string> currentGroupsSubjects = subjectsTaken[groupCount];
				std::vector<std::string>::iterator it;
				it = find(currentGroupsSubjects.begin(), currentGroupsSubjects.end(), subject);	//find the subject in the subjects taken for that group global vector
				int subjectNum = std::distance(currentGroupsSubjects.begin(), it);	// position of the subject within the current groups subjects



				std::vector<int> currentGroupsSubjectHours = subjectHoursCheck[groupCount];		//get the current hours taken for each subject for the current group



				int hoursCurrentSubject = currentGroupsSubjectHours[subjectNum];			//get the current hours taken for that subject   

				it = find(subjects.begin(), subjects.end(), subject);	//find the subject in the subjects global vector
				int globalSubjectNum = std::distance(subjects.begin(), it);	//return the position of the subject


				if (hoursCurrentSubject > hoursSubject[globalSubjectNum]) {				//if number of hours taken for that subject exceeds total hours required for it
					_RPT0(0, "Timetable not feasible, Too many hours for subject\n");  //prints to output
					feasible = 1;
					return 1;
				}


				currentGroupsSubjectHours[subjectNum]++;		//Add an addtional hour for that group for that subject
				subjectHoursCheck[groupCount] = currentGroupsSubjectHours;		//put into the 2d vector for all groups subject hours
			}

			groupCount++;
		}






		if (!checkDuplicates(currentTeachers)) {
			_RPT0(0, "Timetable not feasible, Duplicate teachers in same period\n");  //prints to output
			feasible = 1;
			return 1;
		}


		if (!checkDuplicates(currentRooms)) {
			_RPT0(0, "Timetable not feasible, Duplicate rooms in same period\n");  //prints to output
			feasible = 1;
			return 1;
		}
		



		periodCount++;
	}



	for (int i = 0; i < groupNames.size(); i++) {		//iterates through the groups vector
		_RPT1(0, "The current group is %d\n", i);  //prints to output
		std::vector<std::string> currentGroupsSubjects = subjectsTaken[i];	//get all the subjects taken by the current group
		for (int j = 0; j < currentGroupsSubjects.size(); j++) {		//iterate through the subjects for that group
			_RPT1(0, "The current subject for that group is %d\n", j);  //prints to output
			std::vector<std::string>::iterator it;
			it = find(subjects.begin(), subjects.end(), currentGroupsSubjects[j]);	//find the current groups subject in the subjects global vector
			int subjectNum = std::distance(subjects.begin(), it);	// position of the subject

			std::vector<int> currentGroupsSubjectHours = subjectHoursCheck[i];		//get the current hours taken for each subject for the current group



			if (currentGroupsSubjectHours[j] != hoursSubject[subjectNum]) {
				_RPT0(0, "Timetable not feasible, Not enough hours for subject\n");  //prints to output
				feasible = 1;
				return 1;
			}

		}


	}


	if (feasible == 0) {
		_RPT0(0, "Timetable is feasible\n");  //prints to output
		return 0;
	}
	else {
		_RPT0(0, "Timetable is infeasible\n");  //prints to output
		return 1;
	}
}


void ScoreTimetable() {		//lower score is better
	int totalHours = 25;		//total hours in the timetable
	int lunchPeriod = 4;		//the period after lunch
	int totalScore = 0;
	for (std::vector<Timetable>::const_iterator iter = Timetables.begin(); iter != Timetables.end(); ++iter) {			//iterate through Timetables vector
		Timetable currentTimetable = *iter;	//select the current timetable
		std::vector<std::string> periods = currentTimetable.getPeriods();	//get the period information for that group
		int currentScore = 0;
		std::string lastPeriod = "set-up";
		int hoursPerDay = totalHours / 5;
		int periodDayCount = 1;
		for (int periodCount = 0; periodCount < totalHours; periodCount++) {		//iterate through each period
			std::string currentTeacher = periods[(periodCount * 3 + 1)];		//get current teacher for that period
			std::string currentRoom = periods[(periodCount * 3 + 2)];		//get current room for that period
			std::string subject = periods[periodCount * 3];			//get current subject
			std::string nextPeriod;
			if (periodCount < (totalHours - 1)) {
				nextPeriod = periods[(periodCount * 3) + 3];
	
			}
			else
				nextPeriod = "Free";	//as to not effect scoring on the period after the last period of the week

			_RPT1(0, "period Count is %d \n", periodCount);  //prints to output
		//	_RPT1(0, "last period is %s current is %s next is %s\n", lastPeriod.c_str(), subject.c_str(), nextPeriod.c_str());  //prints to output
			if (periodDayCount == hoursPerDay )
				periodDayCount = 1;
			//check Two subsequent classes
			if ((subject != "Free") &&(lastPeriod == subject)) {
				currentScore++;			//increase score if subsequent class
				_RPT0(0, "Increasing score subsequent class \n");  //prints to output
			}
			//check physically active lesson after lunch
			if ((subject == "PE") && (periodDayCount == lunchPeriod)){
				currentScore++;		//increase score if PE after lunch
			_RPT0(0, "Increasing score PE after lunch \n");  //prints to output
		}
			//check for empty timeslot between class
			if (periodDayCount != 1 || hoursPerDay){		//check not first or last period in the day
				if (subject == "Free")	//check if current subject is free
					if ((lastPeriod != "Free") && (nextPeriod != "Free")) { //if both periods before and after the free are subjects then increase score
						currentScore++;
						_RPT0(0, "Increasing score free inbetween subjects \n");  //prints to output
					}
	}
			//check free periods be put on the final day of the week
			if ((periodCount >= (totalHours - hoursPerDay)) && (periodCount < totalHours)){	//if on final day of the week
				if (subject != "Free") {		//if not a free period increase score
					currentScore++;
					_RPT0(0, "Increasing score not a free on friday \n");  //prints to output
				}
			}
			//Teacher preference 
			lastPeriod = subject;
			periodDayCount++;
		}
		_RPT1(0, "The current score is %d\n", currentScore);  //prints to output
		totalScore = totalScore + currentScore;	//add the current score to the total for the timetable
	}
	_RPT1(0, "The TOTAL score is %d\n", totalScore);  //prints to output
}







bool checkTimetable1(std::vector<Timetable> currentTimetables) {			//check all hours scheduled not too little or too many no double bookings of rooms/teachers/groups, returns 1 if not feasible

	std::vector<std::vector<int>> subjectHoursCheck;				// with subjects ordered how they were first typed in
																	//make the subjectHoursCheck vector the correct size
	for (int i = 0; i < groupNames.size(); i++) {		//iterates through the groupNames vector
		std::vector<int> temp;
		std::vector<std::string> subjectsTakenCurrentGroup = subjectsTaken[i];
		for (int j = 0; j < subjectsTakenCurrentGroup.size(); j++) {	//iterate through subjects vector
			temp.push_back(0);
		}
		subjectHoursCheck.push_back(temp);
	}

	int totalHours = 25;
	int periodCount = 0;
	int feasible = 0;


	while (periodCount < totalHours) {		//while there are still unchecked periods

		std::vector<std::string> currentTeachers;		//stores current teachers for that period
		std::vector<std::string> currentRooms;			//store current rooms for that period

		int groupCount = 0;
		for (std::vector<Timetable>::const_iterator iter = currentTimetables.begin(); iter != currentTimetables.end(); ++iter) {			//iterate through currentTimetables vector
			Timetable currentTimetable = *iter;	//select the current timetable
			std::vector<std::string> periods = currentTimetable.getPeriods();	//get the period information for that group

			std::string currentTeacher = periods[(periodCount * 3 + 1)];		//get current teacher for that period


			std::string currentRoom = periods[(periodCount * 3 + 2)];		//get current room for that period


			std::string subject = periods[periodCount * 3];			//get current subject

			std::string freeCheck = "Free";
			if (subject != freeCheck) {		// if its not a free period then check the subject hours 
				currentTeachers.push_back(currentTeacher);
				currentRooms.push_back(currentRoom);

				std::vector<std::string> currentGroupsSubjects = subjectsTaken[groupCount];
				std::vector<std::string>::iterator it;
				it = find(currentGroupsSubjects.begin(), currentGroupsSubjects.end(), subject);	//find the subject in the subjects taken for that group global vector
				int subjectNum = std::distance(currentGroupsSubjects.begin(), it);	// position of the subject within the current groups subjects



				std::vector<int> currentGroupsSubjectHours = subjectHoursCheck[groupCount];		//get the current hours taken for each subject for the current group



				int hoursCurrentSubject = currentGroupsSubjectHours[subjectNum];			//get the current hours taken for that subject   

				it = find(subjects.begin(), subjects.end(), subject);	//find the subject in the subjects global vector
				int globalSubjectNum = std::distance(subjects.begin(), it);	//return the position of the subject


				if (hoursCurrentSubject > hoursSubject[globalSubjectNum]) {				//if number of hours taken for that subject exceeds total hours required for it
					_RPT0(0, "Timetable not feasible, Too many hours for subject\n");  //prints to output
					feasible = 1;
					return 1;
				}


				currentGroupsSubjectHours[subjectNum]++;		//Add an addtional hour for that group for that subject
				subjectHoursCheck[groupCount] = currentGroupsSubjectHours;		//put into the 2d vector for all groups subject hours
			}

			groupCount++;
		}






		if (!checkDuplicates(currentTeachers)) {
			_RPT0(0, "Timetable not feasible, Duplicate teachers in same period\n");  //prints to output
			feasible = 1;
			return 1;
		}


		if (!checkDuplicates(currentRooms)) {
			_RPT0(0, "Timetable not feasible, Duplicate rooms in same period\n");  //prints to output
			feasible = 1;
			return 1;
		}




		periodCount++;
	}



	for (int i = 0; i < groupNames.size(); i++) {		//iterates through the groups vector
		_RPT1(0, "The current group is %d\n", i);  //prints to output
		std::vector<std::string> currentGroupsSubjects = subjectsTaken[i];	//get all the subjects taken by the current group
		for (int j = 0; j < currentGroupsSubjects.size(); j++) {		//iterate through the subjects for that group
			_RPT1(0, "The current subject for that group is %d\n", j);  //prints to output
			std::vector<std::string>::iterator it;
			it = find(subjects.begin(), subjects.end(), currentGroupsSubjects[j]);	//find the current groups subject in the subjects global vector
			int subjectNum = std::distance(subjects.begin(), it);	// position of the subject

			std::vector<int> currentGroupsSubjectHours = subjectHoursCheck[i];		//get the current hours taken for each subject for the current group



			if (currentGroupsSubjectHours[j] != hoursSubject[subjectNum]) {
				_RPT0(0, "Timetable not feasible, Not enough hours for subject\n");  //prints to output
				feasible = 1;
				return 1;
			}

		}


	}
	if (feasible == 0) {
		_RPT0(0, "Timetable is feasible\n");  //prints to output
		return 0;
	}
	else {
		_RPT0(0, "Timetable is infeasible\n");  //prints to output
		return 1;
	}
}







/*
void CreateTimetablePopulation() {
	int totalHours = 25;		//total hours in the timetable
	std::vector<std::vector<Timetable>> timetablePopulation;	//Population of solutions
	timetablePopulation.push_back(Timetables);					//Put the intial solution into the population
	auto engine = std::default_random_engine{};					//seed for random shuffling
	for (std::vector<Timetable>::const_iterator iter = Timetables.begin(); iter != Timetables.end(); ++iter) {			//iterate through Timetables vector
		Timetable currentTimetable = *iter;	//select the current timetable
		std::vector<std::string> periods = currentTimetable.getPeriods();	//get the period information for that group
		std::vector<std::vector<std::string>> splitperiods;
		for (int i = 0; i < totalHours; i++) {	//may need to check logic i<= totalHours
			std::vector<std::string> splitperiod;
			splitperiod.push_back(periods[i]);			//save teacher
			splitperiod.push_back(periods[i + 1]);		//save room
			splitperiod.push_back(periods[i + 2]);		//save subject
			splitperiods.push_back(splitperiod);
		}
			std::random_shuffle(splitperiods.begin(), splitperiods.end(),engine);		//shuffle the periods randomly
			currentTimetable.setPeriods(splitperiods);

	}
}*/

void DefaultValues() {
	 subjects = { "Maths", "English", "French","Geography","PE","I.C.T","Economics","Science","History","Art" };	//subject names



	 /*			std::vector<std::string>::const_iterator itertest;

			for (itertest = subjectsTakenByCurrentGroup.begin(); itertest != subjectsTakenByCurrentGroup.end(); ++itertest) {		//iterates through the subjects vector

			std::string str = *itertest;
			_RPT1(0, "The test variable is %s\n", str.c_str());  //prints to output

			}

	 }*/
	 hoursSubject = {6,6,4,4,2,5,4,6,4,3};		//hours taught per subject

     groupNames = {"7A","7B","8A","8B","9A","9B","10A","10B"}; //class names

	 std::vector<std::string> temp = { "Mr Maths1","Miss Maths2", "Dr Maths3" }, temp2 = { "M1","M2","M3" };
	 std::vector<int> temp3 = { 18,18,18 };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 teacherHours.push_back(temp3);
	 temp = { "Mr English1","Miss English2", "Dr English3" };
	 temp2 = { "E1","E2","E3" };
	 temp3 = { 18,18,18 };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 teacherHours.push_back(temp3);
	 temp = { "Mr French1","Miss French2", "Dr French3" };
	 temp2 = { "F1","F2","F3" };
	 temp3 = { 12,12,12 };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 teacherHours.push_back(temp3);
	 temp = { "Mr Geography1","Miss Geography2", "Dr Geography3" };
	 temp2 = { "G1","G2","G3" };
	 temp3 = { 12,12,12 };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 teacherHours.push_back(temp3);
	 temp = { "Mr PE1","Miss PE2", "Dr PE3" };
	 temp2 = { "P1","P2","P3" };
	 temp3 = { 2,2,2 };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 teacherHours.push_back(temp3);
	 temp = { "Mr ICT1","Miss ICT2", "Dr ICT3" };
	 temp2 = { "I1","I2","I3" };
	 temp3 = { 5,5,5 };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 teacherHours.push_back(temp3);
	 temp = { "Mr Eco1","Miss Eco2", "Dr Eco3" };
	 temp2 = { "Ec1","Ec2","Ec3" };
	 temp3 = { 4,4,4 };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 teacherHours.push_back(temp3);
	 temp = { "Mr Sci1","Miss Sci2", "Dr Sci3" };
	 temp2 = { "S1","S2","S3" };
	 temp3 = { 6,6,6 };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 teacherHours.push_back(temp3);
	 temp = { "Mr Hist1","Miss Hist2", "Dr Hist3" };
	 temp2 = { "H1","H2","H3" };
	 temp3 = {4,4,4 };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 teacherHours.push_back(temp3);
	 temp = { "Mr Art1","Miss Art2", "Dr Art3" };
	 temp2 = { "A1","A2","A3" };
	 temp3 = { 3,3,3 };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 teacherHours.push_back(temp3);

	 temp = { "Maths", "English", "French","Geography" };
	 subjectsTaken.push_back(temp);
	 temp = { "Maths", "English", "French","Geography" };
	 subjectsTaken.push_back(temp);
	 temp = { "Maths", "English", "French","Geography" };
	 subjectsTaken.push_back(temp);
	 temp = { "Maths", "English", "French","Geography" };
	 subjectsTaken.push_back(temp);
	 temp = { "Maths", "English", "French","Geography" };
	 subjectsTaken.push_back(temp);
	 temp = { "Maths", "English", "French","Geography" };
	 subjectsTaken.push_back(temp);
	 temp = { "Maths", "English", "French","Geography" };
	 subjectsTaken.push_back(temp);
	 temp = { "Maths", "English", "French","Geography" };
	 subjectsTaken.push_back(temp);
}