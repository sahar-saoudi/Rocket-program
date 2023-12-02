
#include <iostream>

#include "rocket.h"

Rocket::Rocket() // constructor
{
    floors_number = 1;
    engine_height = 2;
    triangle_height = 4;
    floor_width = 4;
    floor_height = 3;
    rocket_state = false;
}

Rocket::Rocket(int n) // constructor
{
    floors_number = n;
    if (floors_number < 1) {
        cerr << "nombre minimale d'etages doit etre 1" << endl;
        floors_number = 1;
    }
    engine_height = 2;
    triangle_height = 4;
    floor_width = 4;
    floor_height = 3;
    rocket_state = false;
}

void Rocket::showengine(std::ostream& out) const // shows the engine
{
    for (int i = 0; i < engine_height; i++) {
        for (int j = 0; j < engine_height - i - 1; j++) {
            cout << ' ';
        }
        cout << ' ';
        cout << '/';
        for (int k = -1; k < 2 * i + 1; k++) {
            if (rocket_state == true) {
                cout << 'W';
            }
            else {
                cout << ' ';
            }
        }
        cout << '\\' << endl;
    }
}

void Rocket::showtriangle(std::ostream& out) const // shows the triangle
{
    for (int i = 0; i < triangle_height; i++) {
        for (int j = 0; j < triangle_height - i - 1; j++) {
            cout << ' ';
        }
        cout << '/';
        for (int k = 1; k < 2 * i + 1; k++) {
            if (i == triangle_height - 1) {
                cout << '_';
            }
            else {
                cout << ' ';
            }
        }
        cout << '\\' << endl;
    }
}

void Rocket::showfloors(std::ostream& out) const // shows the floors
{

    for (int e = 0; e < floors_number; e++) {
        for (int i = 0; i < floor_height - 1; i++) {
            cout << "|";
            for (int s = 0; s < 2 * floor_width - 2; s++) {
                cout << ' ';
            }
            cout << "|" << endl;
        }
        cout << '|';
        for (int m = 0; m < 2 * floor_width - 2; m++) {
            cout << '_';
        }
        cout << '|' << endl;
    }
}

ostream& operator<<(ostream& out, const Rocket& f) {
    // triangle
    f.showtriangle(out);
    // floors
    f.showfloors(out);
    // engine
    f.showengine(out);

    return out;
};

float Rocket::width(float l) {
    floor_width = l;
    if (floor_width < 4) {
        cerr << " la largeur de l'etage doit etre minimum 4" << endl;
        floor_width = 4;
    }
    triangle_height = floor_width;
    engine_height = floor_width - 2;
    return floor_width, triangle_height, engine_height;
}

float Rocket::height(float h) {
    floor_height = h;
    if (floor_height < 3) {
        cerr << " l'hauteur de l'etage doit etre minimum 3" << endl;
        floor_height = 3;
    }
    return floor_height;
}

bool Rocket::ignite() {
    rocket_state = true;
    return rocket_state;
}
