//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11   // Gravitational constant

typedef struct {
   double x, y, z;    // position
   double vx, vy, vz; // velocity
   double ax, ay, az; // acceleration
   double mass;
} Body;

void update_acceleration(Body *bodies, int n) {
   int i, j;
   double dx, dy, dz, r, r3;
   for (i = 0; i < n; i++) {
      bodies[i].ax = bodies[i].ay = bodies[i].az = 0.0;
      for (j = 0; j < n; j++) {
         if (i == j) continue;
         dx = bodies[j].x - bodies[i].x;
         dy = bodies[j].y - bodies[i].y;
         dz = bodies[j].z - bodies[i].z;
         r = sqrt(dx*dx + dy*dy + dz*dz);
         r3 = r * r * r;
         bodies[i].ax += G * bodies[j].mass * dx / r3;
         bodies[i].ay += G * bodies[j].mass * dy / r3;
         bodies[i].az += G * bodies[j].mass * dz / r3;
      }
   }
}

void update_velocity(Body *bodies, int n, double dt) {
   int i;
   for (i = 0; i < n; i++) {
      bodies[i].vx += bodies[i].ax * dt;
      bodies[i].vy += bodies[i].ay * dt;
      bodies[i].vz += bodies[i].az * dt;
   }
}

void update_position(Body *bodies, int n, double dt) {
   int i;
   for (i = 0; i < n; i++) {
      bodies[i].x += bodies[i].vx * dt;
      bodies[i].y += bodies[i].vy * dt;
      bodies[i].z += bodies[i].vz * dt;
   }
}

int main() {
   // declare variables
   double dt = 0.1, t = 0.0, t_end = 10.0;
   int n = 3, i;

   Body *bodies = (Body*) malloc(n * sizeof(Body));
   bodies[0] = (Body) {1.0, 0.0, 0.0, 0.0, 2.0 * M_PI, 0.0, 0.0, 0.0, 0.0, 10.0};
   bodies[1] = (Body) {0.0, 1.0, 0.0, -2.0 * M_PI, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0};
   bodies[2] = (Body) {0.0, 0.0, 1.0, 0.0, 0.0, 2.0 * M_PI, 0.0, 0.0, 0.0, 10.0};

   FILE *output_file = fopen("output.txt", "w");

   while (t < t_end) {
      fprintf(output_file, "%f,", t);
      for (i = 0; i < n; i++) {
         fprintf(output_file, "%f,%f,%f,", bodies[i].x, bodies[i].y, bodies[i].z);
      }
      fprintf(output_file, "\n");

      update_acceleration(bodies, n);
      update_velocity(bodies, n, dt);
      update_position(bodies, n, dt);

      t += dt;
   }

   fclose(output_file);
   free(bodies);

   return 0;
}