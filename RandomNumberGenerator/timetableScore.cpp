#include "timetableScore.h"


timetableScore::timetableScore() {	//access timetableScore class using '::'
						//inital values can be set here
}

timetableScore::timetableScore(int score, std::vector<Timetable> timetableInfo) {
	newScore = score;
	newTimetable = timetableInfo;
}

timetableScore::~timetableScore() {

}

int timetableScore::getScore() const {
	return newScore;
}

std::vector<Timetable> timetableScore::getTimetable() const {
	return newTimetable;
}

void timetableScore::setScore(int a) {
	newScore = a;
}

void timetableScore::setTimetable(std::vector<Timetable> b) {
	newTimetable = b;
}


