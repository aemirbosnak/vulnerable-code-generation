//LLAMA2-13B DATASET v1.0 Category: Physics simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GRAVITY 9.8
#define WORLD_WIDTH 1000
#define WORLD_HEIGHT 1000

typedef struct {
    int x;
    int y;
    int mass;
} Object;

typedef struct {
    Object *objects;
    int num_objects;
} World;

void init_world(World *world) {
    int i, j;

    world->objects = calloc(WORLD_WIDTH * WORLD_HEIGHT, sizeof(Object));
    world->num_objects = 0;

    for (i = 0; i < WORLD_WIDTH; i++) {
        for (j = 0; j < WORLD_HEIGHT; j++) {
            Object obj;
            obj.x = i * 10;
            obj.y = j * 10;
            obj.mass = rand() % 10 + 1;
            world->objects[world->num_objects] = obj;
            world->num_objects++;
        }
    }
}

void update_world(World *world) {
    int i, j;

    for (i = 0; i < world->num_objects; i++) {
        Object *obj = world->objects + i;

        // Gravity
        obj->y += GRAVITY;

        // Collision with ground
        if (obj->y >= WORLD_HEIGHT) {
            obj->y = WORLD_HEIGHT - 1;
            world->num_objects--;
            i--;
            continue;
        }

        // Collision with other objects
        for (j = i + 1; j < world->num_objects; j++) {
            Object *other_obj = world->objects + j;

            if (distance(obj, other_obj) < 5) {
                obj->x += other_obj->x - obj->x;
                obj->y += other_obj->y - obj->y;
                world->num_objects--;
                i--;
                break;
            }
        }
    }
}

void draw_world(World *world) {
    int i, j;

    for (i = 0; i < WORLD_WIDTH; i++) {
        for (j = 0; j < WORLD_HEIGHT; j++) {
            Object *obj = world->objects + (i * WORLD_HEIGHT + j);
            printf("obj %d x:%d y:%d m:%d\n", obj->mass, obj->x, obj->y, obj->mass);
        }
    }
}

int distance(Object *a, Object *b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

int main() {
    World world;

    init_world(&world);

    for (int i = 0; i < 1000; i++) {
        update_world(&world);
        draw_world(&world);
    }

    return 0;
}