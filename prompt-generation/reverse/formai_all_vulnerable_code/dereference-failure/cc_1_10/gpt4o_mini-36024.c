//GPT-4o-mini DATASET v1.0 Category: Physics simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 50         // Width of the simulation space
#define HEIGHT 20        // Height of the simulation space
#define GRAVITY 9.81     // Gravitational acceleration
#define TIME_STEP 0.1    // Time step for the simulation

typedef struct {
    float x, y;         // Position of the particle
    float vx, vy;       // Velocity of the particle
} Particle;

void initialize_particle(Particle *p, float x, float y, float vx, float vy) {
    p->x = x;
    p->y = y;
    p->vx = vx;
    p->vy = vy;
}

void update_particle(Particle *p) {
    // Apply gravity
    p->vy += GRAVITY * TIME_STEP;

    // Update position
    p->x += p->vx * TIME_STEP;
    p->y += p->vy * TIME_STEP;

    // Bounce off the ground
    if (p->y >= HEIGHT - 1) {
        p->y = HEIGHT - 1;
        p->vy *= -0.7; // Reverse velocity and reduce speed to simulate energy loss
    }
    
    // Bounce off walls
    if (p->x < 0) {
        p->x = 0;
        p->vx *= -1;
    } else if (p->x >= WIDTH) {
        p->x = WIDTH - 1;
        p->vx *= -1;
    }
}

void render(Particle *particles, int particle_count) {
    char screen[HEIGHT][WIDTH + 1];
    // Clear the screen buffer
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            screen[y][x] = ' ';
        }
        screen[y][WIDTH] = '\0'; // Null-terminate each row
    }

    // Draw particles
    for (int i = 0; i < particle_count; i++) {
        int x = (int)particles[i].x;
        int y = (int)particles[i].y;
        if (y >= 0 && y < HEIGHT && x >= 0 && x < WIDTH) {
            screen[y][x] = '*'; // Particle representation
        }
    }

    // Print the screen
    printf("\033[H\033[J"); // Clear terminal (ANSI escape code)
    for (int y = 0; y < HEIGHT; y++) {
        printf("%s\n", screen[y]);
    }
}

int main() {
    int particle_count = 3; // Number of particles
    Particle *particles = malloc(sizeof(Particle) * particle_count);

    // Initialize particles with random starting positions and velocities
    initialize_particle(&particles[0], 10, 0, 1, 0);
    initialize_particle(&particles[1], 30, 5, -1.5, 0);
    initialize_particle(&particles[2], 20, 1, 0.5, 0);

    // Main simulation loop
    while (1) {
        // Update particle positions
        for (int i = 0; i < particle_count; i++) {
            update_particle(&particles[i]);
        }

        // Render particles on screen
        render(particles, particle_count);
        
        // Delay to control the frame rate
        usleep(100000); // Sleep for 100 milliseconds
    }

    // Free memory (this line will never be reached due to the infinite loop)
    free(particles);
    return 0;
}