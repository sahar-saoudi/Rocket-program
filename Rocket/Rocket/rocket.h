#ifndef _ROCKET_H_
#define _ROCKET_H_

#include <iostream>

using namespace std;

class Rocket {
	float engine_height;
	float triangle_height;
	float floor_width;
	float floor_height;
	bool rocket_state;

	int floors_number;

	void showengine(std::ostream&) const;   // shows the engine
	void showtriangle(std::ostream&) const; // shows the top of the rocket
	void showfloors(std::ostream&) const;   // shows the floors

public:
	Rocket();
	Rocket(int);
	float width(float);  // modifies the width of the floors
	float height(float); // modifies the height of the floors
	bool ignite();       // ignited the rocket

	friend ostream& operator<<(ostream& out, const Rocket& f1);
};

#endif
