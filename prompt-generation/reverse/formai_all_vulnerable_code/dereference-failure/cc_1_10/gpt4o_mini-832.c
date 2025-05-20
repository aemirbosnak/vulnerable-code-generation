//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Define a whimsical structure to represent a magical potion
typedef struct {
    char name[30];
    int potency; // Potency level from 1 to 100
} Potion;

// Function declarations
Potion* create_potion(const char* name, int potency);
void use_potion(Potion* potion);
void handle_error(const char* message, int error_code);
void free_potion(Potion* potion);

int main() {
    // A magical adventure begins!
    printf("Welcome to the Potion Crafting Workshop!\n");
    
    // Create a potion with user input
    char potionName[30];
    int potency;
    
    printf("Enter the name of the potion (up to 29 characters): ");
    if (fgets(potionName, sizeof(potionName), stdin) == NULL) {
        handle_error("Failed to read potion name", errno);
        return EXIT_FAILURE;
    }
    // Remove newline character from fgets
    potionName[strcspn(potionName, "\n")] = 0;

    printf("Enter the potency level (1-100): ");
    if (scanf("%d", &potency) != 1) {
        handle_error("Invalid input for potency level", errno);
        return EXIT_FAILURE;
    }

    // Create the potion
    Potion* myPotion = create_potion(potionName, potency);
    if (myPotion == NULL) {
        return EXIT_FAILURE; // Error handling already done in create_potion
    }

    // Use the potion
    use_potion(myPotion);

    // Clean up
    free_potion(myPotion);
    printf("Potion used and memory freed. Adventure continues!\n");

    return EXIT_SUCCESS;
}

// Function to create a potion
Potion* create_potion(const char* name, int potency) {
    if (potency < 1 || potency > 100) {
        handle_error("Potency must be between 1 and 100", EINVAL);
        return NULL;
    }

    Potion* potion = (Potion*)malloc(sizeof(Potion));
    if (potion == NULL) {
        handle_error("Failed to allocate memory for potion", errno);
        return NULL;
    }

    strncpy(potion->name, name, sizeof(potion->name) - 1);
    potion->name[sizeof(potion->name) - 1] = '\0'; // Ensure null-termination
    potion->potency = potency;

    printf("Potion '%s' with potency %d has been successfully crafted!\n", potion->name, potion->potency);
    return potion;
}

// Function to use the potion
void use_potion(Potion* potion) {
    if (potion == NULL) {
        handle_error("Cannot use a potion that does not exist", EINVAL);
        return;
    }

    printf("Using potion '%s'...\n", potion->name);
    if (potion->potency > 50) {
        printf("Wow! You feel a surge of energy!\n");
    } else {
        printf("You feel a mild tingling sensation.\n");
    }
}

// Function to handle errors
void handle_error(const char* message, int error_code) {
    fprintf(stderr, "Error: %s (Code: %d)\n", message, error_code);
    // Could add more error handling logic here, like logging
}

// Function to free potion memory
void free_potion(Potion* potion) {
    if (potion != NULL) {
        free(potion);
        potion = NULL; // Good practice to avoid dangling pointers
    }
}