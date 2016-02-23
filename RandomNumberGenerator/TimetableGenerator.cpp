#include "mylib.h"
#include <time.h>
#include "TimetableGenerator.h"

void AttachTeachertoGroup() {
	int groupCount = 0;
	int subjectCount = 0;
	srand(time(0));


	while (groupCount < groupNames.size()) {
		std::vector<std::string> subjectsTakenByCurrentGroup = subjectsTaken[groupCount]; //gets the subjects taken by the current group
		std::vector<std::string> teachersForGroup;
		while (subjectCount < subjectsTakenByCurrentGroup.size()) {

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
			subjectCount++;
		}
		subjectCount = 0;
		attachedTeachers.push_back(teachersForGroup);				//put in all the teachers assigned to that group into the attached teachers vector
		groupCount++;
	}

}


std::vector<std::string> AssignTimetable(int periodCount,std::vector<std::vector<std::string>> periodsArray, int groupCount, int subjectNum, std::vector<std::string> currentGroupsTeachers, int teacherPosition, std::vector<std::string> tempRoomNames, int roomNum) {
	_RPT1(0, "Period: %d Group: %s Subject: %s Teacher: %s Room: %s\n", periodCount, groupNames[groupCount].c_str(), subjects[subjectNum].c_str(), currentGroupsTeachers[teacherPosition].c_str(), tempRoomNames[roomNum].c_str());  //prints to output
	std::vector<std::string> periods = periodsArray[groupCount];	//create periods vector from the periods array
	periods.push_back(subjects[subjectNum]);		//save the subject to the periods vector
	periods.push_back(currentGroupsTeachers[teacherPosition]);	//save the teacher to the periods vector
	periods.push_back(tempRoomNames[roomNum]);		//save the room number to periods vector
	Timetable tempTimetable(groupNames[groupCount], periods);									
	Timetables[groupCount] = tempTimetable;
	return periods;
}


