//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 5
#define MAX_OBJECTS 10

typedef struct {
    char *name;
    char *description;
} Object;

typedef struct {
    char *name;
    int light;
} Room;

Object objects[MAX_OBJECTS];
int num_objects = 0;

Room rooms[ROOMS];
int num_rooms = 0;

void generate_room(int index) {
    rooms[index].name = (char *)malloc(20 * sizeof(char));
    sprintf(rooms[index].name, "Room %d", index + 1);
    rooms[index].light = rand() % 2;
}

void generate_objects() {
    int i;
    for (i = 0; i < MAX_OBJECTS; i++) {
        objects[i].name = (char *)malloc(20 * sizeof(char));
        sprintf(objects[i].name, "Object %d", i + 1);
        objects[i].description = (char *)malloc(50 * sizeof(char));
        sprintf(objects[i].description, "A mysterious %s", objects[i].name);
        num_objects++;
    }
}

void describe_room(int room_index) {
    printf("You are in Room %s.\n", rooms[room_index].name);
    if (rooms[room_index].light) {
        printf("The room is well-lit.\n");
    } else {
        printf("The room is dark and spooky.\n");
    }
}

void interact_with_object(int object_index) {
    printf("You interact with the %s.\n", objects[object_index].name);
    printf("It feels %s.\n", objects[object_index].description);
}

int main() {
    srand(time(NULL));

    int i;
    for (i = 0; i < ROOMS; i++) {
        generate_room(i);
    }

    generate_objects();

    int room_index = 0;
    int object_index;

    while (1) {
        describe_room(room_index);

        printf("What would you like to do?\n");
        printf("1. Move to another room\n");
        printf("2. Interact with an object\n");
        printf("3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                room_index = (room_index + 1) % ROOMS;
                break;
            case 2:
                object_index = rand() % num_objects;
                interact_with_object(object_index);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}