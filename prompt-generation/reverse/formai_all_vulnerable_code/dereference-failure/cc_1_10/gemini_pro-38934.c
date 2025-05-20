//GEMINI-pro DATASET v1.0 Category: Educational ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Ragged scavenger crew
typedef struct Scavenger {
    char *name;
    int num_rations;
    struct Scavenger *next;
} Scavenger;

// Resource-rich bunker
typedef struct Bunker {
    char *location;
    int num_rations;
    struct Bunker *next;
} Bunker;

// Initialize the crew
Scavenger *init_crew(char **names, int num_scavengers) {
    Scavenger *head = NULL;
    Scavenger *current = NULL;

    for (int i = 0; i < num_scavengers; i++) {
        Scavenger *scavenger = malloc(sizeof(Scavenger));
        scavenger->name = names[i];
        scavenger->num_rations = rand() % 10;
        scavenger->next = NULL;

        if (head == NULL) {
            head = scavenger;
            current = scavenger;
        } else {
            current->next = scavenger;
            current = scavenger;
        }
    }

    return head;
}

// Initialize the bunkers
Bunker *init_bunkers(char **locations, int num_bunkers) {
    Bunker *head = NULL;
    Bunker *current = NULL;

    for (int i = 0; i < num_bunkers; i++) {
        Bunker *bunker = malloc(sizeof(Bunker));
        bunker->location = locations[i];
        bunker->num_rations = rand() % 100;
        bunker->next = NULL;

        if (head == NULL) {
            head = bunker;
            current = bunker;
        } else {
            current->next = bunker;
            current = bunker;
        }
    }

    return head;
}

// Scavenge for resources
void scavenge(Scavenger *crew, Bunker *bunkers) {
    Scavenger *current_scavenger = crew;
    Bunker *current_bunker = bunkers;

    while (current_scavenger != NULL && current_bunker != NULL) {
        // Check if scavenger has rations
        if (current_scavenger->num_rations <= 0) {
            printf("Scavenger %s has run out of rations!\n", current_scavenger->name);
            // Remove scavenger from crew
            if (current_scavenger == crew) {
                crew = current_scavenger->next;
            } else {
                Scavenger *prev = crew;
                while (prev->next != current_scavenger) {
                    prev = prev->next;
                }
                prev->next = current_scavenger->next;
            }
            free(current_scavenger);
            current_scavenger = crew;
            continue;
        }

        // Check if bunker has rations
        if (current_bunker->num_rations <= 0) {
            printf("Bunker %s has run out of rations!\n", current_bunker->location);
            // Remove bunker from list
            if (current_bunker == bunkers) {
                bunkers = current_bunker->next;
            } else {
                Bunker *prev = bunkers;
                while (prev->next != current_bunker) {
                    prev = prev->next;
                }
                prev->next = current_bunker->next;
            }
            free(current_bunker);
            current_bunker = bunkers;
            continue;
        }

        // Scavenger takes rations from bunker
        int num_rations_taken = rand() % (current_scavenger->num_rations + current_bunker->num_rations);
        current_scavenger->num_rations += num_rations_taken;
        current_bunker->num_rations -= num_rations_taken;

        printf("Scavenger %s took %d rations from bunker %s.\n", current_scavenger->name, num_rations_taken, current_bunker->location);

        // Move to the next scavenger and bunker
        current_scavenger = current_scavenger->next;
        current_bunker = current_bunker->next;
    }
}

// Main function
int main() {
    char *scavenger_names[] = {"Jack", "Jill", "Bob", "Alice"};
    char *bunker_locations[] = {"Chicago", "New York", "Los Angeles", "San Francisco"};

    int num_scavengers = sizeof(scavenger_names) / sizeof(scavenger_names[0]);
    int num_bunkers = sizeof(bunker_locations) / sizeof(bunker_locations[0]);

    Scavenger *crew = init_crew(scavenger_names, num_scavengers);
    Bunker *bunkers = init_bunkers(bunker_locations, num_bunkers);

    // Scavenge for resources
    scavenge(crew, bunkers);

    // Print the remaining scavengers and their rations
    printf("Remaining scavengers:\n");
    Scavenger *current = crew;
    while (current != NULL) {
        printf("%s: %d rations\n", current->name, current->num_rations);
        current = current->next;
    }

    // Print the remaining bunkers and their rations
    printf("Remaining bunkers:\n");
    Bunker *current_bunker = bunkers;
    while (current_bunker != NULL) {
        printf("%s: %d rations\n", current_bunker->location, current_bunker->num_rations);
        current_bunker = current_bunker->next;
    }

    return 0;
}