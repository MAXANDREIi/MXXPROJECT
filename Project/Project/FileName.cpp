#include <iostream>
using namespace std;
#include "Location.h"
#include "Event.h"
#include "Ticket.h"
int main() {
	Ticket ticket;
	cout << ticket.getTicketID()<<endl;
	Ticket ticket2;
	cout << ticket2.getTicketID();
	return 0;
}