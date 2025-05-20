//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOM_NUMBER 10

typedef struct Room {
    int room_number;
    char room_name[20];
    struct Room* next_room;
} Room;

Room* create_room(int room_number, char* room_name) {
    Room* new_room = (Room*)malloc(sizeof(Room));
    new_room->room_number = room_number;
    strcpy(new_room->room_name, room_name);
    new_room->next_room = NULL;
    return new_room;
}

void traverse_rooms(Room* current_room) {
    while (current_room) {
        printf("You are in the %s.\n", current_room->room_name);
        printf("You can go to the following rooms: ");
        Room* next_room = current_room->next_room;
        while (next_room) {
            printf("%s, ", next_room->room_name);
            next_room = next_room->next_room;
        }
        printf("\n");
        char choice;
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                traverse_rooms(current_room->next_room);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

int main() {
    srand(time(NULL));
    Room* first_room = create_room(1, "The Entrance");
    Room* second_room = create_room(2, "The Library");
    Room* third_room = create_room(3, "The Dining Hall");
    first_room->next_room = second_room;
    second_room->next_room = third_room;

    traverse_rooms(first_room);

    return 0;
}