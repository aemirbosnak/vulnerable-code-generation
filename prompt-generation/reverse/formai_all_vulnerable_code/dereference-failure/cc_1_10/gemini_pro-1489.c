//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Define a custom data structure to represent a medieval tavern
struct Tavern {
    char *name;            // Name of the tavern
    int num_tables;      // Number of tables in the tavern
    int num_patrons;     // Number of patrons currently in the tavern
    char **patrons_names; // Array of strings containing the names of the patrons
};

// Define a function to create a new tavern
struct Tavern *create_tavern(char *name, int num_tables) {
    struct Tavern *tavern = malloc(sizeof(struct Tavern));
    tavern->name = name;
    tavern->num_tables = num_tables;
    tavern->num_patrons = 0;
    tavern->patrons_names = NULL;
    return tavern;
}

// Define a function to add a new patron to the tavern
void add_patron(struct Tavern *tavern, char *name) {
    // Reallocate memory for the array of patron names
    tavern->patrons_names = realloc(tavern->patrons_names, (tavern->num_patrons + 1) * sizeof(char *));
    // Store the new patron's name in the array
    tavern->patrons_names[tavern->num_patrons] = name;
    // Increment the number of patrons
    tavern->num_patrons++;
}

// Define a function to remove a patron from the tavern
void remove_patron(struct Tavern *tavern, char *name) {
    int i;
    // Find the index of the patron to be removed
    for (i = 0; i < tavern->num_patrons; i++) {
        if (strcmp(tavern->patrons_names[i], name) == 0) {
            break;
        }
    }
    // If the patron was found, remove them from the array
    if (i < tavern->num_patrons) {
        for (int j = i; j < tavern->num_patrons - 1; j++) {
            tavern->patrons_names[j] = tavern->patrons_names[j + 1];
        }
        // Decrement the number of patrons
        tavern->num_patrons--;
        // Reallocate memory for the array of patron names
        tavern->patrons_names = realloc(tavern->patrons_names, tavern->num_patrons * sizeof(char *));
    }
}

// Define a function to print the tavern's details
void print_tavern(struct Tavern *tavern) {
    printf("**The %s**\n", tavern->name);
    printf("Number of tables: %d\n", tavern->num_tables);
    printf("Number of patrons: %d\n", tavern->num_patrons);
    if (tavern->num_patrons > 0) {
        printf("Patrons:\n");
        for (int i = 0; i < tavern->num_patrons; i++) {
            printf("  * %s\n", tavern->patrons_names[i]);
        }
    } else {
        printf("The tavern is empty.\n");
    }
}

// Main function
int main() {
    // Create a new tavern
    struct Tavern *tavern = create_tavern("The Prancing Pony", 10);

    // Add some patrons to the tavern
    add_patron(tavern, "Frodo Baggins");
    add_patron(tavern, "Samwise Gamgee");
    add_patron(tavern, "Gandalf the Grey");
    add_patron(tavern, "Aragorn son of Arathorn");

    // Print the tavern's details
    print_tavern(tavern);

    // Remove a patron from the tavern
    remove_patron(tavern, "Gandalf the Grey");

    // Print the tavern's details again
    print_tavern(tavern);

    // Free the memory allocated for the tavern
    free(tavern->patrons_names);
    free(tavern);

    return 0;
}