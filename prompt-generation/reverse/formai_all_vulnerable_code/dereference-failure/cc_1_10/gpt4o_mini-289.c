//GPT-4o-mini DATASET v1.0 Category: Simulation of the Solar System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define NUM_PLANETS 8

typedef struct {
    char name[20];
    double distance_from_sun; // in million km
    double orbital_period; // in Earth years
    double current_angle; // in degrees
    double orbital_speed; // degrees per year
} Planet;

void initialize_planets(Planet planets[]) {
    // Sun is not a planet, but included for the sake of structure
    sprintf(planets[0].name, "Sun");
    planets[0].distance_from_sun = 0.0;
    planets[0].orbital_period = 0.0;
    planets[0].current_angle = 0.0;
    planets[0].orbital_speed = 0.0;

    sprintf(planets[1].name, "Mercury");
    planets[1].distance_from_sun = 57.91;
    planets[1].orbital_period = 0.241;
    planets[1].orbital_speed = 149.6 / planets[1].orbital_period; // arbitrary units
    
    sprintf(planets[2].name, "Venus");
    planets[2].distance_from_sun = 108.21;
    planets[2].orbital_period = 0.615;
    planets[2].orbital_speed = 149.6 / planets[2].orbital_period;

    sprintf(planets[3].name, "Earth");
    planets[3].distance_from_sun = 149.6;
    planets[3].orbital_period = 1.0;
    planets[3].orbital_speed = 149.6 / planets[3].orbital_period;
    
    sprintf(planets[4].name, "Mars");
    planets[4].distance_from_sun = 227.92;
    planets[4].orbital_period = 1.881;
    planets[4].orbital_speed = 149.6 / planets[4].orbital_period;

    sprintf(planets[5].name, "Jupiter");
    planets[5].distance_from_sun = 778.57;
    planets[5].orbital_period = 11.86;
    planets[5].orbital_speed = 149.6 / planets[5].orbital_period;

    sprintf(planets[6].name, "Saturn");
    planets[6].distance_from_sun = 1433.5;
    planets[6].orbital_period = 29.46;
    planets[6].orbital_speed = 149.6 / planets[6].orbital_period;

    sprintf(planets[7].name, "Uranus");
    planets[7].distance_from_sun = 2872.5;
    planets[7].orbital_period = 84.01;
    planets[7].orbital_speed = 149.6 / planets[7].orbital_period;

    // Neptune is last
    sprintf(planets[8].name, "Neptune");
    planets[8].distance_from_sun = 4497.1;
    planets[8].orbital_period = 164.8;
    planets[8].orbital_speed = 149.6 / planets[8].orbital_period;
}

void update_orbits(Planet planets[]) {
    for (int i = 1; i < NUM_PLANETS; i++) {
        planets[i].current_angle += planets[i].orbital_speed;
        if (planets[i].current_angle >= 360.0) {
            planets[i].current_angle -= 360.0;
        }
    }
}

void draw_planets(const Planet planets[]) {
    system("clear");  // Clear the terminal
    
    for (int i = 1; i < NUM_PLANETS; i++) {
        printf("%s: Distance from Sun: %.2f million km, Angle: %.2f degrees\n",
               planets[i].name,
               planets[i].distance_from_sun,
               planets[i].current_angle);
    }
    usleep(500000); // Sleep for a short duration (0.5 seconds)
}

int main() {
    Planet planets[NUM_PLANETS];
    initialize_planets(planets);

    while (1) {
        update_orbits(planets);
        draw_planets(planets);
    }

    return 0;
}