#include "mylib.h"
#include <time.h>
#include "TimetableGenerator.h"
#include <random>
#include <fstream>
#include <iterator>
#include <iostream>

void ClearGlobals() {
	subjects.clear();
	hoursSubject.clear();
	groupNames.clear();
	teacherNames.clear();
	roomNames.clear();
	subjectsTaken.clear();
//	attachedTeachers.clear();
	Timetables.clear();
}

void SaveTeachers() {
	std::ofstream output_file("savedTeachers.txt");
	std::ostream_iterator<std::string> output_iterator(output_file, ",");
	for (int groupCount = 0; groupCount < groupNames.size(); groupCount++) {
		std::vector<std::string> currentTeachers = attachedTeachers[groupCount];
		std::copy(currentTeachers.begin(), currentTeachers.end(), output_iterator);
		output_file << std::endl;
	}
}

void SaveTimetable(std::string name) {

	std::ofstream output_file(name + "savedTimetables.txt");
	std::ostream_iterator<std::string> output_iterator(output_file, ",");
	for (std::vector<Timetable>::const_iterator iter = Timetables.begin(); iter != Timetables.end(); ++iter) {
		Timetable currentTimetable = *iter;
		std::vector<std::string> currentPeriods = currentTimetable.getPeriods();
		std::copy(currentPeriods.begin(), currentPeriods.end(), output_iterator);
		output_file << std::endl;
	}
}

void SaveTimetable1() {

	std::ofstream output_file("savedTimetables.txt");
	std::ostream_iterator<std::string> output_iterator(output_file, ",");
	for (std::vector<Timetable>::const_iterator iter = Timetables.begin(); iter != Timetables.end(); ++iter) {
		Timetable currentTimetable = *iter;
		std::vector<std::string> currentPeriods = currentTimetable.getPeriods();
		std::copy(currentPeriods.begin(), currentPeriods.end(), output_iterator);
		output_file << std::endl;
	}
}

void LoadTimetable() {

	for (std::vector<std::string>::const_iterator iter = groupNames.begin(); iter != groupNames.end(); ++iter) {
		Timetable currentTimetable;
		currentTimetable.setGroup(*iter);	//give the group name to the timetable object
		Timetables.push_back(currentTimetable);	//save timetable to global timetables vector
	}

	std::ifstream infile("savedTimetables.txt");

	for (int i = 0; infile; i++)
	{
		std::string s;
		if (!getline(infile, s)) break;
		std::istringstream ss(s);
		std::vector<std::string> periods;
		while (ss)
		{
			std::string s;
			if (!getline(ss, s, ',')) break;
			periods.push_back(s);
		}
		Timetable currentTimetable = Timetables[i];	//get the current timetable
		currentTimetable.setPeriods(periods); //give the periods information to the timetable object
		Timetables[i] = currentTimetable;	//save to global timetable vector
		//data.push_back(periods);
	}



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
		//	_RPT1(0, "subject is %s tempHours is %d tempteacherHours is %d\n", subjects[position].c_str(),tempHours[teacherNum], tempTeacherHours[teacherNum]);  //prints to output
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
		//_RPT1(0, "Period: %d Group: %s Subject: %s Teacher: %s Room: %s\n", periodCount, groupNames[groupCount].c_str(), "Free", currentGroupsTeachers[teacherPosition].c_str(), tempRoomNames[roomNum].c_str());  //prints to output
	}
	else {
		periods.push_back(subjects[subjectNum]);		//save the subject to the periods vector
	//	_RPT1(0, "Period: %d Group: %s Subject: %s Teacher: %s Room: %s\n", periodCount, groupNames[groupCount].c_str(), subjects[subjectNum].c_str(), currentGroupsTeachers[teacherPosition].c_str(), tempRoomNames[roomNum].c_str());  //prints to output
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
	std::vector<int> availableSubjectsRemainingHours;

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
			availableSubjectsRemainingHours.push_back(hoursSubject[subjectNum]-tempHoursPerSubjectGroup[subjectNum]);
		}
	}



		if (availableSubjects.size() == 0)
			return subjects.size()+1;
		else {
			int Rnum = rand();
			int rSubjectNum = (Rnum % availableSubjects.size());	//random number between 0 and the total number of stored subjectNums
			//auto mostHoursRemaining = std::max_element(std::begin(availableSubjectsRemainingHours), std::end(availableSubjectsRemainingHours));	//returns a iterator pointing towards the largest value in the vector
			//int chosenSubjectNum = std::distance(std::begin(availableSubjectsRemainingHours), mostHoursRemaining);	//returns the postion of the avaliable subject with the most remaining hours
			return availableSubjects[rSubjectNum];
		}



}

