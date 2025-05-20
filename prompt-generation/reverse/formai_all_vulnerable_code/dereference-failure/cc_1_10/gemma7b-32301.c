//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure to represent a haunted house
typedef struct HauntedHouse {
    char name[20];
    int year_built;
    float square_footage;
    struct HauntedHouse* next;
} HauntedHouse;

HauntedHouse* createHauntedHouse(char* name, int year_built, float square_footage) {
    HauntedHouse* house = malloc(sizeof(HauntedHouse));
    strcpy(house->name, name);
    house->year_built = year_built;
    house->square_footage = square_footage;
    house->next = NULL;
    return house;
}

HauntedHouse* addHauntedHouse(HauntedHouse* head, char* name, int year_built, float square_footage) {
    HauntedHouse* new_house = createHauntedHouse(name, year_built, square_footage);
    if (head == NULL) {
        head = new_house;
    } else {
        HauntedHouse* current_house = head;
        while (current_house->next != NULL) {
            current_house = current_house->next;
        }
        current_house->next = new_house;
    }
    return head;
}

void traverseHauntedHouse(HauntedHouse* head) {
    HauntedHouse* current_house = head;
    while (current_house) {
        printf("Name: %s, Year Built: %d, Square Footage: %.2f\n", current_house->name, current_house->year_built, current_house->square_footage);
        current_house = current_house->next;
    }
}

int main() {
    HauntedHouse* haunted_house_list = NULL;

    // Create a few haunted houses
    addHauntedHouse(haunted_house_list, "The Thorn Mansion", 1890, 10000);
    addHauntedHouse(haunted_house_list, "The Blackwood Estate", 1920, 12000);
    addHauntedHouse(haunted_house_list, "The Raven's Nest", 1850, 8000);

    // Traverse the haunted house list
    traverseHauntedHouse(haunted_house_list);

    return 0;
}