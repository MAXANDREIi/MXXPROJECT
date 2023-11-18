#include <iostream>
using namespace std;
#include "Location.h"
#include "Event.h"
#include "Ticket.h"
int main() {
	Ticket ticket;
	cout << ticket.getTicketID()<<endl;
	Ticket ticket2(200,TicketType::LAWN);
	cout << ticket2.getTicketPrice()<<endl<<ticket2.getTicketType();
	return 0;
}