/*
int checkMaxHoursReached2(std::vector<int> tempHoursPerSubjectGroup, int groupCount, std::vector<std::string> currentTeachers, bool priority) {	//check if the max hours have been reached for every subject for this group
	std::vector<std::string> subjectsTakenByGroup = subjectsTaken[groupCount];	//get the subjects taken by the group

	std::vector<int> availableSubjects;
	std::vector<int> availableSubjectsRemainingHours;

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
			availableSubjectsRemainingHours.push_back(hoursSubject[subjectNum] - tempHoursPerSubjectGroup[subjectNum]);
		}
	}



	if (availableSubjects.size() == 0)
		return subjects.size() + 1;
	else {
		//int Rnum = rand();
		//int rSubjectNum = (Rnum % availableSubjects.size());	//random number between 0 and the total number of stored subjectNums
		/*std::vector<int>::iterator hoursRemaining;
		if (priority == 1) {
			 hoursRemaining = std::max_element(std::begin(availableSubjectsRemainingHours), std::end(availableSubjectsRemainingHours));	//returns a iterator pointing towards the largest value in the vector
		}
		else {
			 hoursRemaining = std::min_element(std::begin(availableSubjectsRemainingHours), std::end(availableSubjectsRemainingHours));	//returns a iterator pointing towards the largest value in the vector
		}
		int chosenSubjectNum = std::distance(std::begin(availableSubjectsRemainingHours), hoursRemaining);	//returns the postion of the avaliable subject with the most remaining hours
		int chosenSubjectNum; // integer within range 0 - availableSubjects.size()

		return availableSubjects[chosenSubjectNum];

	}



}*/

void Generate(){
	int groupCount = 0;
	int totalHours = 25;		//total hours taught each week 
	int periodCount = 0;		//stores current period number being allocated
	//bool priority = 1;
	//srand(time(0));				//seed random number based on time

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
			//int rSubjectNum = (Rnum % subjectsTakenByCurrentGroup.size());											//get a random number between  0 and the total number of (subjects-1) for that group

			std::vector<std::string>::iterator it;
			/*	it = find(subjects.begin(), subjects.end(), subjectsTakenByCurrentGroup[rSubjectNum]);	//find the subject in the subjects global vector
				int subjectNum = std::distance(subjects.begin(), it);	//return the position of the subject */

			std::vector<int> tempHoursPerSubjectGroup = hoursPerSubjectGroup[groupCount];					//create the tempHoursPerSubjectGroup  
			int subjectNum;
			//check if max hours for that subject is reached 
			//priority = !priority;
			//int testTimetable = checkMaxHoursReached2(tempHoursPerSubjectGroup, groupCount, currentTeachers, priority);
			int testTimetable = checkMaxHoursReached(tempHoursPerSubjectGroup, groupCount, currentTeachers);
			if (testTimetable == (subjects.size() + 1)) {
				freePeriodFlag = 1;
				subjectNum = 0;	//as every class has at least 1 subject to not cause vector subsript out of range errors
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
				for (std::vector<std::string>::const_iterator iter = tempRoomNames.begin(); (iter != tempRoomNames.end()) && (freePeriodFlag == 0); ++iter) {		//iterates through the  rooms names for that subject
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
					std::vector<std::string> tempRoomNamesFree;
					tempRoomNamesFree.push_back("FreeRoom");
					roomNum = 0;
					std::vector<std::string> currentGroupsTeachersFree;
					currentGroupsTeachersFree.push_back("FreeTeacher");
					teacherPosition = 0;


					periodsArray[groupCount] = AssignTimetable(periodCount,periodsArray, groupCount, subjectNum, currentGroupsTeachersFree, teacherPosition, tempRoomNames, roomNum);	//assign the timetable to the global timetable variable and save the periodsArray in its current state
					groupCount++;			//go to the next group
				}		
		}
		periodCount++;			//go to next period
	//	_RPT1(0, "Period Count is %d\n", periodCount);  //prints to output
	}
}



