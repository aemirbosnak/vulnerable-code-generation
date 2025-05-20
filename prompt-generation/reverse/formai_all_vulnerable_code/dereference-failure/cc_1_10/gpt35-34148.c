//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#define G 6.674 // Gravitational constant

typedef struct Planet {
  double x, y; // position
  double vx, vy; // velocity
  double m; // mass
} Planet;

void planetUpdate(Planet *a, double fx, double fy, double dt) {
  a->vx += fx / a->m * dt;
  a->vy += fy / a->m * dt;
  a->x += a->vx * dt;
  a->y += a->vy * dt;
}

void calculateForce(Planet *a, Planet *b, double *fx, double *fy) {
  double dx = b->x - a->x;
  double dy = b->y - a->y;
  double dist = sqrt(dx*dx + dy*dy);
  double f = G * a->m * b->m / (dist*dist);
  *fx = f * dx / dist;
  *fy = f * dy / dist;
}

int main() {
  srand(time(NULL));
  
  // create planets
  Planet *earth = malloc(sizeof(Planet));
  earth->x = 0;
  earth->y = 0;
  earth->vx = 0;
  earth->vy = 0;
  earth->m = 5.97e24;
  
  Planet *moon = malloc(sizeof(Planet));
  moon->x = 385000000;
  moon->y = 0;
  moon->vx = 0;
  moon->vy = 1023; // just some random value to make the moon move
  moon->m = 7.34e22;

  printf("Welcome to the Planet Gravity Simulation Game!\n");
  printf("Today you'll be helping the moon escape from the earth's gravity.\n");
  printf("You have to enter the moon's initial velocity such that it escapes earth's gravity.\n");
  
  int tries = 0;
  while (1) { // game loop
    double fx, fy;
    calculateForce(moon, earth, &fx, &fy);
    planetUpdate(moon, fx, fy, 1);
    planetUpdate(earth, -fx, -fy, 1);
     
    printf("Moon position: (%f, %f)\n", moon->x, moon->y);
    printf("Earth position: (%f, %f)\n", earth->x, earth->y);
    
    if (moon->y > earth->y) { // moon escaped
      printf("\nCongratulations! You helped the moon escape earth's gravity in %d tries.\n", tries);
      printf("You can now apply for a job at NASA.\n");
      break;
    }
    
    printf("Enter the moon's initial velocity (m/s): ");
    
    double initialVel;
    scanf("%lf", &initialVel);
    
    moon->vy = initialVel;
    
    tries++;
    
    // add some randomness to the simulation
    usleep(100000);
  }
  
  free(earth);
  free(moon);
  
  return 0;
}