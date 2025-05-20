//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

typedef struct particle {
    double mass; // Mass of the particle
    double x, y, z; // Coordinates of the particle
    double vx, vy, vz; // Velocities of the particle
    double fx, fy, fz; // Forces on the particle
} particle;

int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s num_particles timestep simulation_time output_file\n", argv[0]);
        return 1;
    }

    int num_particles = atoi(argv[1]);
    double timestep = atof(argv[2]);
    double simulation_time = atof(argv[3]);
    char *output_file = argv[4];

    // Create an array of particles
    particle *particles = malloc(num_particles * sizeof(particle));

    // Initialize the particles
    for (int i = 0; i < num_particles; i++) {
        particles[i].mass = 1.0;
        particles[i].x = i;
        particles[i].y = i;
        particles[i].z = i;
        particles[i].vx = 0.0;
        particles[i].vy = 0.0;
        particles[i].vz = 0.0;
        particles[i].fx = 0.0;
        particles[i].fy = 0.0;
        particles[i].fz = 0.0;
    }

    // Open the output file
    FILE *fp = fopen(output_file, "w");

    // Run the simulation
    for (double t = 0.0; t < simulation_time; t += timestep) {
        // Calculate the forces on each particle
        for (int i = 0; i < num_particles; i++) {
            for (int j = i + 1; j < num_particles; j++) {
                double dx = particles[j].x - particles[i].x;
                double dy = particles[j].y - particles[i].y;
                double dz = particles[j].z - particles[i].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);
                double f = G * particles[i].mass * particles[j].mass / (r * r);
                particles[i].fx += f * dx / r;
                particles[i].fy += f * dy / r;
                particles[i].fz += f * dz / r;
            }
        }

        // Update the velocities and positions of the particles
        for (int i = 0; i < num_particles; i++) {
            particles[i].vx += timestep * particles[i].fx / particles[i].mass;
            particles[i].vy += timestep * particles[i].fy / particles[i].mass;
            particles[i].vz += timestep * particles[i].fz / particles[i].mass;
            particles[i].x += timestep * particles[i].vx;
            particles[i].y += timestep * particles[i].vy;
            particles[i].z += timestep * particles[i].vz;
        }

        // Write the positions of the particles to the output file
        for (int i = 0; i < num_particles; i++) {
            fprintf(fp, "%f %f %f\n", particles[i].x, particles[i].y, particles[i].z);
        }
    }

    // Close the output file
    fclose(fp);

    // Free the array of particles
    free(particles);

    return 0;
}