std::vector<std::string> AssignTimetableV2(std::vector<int> allocatedPeriods, int totalHours, int periodCount, std::vector<std::vector<std::string>> periodsArray, int groupCount, int subjectNum, std::vector<std::string> currentGroupsTeachers, int teacherPosition, std::vector<std::string> tempRoomNames, int roomNum) {
	std::vector<std::string> periods = periodsArray[groupCount];	//create periods vector from the periods array
	int Rnum = rand();
	int periodNum = (Rnum % totalHours);	//get a random Number between 0 and total timetabled hours
	std::vector<int>::iterator checkPeriod = std::find(allocatedPeriods.begin(), allocatedPeriods.end(), periodNum);	//check if selected period already allocated

	while (checkPeriod != allocatedPeriods.end()) {		//stay in this loop till a period is found which has not been allocated
		Rnum = rand();
		periodNum = (Rnum % totalHours);	//get a random Number between 0 and total timetabled hours
		std::vector<int>::iterator checkPeriod = std::find(allocatedPeriods.begin(), allocatedPeriods.end(), periodNum);	//check if selected period already allocated
	}

	if (currentGroupsTeachers[teacherPosition] == "FreeTeacher") {
		periods[periodNum] = "Free";		//save the free subject to the periods vector
											//_RPT1(0, "Period: %d Group: %s Subject: %s Teacher: %s Room: %s\n", periodCount, groupNames[groupCount].c_str(), "Free", currentGroupsTeachers[teacherPosition].c_str(), tempRoomNames[roomNum].c_str());  //prints to output
	}
	else {
		periods[periodNum] = subjects[subjectNum];		//save the subject to the periods vector
														//	_RPT1(0, "Period: %d Group: %s Subject: %s Teacher: %s Room: %s\n", periodCount, groupNames[groupCount].c_str(), subjects[subjectNum].c_str(), currentGroupsTeachers[teacherPosition].c_str(), tempRoomNames[roomNum].c_str());  //prints to output
	}
	periods[periodNum] = currentGroupsTeachers[teacherPosition];	//save the teacher to the periods vector
	periods[periodNum] = tempRoomNames[roomNum];		//save the room number to periods vector
	//CONTINUE WORKING FROM HERE
	Timetable tempTimetable(groupNames[groupCount], periods);
	Timetables[groupCount] = tempTimetable;
	return periods;
}

int checkMaxHoursReachedV2(std::vector<int> tempHoursPerSubjectGroup, int groupCount) {	//check if the max hours have been reached for every subject for this group
	std::vector<std::string> subjectsTakenByGroup = subjectsTaken[groupCount];	//get the subjects taken by the group
	std::vector<int> availableSubjects;

	for (std::vector<std::string>::const_iterator iter = subjectsTakenByGroup.begin(); iter != subjectsTakenByGroup.end(); ++iter) {		//iterates through the subjects taken by the group
		std::vector<std::string>::iterator it;
		it = find(subjects.begin(), subjects.end(), *iter);	//find the subject in the subjects global vector
		int subjectNum = std::distance(subjects.begin(), it);	//return the position of the subject
		if (hoursSubject[subjectNum] > tempHoursPerSubjectGroup[subjectNum]) {	//if subject remains with hours left to teach 
			availableSubjects.push_back(subjectNum);
		}
	}

	if (availableSubjects.size() == 0)
		return subjects.size() + 1;
	else {
		int Rnum = rand();
		int rSubjectNum = (Rnum % availableSubjects.size());	//random number between 0 and the total number of stored subjectNums
		return availableSubjects[rSubjectNum];
	}
}

