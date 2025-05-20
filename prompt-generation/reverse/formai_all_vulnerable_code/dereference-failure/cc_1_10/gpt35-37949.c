//FormAI DATASET v1.0 Category: Physics simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPEED_OF_LIGHT 299792458

typedef struct Particle {
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double mass;
} Particle;

void calculate_acceleration(Particle* particle, Particle* other_particle, double* ax, double* ay, double* az) {
    // Calculate distance between two particles
    double dx = other_particle->x - particle->x;
    double dy = other_particle->y - particle->y;
    double dz = other_particle->z - particle->z;
    double distance = sqrt(dx * dx + dy * dy + dz * dz);
    
    // Calculate gravitational force between two particles
    double force = (particle->mass * other_particle->mass) / (distance * distance);
    
    // Calculate acceleration in x, y and z directions
    *ax = force * dx / distance / particle->mass;
    *ay = force * dy / distance / particle->mass;
    *az = force * dz / distance / particle->mass;
}

void simulate_particles(int num_particles, double simulation_time) {
    // Initialize particles with random positions, velocities and masses
    Particle* particles = (Particle*) malloc(num_particles * sizeof(Particle));
    srand(time(NULL));
    for (int i = 0; i < num_particles; i++) {
        particles[i].x = (double) rand() / RAND_MAX * 100;
        particles[i].y = (double) rand() / RAND_MAX * 100;
        particles[i].z = (double) rand() / RAND_MAX * 100;
        particles[i].vx = (double) rand() / RAND_MAX * SPEED_OF_LIGHT;
        particles[i].vy = (double) rand() / RAND_MAX * SPEED_OF_LIGHT;
        particles[i].vz = (double) rand() / RAND_MAX * SPEED_OF_LIGHT;
        particles[i].mass = (double) rand() / RAND_MAX * 1000000;
    }
    
    // Simulate particles for the given time
    double time_step = 0.1;
    int num_steps = simulation_time / time_step;
    for (int i = 0; i < num_steps; i++) {
        // Calculate acceleration for each particle
        double ax[num_particles], ay[num_particles], az[num_particles];
        for (int j = 0; j < num_particles; j++) {
            ax[j] = 0;
            ay[j] = 0;
            az[j] = 0;
            for (int k = 0; k < num_particles; k++) {
                if (j == k) continue;
                double ax_jk, ay_jk, az_jk;
                calculate_acceleration(&particles[j], &particles[k], &ax_jk, &ay_jk, &az_jk);
                ax[j] += ax_jk;
                ay[j] += ay_jk;
                az[j] += az_jk;
            }
        }
        
        // Update positions and velocities for each particle
        for (int j = 0; j < num_particles; j++) {
            particles[j].x += particles[j].vx * time_step + 0.5 * ax[j] * time_step * time_step;
            particles[j].y += particles[j].vy * time_step + 0.5 * ay[j] * time_step * time_step;
            particles[j].z += particles[j].vz * time_step + 0.5 * az[j] * time_step * time_step;
            particles[j].vx += ax[j] * time_step;
            particles[j].vy += ay[j] * time_step;
            particles[j].vz += az[j] * time_step;
        }
    }
    
    // Print final positions and velocities of particles
    for (int i = 0; i < num_particles; i++) {
        printf("Particle %d: (%f, %f, %f) | (%f, %f, %f)\n", i + 1, particles[i].x, particles[i].y, particles[i].z, particles[i].vx, particles[i].vy, particles[i].vz);
    }
    
    free(particles);
}

int main() {
    simulate_particles(10, 10);
    return 0;
}