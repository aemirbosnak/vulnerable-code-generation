//Gemma-7B DATASET v1.0 Category: Simulation of the Solar System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 8

typedef struct Planet {
  char name[20];
  double mass;
  double distance;
  double orbital_speed;
  double orbital_period;
  double eccentricity;
  double tilt;
  struct Planet* next;
} Planet;

Planet* create_planet(char name, double mass, double distance, double orbital_speed, double orbital_period, double eccentricity, double tilt) {
  Planet* new_planet = malloc(sizeof(Planet));
  strcpy(new_planet->name, name);
  new_planet->mass = mass;
  new_planet->distance = distance;
  new_planet->orbital_speed = orbital_speed;
  new_planet->orbital_period = orbital_period;
  new_planet->eccentricity = eccentricity;
  new_planet->tilt = tilt;
  new_planet->next = NULL;
  return new_planet;
}

void simulate_solar_system(Planet* planets) {
  int i = 0;
  for (i = 0; planets->next; i++) {
    // Calculate orbital position and velocity
    double x = planets->distance * sin(2 * M_PI * planets->orbital_period * i / NUM_PLANETS) * (1 - planets->eccentricity);
    double y = planets->distance * cos(2 * M_PI * planets->orbital_period * i / NUM_PLANETS) * (1 - planets->eccentricity);

    // Rotate planet
    double theta = planets->tilt * M_PI / 180;
    double dx = x * sin(theta);
    double dy = y * cos(theta);

    // Draw planet
    printf("Planet: %s\n", planets->name);
    printf("x: %.2f, y: %.2f\n", dx, dy);
    printf("Distance: %.2f, Speed: %.2f, Period: %.2f\n", planets->distance, planets->orbital_speed, planets->orbital_period);
    printf("\n");
  }
}

int main() {
  Planet* planets = create_planet("Sun", 1e30, 0, 0, 0, 0, 0);
  planets = create_planet("Mercury", 0.055, 59.2, 29.7, 88, 0.2, 23);
  planets = create_planet("Venus", 0.816, 67.2, 24.0, 225, 0.0, 12);
  planets = create_planet("Earth", 0.055, 93.0, 29.7, 365, 0.0, 23);
  planets = create_planet("Mars", 0.048, 248, 24.0, 687, 0.0, 23);
  planets = create_planet("Jupiter", 5.9e24, 520, 13.0, 12.6, 0.0, 0);
  planets = create_planet("Saturn", 5.8e24, 886, 9.0, 10.7, 0.0, 0);
  planets = create_planet("Uranus", 1.0e24, 1920, 4.8, 84.0, 0.0, 97);
  planets = create_planet("Neptune", 1.0e24, 2.79e8, 4.8, 165, 0.0, 97);

  simulate_solar_system(planets);

  return 0;
}