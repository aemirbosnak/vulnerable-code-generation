//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct haunted_house {
    char name[20];
    int year_built;
    float square_footage;
    struct haunted_house* next;
} haunted_house;

// Create a linked list of haunted houses
haunted_house* head = NULL;

// Function to add a haunted house to the list
void add_haunted_house(char* name, int year_built, float square_footage) {
    haunted_house* new_house = malloc(sizeof(haunted_house));
    strcpy(new_house->name, name);
    new_house->year_built = year_built;
    new_house->square_footage = square_footage;
    new_house->next = NULL;

    if (head == NULL) {
        head = new_house;
    } else {
        haunted_house* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_house;
    }
}

// Function to simulate the haunted house
void simulate_haunted_house() {
    haunted_house* current = head;
    while (current) {
        printf("Name: %s\n", current->name);
        printf("Year built: %d\n", current->year_built);
        printf("Square footage: %.2f\n", current->square_footage);
        printf("\n");
        current = current->next;
    }
}

int main() {
    // Add some haunted houses to the list
    add_haunted_house("The Blackwood Mansion", 1880, 10000);
    add_haunted_house("The Amityville Horror", 1974, 3000);
    add_haunted_house("The Winchester Mystery House", 1886, 25000);

    // Simulate the haunted house
    simulate_haunted_house();

    return 0;
}