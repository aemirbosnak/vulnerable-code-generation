//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 9.81

typedef struct {
  double mass;
  double radius;
  double x;
  double y;
  double vx;
  double vy;
} Body;

Body *createBody(double mass, double radius, double x, double y, double vx, double vy) {
  Body *body = malloc(sizeof(Body));
  body->mass = mass;
  body->radius = radius;
  body->x = x;
  body->y = y;
  body->vx = vx;
  body->vy = vy;
  return body;
}

void freeBody(Body *body) {
  free(body);
}

void updateBody(Body *body, double dt) {
  body->x += body->vx * dt;
  body->y += body->vy * dt;
  body->vy += GRAVITY * dt;
}

void drawBody(Body *body) {
  printf("Body at (%f, %f) with radius %f\n", body->x, body->y, body->radius);
}

int main() {
  const double dt = 0.01;
  Body *body1 = createBody(1, 0.5, 0, 0, 0, 0);
  Body *body2 = createBody(2, 1, 1, 0, 0, 0);

  for (int i = 0; i < 1000; i++) {
    updateBody(body1, dt);
    updateBody(body2, dt);

    // Check for collisions
    double dx = body1->x - body2->x;
    double dy = body1->y - body2->y;
    double distance = sqrt(dx * dx + dy * dy);
    if (distance < body1->radius + body2->radius) {
      // Collision detected!
      // Calculate the new velocities
      double v1x = body1->vx * (body1->mass - body2->mass) / (body1->mass + body2->mass) + 2 * body2->vx * body2->mass / (body1->mass + body2->mass);
      double v1y = body1->vy * (body1->mass - body2->mass) / (body1->mass + body2->mass) + 2 * body2->vy * body2->mass / (body1->mass + body2->mass);
      double v2x = body2->vx * (body2->mass - body1->mass) / (body1->mass + body2->mass) + 2 * body1->vx * body1->mass / (body1->mass + body2->mass);
      double v2y = body2->vy * (body2->mass - body1->mass) / (body1->mass + body2->mass) + 2 * body1->vy * body1->mass / (body1->mass + body2->mass);

      body1->vx = v1x;
      body1->vy = v1y;
      body2->vx = v2x;
      body2->vy = v2y;
    }

    drawBody(body1);
    drawBody(body2);
  }

  freeBody(body1);
  freeBody(body2);

  return 0;
}