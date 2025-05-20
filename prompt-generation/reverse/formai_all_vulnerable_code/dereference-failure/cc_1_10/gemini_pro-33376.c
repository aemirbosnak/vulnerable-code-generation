//GEMINI-pro DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Position;

typedef struct {
    char symbol;
    Position position;
} Entity;

typedef struct {
    int width, height;
    Entity *entities;
} World;

World *createWorld(int width, int height) {
    World *world = malloc(sizeof(World));
    world->width = width;
    world->height = height;
    world->entities = malloc(sizeof(Entity) * 2);
    
    // Create Romeo and Juliet
    world->entities[0] = (Entity) {'R', {0, 0}};
    world->entities[1] = (Entity) {'J', {width - 1, height - 1}};

    return world;
}

void destroyWorld(World *world) {
    free(world->entities);
    free(world);
}

void drawWorld(World *world) {
    for (int y = 0; y < world->height; y++) {
        for (int x = 0; x < world->width; x++) {
            Entity *entity = &world->entities[0];
            if (entity->position.x == x && entity->position.y == y) {
                printf("%c", entity->symbol);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void moveEntity(Entity *entity, int dx, int dy) {
    entity->position.x += dx;
    entity->position.y += dy;
}

int main() {
    srand(time(NULL));

    World *world = createWorld(80, 25);

    drawWorld(world);

    while (1) {
        // Get input from the user
        char input = getchar();

        // Move Romeo and Juliet
        switch (input) {
            case 'w':
                moveEntity(&world->entities[0], 0, -1);
                break;
            case 'a':
                moveEntity(&world->entities[0], -1, 0);
                break;
            case 's':
                moveEntity(&world->entities[0], 0, 1);
                break;
            case 'd':
                moveEntity(&world->entities[0], 1, 0);
                break;
            case 'i':
                moveEntity(&world->entities[1], 0, -1);
                break;
            case 'j':
                moveEntity(&world->entities[1], -1, 0);
                break;
            case 'k':
                moveEntity(&world->entities[1], 0, 1);
                break;
            case 'l':
                moveEntity(&world->entities[1], 1, 0);
                break;
            case 'q':
                destroyWorld(world);
                return 0;
        }

        // Check if Romeo and Juliet have met
        if (world->entities[0].position.x == world->entities[1].position.x && world->entities[0].position.y == world->entities[1].position.y) {
            printf("Romeo and Juliet have met!\n");
            destroyWorld(world);
            return 0;
        }

        // Draw the world
        drawWorld(world);
    }

    return 0;
}