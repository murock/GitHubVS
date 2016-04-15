#include "mylib.h"
#include <time.h>
#include "TimetableGenerator.h"
#include <random>
#include <fstream>
#include <iterator>
#include <iostream>
#include "timetablescore.h"




void clearGlobals() {
	subjects.clear();
	hoursSubject.clear();
	groupNames.clear();
	groupSizes.clear();
	teacherNames.clear();
	teacherHours.clear();
	roomNames.clear();
	roomCapacitys.clear();
	subjectsTaken.clear();
	attachedTeachers.clear();
	timetables.clear();
	teacherPreference.clear();
}

void attachTeacherToGroup() {
	srand(time(0));		//seed for random number generation
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

struct periodsStruct
{
	std::vector<std::string> periods;
	std::vector<int> allocatedPeriods;
};

periodsStruct assignTimetable(std::vector<int>& allocatedPeriods, int totalHours, std::vector<std::vector<std::string>>& periodsArray, int groupCount, int subjectNum, std::vector<std::string>& currentGroupsTeachers, int teacherPosition, std::vector<std::string>& tempRoomNames, int roomNum) {
	std::vector<std::string> periods = periodsArray[groupCount];	//create periods vector from the periods array
	int Rnum = rand();
	int periodNum = (Rnum % totalHours);	//get a random Number between 0 and total timetabled hours
	std::vector<int>::iterator checkPeriod = std::find(allocatedPeriods.begin(), allocatedPeriods.end(), periodNum);	//check if selected period already allocated
	while (checkPeriod != allocatedPeriods.end()) {		//stay in this loop till a period is found which has not been allocated
		Rnum = rand();
		periodNum = (Rnum % totalHours);	//get a random Number between 0 and total timetabled hours
		checkPeriod = std::find(allocatedPeriods.begin(), allocatedPeriods.end(), periodNum);	//check if selected period already allocated
	}
	if (currentGroupsTeachers[teacherPosition] == "FreeTeacher") {
		periods[periodNum*3] = "Free";		//save the free subject to the periods vector
	}
	else {
		periods[periodNum*3] = subjects[subjectNum];		//save the subject to the periods vector
	}
	periods[(periodNum*3)+1] = currentGroupsTeachers[teacherPosition];	//save the teacher to the periods vector
	periods[(periodNum*3)+2] = tempRoomNames[roomNum];		//save the room number to periods vector
	allocatedPeriods.push_back(periodNum);				//save the selected periodNum to the allocated periods vector
	periodsStruct returnPeriods;
	returnPeriods.periods = periods;
	returnPeriods.allocatedPeriods = allocatedPeriods;
	return returnPeriods;
}

int checkMaxHoursReachedV2(std::vector<int>& tempHoursPerSubjectGroup, int groupCount) {	//check if the max hours have been reached for every subject for this group
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

std::vector<Timetable> generate() {
	std::vector<Timetable> returnTimetable;
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

	while (groupCount < groupNames.size()) {		// while there are still remaining groups without a timetable
		periodCount = 0;
		std::vector<int> allocatedPeriods;
		while (periodCount < totalHours) {		//while there are still unallocated periods
			int freePeriodFlag = 0;			//indicates weather the current period for the group is a free(1) or not(0)
			std::vector<std::string> subjectsTakenByCurrentGroup = subjectsTaken[groupCount]; //gets the subjects taken by the current group  

			std::vector<int> tempHoursPerSubjectGroup = hoursPerSubjectGroup[groupCount];					//create the tempHoursPerSubjectGroup  
			int subjectNum;
			int testTimetable = checkMaxHoursReachedV2(tempHoursPerSubjectGroup, groupCount);
			if (testTimetable == (subjects.size() + 1)) {
				freePeriodFlag = 1;
			}
			else {
				subjectNum = testTimetable;
			}
			//teacher selection
			std::vector<std::string> currentGroupsTeachers = attachedTeachers[groupCount];	//gets the current groups set of teachers
			std::vector<std::string>::iterator it = find(currentGroupsTeachers.begin(), currentGroupsTeachers.end(), subjects[subjectNum]);	//find the subject in the current groups teacher vector
			int teacherPosition = std::distance(currentGroupsTeachers.begin(), it);
			teacherPosition++;		//increment to teacher position
			//room selection
			int Rnum = rand();
			std::vector<std::string> tempRoomNames = roomNames[subjectNum];					//get all rooms for current subject
			int roomNum = (Rnum % tempRoomNames.size());									//get a random number between 0 and total number of rooms for current subject
			std::vector<int> tempRoomCapacitys = roomCapacitys[subjectNum];					//get all room capacitys for that subject
			while (tempRoomCapacitys[roomNum] < groupSizes[groupCount]) {					//while chosen rooms capacity is less than total num of students in group keep looking for new rooms
				Rnum = rand();
				roomNum = (Rnum % tempRoomNames.size());		//choose another room
			}

			if (freePeriodFlag == 0) {	// assign chosen subject 
				tempHoursPerSubjectGroup[subjectNum]++;										//increment the hour for that subject by 1
				hoursPerSubjectGroup.at(groupCount) = tempHoursPerSubjectGroup;		//save the updated vector to the hoursPerSubjectGroup vector
				periodsStruct tempPeriods = assignTimetable(allocatedPeriods, totalHours, periodsArray, groupCount, subjectNum, currentGroupsTeachers, teacherPosition, tempRoomNames, roomNum);		//assign the timetable to the global timetable variable and save the periodsArray in its current state
				periodsArray[groupCount] = tempPeriods.periods;
				allocatedPeriods = tempPeriods.allocatedPeriods;
			}
			else if (freePeriodFlag == 1) {				// assign free period
				std::vector<std::string> tempRoomNamesFree;
				tempRoomNamesFree.push_back("FreeRoom");
				roomNum = 0;
				std::vector<std::string> currentGroupsTeachersFree;
				currentGroupsTeachersFree.push_back("FreeTeacher");
				teacherPosition = 0;
				periodsStruct tempPeriods = assignTimetable(allocatedPeriods, totalHours, periodsArray, groupCount, subjectNum, currentGroupsTeachersFree, teacherPosition, tempRoomNames, roomNum);	//assign the timetable to the global timetable variable and save the periodsArray in its current state
				periodsArray[groupCount] = tempPeriods.periods;
				allocatedPeriods = tempPeriods.allocatedPeriods;
			}
			periodCount++;			//go to next period							
		}
		Timetable groupTimetable(groupNames[groupCount], periodsArray[groupCount]); //save the timetable for the group
		returnTimetable.push_back(groupTimetable);	// save the groups timetable to the timetable Chromosome 
		groupCount++;			//go to the next group
	}
	return returnTimetable;
}

int sumSubjectHours(int groupNum) {
	int totalHours = 0;
	std::vector<std::string> currentGroupsSubjects = subjectsTaken[groupNum];	//get all the subjects taken by the current group
	for (int j = 0; j < currentGroupsSubjects.size(); j++) {		//iterate through the subjects for that group
		std::vector<std::string>::iterator it;
		it = find(subjects.begin(), subjects.end(), currentGroupsSubjects[j]);	//find the current groups subject in the subjects global vector
		int subjectNum = std::distance(subjects.begin(), it);	// position of the subject
		totalHours = totalHours + hoursSubject[subjectNum];	//add subject hours to total hours
	}
	return totalHours;
}

int scoreTimetable(std::vector<Timetable>& currentTimetables) {		//lower score is better
	int totalHours = 25;		//total hours in the timetable
	int lunchPeriod = 4;		//the period after lunch
	int totalScore = 0;
	int groupCount = 0;
	for (std::vector<Timetable>::const_iterator iter = currentTimetables.begin(); iter != currentTimetables.end(); ++iter) {			//iterate through Timetables vector
		Timetable currentTimetable = *iter;	//select the current timetable
		std::vector<std::string> periods = currentTimetable.getPeriods();	//get the period information for that group
		int currentScore = 0;
		std::string lastPeriod = "set-up";
		int hoursPerDay = totalHours / 5;
		int periodDayCount = 0;
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

			if (periodDayCount == hoursPerDay)
				periodDayCount = 0;
			//check Two subsequent classes
			if ((subject != "Free") && (lastPeriod == subject)) {
				currentScore++;			//increase score if subsequent class
			}
			//check physically active lesson after lunch
			if ((subject == "PE") && (periodDayCount == lunchPeriod)) {
				currentScore++;		//increase score if PE after lunch
			}
			//check for empty timeslot between class
			if (periodDayCount != 0  && periodDayCount != (hoursPerDay - 1)) {		//check not first or last period in the day
				if (subject == "Free")	//check if current subject is free
					if ((lastPeriod != "Free") && (nextPeriod != "Free")) { //if both periods before and after the free are subjects then increase score
						currentScore++;
					}
			}
			//check free periods be put on the final day of the week
			if (sumSubjectHours(groupCount) < totalHours) {		//if the timetable has free periods
				if ((periodCount >= (totalHours - hoursPerDay)) && (periodCount < totalHours)) {	//if on final day of the week
					if (subject != "Free") {		//if not a free period increase score
						currentScore++;
					}
				}
			}			
			//Teacher preference 
			if (subject != "Free") {
				std::vector<std::string>::iterator it = find(subjects.begin(), subjects.end(), subject);	//find the subject in the subjects global vector
				int subjectNum = std::distance(subjects.begin(), it);	//return the position of the subject 
				std::vector<std::string> currentSubjectTeachers = teacherNames[subjectNum];	//get current subjects teachers
				it = find(currentSubjectTeachers.begin(), currentSubjectTeachers.end(), currentTeacher);	//find teacher in current subject teachers
				int teacherNum = std::distance(currentSubjectTeachers.begin(), it);	//return position of teacher
				std::vector<int> currentPrefTeaching = teacherPreference[subjectNum];	//get current preferred teaching hours
				if ((periodDayCount >= lunchPeriod) && (currentPrefTeaching[teacherNum] == 0)) {	//if its the afternoon and the teacher prefers teaching mornings then increment score
					currentScore++;
				}
				else if ((periodDayCount < lunchPeriod) && (currentPrefTeaching[teacherNum] == 1)) {	//if its the morning and the teacher prefers teaching afternoons then increment score
					currentScore++;
				}
			}
			lastPeriod = subject;
			periodDayCount++;
		}
		totalScore = totalScore + currentScore;	//add the current score to the total for the timetable
		groupCount++;
	}
	return totalScore;
}

int checkTimetable(std::vector<Timetable>& currentTimetables) {			//check all hours scheduled not too little or too many, no double bookings of rooms/teachers/groups, returns a score 0 if feasible
	std::vector<std::vector<int>> subjectHoursCheck;				// with subjects ordered how they were first typed in																//make the subjectHoursCheck vector the correct size
	for (int i = 0; i < groupNames.size(); i++) {		//iterates through the groupNames vector
		std::vector<int> temp;
		std::vector<std::string> subjectsTakenCurrentGroup = subjectsTaken[i];	//get the subjects taken by the current group
		for (int j = 0; j < subjectsTakenCurrentGroup.size(); j++) {	//iterate through subjects taken by current group vector
			temp.push_back(0);			//fill in 0's for as many subjects as the group has
		}
		subjectHoursCheck.push_back(temp);
	}
	int totalHours = 25;
	int periodCount = 0;
	int score= 0;
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
					score++;
				}
				currentGroupsSubjectHours[subjectNum]++;		//Add an addtional hour for that group for that subject
				subjectHoursCheck[groupCount] = currentGroupsSubjectHours;		//put into the 2d vector for all groups subject hours
			}
			groupCount++;
		}
		for (int duplicateSelect = 0; duplicateSelect < 2; duplicateSelect++) {
			std::vector<std::string> duplicateCheck;
			if (duplicateSelect == 0) {
				duplicateCheck = currentTeachers;
			}
			else if (duplicateSelect == 1)
				duplicateCheck = currentRooms;
			//duplicate teacher/room clash
			for (int i = 0; i < duplicateCheck.size(); i++) {
				int jPlus = i + 1;
				for (int j = jPlus; j < duplicateCheck.size(); j++) {
					if (duplicateCheck[i] == duplicateCheck[j]) {
						score++;
					}
				}
			}
		}
		periodCount++;
	}
	for (int i = 0; i < groupNames.size(); i++) {		//iterates through the groups vector
		std::vector<std::string> currentGroupsSubjects = subjectsTaken[i];	//get all the subjects taken by the current group
		for (int j = 0; j < currentGroupsSubjects.size(); j++) {		//iterate through the subjects for that group
			std::vector<std::string>::iterator it;
			it = find(subjects.begin(), subjects.end(), currentGroupsSubjects[j]);	//find the current groups subject in the subjects global vector
			int subjectNum = std::distance(subjects.begin(), it);	// position of the subject
			std::vector<int> currentGroupsSubjectHours = subjectHoursCheck[i];		//get the current hours taken for each subject for the current group
			if (currentGroupsSubjectHours[j] != hoursSubject[subjectNum]) {
				score++;
			}
		}
	}
	return score;
}

