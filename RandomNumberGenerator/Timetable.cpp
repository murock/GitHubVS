#include "Timetable.h"

Timetable::Timetable() {	//access Timetable class using '::'
						//set null values strings are already set in the string header file
}

Timetable::Timetable(std::string group, std::vector<std::string> periods) {
	 newGroup = group;
	 newPeriods = periods;			//with subject then teacher then room
}

Timetable::~Timetable() {

}
