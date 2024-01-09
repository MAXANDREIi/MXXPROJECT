#pragma once
#include <iostream>
#include <string>
#include "Util.h"
#include <fstream>
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
	Event& operator=(const Event& other)
	{
		if (&other == this)
			throw exception();
		
			this->setEventName(string(other.name));
			this->setEventDate(other.date);
			this->setEventTime(other.time);
			return *this;
	}
	
	bool operator==(const Event& other) {
		return (this->name == other.name && this->date == other.date && this->time == other.time);
	}
	Event() {}

	Event(string name, const char* date,const char* time) {
		this->setEventDate(date);
		this->setEventTime(time);
		this->setEventName(name);
	}

	void saveData(ofstream& file) {
		if (!file.is_open()) {
			throw exception ("file not opened");
		}
		int nameSize = sizeof(this->name);
		int dateSize = strlen(this->date);
		int timeSize = strlen(this->time);
		file.write((char*)&nameSize, sizeof(int));
		file.write(this->name.c_str(),sizeof(char)*(strlen(this->name.c_str()) + 1));
		file.write((char*)&dateSize, sizeof(int));
		file.write(this->date, sizeof(char) * (strlen(this->date) + 1));
		file.write((char*)&timeSize, sizeof(int));
		file.write(this->time, sizeof(char) * (strlen(this->time) + 1));


	}

	void readData(ifstream& file) {

		if (!file.is_open())
		{
			throw exception("file not opened");
		}
		int nameSize = sizeof(this->name);
		int dateSize = strlen(this->date);
		int timeSize = strlen(this->time);
		file.read((char*)&nameSize, sizeof(int));
		file.read((char*)this->name.c_str(), sizeof(char) * (strlen(this->name.c_str()) + 1));
		file.read((char*)&dateSize, sizeof(int));
		file.read(this->date, sizeof(char) * (strlen(this->date) + 1));
		file.read((char*)&timeSize, sizeof(int));
		file.read(this->time, sizeof(char) * (strlen(this->time) + 1));
	}

	friend void operator<<(ostream& console, Event& event);
	friend void operator>>(istream& console, Event& event);

};

void operator<<(ostream& console, Event& event) {
	console << endl << "Name of event: " << event.getEventName();
	console << endl << "Event date: " << event.getEventDate();
	console << endl << "Time of the event: " << event.getEventTime();

}

void operator>>(istream& console, Event& event) {
	cout << "Event name is: "; 
	char buffer[2000];
	console.getline(buffer, 2000);
	console.clear();
	event.setEventName(buffer);
	cout<<endl << "Event date is: ";

	console.getline(buffer, 2000);
	console.clear();
	event.setEventDate(buffer);
	cout << endl << "Event time is: ";
	
	console.getline(buffer, 2000);
	console.clear();
	event.setEventTime(buffer);


}