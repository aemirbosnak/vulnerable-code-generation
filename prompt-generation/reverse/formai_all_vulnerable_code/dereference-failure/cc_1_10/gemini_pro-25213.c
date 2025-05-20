//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our trusty database of suspects
typedef struct suspect {
    char *name;
    char *weapon;
    char *motive;
} suspect_t;

// An array of our suspects
suspect_t suspects[] = {
    { "John Watson", "Revolver", "Jealousy" },
    { "Irene Adler", "Poison", "Revenge" },
    { "Professor Moriarty", "Knife", "Power" },
    { "Charles Augustus Milverton", "Blackmail", "Greed" },
    { "Inspector Lestrade", "Gun", "Duty" },
};

// The number of suspects
#define NUM_SUSPECTS (sizeof(suspects) / sizeof(suspect_t))

// Our trusty function to print the details of a suspect
void print_suspect(suspect_t *suspect) {
    printf("Name: %s\n", suspect->name);
    printf("Weapon: %s\n", suspect->weapon);
    printf("Motive: %s\n\n", suspect->motive);
}

// Our main function, where the investigation begins
int main(int argc, char *argv[]) {
    // Check if we have a query
    if (argc < 2) {
        printf("Usage: %s <query>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the query
    char *query = argv[1];

    // Loop through the suspects
    for (int i = 0; i < NUM_SUSPECTS; i++) {
        // Check if the query matches the suspect's name, weapon, or motive
        if (strstr(suspects[i].name, query) || strstr(suspects[i].weapon, query) || strstr(suspects[i].motive, query)) {
            // Print the suspect's details
            print_suspect(&suspects[i]);
        }
    }

    return EXIT_SUCCESS;
}