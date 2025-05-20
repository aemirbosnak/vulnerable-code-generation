//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct HauntedHouse {
    char name[20];
    int rooms;
    struct HauntedHouse* next;
} HauntedHouse;

// Create a linked list of haunted houses
HauntedHouse* createHauntedHouseList() {
    HauntedHouse* head = NULL;
    HauntedHouse* tail = NULL;

    // Allocate memory for the first house
    head = (HauntedHouse*)malloc(sizeof(HauntedHouse));
    tail = head;

    // Set the house name and number of rooms
    strcpy(head->name, "The Thorn Mansion");
    head->rooms = 10;

    // Create the remaining houses
    for (int i = 1; i < 5; i++) {
        tail->next = (HauntedHouse*)malloc(sizeof(HauntedHouse));
        tail = tail->next;
        strcpy(tail->name, "House " + i);
        tail->rooms = i * 5;
    }

    return head;
}

// Simulate a haunted house visit
void simulateHauntedHouseVisit(HauntedHouse* house) {
    // Randomly choose a room
    int roomNumber = rand() % house->rooms;

    // Enter the room
    printf("You have entered room %d.\n", roomNumber);

    // Check if the room is haunted
    if (roomNumber == 3) {
        printf("The room is haunted by a ghostly figure.\n");
    } else {
        printf("The room is not haunted.\n");
    }
}

int main() {
    // Create a linked list of haunted houses
    HauntedHouse* houseList = createHauntedHouseList();

    // Simulate a haunted house visit
    simulateHauntedHouseVisit(houseList);

    return 0;
}