#pragma once
#include <iostream>
#include <string>
using namespace std;

class Location {
private:
	string cityName = "";
	char* venueName = nullptr;
	int capacity = 0;
	static int const MAX_CAPACITY = 4000;
	int zones = 0;

public:
	void setZone(int zones)
	{
		if (zones < 1)
			throw exception("Put more zones");
		this->zones = zones;
	}
	int getZones() {
		return zones;
	}
	void setCapacity(int capacity)
	{
		if (capacity > MAX_CAPACITY)
			throw exception("Capacity too high!");
		this->capacity = capacity;
	}
	int getCapacity() {
		return capacity;
	}
	void setCityName(string cityName) {
		if (cityName.size() <= 1 || cityName[0] < 'A' || cityName[0]>'Z')
			throw exception("Invalid");
		this->cityName = cityName;

	}
	string getCityName() {
		return cityName;
	}
	void setVenueName(const char* venueName) {
		if (strlen(venueName) <= 1 || venueName[0] < 'A' || venueName[0]>'Z')
			throw exception("Invalid");
		delete[] this->venueName;
		this->venueName = new char[strlen(venueName) + 1];
		strcpy_s(this->venueName, strlen(venueName) + 1, venueName);

	}
	char* getVenueName() {
		if (venueName == nullptr)
			throw exception();
		char* copy = new char[strlen(this->venueName) + 1];
		strcpy_s(copy, strlen(this->venueName) + 1, this->venueName);
		return copy;
	}
	Location(string cityName, char* venueName, int capacity, int zones) {
		this->setCapacity(capacity);
		this->setCityName(cityName);
		this->setVenueName(venueName);
		this->setZone(zones);
	}
	Location() {}
};

