//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define NUM_OF_PLANETS 8
#define G_CONST 6.67430e-11
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800
#define SUN_RADIUS 10
#define PLANET_RADIUS 5

typedef struct {
  double x;
  double y;
} Vector2D;

typedef struct {
  Vector2D pos;
  Vector2D vel;
  Vector2D acc;
  double mass;
} Body;

typedef struct {
  Body* bodies;
  int num_of_bodies;
} Universe;

void simulate(Universe* universe, double time_step, int time_steps) {
  // Run simulation for given number of time steps
  for (int t = 0; t < time_steps; t++) {
    // Update positions of each body
    for (int i = 0; i < universe->num_of_bodies; i++) {
      Body* current_body = &universe->bodies[i];
      current_body->pos.x += current_body->vel.x * time_step;
      current_body->pos.y += current_body->vel.y * time_step;
    }

    // Update accelerations of each body based on gravitational forces
    for (int i = 0; i < universe->num_of_bodies; i++) {
      Body* current_body = &universe->bodies[i];
      current_body->acc.x = 0.0;
      current_body->acc.y = 0.0;
      
      for (int j = 0; j < universe->num_of_bodies; j++) {
        if (i != j) {
          Body* other_body = &universe->bodies[j];
          
          double x_diff = other_body->pos.x - current_body->pos.x;
          double y_diff = other_body->pos.y - current_body->pos.y;
          
          double distance = sqrt(x_diff * x_diff + y_diff * y_diff);
          double force_magnitude = G_CONST * current_body->mass * other_body->mass / pow(distance, 2);
          
          double force_x = force_magnitude * x_diff / distance;
          double force_y = force_magnitude * y_diff / distance;
          
          current_body->acc.x += force_x / current_body->mass;
          current_body->acc.y += force_y / current_body->mass;
        }
      }
    }

    // Update velocities of each body based on accelerations
    for (int i = 0; i < universe->num_of_bodies; i++) {
      Body* current_body = &universe->bodies[i];
      current_body->vel.x += current_body->acc.x * time_step;
      current_body->vel.y += current_body->acc.y * time_step;
    }
  }
}

void initialize_universe(Universe* universe) {
  // Initialize the sun
  Body* sun = &universe->bodies[0];
  sun->pos.x = SCREEN_WIDTH / 2;
  sun->pos.y = SCREEN_HEIGHT / 2;
  sun->vel.x = 0.0;
  sun->vel.y = 0.0;
  sun->mass = 1.989e+30;

  // Initialize the planets
  Body* planets = &universe->bodies[1];
  double planet_radius[NUM_OF_PLANETS-1] = {
    57910000,
    108208930,
    149597890,
    227936640,
    778412020,
    1425048000,
    2876679080
  };
  double planet_velocity[NUM_OF_PLANETS-1] = {
    47.87e3,
    35.02e3,
    29.78e3,
    24.077
  };
  double planet_mass[NUM_OF_PLANETS-1] = {
    3.302e+23,
    4.869e+24,
    5.972e+24, 
    6.39e+23,
    1.898e+27,
    5.683e+26,
    8.681e+25
  };
  for (int i = 0; i < NUM_OF_PLANETS-1; i++) {
    planets[i].pos.x = SCREEN_WIDTH / 2 + planet_radius[i];
    planets[i].pos.y = SCREEN_HEIGHT / 2;
    planets[i].vel.x = 0.0;
    planets[i].vel.y = planet_velocity[i];
    planets[i].mass = planet_mass[i];
  }

  universe->num_of_bodies = NUM_OF_PLANETS;
}

void draw_bodies(Universe* universe) {
  // Draw the sun
  Body* sun = &universe->bodies[0];
  printf("<circle cx=\"%lf\" cy=\"%lf\" r=\"%d\" fill=\"yellow\"/>\n", sun->pos.x, sun->pos.y, SUN_RADIUS);

  // Draw the planets
  Body* planets = &universe->bodies[1];
  char* planet_colors[NUM_OF_PLANETS-1] = {
    "gray",
    "brown",
    "blue",
    "red",
    "orange",
    "blue",
    "purple"
  };
  for (int i = 0; i < NUM_OF_PLANETS-1; i++) {
    printf("<circle cx=\"%lf\" cy=\"%lf\" r=\"%d\" fill=\"%s\"/>\n", planets[i].pos.x, planets[i].pos.y, PLANET_RADIUS, planet_colors[i]);
  }
}

int main() {
  Universe universe;
  universe.bodies = (Body*)malloc(sizeof(Body) * NUM_OF_PLANETS);
  
  initialize_universe(&universe);
  
  printf("<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\">\n", SCREEN_WIDTH, SCREEN_HEIGHT);
  
  int time_steps = 365;
  double time_step = 86400;
  
  simulate(&universe, time_step, time_steps);
  
  draw_bodies(&universe);
  
  printf("</svg>");
  
  free(universe.bodies);
  
  return 0;
}