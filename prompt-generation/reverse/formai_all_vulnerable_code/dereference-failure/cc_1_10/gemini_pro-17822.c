//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct {
    double x;
    double y;
    double vx;
    double vy;
    double mass;
    double radius;
    bool alive;
} particle;

particle* particles;
int num_particles;

pthread_mutex_t lock;

void* physics_thread(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        for (int i = 0; i < num_particles; i++) {
            if (!particles[i].alive) continue;

            particles[i].x += particles[i].vx;
            particles[i].y += particles[i].vy;

            // Check for collisions with the walls
            if (particles[i].x < 0 || particles[i].x > WINDOW_WIDTH){
                particles[i].vx = -particles[i].vx;
            }

            if (particles[i].y < 0 || particles[i].y > WINDOW_HEIGHT){
                particles[i].vy = -particles[i].vy;
            }

            // Check for collisions between particles
            for (int j = i + 1; j < num_particles; j++) {
                if (!particles[j].alive) continue;

                double dx = particles[i].x - particles[j].x;
                double dy = particles[i].y - particles[j].y;
                double distance = sqrt(dx * dx + dy * dy);

                if (distance < particles[i].radius + particles[j].radius) {
                    // Calculate the collision response
                    double nx = dx / distance;
                    double ny = dy / distance;
                    double tx = -ny;
                    double ty = nx;

                    // Calculate the impulse
                    double J = 2 * (particles[i].vx * nx + particles[i].vy * ny - particles[j].vx * nx - particles[j].vy * ny) / (particles[i].mass + particles[j].mass);

                    // Apply the impulse
                    particles[i].vx += J * nx;
                    particles[i].vy += J * ny;
                    particles[j].vx -= J * nx;
                    particles[j].vy -= J * ny;
                }
            }
        }
        pthread_mutex_unlock(&lock);
        usleep(10000);
    }
}

void* render_thread(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        for (int i = 0; i < num_particles; i++) {
            if (!particles[i].alive) continue;

            printf("Particle %d: (%.2f, %.2f)\n", i, particles[i].x, particles[i].y);
        }
        pthread_mutex_unlock(&lock);
        usleep(10000);
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the particles
    num_particles = 10;
    particles = malloc(num_particles * sizeof(particle));
    for (int i = 0; i < num_particles; i++) {
        particles[i].x = (double)rand() / ((double)RAND_MAX / WINDOW_WIDTH);
        particles[i].y = (double)rand() / ((double)RAND_MAX / WINDOW_HEIGHT);
        particles[i].vx = 0.0;
        particles[i].vy = 0.0;
        particles[i].mass = 1.0;
        particles[i].radius = 10.0;
        particles[i].alive = true;
    }

    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    // Create the physics and render threads
    pthread_t physics_thread_id;
    pthread_t render_thread_id;
    pthread_create(&physics_thread_id, NULL, physics_thread, NULL);
    pthread_create(&render_thread_id, NULL, render_thread, NULL);

    // Join the threads
    pthread_join(physics_thread_id, NULL);
    pthread_join(render_thread_id, NULL);

    // Free the particles
    free(particles);

    return 0;
}