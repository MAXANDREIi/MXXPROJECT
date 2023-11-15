#pragma once
#include <iostream>
#include <string>
using namespace std;

class Location {
private:
	string cityName = "";
	char* venueName = nullptr;

public:
	void setCityName(string cityName) {
		if (cityName.size() <= 1)
			throw exception("Name too short");
		this->cityName = cityName;

	}
	string getCityName() {
		return cityName;
	}
	void setVenueName(const char* venueName) {
		if (strlen(venueName) <= 1)
			throw exception("Name too short");
		delete[] this->venueName;
		this->venueName = new char[strlen(venueName) + 1];
		strcpy_s(this->venueName, strlen(venueName) + 1, venueName);

	}
	 char* getVenueName() {
		char* copy = new char[strlen(this->venueName) + 1];
		strcpy_s(copy, strlen(this->venueName) + 1, this->venueName);
		return copy;
	}

};


class Event {
	string eventName = "";


};