std::vector<Timetable> randomMutation(std::vector<Timetable>& currentTimetables,int numMutation) {
	for (int i = 0; i < numMutation; i++) {
		int Rnum = rand();
		int groupToSwap = (Rnum % groupNames.size());	//get a random number 0 the total number of groups
		Timetable currentTimetable = currentTimetables[groupToSwap];
		std::vector<std::string> periods = currentTimetable.getPeriods();	//get the period information for that group
		int totalHours = (periods.size() / 3);
		int period1ToSwap = (Rnum % totalHours);	//get a random number 0 the total hours in timetable
		Rnum = rand();
		int period2ToSwap = (Rnum % totalHours);	//get a random number 0 the total hours in timetable
		std::string currentTeacher1 = periods[(period1ToSwap * 3 + 1)];		//get current teacher for that period
		std::string currentRoom1 = periods[(period1ToSwap * 3 + 2)];		//get current room for that period
		std::string subject1 = periods[period1ToSwap * 3];			//get current subject
		std::string currentTeacher2 = periods[(period2ToSwap * 3 + 1)];		//get current teacher for that period
		std::string currentRoom2 = periods[(period2ToSwap * 3 + 2)];		//get current room for that period
		std::string subject2 = periods[period2ToSwap * 3];			//get current subject
		//swap period info
		periods[(period1ToSwap * 3 + 1)] = currentTeacher2;
		periods[(period1ToSwap * 3 + 2)] = currentRoom2;
		periods[(period1ToSwap * 3)] = subject2;
		periods[(period2ToSwap * 3 + 1)] = currentTeacher1;
		periods[(period2ToSwap * 3 + 2)] = currentRoom1;
		periods[(period2ToSwap * 3)] = subject1;
		currentTimetable.setPeriods(periods);
		currentTimetables[groupToSwap] = currentTimetable;
	}
	return currentTimetables;
}


