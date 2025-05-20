//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67408e-11

typedef struct {
  double x, y;
} Vector2D;

typedef struct {
  Vector2D position;
  Vector2D velocity;
  double mass;
  double radius;
  int red, green, blue; // Color for drawing.
} Body;

// Computes the distance between two bodies.
double distance(Body a, Body b) {
  return sqrt(pow(a.position.x - b.position.x, 2) + pow(a.position.y - b.position.y, 2));
}

// Calculates the gravitational force between two bodies and returns a vector.
Vector2D gravity(Body a, Body b) {
  Vector2D force;

  double dist = distance(a, b);
  double magnitude = G * a.mass * b.mass / pow(dist, 2);

  force.x = magnitude * (b.position.x - a.position.x) / dist;
  force.y = magnitude * (b.position.y - a.position.y) / dist;

  return force;
}

// Computes the total force exerted by all the other bodies on a given body.
Vector2D totalForce(int index, Body *bodies, int numBodies) {
  Vector2D force = {0, 0};
  for (int i = 0; i < numBodies; i++) {
    if (i == index) continue;
    Vector2D g = gravity(bodies[index], bodies[i]);
    force.x += g.x;
    force.y += g.y;
  }
  return force;
}

// Updates the position and velocity of a body based on the total force exerted on it.
void updateBody(int index, Body *bodies, int numBodies, double timeStep) {
  Vector2D force = totalForce(index, bodies, numBodies);

  bodies[index].velocity.x += force.x * timeStep / bodies[index].mass;
  bodies[index].velocity.y += force.y * timeStep / bodies[index].mass;

  bodies[index].position.x += bodies[index].velocity.x * timeStep;
  bodies[index].position.y += bodies[index].velocity.y * timeStep;
}

// Draw all the bodies on the screen.
void drawBodies(Body *bodies, int numBodies) {
  for (int i = 0; i < numBodies; i++) {
    printf("<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" style=\"fill:rgb(%d,%d,%d);\" />\n", bodies[i].position.x, bodies[i].position.y, bodies[i].radius, bodies[i].red, bodies[i].green, bodies[i].blue);
  }
}

int main() {
  int numBodies = 4;
  Body *bodies = calloc(numBodies, sizeof(Body));

  // Set up the initial conditions for the bodies.
  bodies[0].position.x = 0;
  bodies[0].position.y = 0;
  bodies[0].velocity.x = 0;
  bodies[0].velocity.y = 0;
  bodies[0].mass = 1.989e30;
  bodies[0].radius = 695510;
  bodies[0].red = 255;
  bodies[0].green = 255;
  bodies[0].blue = 0;

  bodies[1].position.x = 147e9;
  bodies[1].position.y = 0;
  bodies[1].velocity.x = 0;
  bodies[1].velocity.y = 30300;
  bodies[1].mass = 5.9742e24;
  bodies[1].radius = 6371;
  bodies[1].red = 0;
  bodies[1].green = 50;
  bodies[1].blue = 255;

  bodies[2].position.x = 0;
  bodies[2].position.y = 778e9;
  bodies[2].velocity.x = -13100;
  bodies[2].velocity.y = 0;
  bodies[2].mass = 1.898e27;
  bodies[2].radius = 69911;
  bodies[2].red = 255;
  bodies[2].green = 0;
  bodies[2].blue = 0;

  bodies[3].position.x = -1.5e11;
  bodies[3].position.y = 0;
  bodies[3].velocity.x = 0;
  bodies[3].velocity.y = -24000;
  bodies[3].mass = 3.285e23;
  bodies[3].radius = 2440;
  bodies[3].red = 190;
  bodies[3].green = 190;
  bodies[3].blue = 190;

  double timeStep = 3600*24; // 1 day
  int numSteps = 365; // 1 year
  
  // Print header for SVG file.
  printf("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
  printf("<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"1000\" height=\"1000\">\n");

  for (int i = 0; i < numSteps; i++) {
    // Update each body.
    for (int j = 0; j < numBodies; j++) {
      updateBody(j, bodies, numBodies, timeStep);
    }
    // Draw all the bodies.
    drawBodies(bodies, numBodies);
  }

  // Print footer for SVG file.
  printf("</svg>\n");

  free(bodies);

  return 0;
}