bool checkMaxHoursReached(std::vector<int> tempHoursPerSubjectGroup, int groupCount, std::vector<std::string> currentTeachers) {	//check if the max hours have been reached for every subject for this group

	std::vector<std::string> subjectsTakenByGroup = subjectsTaken[groupCount];	//get the subjects taken by the group

	int maxHoursReached = 0;		//counts how many subjects have the max hours reached

	for (std::vector<std::string>::const_iterator iter = subjectsTakenByGroup.begin(); iter != subjectsTakenByGroup.end(); ++iter) {		//iterates through the subjects taken by the group
		std::vector<std::string>::iterator it;
		it = find(subjects.begin(), subjects.end(), *iter);	//find the subject in the subjects global vector
		int subjectNum = std::distance(subjects.begin(), it);	//return the position of the subject

		std::vector<std::string> currentGroupsTeachers = attachedTeachers[groupCount];	//gets the current groups set of teachers

		it = find(currentGroupsTeachers.begin(), currentGroupsTeachers.end(), subjects[subjectNum]);	//find the subject in the current groups teacher vector
		int teacherPosition = std::distance(currentGroupsTeachers.begin(), it);
		teacherPosition++;		//increment to teacher position


		if (hoursSubject[subjectNum] == tempHoursPerSubjectGroup[subjectNum]) 		//check if max hours are reached for this subject
			maxHoursReached++;
		else if (std::find(currentTeachers.begin(), currentTeachers.end(), currentGroupsTeachers[teacherPosition]) != currentTeachers.end()) {	//check if teacher is busy for that period
		//	_RPT0(0, "Teacher busy for that period\n");  //prints to output
			maxHoursReached++;
		}

		

	}
	if (maxHoursReached == subjectsTakenByGroup.size())				//if the max hours for all subjects is reached
		return 1;
	else
		return 0;

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

	/*
	std::vector<std::vector<int>> subjectHoursCheck;				// with subjects ordered how they were first typed in
																	//make the subjectHoursCheck vector the correct size
	for (int i = 0; i < groupNames.size(); i++) {		//iterates through the groupNames vector
		std::vector<int> temp;
		std::vector<std::string> subjectsTakenCurrentGroup = subjectsTaken[i];
		for (int j = 0; j < subjectsTakenCurrentGroup.size(); j++) {	//iterate through subjects vector
			temp.push_back(0);
		}
		subjectHoursCheck.push_back(temp);
	}*/

	while (periodCount < totalHours) {		//while there are still unallocated periods
		std::vector<std::string> currentTeachers;	//store the teachers who are teaching this period already
		std::vector<std::string> currentRooms;	//store the Rooms that are in use for this period already
		groupCount = 0;


		int iterationCount = 0;			//counts the number of times the randomely selected subject max hours were reached
		while (groupCount < groupNames.size()) {		// while there are still remaining groups without a timetable
			int freePeriodFlag = 0;			//indicates weather the current period for the group is a free or not

			std::vector<std::string> subjectsTakenByCurrentGroup = subjectsTaken[groupCount]; //gets the subjects taken by the current group   

			int Rnum = rand();
			int rSubjectNum = (Rnum % subjectsTakenByCurrentGroup.size());											//get a random number between  0 and the total number of (subjects-1) for that group

			std::vector<std::string>::iterator it;
			it = find(subjects.begin(), subjects.end(), subjectsTakenByCurrentGroup[rSubjectNum]);	//find the subject in the subjects global vector
			int subjectNum = std::distance(subjects.begin(), it);	//return the position of the subject


			std::vector<std::string> currentGroupsTeachers = attachedTeachers[groupCount];	//gets the current groups set of teachers


			it = find(currentGroupsTeachers.begin(), currentGroupsTeachers.end(), subjects[subjectNum]);	//find the subject in the current groups teacher vector
			int teacherPosition = std::distance(currentGroupsTeachers.begin(), it);
			teacherPosition++;		//increment to teacher position




			if (std::find(currentTeachers.begin(), currentTeachers.end(), currentGroupsTeachers[teacherPosition]) == currentTeachers.end()) {			//if the current teacher is busy then choose a new subject for the group for this period
				currentTeachers.push_back(currentGroupsTeachers[teacherPosition]);								//put the current teacher into the currentteachers vector for this period
				std::vector<int> tempHoursPerSubjectGroup = hoursPerSubjectGroup[groupCount];					//create the tempHoursPerSubjectGroup 

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
		//		std::vector<int> currentGroupsSubjectHours = subjectHoursCheck[groupCount];		//get the current hours taken for each subject for the current group
		//		int hoursCurrentSubject = currentGroupsSubjectHours[rSubjectNum];			//get the current hours taken for that subject 
			//	_RPT0(0, "1\n");  //prints to output
				if (checkMaxHoursReached(tempHoursPerSubjectGroup, groupCount, currentTeachers)) {
					//_RPT0(0, "setting flag\n");  //prints to output
					freePeriodFlag = 1;
				}
				//_RPT1(0, "free period flag is %d hoursSubject is %d temp hours is %d the subject is %s \n", freePeriodFlag, hoursSubject[subjectNum],tempHoursPerSubjectGroup[subjectNum], subjects[subjectNum].c_str());  //prints to output

				

				if ((hoursSubject[subjectNum] > tempHoursPerSubjectGroup[subjectNum]) && (freePeriodFlag == 0)) {	//if max number of hours for that subject for that class is met then choose a new subject. Or if subjects for that class exhausted then give them a free period
					iterationCount = 0;
					tempHoursPerSubjectGroup[subjectNum]++;										//increment the hour for that subject by 1
					hoursPerSubjectGroup.at(groupCount) = tempHoursPerSubjectGroup;		//save the updated vector to the hoursPerSubjectGroup vector






					currentRooms.push_back(tempRoomNames[roomNum]);			//save the selected room to the current rooms for that period vector
					periodsArray[groupCount] = AssignTimetable(periodCount, periodsArray, groupCount, subjectNum, currentGroupsTeachers, teacherPosition, tempRoomNames, roomNum);		//assign the timetable to the global timetable variable and save the periodsArray in its current state

					groupCount++;			//go to the next group

				}
				else if (freePeriodFlag == 1) {				//WOULD BE BETTER IF THIS CHECKED IF ALL SUBJECT HOURS WERE EXHAUSTED, assign free period
					subjectNum = 10;		//make the subjectNum point to "Free"
					currentRooms.push_back(tempRoomNames[roomNum]);			//save the selected room to the current rooms for that period vector
					periodsArray[groupCount] = AssignTimetable(periodCount,periodsArray, groupCount, subjectNum, currentGroupsTeachers, teacherPosition, tempRoomNames, roomNum);	//assign the timetable to the global timetable variable and save the periodsArray in its current state

					groupCount++;			//go to the next group

				}
				else {
					iterationCount++;
					currentTeachers.pop_back();
				}


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


void checkTimetable() {			//check all hours scheduled not too little or too many(NEED TO DO THIS ONLYY CHECK FOR TOO MANY HOURS), no double bookings of rooms/teachers/groups,

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
			currentTeachers.push_back(currentTeacher);
		
			std::string currentRoom = periods[(periodCount * 3 + 2)];		//get current room for that period
			currentRooms.push_back(currentRoom);
		
			std::string subject = periods[periodCount * 3];			//get current subject

			std::string freeCheck = "Free";
			if (subject != freeCheck)  {		// if its not a free period then check the subject hours 


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
				}


				currentGroupsSubjectHours[subjectNum]++;		//Add an addtional hour for that group for that subject
				subjectHoursCheck[groupCount] = currentGroupsSubjectHours;		//put into the 2d vector for all groups subject hours
			}

			groupCount++;
		}






		if (!checkDuplicates(currentTeachers)) {
			_RPT0(0, "Timetable not feasible, Duplicate teachers in same period\n");  //prints to output
			feasible = 1;
		}


		if (!checkDuplicates(currentRooms)) {
			_RPT0(0, "Timetable not feasible, Duplicate rooms in same period\n");  //prints to output
			feasible = 1;
		}
		



		periodCount++;
	}

;

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
			}

		}


	}


	if (feasible == 0)
		_RPT0(0, "Timetable is feasible\n");  //prints to output
	else
		_RPT0(0, "Timetable is infeasible\n");  //prints to output
}

