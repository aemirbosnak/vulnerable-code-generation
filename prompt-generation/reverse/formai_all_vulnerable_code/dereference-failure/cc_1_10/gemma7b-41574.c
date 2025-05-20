//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct HauntedHouse {
    char name[20];
    int yearBuilt;
    char address[50];
    struct HauntedHouse* next;
} HauntedHouse;

HauntedHouse* createHauntedHouse(char* name, int yearBuilt, char* address) {
    HauntedHouse* house = (HauntedHouse*)malloc(sizeof(HauntedHouse));
    strcpy(house->name, name);
    house->yearBuilt = yearBuilt;
    strcpy(house->address, address);
    house->next = NULL;
    return house;
}

void addHauntedHouse(HauntedHouse* head, char* name, int yearBuilt, char* address) {
    HauntedHouse* house = createHauntedHouse(name, yearBuilt, address);
    if (head == NULL) {
        head = house;
    } else {
        house->next = head;
        head = house;
    }
}

void hauntHouse(HauntedHouse* head) {
    time_t t = time(NULL);
    srand(t);
    HauntedHouse* currentHouse = head;
    while (currentHouse) {
        int chance = rand() % 100;
        if (chance < 20) {
            printf("The haunted house of %s is whispering secrets...\n", currentHouse->name);
        } else if (chance < 40) {
            printf("A ghostly figure roams the halls of %s...\n", currentHouse->name);
        } else if (chance < 60) {
            printf("The smell of decay fills the air in %s...\n", currentHouse->name);
        } else if (chance < 80) {
            printf("A chilling scream echoes through the night in %s...\n", currentHouse->name);
        } else if (chance < 100) {
            printf("The hairs on your neck stand on end as you sense an unnatural presence in %s...\n", currentHouse->name);
        }
        currentHouse = currentHouse->next;
    }
}

int main() {
    HauntedHouse* head = NULL;
    addHauntedHouse(head, "The Blackwood Mansion", 1890, "123 Main St.");
    addHauntedHouse(head, "The Thornfield Hall", 1850, "456 Oak Ave.");
    addHauntedHouse(head, "The Briarcliff Manor", 1820, "789 Oak St.");

    hauntHouse(head);

    return 0;
}