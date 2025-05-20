//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed the random number generator
    srand(time(NULL));

    // Create a haunted house structure
    struct haunted_house {
        int room_number;
        char *room_name;
        int spirits_present;
        struct haunted_house *next;
    };

    // Create the first room in the haunted house
    struct haunted_house *first_room = malloc(sizeof(struct haunted_house));
    first_room->room_number = 1;
    first_room->room_name = "The Living Room";
    first_room->spirits_present = rand() % 3;

    // Create the second room in the haunted house
    struct haunted_house *second_room = malloc(sizeof(struct haunted_house));
    second_room->room_number = 2;
    second_room->room_name = "The Dining Room";
    second_room->spirits_present = rand() % 3;

    // Create the third room in the haunted house
    struct haunted_house *third_room = malloc(sizeof(struct haunted_house));
    third_room->room_number = 3;
    third_room->room_name = "The Bedroom";
    third_room->spirits_present = rand() % 3;

    // Link the rooms together
    first_room->next = second_room;
    second_room->next = third_room;

    // Simulate the haunted house
    printf("You have entered the haunted house.\n");
    struct haunted_house *current_room = first_room;
    while (current_room) {
        printf("You are in %s.\n", current_room->room_name);
        printf("There are %d spirits present.\n", current_room->spirits_present);
        current_room = current_room->next;
    }

    return 0;
}