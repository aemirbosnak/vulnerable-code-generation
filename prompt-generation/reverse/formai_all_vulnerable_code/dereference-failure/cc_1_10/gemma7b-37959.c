//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define the haunted house structure
typedef struct haunted_house {
    char name[20];
    int rooms;
    struct haunted_house *next;
} haunted_house;

// Create a linked list of haunted houses
haunted_house *head = NULL;

// Function to add a haunted house to the list
void add_house(char *name, int rooms) {
    haunted_house *new_house = (haunted_house *)malloc(sizeof(haunted_house));
    strcpy(new_house->name, name);
    new_house->rooms = rooms;
    new_house->next = NULL;

    if (head == NULL) {
        head = new_house;
    } else {
        haunted_house *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_house;
    }
}

// Function to simulate the haunted house
void simulate_house(haunted_house *house) {
    printf("Welcome to the haunted house of %s.\n", house->name);
    printf("There are %d rooms in this house.\n", house->rooms);
    printf("Please enter the room number you want to visit:\n");
    int room_number = scanf("%d");

    switch (room_number) {
        case 1:
            printf("You have entered the living room.\n");
            break;
        case 2:
            printf("You have entered the kitchen.\n");
            break;
        case 3:
            printf("You have entered the bedroom.\n");
            break;
        default:
            printf("Invalid room number.\n");
    }

    printf("Thank you for visiting the haunted house of %s.\n", house->name);
}

int main() {
    // Add some haunted houses to the list
    add_house("The Blackwood Mansion", 10);
    add_house("The Thornwood Estate", 12);
    add_house("The Winchester Mystery House", 8);

    // Simulate the haunted house
    simulate_house(head);

    return 0;
}