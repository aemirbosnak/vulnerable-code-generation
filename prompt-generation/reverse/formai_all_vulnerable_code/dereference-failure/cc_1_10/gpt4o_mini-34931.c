//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TREASURES 5
#define MAX_LOCATIONS 10

typedef struct Location {
    char name[50];
    int treasures;
    struct Location *next; // linked list of locations
} Location;

Location* createLocation(const char *name, int treasures) {
    Location *loc = (Location *)malloc(sizeof(Location));
    if (loc == NULL) {
        perror("Failed to allocate memory for location");
        exit(EXIT_FAILURE);
    }
    snprintf(loc->name, sizeof(loc->name), "%s", name);
    loc->treasures = treasures;
    loc->next = NULL;
    return loc;
}

void addLocation(Location **head, const char *name, int treasures) {
    Location *new_loc = createLocation(name, treasures);
    new_loc->next = *head;
    *head = new_loc;
}

void freeLocations(Location *head) {
    Location *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void explore(Location *loc, int *totalTreasures) {
    if (loc == NULL) {
        return;
    }
    printf("You have arrived at %s with %d treasures available!\n", loc->name, loc->treasures);
    *totalTreasures += loc->treasures;

    // Recursively explore the next location in the linked list
    explore(loc->next, totalTreasures);
}

int main() {
    srand(time(NULL)); // seed the random number generator

    // Create the magical forest locations
    Location *forest = NULL;
    addLocation(&forest, "Enchanted Glade", rand() % (MAX_TREASURES + 1));
    addLocation(&forest, "Whispering Woods", rand() % (MAX_TREASURES + 1));
    addLocation(&forest, "Mystical Meadow", rand() % (MAX_TREASURES + 1));
    addLocation(&forest, "Ancient Ruins", rand() % (MAX_TREASURES + 1));
    addLocation(&forest, "Silver Stream", rand() % (MAX_TREASURES + 1));

    // The hero begins their adventure
    printf("Welcome to the Magical Forest Adventure!\n");
    printf("Your mission is to collect treasures hidden in different locations.\n");

    int totalTreasures = 0;
    explore(forest, &totalTreasures);

    printf("You've collected a total of %d treasures on your adventure!\n", totalTreasures);

    // Free allocated locations
    freeLocations(forest);

    return 0;
}