void DefaultValues() {
	 subjects = { "Maths", "English", "French","Geography","PE","I.C.T","Economics","Science","History","Art","Free" };	//subject names



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
	 temp2 = { "E1","E2","E3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr French1","Miss French2", "Dr French3" };
	 temp2 = { "F1","F2","F3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr Geography1","Miss Geography2", "Dr Geography3" };
	 temp2 = { "G1","G2","G3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr PE1","Miss PE2", "Dr PE3" };
	 temp2 = { "P1","P2","P3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr ICT1","Miss ICT2", "Dr ICT3" };
	 temp2 = { "I1","I2","I3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr Eco1","Miss Eco2", "Dr Eco3" };
	 temp2 = { "Ec1","Ec2","Ec3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr Sci1","Miss Sci2", "Dr Sci3" };
	 temp2 = { "S1","S2","S3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr Hist1","Miss Hist2", "Dr Hist3" };
	 temp2 = { "H1","H2","H3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);
	 temp = { "Mr Art1","Miss Art2", "Dr Art3" };
	 temp2 = { "A1","A2","A3" };
	 roomNames.push_back(temp2);
	 teacherNames.push_back(temp);

	 temp = {"Maths","English","Economics","PE"};
	 subjectsTaken.push_back(temp);
	 temp = {"Science","English","History"};
	 subjectsTaken.push_back(temp);
	 temp = { "Geography","Maths","History","Art" };
	 subjectsTaken.push_back(temp);
	 temp = { "French","Science","History","PE" };
	 subjectsTaken.push_back(temp);
}