timetableScore giveScore(std::vector<Timetable>& scoringTimetable) {
	timetableScore scoredTimetable;
	scoredTimetable.setTimetable(scoringTimetable);
	int a = scoreTimetable(scoringTimetable);
	int b = checkTimetable(scoringTimetable);
	int score = (a*0.25) + (b*2);	//value meeting hard constraints over soft constraints
	scoredTimetable.setScore(score);
	return scoredTimetable;
}
void printScore(std::vector<Timetable>& scoringTimetable) {
	int a = scoreTimetable(scoringTimetable);
	int b = checkTimetable(scoringTimetable);
	_RPT1(0, "%d Hard violations broken %d Soft violations broken\n", b, a);  //prints to output
}

int selectParent(std::vector<timetableScore>& population, int totalPopScore, int previousIterator) {
	int selectionIterator = 0;
	do  {
		selectionIterator = 0;
		int Rnum = rand();
		int selectionNum = (Rnum % totalPopScore);	//get a random number between 0 and total population score maximum score cannot exceed 32767
		std::vector<timetableScore>::const_iterator iter = population.begin();
		do  {
			timetableScore currentTimetables = *iter;
			int currentScore = currentTimetables.getScore();
			selectionNum = selectionNum - currentScore;
			selectionIterator++;
			iter++;
		} while (iter != population.end() && selectionNum > 0);
	} while (previousIterator + 1 == selectionIterator);	//if same parent is picked loop again
	return selectionIterator - 1; //as the loop increments 1 too many times
}

