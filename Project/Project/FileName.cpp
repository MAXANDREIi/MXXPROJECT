#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Location.h"
#include "Event.h"
#include "Ticket.h"
int main() {
	Ticket ticket;
	ifstream data("data.txt");
	data >> ticket;
	cout << endl << ticket;
}


