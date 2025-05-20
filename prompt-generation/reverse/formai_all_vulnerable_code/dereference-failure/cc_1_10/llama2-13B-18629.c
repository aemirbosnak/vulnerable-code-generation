//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITY 9.8
#define WORLD_SIZE 100

typedef struct {
    int x;
    int y;
    int mass;
} Body;

Body bodies[10];
int num_bodies = 0;

void update_bodies() {
    for (int i = 0; i < num_bodies; i++) {
        Body* body = &bodies[i];
        int new_x = body->x + (body->mass * GRAVITY) / (body->y + 1);
        int new_y = body->y + (body->mass * GRAVITY) / (body->x + 1);
        if (new_x != body->x || new_y != body->y) {
            body->x = new_x;
            body->y = new_y;
        }
    }
}

void add_body(int x, int y, int mass) {
    Body* body = &bodies[num_bodies];
    body->x = x;
    body->y = y;
    body->mass = mass;
    num_bodies++;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < WORLD_SIZE; i++) {
        for (int j = 0; j < WORLD_SIZE; j++) {
            int x = rand() % WORLD_SIZE;
            int y = rand() % WORLD_SIZE;
            int mass = rand() % 10 + 1;
            add_body(x, y, mass);
        }
    }

    while (1) {
        update_bodies();
        for (int i = 0; i < num_bodies; i++) {
            Body* body = &bodies[i];
            printf("%d, %d\n", body->x, body->y);
        }
        sleep(1);
    }

    return 0;
}