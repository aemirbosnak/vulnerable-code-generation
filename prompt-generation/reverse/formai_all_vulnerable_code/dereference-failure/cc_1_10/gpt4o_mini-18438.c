//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 50
#define HEIGHT 20
#define G 0.1 // Gravitational constant

typedef struct {
    double x, y; // Position
    double vx, vy; // Velocity
    double mass;  // Mass
    char symbol;  // Representation
} Body;

void update_position(Body *body, double dt) {
    body->x += body->vx * dt;
    body->y += body->vy * dt;
}

void apply_gravity(Body *a, Body *b) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double distance = sqrt(dx * dx + dy * dy);

    if (distance == 0) return; // Prevent division by zero

    double force = (G * a->mass * b->mass) / (distance * distance);
    double fx = (force * dx) / distance;
    double fy = (force * dy) / distance;

    a->vx += fx / a->mass;
    a->vy += fy / a->mass;
}

void draw_space(Body *bodies, int num_bodies) {
    char space[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            space[i][j] = ' ';
        }
    }
    
    for (int i = 0; i < num_bodies; i++) {
        int x = (int)(bodies[i].x);
        int y = (int)(bodies[i].y);
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
            space[y][x] = bodies[i].symbol;
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", space[i][j]);
        }
        printf("\n");
    }
}

void clear_screen() {
    printf("\033[H\033[J");
}

int main() {
    int num_bodies = 3;
    Body *bodies = (Body *)malloc(num_bodies * sizeof(Body));
    
    bodies[0] = (Body){25, 10, 0, 0, 10, 'O'}; // Body 1
    bodies[1] = (Body){10, 5, 0, 0, 5, 'X'}; // Body 2
    bodies[2] = (Body){35, 15, 0, 0, 8, '*'}; // Body 3

    double dt = 0.1; // Time step

    while (1) {
        clear_screen();
        
        for (int i = 0; i < num_bodies; i++) {
            for (int j = 0; j < num_bodies; j++) {
                if (i != j) {
                    apply_gravity(&bodies[i], &bodies[j]);
                }
            }
        }

        for (int i = 0; i < num_bodies; i++) {
            update_position(&bodies[i], dt);
        }

        draw_space(bodies, num_bodies);
        usleep(100000); // Sleep for 0.1 second
    }

    free(bodies);
    return 0;
}