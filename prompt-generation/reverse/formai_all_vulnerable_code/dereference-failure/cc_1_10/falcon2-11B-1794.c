//Falcon2-11B DATASET v1.0 Category: Physics simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

typedef struct particle {
    float x;
    float y;
    float vx;
    float vy;
    float ax;
    float ay;
} particle;

int main() {
    int num_particles = 100;
    float dt = 0.1;
    float fx = 0.0;
    float fy = 0.0;
    float mass = 1.0;
    float g = -9.8;
    
    particle* particles = (particle*)malloc(num_particles * sizeof(particle));
    
    for (int i = 0; i < num_particles; i++) {
        particles[i].x = rand() % 100;
        particles[i].y = rand() % 100;
        particles[i].vx = 0.0;
        particles[i].vy = 0.0;
        particles[i].ax = 0.0;
        particles[i].ay = 0.0;
    }
    
    int* time = (int*)malloc(sizeof(int));
    *time = 0;
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < num_particles; j++) {
            particles[j].x += particles[j].vx * dt;
            particles[j].y += particles[j].vy * dt;
            
            particles[j].vx += particles[j].ax * dt;
            particles[j].vy += particles[j].ay * dt;
            
            particles[j].ax = fx * particles[j].vx + fy * particles[j].vy;
            particles[j].ay = g;
        }
        
        *time += 1;
    }
    
    for (int j = 0; j < num_particles; j++) {
        printf("Particle %d: x = %f, y = %f, vx = %f, vy = %f\n", j, particles[j].x, particles[j].y, particles[j].vx, particles[j].vy);
    }
    
    free(particles);
    free(time);
    
    return 0;
}