//MISTRAL-7B DATASET v1.0 Category: Simulation of the Solar System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
    double mass;
    char name[20];
} Planet;

double G = 6.67430e-11; // Gravitational constant

void solar_system_simulation(int num_planets, double time_step, double days_to_simulate) {
    Planet *planets = malloc(num_planets * sizeof(Planet));
    double total_mass = 0;

    for (int i = 0; i < num_planets; i++) {
        sprintf(planets[i].name, "Planet %d", i + 1);
        planets[i].mass = 5.972e24 * pow(1.01, i); // Mass of each planet in kg, assuming Mercury's mass is 5.972e24 kg and each subsequent planet is 1% heavier
        total_mass += planets[i].mass;
        planets[i].x = (i + 0.5) * 1.496e11; // Initial x position in meters, assuming planets are evenly spaced
        planets[i].y = 0;

        printf("Initial state of %s:\nx = %.2e m\ny = %.2e m\n", planets[i].name, planets[i].x, planets[i].y);
    }

    double current_time = 0;
    double current_day = 0;

    while (current_day <= days_to_simulate) {
        for (int i = 0; i < num_planets; i++) {
            double x_diff = planets[(i + 1) % num_planets].x - planets[i].x;
            double y_diff = planets[(i + 1) % num_planets].y - planets[i].y;
            double distance = sqrt(x_diff * x_diff + y_diff * y_diff);
            double force = G * planets[i].mass * (planets[(i + 1) % num_planets].mass / distance);
            double accel_x = (x_diff / distance) * force / planets[i].mass;
            double accel_y = (y_diff / distance) * force / planets[i].mass;

            planets[i].x += time_step * accel_x;
            planets[i].y += time_step * accel_y;

            current_day += time_step / (2 * M_PI * sqrt(total_mass / (4 * M_PI * M_PI * 6.67430e-11)));

            printf("%s position after %.2f days:\nx = %.2e m\ny = %.2e m\n", planets[i].name, current_day, planets[i].x, planets[i].y);
        }
    }

    free(planets);
}

int main() {
    int num_planets = 5;
    double time_step = 86400; // One day in seconds
    double days_to_simulate = 365 * 5; // Five years

    solar_system_simulation(num_planets, time_step, days_to_simulate);

    return 0;
}