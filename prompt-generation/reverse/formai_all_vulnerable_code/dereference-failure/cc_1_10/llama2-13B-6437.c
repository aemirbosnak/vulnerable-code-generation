//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    int x, y;
    int size;
    int speed;
} Particle;

int main() {
    int particles = 100;
    Particle* particles_array = (Particle*)calloc(particles, sizeof(Particle));

    for (int i = 0; i < particles; i++) {
        particles_array[i].x = rand() % WIDTH;
        particles_array[i].y = rand() % HEIGHT;
        particles_array[i].size = rand() % 10 + 1;
        particles_array[i].speed = rand() % 5 + 1;
    }

    while (1) {
        for (int i = 0; i < particles; i++) {
            particles_array[i].x += particles_array[i].speed;
            particles_array[i].y += particles_array[i].speed;

            if (particles_array[i].x > WIDTH - particles_array[i].size) {
                particles_array[i].x = WIDTH - particles_array[i].size;
            }
            if (particles_array[i].y > HEIGHT - particles_array[i].size) {
                particles_array[i].y = HEIGHT - particles_array[i].size;
            }

            if (particles_array[i].x < 0) {
                particles_array[i].x = 0;
            }
            if (particles_array[i].y < 0) {
                particles_array[i].y = 0;
            }
        }

        // Draw particles
        for (int i = 0; i < particles; i++) {
            printf("%d, %d, %d, %d\n", particles_array[i].x, particles_array[i].y, particles_array[i].size, particles_array[i].speed);
        }

        // Wait for a key press
        system("pause");
    }

    return 0;
}