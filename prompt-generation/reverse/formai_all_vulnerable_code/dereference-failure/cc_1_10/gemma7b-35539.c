//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct HauntedHouse {
    char name[20];
    int yearBuilt;
    float squareFootage;
    struct HauntedHouse* next;
} HauntedHouse;

// Create a haunted house
HauntedHouse* createHauntedHouse(char* name, int yearBuilt, float squareFootage) {
    HauntedHouse* house = malloc(sizeof(HauntedHouse));
    strcpy(house->name, name);
    house->yearBuilt = yearBuilt;
    house->squareFootage = squareFootage;
    house->next = NULL;
    return house;
}

// Add a haunted house to the end of the list
void addHauntedHouse(HauntedHouse* head, char* name, int yearBuilt, float squareFootage) {
    HauntedHouse* newHouse = createHauntedHouse(name, yearBuilt, squareFootage);
    if (head == NULL) {
        head = newHouse;
    } else {
        HauntedHouse* currentHouse = head;
        while (currentHouse->next != NULL) {
            currentHouse = currentHouse->next;
        }
        currentHouse->next = newHouse;
    }
}

// Simulate the haunted house
void simulateHauntedHouse(HauntedHouse* head) {
    time_t t = time(NULL);
    int i = 0;
    for (i = 0; i < 10; i++) {
        printf("Current time: %s\n",ctime(NULL));
        sleep(1);
        t++;
    }

    printf("The haunted house has been active for %d hours.\n", t - time(NULL));
}

int main() {
    HauntedHouse* head = NULL;
    addHauntedHouse(head, "The Old Victorian", 1880, 5000);
    addHauntedHouse(head, "The Blackwood Mansion", 1920, 10000);
    addHauntedHouse(head, "The Thornhill Estate", 1900, 7000);

    simulateHauntedHouse(head);

    return 0;
}