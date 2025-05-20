//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for a haunted house
typedef struct haunted_house {
    char name[20];
    int year_built;
    float square_footage;
    struct haunted_house* next;
} haunted_house;

// Define a function to create a haunted house
haunted_house* create_haunted_house(char* name, int year_built, float square_footage) {
    haunted_house* house = malloc(sizeof(haunted_house));
    strcpy(house->name, name);
    house->year_built = year_built;
    house->square_footage = square_footage;
    house->next = NULL;
    return house;
}

// Define a function to add a haunted house to a list
void add_haunted_house(haunted_house* head, haunted_house* new_house) {
    if (head == NULL) {
        head = new_house;
    } else {
        new_house->next = head;
        head = new_house;
    }
}

// Define a function to simulate a haunted house
void simulate_haunted_house(haunted_house* head) {
    while (head) {
        printf("%s was built in %d and is %f square feet.\n", head->name, head->year_built, head->square_footage);
        head = head->next;
    }
}

int main() {
    // Create a haunted house list
    haunted_house* head = NULL;

    // Add some haunted houses to the list
    add_haunted_house(head, create_haunted_house("The Winchester Mystery House", 1883, 13000));
    add_haunted_house(head, create_haunted_house("The Lizzie Borden House", 1892, 1600));
    add_haunted_house(head, create_haunted_house("The Amityville Horror House", 1974, 2000));

    // Simulate the haunted house list
    simulate_haunted_house(head);

    return 0;
}