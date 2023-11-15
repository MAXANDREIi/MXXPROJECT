#pragma once
#include <iostream>
#include <string>
#include "Util.h"
using namespace std;

class Event {
private: 
	string name = "";
	char date[11]="";
	char time[6]="";

public:
	void setEventName(string name) {
		if (name.size() <= 1)
			throw exception("Name too short");
		this->name = name;
	}
	string getEventName() {
		return name;
	}
	void setEventDate(const char* date) {
		if (strlen(date) != 10 || date[2]!='/' || date[5]!='/')
			throw exception("Invalid date");
		strcpy_s(this->date, strlen(date) + 1, date);
	}
	char* getEventDate() {
		return Util::copyString(this->date);
	}
	void setEventTime(const char* time) {
		if (strlen(time) != 5 || time[2] != ':')
			throw exception("Invalid time");
		strcpy_s(this->time, strlen(time) + 1, time);
	}
	char* getEventTime() {
		return Util::copyString(this->time);
	}


	Event() {}

	Event(string name, const char* date,const char* time) {
		this->setEventDate(date);
		this->setEventTime(time);
		this->setEventName(name);
	}
};