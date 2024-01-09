#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Location.h"
#include "Event.h"
#include "Ticket.h"
int main() {
	ofstream ticket_file("ticket.bin", ios::binary);
	Ticket ticket;
	SeasonPass pass;
	int ans = 0;
	cout << "   Welcome to the TICKETING APP! " << endl<<"  1) Buy a ticket or a season pass? (0 for ticket , 1 for season pass) ";
	cout << endl << "  2) Validate a ticket or pass (press 2 for validation) "<<endl<<" Type(0, 1 or 2) : ";
	cin >> ans;
	cout << endl;
	if (!ans ) {
		
		cin >> ticket;
		cout << endl;
		cout << "** Your ticket details : " << endl;
		cout << ticket;
		cout << endl;
		ticket.saveData(ticket_file);
		ticket_file.close();
		cout << " Ticket data saved at ticket.bin ";
	
	}
	if (ans==1) {
	
		cin >> pass;
		cout << endl;
		cout << "** Your pass details : " << endl;
		cout << pass;
		cout << endl;

	}
	if (ans == 2) {
		int ans2 = 0;
		cout << " Validate a ticket( press 1 ) or a pass (press 2): ";
		cin >> ans2;
		if (ans2 == 1) {
			char id[9];
			cout << endl << "  Insert ID: ";
			cin >> id;
			if (ticket.Valid(id))
				cout << " VALID ";
			else
				cout << " NOT VALID ";

		}
		if (ans2 == 2)
		{
			char id[9];
			cout << endl << "  Insert ID: ";
			cin >> id;
			if (pass.Valid(id))
				cout << " VALID ";
			else
				cout << " NOT VALID ";


		}
		}


}