std::vector<timetableScore> optimiseTimetable(int generations, std::vector<timetableScore>& population, bool initialPopCheck, int popSize, int elitism, int culling, int mutation) {
	if (initialPopCheck == 1) {
		for (int i = 0; i < popSize; i++) {
			_RPT1(0, "population size is %d\n", i);  //prints to output
			std::vector<Timetable> tempTimetables = generate();
			population.push_back(giveScore(tempTimetables));
		}
	}
	std::ofstream totalscore_file("totalscores.txt");	//create a text file to contain total scores each generation
	std::ofstream bestscore_file("bestscores.txt");	//create a text file to contain best scores each generation
	int memberCount = 0;
	auto engine = std::default_random_engine{};
	for (int i = 0; i < generations; i++) {
		_RPT1(0, "Generation count is %d\n", i);  //prints to output
		std::sort(population.begin(), population.end());
		population.erase(population.begin() + popSize, population.end());	//delete the extra members of the population
		int totalPopScore = 0;
		memberCount = 0;
		//loop below used to get the total score for parent selection
		for (std::vector<timetableScore>::const_iterator iter = population.begin(); iter != population.end(); ++iter) {
			timetableScore currentMember = *iter;
			int x = currentMember.getScore();
			_RPT1(0, "Member %d's score is %d\n", memberCount, x);  //prints to output
			memberCount++;
			totalPopScore = totalPopScore + x;
		}
		_RPT1(0, "Total populationScore is %d\n", totalPopScore);  //prints to output
		totalscore_file << totalPopScore;
		totalscore_file << std::endl;
		bestscore_file << population[0].getScore();
		bestscore_file << std::endl;



		std::vector<timetableScore> childPopulation;	//create population of children
		for (int i = 0; i < elitism; i++) {
			childPopulation.push_back(population[i]);	//save best solution
		}
		while (childPopulation.size() < population.size() + culling) {
			int parent1Iterator = selectParent(population, totalPopScore, population.size() + 2);
			int selectParent1 = popSize - parent1Iterator - 1;		//population size - iterator as a lower score is better 
			int parent2Iterator = selectParent(population, totalPopScore, parent1Iterator);
			int selectParent2 = popSize - parent2Iterator - 1;		//population size - iterator as a lower score is better 
			timetableScore parent1 = population[selectParent1];
			std::vector<Timetable> parent1Timetables = parent1.getTimetable();
			timetableScore parent2 = population[selectParent2];
			std::vector<Timetable> parent2Timetables = parent2.getTimetable();
			std::vector<Timetable> child1;
			std::vector<Timetable> child2;
			int Rnum = rand();
			int crossoverPoint = (Rnum % groupNames.size() + 1);		//get a random number between 1 and total number of groups
			for (int k = 0; k < crossoverPoint; k++) {		//first half of the chromosomes
				child1.push_back(parent1Timetables[k]);
				child2.push_back(parent2Timetables[k]);
			}
			for (int k = crossoverPoint; k < groupNames.size(); k++) {	//second half of chromosomes
				child2.push_back(parent1Timetables[k]);
				child1.push_back(parent2Timetables[k]);
			}
			int numMutation = (Rnum % mutation + 1);		//get a random number between 1 and maximum number of mutations
			child1 = randomMutation(child1,numMutation);
			Rnum = rand();
			numMutation = (Rnum % mutation + 1 );		//get a random number between 1 and maximum number of mutations
			child2 = randomMutation(child2,numMutation);
			childPopulation.push_back(giveScore(child1));
			childPopulation.push_back(giveScore(child2));

		}
		population = childPopulation;
	}
	std::sort(population.begin(), population.end());
	timetables = population[0].getTimetable();
	printScore(timetables);
	return population;
}


