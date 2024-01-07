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
	

public:

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
	
	}
	~Location() {
		delete[] this->venueName;
	}
	bool operator==(const Location& other)
	{
		return (this->cityName == other.cityName &&
			    (this->venueName == nullptr && other.venueName == nullptr ||
				(this->venueName != nullptr && other.venueName != nullptr && 
				strcmp(this->venueName, other.venueName) == 0)) &&
			     this->capacity == other.capacity );
	}
	bool operator!=(const Location& location) {
		return !(*this==location);
	}
	Location() {}
	friend void operator<<(ostream& console, Location& location);
	friend void operator>>(istream& console, Location& location);
};
void operator>>(istream& console,  Location& location) {
	cout << endl << " Choose City :";
	char buffer[2000];
	console.getline(buffer, 2000);
	console.clear();
	location.setCityName(buffer);
	cout << endl << " Venue name : ";
	console.getline(buffer, 2000);
	console.clear();
	location.setVenueName(buffer);
	
	cout << endl << " Choose the capacity: ";
	console>>location.capacity;
	console.getline(buffer, 2000);
	console.clear();
	

}
void operator<<(ostream& console, Location& location) {
	cout << endl << " City :"; console << location.getCityName();
	cout << endl << "Venue name:"; console << location.getVenueName();
	cout << endl << "Capacity: "; console << location.getCapacity();
	
}

