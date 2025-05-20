//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct HauntedHouse {
    char name[20];
    int yearBuilt;
    struct HauntedHouse* next;
} HauntedHouse;

// Function to create a haunted house
HauntedHouse* createHauntedHouse(char* name, int yearBuilt) {
    HauntedHouse* house = (HauntedHouse*)malloc(sizeof(HauntedHouse));
    strcpy(house->name, name);
    house->yearBuilt = yearBuilt;
    house->next = NULL;
    return house;
}

// Function to add a haunted house to the end of the list
void addHauntedHouse(HauntedHouse* head, char* name, int yearBuilt) {
    HauntedHouse* newHouse = createHauntedHouse(name, yearBuilt);
    if (head == NULL) {
        head = newHouse;
    } else {
        HauntedHouse* tempHouse = head;
        while (tempHouse->next != NULL) {
            tempHouse = tempHouse->next;
        }
        tempHouse->next = newHouse;
    }
}

// Function to simulate the haunted house
void simulateHauntedHouse(HauntedHouse* head) {
    time_t t = time(NULL);
    srand(t);
    HauntedHouse* currentHouse = head;
    while (currentHouse) {
        printf("You are in the %s, built in %d.\n", currentHouse->name, currentHouse->yearBuilt);
        int randNum = rand() % 3;
        switch (randNum) {
            case 0:
                printf("You hear a strange noise.\n");
                break;
            case 1:
                printf("You smell a strong odor.\n");
                break;
            case 2:
                printf("You see a ghostly figure.\n");
                break;
        }
        currentHouse = currentHouse->next;
    }
}

int main() {
    HauntedHouse* head = NULL;
    addHauntedHouse(head, "The Old House", 1880);
    addHauntedHouse(head, "The Thornbush Inn", 1920);
    addHauntedHouse(head, "The Blackwood Manor", 1750);

    simulateHauntedHouse(head);

    return 0;
}