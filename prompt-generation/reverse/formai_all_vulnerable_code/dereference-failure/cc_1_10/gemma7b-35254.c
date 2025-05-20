//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOM_NUM 5

typedef struct Room {
    char name[20];
    struct Room* next;
    int num;
} Room;

void create_room(char* name, int num) {
    Room* new_room = malloc(sizeof(Room));
    strcpy(new_room->name, name);
    new_room->num = num;
    new_room->next = NULL;
}

int main() {
    Room* rooms = NULL;
    create_room("The Grand Hall", 0);
    create_room("The Library", 1);
    create_room("The Dining Hall", 2);
    create_room("The Kitchen", 3);
    create_room("The Bedroom", 4);

    rooms = rooms->next;

    printf("You are in %s. Please enter the direction you want to go (N, S, E, W): ", rooms->name);
    char direction;
    scanf(" %c", &direction);

    switch (direction) {
        case 'N':
            rooms = rooms->next->next;
            printf("You are now in %s. Please enter the direction you want to go (N, S, E, W): ", rooms->name);
            break;
        case 'S':
            rooms = rooms->next;
            printf("You are now in %s. Please enter the direction you want to go (N, S, E, W): ", rooms->name);
            break;
        case 'E':
            rooms = rooms->next->next->next;
            printf("You are now in %s. Please enter the direction you want to go (N, S, E, W): ", rooms->name);
            break;
        case 'W':
            rooms = rooms->next->next->next->next;
            printf("You are now in %s. Please enter the direction you want to go (N, S, E, W): ", rooms->name);
            break;
        default:
            printf("Invalid direction. Please try again.");
    }

    return 0;
}