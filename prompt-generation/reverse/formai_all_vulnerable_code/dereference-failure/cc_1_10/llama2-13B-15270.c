//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: artistic
// A Celestial Phone Book for the Gods

#include <stdlib.h>
#include <string.h>

// Define the structure for a celestial being
typedef struct {
    char name[50];    // Name of the being
    char domain[50];  // Domain of the being
    char description[100]; // Description of the being
} celestial_being;

// Define the array to store the celestial beings
celestial_being gods[10];

// Function to insert a new celestial being into the array
void insert_being(char *name, char *domain, char *description) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(gods[i].name, name) == 0) {
            // Being already exists, do nothing
            return;
        }
    }
    // Insert the new being at the end of the array
    strcpy(gods[i].name, name);
    strcpy(gods[i].domain, domain);
    strcpy(gods[i].description, description);
}

// Function to search for a celestial being in the array
celestial_being *search_being(char *name) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(gods[i].name, name) == 0) {
            return &gods[i];
        }
    }
    return NULL;
}

// Function to print the contents of the array
void print_beings() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d: %s (%s)\n", i, gods[i].name, gods[i].domain);
    }
}

int main() {
    // Insert some celestial beings into the array
    insert_being("Apollo", "Music and Prophecy", "God of the Lyre and the Oracle");
    insert_being("Artemis", "Hunting and the Moon", "Goddess of the Hunt and the Night Sky");
    insert_being("Ares", "War and Bloodlust", "God of Battle and Conflict");

    // Search for a celestial being in the array
    celestial_being *apollo = search_being("Apollo");
    if (apollo != NULL) {
        printf("Found Apollo! His domain is Music and Prophecy, and his description is God of the Lyre and the Oracle.\n");
    } else {
        printf("Apollo not found.\n");
    }

    // Print the contents of the array
    print_beings();

    return 0;
}