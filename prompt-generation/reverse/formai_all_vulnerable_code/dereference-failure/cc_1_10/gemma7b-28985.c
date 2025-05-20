//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("clear");

    // Create a haunted house structure
    struct haunted_house
    {
        char name[20];
        int rooms;
        struct haunted_house* next;
    };

    // Create the first haunted house
    struct haunted_house* first_house = (struct haunted_house*)malloc(sizeof(struct haunted_house));
    strcpy(first_house->name, "The Haunted Mansion");
    first_house->rooms = 10;

    // Create the second haunted house
    struct haunted_house* second_house = (struct haunted_house*)malloc(sizeof(struct haunted_house));
    strcpy(second_house->name, "The Bloodstained Cottage");
    second_house->rooms = 5;

    // Create the third haunted house
    struct haunted_house* third_house = (struct haunted_house*)malloc(sizeof(struct haunted_house));
    strcpy(third_house->name, "The Twisted Tower");
    third_house->rooms = 7;

    // Link the haunted houses together
    first_house->next = second_house;
    second_house->next = third_house;

    // Enter the haunted house
    printf("Welcome to the Haunted Mansion!\n");
    printf("Please select a room number:\n");

    // Get the room number from the user
    int room_number = atoi(gets(NULL));

    // Find the room
    struct haunted_house* current_house = first_house;
    while (current_house && current_house->rooms < room_number)
    {
        current_house = current_house->next;
    }

    // If the room was found, display its information
    if (current_house)
    {
        printf("You are in %s.\n", current_house->name);
        printf("There are %d rooms in this house.\n", current_house->rooms);
    }
    else
    {
        printf("Sorry, the room number is not valid.\n");
    }

    return;
}