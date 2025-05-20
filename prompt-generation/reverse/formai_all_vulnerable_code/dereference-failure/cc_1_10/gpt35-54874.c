//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67408e-11            // gravitational constant
#define INTERVAL 0.1             // time interval between timesteps
#define STEPS 1000               // number of timesteps for simulation
#define UNITS_PER_METER 10       // pixels per meter on screen
#define SCREEN_SIZE 600          // screen size in pixels
#define SOLAR_MASS 1.9885e30     // mass of the sun
#define CYBER_PLANET_COLOR 0x00ff00   // cyber colored planet
#define CYBER_STAR_COLOR 0xffa500     // cyber colored star

struct Point {
    double x, y;
};

struct Vector {
    double x, y;
};

struct Body {
    struct Point pos;
    struct Vector vel;
    struct Vector accel;
    double mass;
    unsigned int color;
};

void init_body(struct Body *body, double mass, double x_pos, double y_pos, double x_vel, double y_vel, unsigned int color) {
    body->pos.x = x_pos;
    body->pos.y = y_pos;
    body->vel.x = x_vel;
    body->vel.y = y_vel;
    body->mass = mass;
    body->color = color;
}

void update_accel(struct Body *body, struct Body *other) {
    double distance_squared, force_magnitude;
    struct Vector force, direction;

    direction.x = other->pos.x - body->pos.x;
    direction.y = other->pos.y - body->pos.y;
    distance_squared = pow(direction.x, 2) + pow(direction.y, 2);
    force_magnitude = (G * body->mass * other->mass) / distance_squared;
    force.x = force_magnitude * direction.x / sqrt(distance_squared);
    force.y = force_magnitude * direction.y / sqrt(distance_squared);
    body->accel.x += force.x / body->mass;
    body->accel.y += force.y / body->mass;
}

void update_vel(struct Body *body, double timestep) {
    body->vel.x += timestep * body->accel.x;
    body->vel.y += timestep * body->accel.y;
}

void update_pos(struct Body *body, double timestep) {
    body->pos.x += timestep * body->vel.x;
    body->pos.y += timestep * body->vel.y;
}

void clear_screen(unsigned char *screen) {
    int i;
    for(i = 0; i < SCREEN_SIZE * SCREEN_SIZE * 3; i++) {
        screen[i] = 0;
    }
}

void draw_body(struct Body *body, unsigned char *screen) {
    int x = (int)((body->pos.x + (SCREEN_SIZE / 2)) * UNITS_PER_METER);
    int y = (int)(((SCREEN_SIZE / 2) - body->pos.y) * UNITS_PER_METER);
    int i;
    for(i = 0; i < SCREEN_SIZE; i++) {
        int j;
        for(j = 0; j < SCREEN_SIZE; j++) {
            int dx = i - x;
            int dy = j - y;
            double d = sqrt(dx * dx + dy * dy) / UNITS_PER_METER;
            if(d < 1) {
                int index = (i + j * SCREEN_SIZE) * 3;
                screen[index] += (body->color & 0xff0000) >> 16;
                screen[index + 1] += (body->color & 0xff00) >> 8;
                screen[index + 2] += (body->color & 0xff);
            }
        }
    }
}

int main() {
    srand(time(NULL));

    // initialize bodies
    struct Body planet, star;
    init_body(&planet, 5.9722e24, 0, 1.496e11, 29780, 0, CYBER_PLANET_COLOR);
    init_body(&star, SOLAR_MASS, 0, 0, 0, 0, CYBER_STAR_COLOR);

    // initialize screen
    unsigned char *screen = (unsigned char*)malloc(SCREEN_SIZE * SCREEN_SIZE * 3);
    clear_screen(screen);

    // simulate motion
    int timestep;
    for(timestep = 0; timestep < STEPS; timestep++) {
        // clear screen
        clear_screen(screen);

        // update acceleration
        planet.accel.x = 0;
        planet.accel.y = 0;
        update_accel(&planet, &star);

        // update velocity and position
        update_vel(&planet, INTERVAL);
        update_pos(&planet, INTERVAL);

        // draw bodies on screen
        draw_body(&planet, screen);
        draw_body(&star, screen);

        // print screen to console
        int i, j;
        for(i = 0; i < SCREEN_SIZE; i++) {
            for(j = 0; j < SCREEN_SIZE; j++) {
                int index = (i + j * SCREEN_SIZE) * 3;
                printf("%02x%02x%02x", screen[index], screen[index + 1], screen[index + 2]);
            }
            printf("\n");
        }

        // wait for user
        printf("Press Enter to continue to next timestep.\n");
        getchar();
    }

    free(screen);

    return EXIT_SUCCESS;
}