void SaveTimetable() {

	std::ofstream output_file("savedTimetables.txt");
	std::ostream_iterator<std::string> output_iterator(output_file, ",");
	for (std::vector<Timetable>::const_iterator iter = timetables.begin(); iter != timetables.end(); ++iter) {
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
		timetables.push_back(currentTimetable);	//save timetable to global timetables vector
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
		Timetable currentTimetable = timetables[i];	//get the current timetable
		currentTimetable.setPeriods(periods); //give the periods information to the timetable object
		timetables[i] = currentTimetable;	//save to global timetable vector
	}
}
void loadConfig() {
	std::ifstream infile("config.txt");
	int hashCount = 0;
	int readLineCount = 0;
	bool inputHalf = 0;		//used to determine which half of the inputs you are on
	for (int i = 0; infile; i++) {
		std::vector<std::string> vectorString;
		std::vector<int> vectorInt;
		std::string s;
		if (!getline(infile, s)) break;
		if (s[0] == '#')
			hashCount++;
		else {
			if (((readLineCount % 2 != 0) && (hashCount < 6) && (hashCount != 5))||((hashCount == 5) && (readLineCount == 0 || readLineCount == 1|| readLineCount == 3))) {	//if line count is odd and hashcount is 5 or below read ints OR if in subjectinfo section read ints if line count is 1,2 or 4
				std::istringstream ss(s);
				while (ss)
				{
					std::string s;
					if (!getline(ss, s, ',')) break;
					int tempNum;
					std::istringstream convert(s);
					convert >> tempNum;		//make the string an int
					vectorInt.push_back(tempNum);
				}
				readLineCount++;
			}
			else {					// if line count is even read strings
				std::istringstream ss(s);
				while (ss)
				{
					std::string s;
					if (!getline(ss, s, ',')) break;
					vectorString.push_back(s);
				}
				readLineCount++;
			}
			if (hashCount == 5) {//if on subject information section of config
				if (readLineCount == 5)
					readLineCount = 0;
			}
			if (hashCount == 1)
				subjects = vectorString;
			else if (hashCount == 2)
				hoursSubject = vectorInt;
			else if (hashCount == 3)
				groupNames = vectorString;
			else if (hashCount == 4)
				groupSizes = vectorInt;
			else if (hashCount == 5) {
				if (readLineCount == 0) {
					teacherNames.push_back(vectorString);
				}
				else if (readLineCount == 1) {
					teacherHours.push_back(vectorInt);
				}
				else if (readLineCount == 2){
					teacherPreference.push_back(vectorInt);
				}
				else if (readLineCount == 3) {
					roomNames.push_back(vectorString);
				}
				else if (readLineCount == 4) {
					roomCapacitys.push_back(vectorInt);
				}
			}
			else {				//else fill in subject choices
				subjectsTaken.push_back(vectorString);
			}
		}
	}
}
