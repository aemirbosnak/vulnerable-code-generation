//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PARANOID

typedef struct {
  double mass;
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
} Planet;

#ifdef PARANOID
#define ASSERT(expr) if (!(expr)) { fprintf(stderr, "Assertion failed: %s\n", #expr); exit(EXIT_FAILURE); }
#else
#define ASSERT(expr)
#endif

int main(int argc, char *argv[]) {
  // Check for the correct number of arguments.
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Open the input file.
  FILE *input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  // Read the number of planets from the input file.
  int num_planets;
  fscanf(input_file, "%d", &num_planets);

  // Allocate memory for the planets.
  Planet *planets = malloc(num_planets * sizeof(Planet));
  ASSERT(planets != NULL);

  // Read the data for each planet from the input file.
  for (int i = 0; i < num_planets; i++) {
    fscanf(input_file, "%lf %lf %lf %lf %lf %lf %lf",
           &planets[i].mass, &planets[i].x, &planets[i].y, &planets[i].z,
           &planets[i].vx, &planets[i].vy, &planets[i].vz);
  }

  // Close the input file.
  fclose(input_file);

  // Calculate the gravitational force between each pair of planets.
  for (int i = 0; i < num_planets; i++) {
    for (int j = i + 1; j < num_planets; j++) {
      double dx = planets[j].x - planets[i].x;
      double dy = planets[j].y - planets[i].y;
      double dz = planets[j].z - planets[i].z;
      double r = sqrt(dx * dx + dy * dy + dz * dz);
      double force = (6.674e-11 * planets[i].mass * planets[j].mass) / (r * r);
      double theta = atan2(dy, dx);
      double phi = acos(dz / r);
      planets[i].vx += force * cos(theta) * sin(phi) / planets[i].mass;
      planets[i].vy += force * sin(theta) * sin(phi) / planets[i].mass;
      planets[i].vz += force * cos(phi) / planets[i].mass;
      planets[j].vx -= force * cos(theta) * sin(phi) / planets[j].mass;
      planets[j].vy -= force * sin(theta) * sin(phi) / planets[j].mass;
      planets[j].vz -= force * cos(phi) / planets[j].mass;
    }
  }

  // Update the positions of the planets.
  for (int i = 0; i < num_planets; i++) {
    planets[i].x += planets[i].vx;
    planets[i].y += planets[i].vy;
    planets[i].z += planets[i].vz;
  }

  // Output the positions of the planets to a file.
  FILE *output_file = fopen("output.txt", "w");
  ASSERT(output_file != NULL);
  for (int i = 0; i < num_planets; i++) {
    fprintf(output_file, "%lf %lf %lf\n", planets[i].x, planets[i].y, planets[i].z);
  }

  // Close the output file.
  fclose(output_file);

  // Free the memory allocated for the planets.
  free(planets);

  return EXIT_SUCCESS;
}