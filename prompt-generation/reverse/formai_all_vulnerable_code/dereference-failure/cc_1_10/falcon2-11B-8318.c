//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x, y;
} Coordinate;

typedef struct {
    char name[50];
    Coordinate location;
} Room;

void print_room(Room *room) {
    printf("Room %s at (%d, %d)\n", room->name, room->location.x, room->location.y);
}

void move_to_room(Room *room) {
    printf("Moving to %s at (%d, %d)\n", room->name, room->location.x, room->location.y);
}

int main() {
    srand(time(NULL));

    Room *room1 = (Room*)malloc(sizeof(Room));
    strcpy(room1->name, "Living Room");
    room1->location.x = rand() % 10;
    room1->location.y = rand() % 10;

    Room *room2 = (Room*)malloc(sizeof(Room));
    strcpy(room2->name, "Kitchen");
    room2->location.x = rand() % 10;
    room2->location.y = rand() % 10;

    Room *room3 = (Room*)malloc(sizeof(Room));
    strcpy(room3->name, "Bedroom");
    room3->location.x = rand() % 10;
    room3->location.y = rand() % 10;

    Room *room4 = (Room*)malloc(sizeof(Room));
    strcpy(room4->name, "Attic");
    room4->location.x = rand() % 10;
    room4->location.y = rand() % 10;

    Room *room5 = (Room*)malloc(sizeof(Room));
    strcpy(room5->name, "Basement");
    room5->location.x = rand() % 10;
    room5->location.y = rand() % 10;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in the Living Room at (%d, %d).\n", room1->location.x, room1->location.y);

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Go to the Kitchen\n");
        printf("2. Go to the Bedroom\n");
        printf("3. Go to the Attic\n");
        printf("4. Go to the Basement\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_to_room(room2);
                break;
            case 2:
                move_to_room(room3);
                break;
            case 3:
                move_to_room(room4);
                break;
            case 4:
                move_to_room(room5);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    free(room1);
    free(room2);
    free(room3);
    free(room4);
    free(room5);

    return 0;
}