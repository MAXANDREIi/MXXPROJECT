#include <iostream>
using namespace std;
#include "Header.h"
int main() {
	Location location;
	location.setCityName("Bucuresti");
	location.setVenueName("Parcul Cismigiu");
	cout<<location.getCityName();
	cout << endl;
	cout<<location.getVenueName();



	return 0;
}