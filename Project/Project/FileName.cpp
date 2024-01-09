#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Location.h"
#include "Event.h"
#include "Ticket.h"
int main() {
	
	ifstream data("bin.bin",ios::binary);
	ofstream bin("bin.bin",ios::binary);
	Event event;
	cin >> event;
	event.saveData(bin);
	bin.close();
	event.readData(data);
	data.close();
	cout << event;



}


