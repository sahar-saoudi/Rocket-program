#include <iostream>

#include "rocket.h"

using namespace std;

int main() {
	Rocket f(2);

	cout << "small rocket :" << endl;
	cout << f << endl;

	f.width(12);
	f.height(6);

	cout << "big rocket :" << endl;
	cout << f << endl;

	f.ignite();

	cout << "big, ignited rocket :" << endl;
	cout << f << endl;

	return 0;
}
