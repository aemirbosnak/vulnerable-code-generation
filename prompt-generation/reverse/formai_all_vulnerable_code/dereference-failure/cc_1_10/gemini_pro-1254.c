//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: Cyberpunk
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Constants
#define MAX_X 100
#define MAX_Y 100
#define MAX_Z 100
#define MAX_OBJECTS 100

// Types
typedef struct {
    int x;
    int y;
    int z;
} Position;

typedef struct {
    Position position;
    char *name;
} Object;

// Functions
Object* create_object(char *name, int x, int y, int z) {
    Object *object = malloc(sizeof(Object));
    object->name = name;
    object->position.x = x;
    object->position.y = y;
    object->position.z = z;
    return object;
}

void destroy_object(Object *object) {
    free(object->name);
    free(object);
}

void generate_objects(Object objects[], int num_objects) {
    srand(time(NULL));

    for (int i = 0; i < num_objects; i++) {
        char *names[] = {"asteroid", "ship", "station", "planet", "black hole"};
        char *name = names[rand() % 5];

        int x = rand() % MAX_X;
        int y = rand() % MAX_Y;
        int z = rand() % MAX_Z;

        objects[i] = *create_object(name, x, y, z);
    }
}

void print_objects(Object objects[], int num_objects) {
    for (int i = 0; i < num_objects; i++) {
        printf("%s at (%d, %d, %d)\n", objects[i].name, objects[i].position.x, objects[i].position.y, objects[i].position.z);
    }
}

int main() {
    // Generate objects
    Object objects[MAX_OBJECTS];
    generate_objects(objects, MAX_OBJECTS);

    // Print objects
    print_objects(objects, MAX_OBJECTS);

    // Destroy objects
    for (int i = 0; i < MAX_OBJECTS; i++) {
        destroy_object(&objects[i]);
    }

    return 0;
}