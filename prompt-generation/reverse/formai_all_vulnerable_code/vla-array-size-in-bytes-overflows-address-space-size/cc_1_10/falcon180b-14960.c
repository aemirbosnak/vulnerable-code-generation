//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum {
    ROOM_TYPE_NORMAL = 0,
    ROOM_TYPE_TRAP = 1,
    ROOM_TYPE_TREASURE = 2
};

struct Room {
    int type;
    char* description;
};

void generate_room(struct Room* room) {
    room->type = rand() % 3;

    switch(room->type) {
        case ROOM_TYPE_NORMAL:
            room->description = "This is a normal room.";
            break;
        case ROOM_TYPE_TRAP:
            room->description = "There is a trap here!";
            break;
        case ROOM_TYPE_TREASURE:
            room->description = "You found a treasure!";
            break;
    }
}

int main() {
    srand(time(NULL));

    int num_rooms;
    printf("How many rooms do you want to explore? ");
    scanf("%d", &num_rooms);

    struct Room rooms[num_rooms];

    for(int i = 0; i < num_rooms; i++) {
        generate_room(&rooms[i]);
    }

    int current_room = 0;

    while(1) {
        printf("\nYou are in room %d.\n%s\n", current_room + 1, rooms[current_room].description);

        char choice;
        printf("Do you want to go to the next room? (y/n) ");
        scanf(" %c", &choice);

        if(choice == 'n') {
            break;
        } else if(choice!= 'y') {
            printf("Invalid input.\n");
            continue;
        }

        current_room = (current_room + 1) % num_rooms;
    }

    return 0;
}