//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

// constant value of gravitational constant, G
#define G 6.67e-11

// define the number of planets in the solar system
#define NUM_PLANETS 8

// define the maximum number of days the simulation will run
#define MAX_DAYS 365

// define the data structure to store information about each planet
typedef struct {
  char name[20];
  double mass;
  double x_pos;
  double y_pos;
  double x_vel;
  double y_vel;
  double x_acc;
  double y_acc;
} planet_t;

// function to initialize the planets 
void initialize_planets(planet_t planets[NUM_PLANETS]) {
  // sun
  strcpy(planets[0].name, "Sun");
  planets[0].mass = 1.99e+30;
  planets[0].x_pos = 0;
  planets[0].y_pos = 0;
  planets[0].x_vel = 0;
  planets[0].y_vel = 0;
  planets[0].x_acc = 0;
  planets[0].y_acc = 0;

  // mercury
  strcpy(planets[1].name, "Mercury");
  planets[1].mass = 3.3e+23;
  planets[1].x_pos = -5.7e+10;
  planets[1].y_pos = 0;
  planets[1].x_vel = 0;
  planets[1].y_vel = 4.79e+04;
  planets[1].x_acc = 0;
  planets[1].y_acc = 0;

  // venus
  strcpy(planets[2].name, "Venus");
  planets[2].mass = 4.87e+24;
  planets[2].x_pos = 1.1e+11;
  planets[2].y_pos = 0;
  planets[2].x_vel = 0;
  planets[2].y_vel = -3.5e+04;
  planets[2].x_acc = 0;
  planets[2].y_acc = 0;

  // earth
  strcpy(planets[3].name, "Earth");
  planets[3].mass = 5.97e+24;
  planets[3].x_pos = 1.5e+11;
  planets[3].y_pos = 0;
  planets[3].x_vel = 0;
  planets[3].y_vel = 2.98e+04;
  planets[3].x_acc = 0;
  planets[3].y_acc = 0;

  // mars
  strcpy(planets[4].name, "Mars");
  planets[4].mass = 6.39e+23;
  planets[4].x_pos = -2.2e+11;
  planets[4].y_pos = 0;
  planets[4].x_vel = 0;
  planets[4].y_vel = -2.41e+04;
  planets[4].x_acc = 0;
  planets[4].y_acc = 0;

  // jupiter
  strcpy(planets[5].name, "Jupiter");
  planets[5].mass = 1.9e+27;
  planets[5].x_pos = 7.8e+11;
  planets[5].y_pos = 0;
  planets[5].x_vel = 0;
  planets[5].y_vel = -1.307e+04;
  planets[5].x_acc = 0;
  planets[5].y_acc = 0;

  // saturn
  strcpy(planets[6].name, "Saturn");
  planets[6].mass = 5.68e+26;
  planets[6].x_pos = 1.4e+12;
  planets[6].y_pos = 0;
  planets[6].x_vel = 0;
  planets[6].y_vel = -9.6e+03;
  planets[6].x_acc = 0;
  planets[6].y_acc = 0;

  // uranus
  strcpy(planets[7].name, "Uranus");
  planets[7].mass = 8.68e+25;
  planets[7].x_pos = -2.9e+12;
  planets[7].y_pos = 0;
  planets[7].x_vel = 0;
  planets[7].y_vel = 6.8e+03;
  planets[7].x_acc = 0;
  planets[7].y_acc = 0;

  // neptune
  strcpy(planets[8].name, "Neptune");
  planets[8].mass = 1.02e+26;
  planets[8].x_pos = 4.5e+12;
  planets[8].y_pos = 0;
  planets[8].x_vel = 0;
  planets[8].y_vel = -5.4e+03;
  planets[8].x_acc = 0;
  planets[8].y_acc = 0;
}

// function to calculate the acceleration of each planet due to gravitational force
void calculate_acceleration(planet_t planets[NUM_PLANETS]) {
  for (int i = 0; i < NUM_PLANETS; i++) {
    for (int j = i + 1; j < NUM_PLANETS; j++) {
      double dx = planets[j].x_pos - planets[i].x_pos;
      double dy = planets[j].y_pos - planets[i].y_pos;
      double dist = sqrt(dx*dx + dy*dy);
      double force = G*planets[i].mass*planets[j].mass/(dist*dist);
      double ax = force*dy/(dist*planets[i].mass);
      double ay = force*dx/(dist*planets[i].mass);
      planets[i].x_acc += ax;
      planets[i].y_acc += ay;
      planets[j].x_acc -= ax;
      planets[j].y_acc -= ay;
    }
  }
}

// function to calculate the velocity and position of each planet after 1 day
void calculate_velocity_position(planet_t planets[NUM_PLANETS]) {
  for (int i = 0; i < NUM_PLANETS; i++) {
    planets[i].x_vel += planets[i].x_acc*86400;
    planets[i].y_vel += planets[i].y_acc*86400;
    planets[i].x_pos += planets[i].x_vel*86400;
    planets[i].y_pos += planets[i].y_vel*86400;
    planets[i].x_acc = 0;
    planets[i].y_acc = 0;
  }
}

// function to print the current position of each planet
void print_planet_positions(planet_t planets[NUM_PLANETS]) {
  printf("Day 0:\n");
  for (int i = 0; i < NUM_PLANETS; i++) {
    printf("%s: (%g, %g)\n", planets[i].name, planets[i].x_pos, planets[i].y_pos);
  }
  printf("\n");
}

int main(void) {
  srand(time(NULL));
  planet_t planets[NUM_PLANETS];

  initialize_planets(planets);
  print_planet_positions(planets);

  for (int day = 1; day <= MAX_DAYS; day++) {
    printf("Day %d:\n", day);
    calculate_acceleration(planets);
    calculate_velocity_position(planets);
    for (int i = 0; i < NUM_PLANETS; i++) {
      printf("%s: (%g, %g)\n", planets[i].name, planets[i].x_pos, planets[i].y_pos);
    }
    printf("\n");
  }

  return 0;
}