void GenerateV2() {
	int groupCount = 0;
	int totalHours = 25;		//total hours taught each week 
	int periodCount = 0;		//stores current period number being allocated

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
	for (int i = 0; i < groupNames.size(); i++) {		//iterates through the groupNames vector
		std::vector<std::string> tempPeriods;
		for (int j = 0; j < totalHours; j++) {
			std::string tempSubject = "Temp Subject";
			std::string tempTeacher = "Temp Teacher";
			std::string tempRoom = "Temp Room";	
			tempPeriods.push_back(tempSubject);
			tempPeriods.push_back(tempTeacher);
			tempPeriods.push_back(tempRoom);
		}
		periodsArray.push_back(tempPeriods);
	}

	//make timetables the correct size
	for (std::vector<std::string>::const_iterator iter = groupNames.begin(); iter != groupNames.end(); ++iter) {		//iterates through the groupNames vector
		Timetable temp;
		Timetables.push_back(temp);
	}
	while (groupCount < groupNames.size()) {		// while there are still remaining groups without a timetable
		periodCount = 0;
		while (periodCount < totalHours) {		//while there are still unallocated periods
			int freePeriodFlag = 0;			//indicates weather the current period for the group is a free(1) or not(0)
			std::vector<std::string> subjectsTakenByCurrentGroup = subjectsTaken[groupCount]; //gets the subjects taken by the current group  
			int Rnum = rand();
			std::vector<int> tempHoursPerSubjectGroup = hoursPerSubjectGroup[groupCount];					//create the tempHoursPerSubjectGroup  
			int subjectNum;
			int testTimetable = checkMaxHoursReachedV2(tempHoursPerSubjectGroup, groupCount);
			if (testTimetable == (subjects.size() + 1)) {
				freePeriodFlag = 1;
			}
			else {
				subjectNum = testTimetable;
			}

			std::vector<std::string> currentGroupsTeachers = attachedTeachers[groupCount];	//gets the current groups set of teachers
			std::vector<std::string>::iterator it = find(currentGroupsTeachers.begin(), currentGroupsTeachers.end(), subjects[subjectNum]);	//find the subject in the current groups teacher vector
			int teacherPosition = std::distance(currentGroupsTeachers.begin(), it);
			teacherPosition++;		//increment to teacher position

			//room selection
			std::vector<std::string> tempRoomNames = roomNames[subjectNum];					//get all rooms for current subject
			int roomNum = (Rnum % tempRoomNames.size());									//get a random number between 0 and total number of rooms for current subject
			//end room selection					

			if (freePeriodFlag == 0) {	// assign chosen subject 
				tempHoursPerSubjectGroup[subjectNum]++;										//increment the hour for that subject by 1
				hoursPerSubjectGroup.at(groupCount) = tempHoursPerSubjectGroup;		//save the updated vector to the hoursPerSubjectGroup vector
				periodsArray[groupCount] = AssignTimetable(periodCount, periodsArray, groupCount, subjectNum, currentGroupsTeachers, teacherPosition, tempRoomNames, roomNum);		//assign the timetable to the global timetable variable and save the periodsArray in its current state


			}
			else if (freePeriodFlag == 1) {				// assign free period
				std::vector<std::string> tempRoomNamesFree;
				tempRoomNamesFree.push_back("FreeRoom");
				roomNum = 0;
				std::vector<std::string> currentGroupsTeachersFree;
				currentGroupsTeachersFree.push_back("FreeTeacher");
				teacherPosition = 0;


				periodsArray[groupCount] = AssignTimetable(periodCount, periodsArray, groupCount, subjectNum, currentGroupsTeachersFree, teacherPosition, tempRoomNames, roomNum);	//assign the timetable to the global timetable variable and save the periodsArray in its current state
				groupCount++;			//go to the next group
			}
			periodCount++;			//go to next period
									//	_RPT1(0, "Period Count is %d\n", periodCount);  //prints to output
		}
		groupCount++;			//go to the next group

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
	//	_RPT1(0, "The current group is %d\n", i);  //prints to output
		std::vector<std::string> currentGroupsSubjects = subjectsTaken[i];	//get all the subjects taken by the current group
		for (int j = 0; j < currentGroupsSubjects.size(); j++) {		//iterate through the subjects for that group
		//	_RPT1(0, "The current subject for that group is %d\n", j);  //prints to output
			std::vector<std::string>::iterator it;
			it = find(subjects.begin(), subjects.end(), currentGroupsSubjects[j]);	//find the current groups subject in the subjects global vector
			int subjectNum = std::distance(subjects.begin(), it);	// position of the subject

			std::vector<int> currentGroupsSubjectHours = subjectHoursCheck[i];		//get the current hours taken for each subject for the current group



			if (currentGroupsSubjectHours[j] != hoursSubject[subjectNum]) {
				_RPT1(0, "Timetable not feasible, Not enough hours for subject %s for class %s\n", subjects[subjectNum].c_str(), groupNames[i].c_str());  //prints to output
				feasible = 1;
			//	return 1;
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
	//	_RPT1(0, "The current group is %d\n", i);  //prints to output
		std::vector<std::string> currentGroupsSubjects = subjectsTaken[i];	//get all the subjects taken by the current group
		for (int j = 0; j < currentGroupsSubjects.size(); j++) {		//iterate through the subjects for that group
			_RPT1(0, "The current subject for that group is %d\n", j);  //prints to output
			std::vector<std::string>::iterator it;
			it = find(subjects.begin(), subjects.end(), currentGroupsSubjects[j]);	//find the current groups subject in the subjects global vector
			int subjectNum = std::distance(subjects.begin(), it);	// position of the subject

			std::vector<int> currentGroupsSubjectHours = subjectHoursCheck[i];		//get the current hours taken for each subject for the current group



			if (currentGroupsSubjectHours[j] != hoursSubject[subjectNum]) {
				_RPT1(0, "Timetable not feasible, Not enough hours for subject %s\n", subjects[subjectNum].c_str());  //prints to output
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
	subjects = { "English", "Maths","Science","Art" ,"ICT","Humanities","RE","French","Music","PE","PSHE" };	//subject names


	hoursSubject = { 4,3,3,3,1,4,1,2,1,2,1 };		//hours taught per subject

	groupNames = { "7A","7B","7C","8A","8B","8C","9A","9B","9C" }; //class names

	std::vector<std::string> temp = { "Mr English1","Miss English2", "Dr English3" }, temp2 = { "E1","E2","E3" };
	std::vector<int> temp3 = { 12,12,12 };
	roomNames.push_back(temp2);
	teacherNames.push_back(temp);
	teacherHours.push_back(temp3);
	temp = { "Mr Maths1","Miss Maths2" };
	temp2 = { "M1","M2" };
	temp3 = { 15,15 };
	roomNames.push_back(temp2);
	teacherNames.push_back(temp);
	teacherHours.push_back(temp3);
	temp = { "Mr Sci1","Miss Sci2" };
	temp2 = { "S1","S2" };
	temp3 = { 15,15 };
	roomNames.push_back(temp2);
	teacherNames.push_back(temp);
	teacherHours.push_back(temp3);
	temp = { "Mr Art1","Miss Art2" };
	temp2 = { "A1","A2" };
	temp3 = { 15,15 };
	roomNames.push_back(temp2);
	teacherNames.push_back(temp);
	teacherHours.push_back(temp3);
	temp = { "Mr ICT1","Miss ICT2" };
	temp2 = { "IT1","IT2" };
	temp3 = { 5,5 };
	roomNames.push_back(temp2);
	teacherNames.push_back(temp);
	teacherHours.push_back(temp3);
	temp = { "Mr Hum1","Miss Hum2", "Dr Hum3" };
	temp2 = { "H1","H2","H3" };
	temp3 = { 12,12,12 };
	roomNames.push_back(temp2);
	teacherNames.push_back(temp);
	teacherHours.push_back(temp3);
	temp = { "Mr RE1","Miss RE2" };
	temp2 = { "RE1","RE2" };
	temp3 = { 5,5 };
	roomNames.push_back(temp2);
	teacherNames.push_back(temp);
	teacherHours.push_back(temp3);
	temp = { "Mr French1","Miss French2" };
	temp2 = { "L1","L2" };
	temp3 = { 10,10 };
	roomNames.push_back(temp2);
	teacherNames.push_back(temp);
	teacherHours.push_back(temp3);
	temp = { "Mr Music1","Miss Music2" };
	temp2 = { "MU1","MU2" };
	temp3 = { 5,5 };
	roomNames.push_back(temp2);
	teacherNames.push_back(temp);
	teacherHours.push_back(temp3);
	temp = { "Mr PE1","Miss PE2" };
	temp2 = { "Playground","Field" };
	temp3 = { 10,10 };
	roomNames.push_back(temp2);
	teacherNames.push_back(temp);
	teacherHours.push_back(temp3);
	temp = { "Mr PSHE1","Miss PSHE2" };
	temp2 = { "PS1","PS2" };
	temp3 = { 5,5 };
	roomNames.push_back(temp2);
	teacherNames.push_back(temp);
	teacherHours.push_back(temp3);


	for (int i = 0; i < 9; i++) {			//fill in the subjects for the years 7-9
		temp = { "English", "Maths","Science","Art" ,"ICT","Humanities","RE","French","Music","PE","PSHE" };
		subjectsTaken.push_back(temp);
	}
}
