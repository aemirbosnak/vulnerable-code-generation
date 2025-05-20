//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Let's imagine we're running a bustling city with skyscrapers and cozy apartments.

// Define a "building" struct to represent each block in our city.
typedef struct building {
    int floors;                  // How many stories does this building have?
    char **apartments;         // An array of pointers to the apartments in this building
    int num_apartments;         // How many apartments are in this building?
} building;

// Oopsy, our bustling city is empty! Let's build some buildings...

building *construct_building(int floors, int num_apartments) {
    // Allocate memory for our new building.
    building *new_building = (building *)malloc(sizeof(building));
    if (new_building == NULL) {
        fprintf(stderr, "Oops! Ran out of memory while building the city...\n");
        return NULL;
    }

    // Assign the values to the building's properties.
    new_building->floors = floors;
    new_building->num_apartments = num_apartments;

    // Allocate memory for the array of apartment pointers.
    new_building->apartments = (char **)malloc(sizeof(char *) * num_apartments);
    if (new_building->apartments == NULL) {
        fprintf(stderr, "Whoops! Ran out of memory while allocating apartments...\n");
        free(new_building); // Remember to clean up after ourselves!
        return NULL;
    }

    // Let's not leave our apartments empty. Populate them with residents.
    for (int i = 0; i < num_apartments; i++) {
        // Each apartment is represented by a simple string. Let's create one.
        char *resident = (char *)malloc(20); // Assuming each resident's name is less than 20 characters long
        if (resident == NULL) {
            fprintf(stderr, "Oops! Out of memory while populating apartments...\n");
            // Time to demolish this building and its incomplete apartments...
            free(new_building->apartments);
            free(new_building);
            return NULL;
        }

        // Let's give this apartment a creative resident name.
        snprintf(resident, 20, "Resident %d", i + 1);
        new_building->apartments[i] = resident;
    }

    // Our building is complete and ready for residents to move in!
    return new_building;
}

// Time to take a tour of our vibrant city and meet its residents.

void explore_city(building *city[], int num_buildings) {
    for (int i = 0; i < num_buildings; i++) {
        // Let's knock on each building's door and introduce ourselves.
        printf("Welcome to Building %d!\n", i + 1);
        printf("This building has %d floors and %d apartments.\n", city[i]->floors, city[i]->num_apartments);

        // Let's meet the friendly neighbors in each apartment.
        for (int j = 0; j < city[i]->num_apartments; j++) {
            printf("Apartment %d: Meet %s!\n", j + 1, city[i]->apartments[j]);
        }
        printf("\n");
    }
}

// Alas, our city's glory days must come to an end. Time to demolish it and reclaim the memory.

void demolish_city(building *city[], int num_buildings) {
    for (int i = 0; i < num_buildings; i++) {
        // Let's evict the residents and pack up their belongings.
        for (int j = 0; j < city[i]->num_apartments; j++) {
            free(city[i]->apartments[j]);
        }
        // Time to tear down this building.
        free(city[i]->apartments);
        free(city[i]);
    }
}

// Let's get our city up and running!

int main() {
    // Create an array of buildings to represent our bustling city.
    building *our_city[5];

    // Construct each building with varying sizes and apartments.
    our_city[0] = construct_building(10, 5);
    our_city[1] = construct_building(20, 10);
    our_city[2] = construct_building(15, 8);
    our_city[3] = construct_building(25, 12);
    our_city[4] = construct_building(30, 15);

    // Let's explore our vibrant city and meet its residents.
    printf("Welcome to our magnificent metropolis!\n");
    explore_city(our_city, 5);

    // Time to bid farewell to our city and reclaim the memory it occupied.
    demolish_city(our_city, 5);

    return 0;
}