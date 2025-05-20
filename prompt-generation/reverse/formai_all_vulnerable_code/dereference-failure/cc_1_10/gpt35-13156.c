//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20

typedef struct Element {
    int atomic_number;
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    float atomic_mass;
    int electron_configuration[7];
} Element;

// Function that allocates memory for each element of the periodic table
Element* allocate_elements() {
    Element* elements = (Element*) malloc(sizeof(Element) * MAX_ELEMENTS);

    elements[0] = (Element) {
        .atomic_number = 1,
        .symbol = "H",
        .name = "Hydrogen",
        .category = "Non-metal",
        .atomic_mass = 1.008,
        .electron_configuration = {1}
    };

    // Populate the rest of the elements here...

    return elements;
}

// Function to print a given element
void print_element(Element e) {
    printf("%s (%s)\n", e.name, e.symbol);
    printf("Atomic Number: %d\n", e.atomic_number);
    printf("Category: %s\n", e.category);
    printf("Atomic Mass: %.3f\n", e.atomic_mass);
    printf("Electron Configuration: ");

    for(int i=0; i<7; i++) {
        if(e.electron_configuration[i] != 0) {
            printf("%d ", e.electron_configuration[i]);
        } else {
            break;
        }
    }

    printf("\n\n");
}

// Function to get a user's guess for an element based on its symbol
char* get_user_guess() {
    char *guess = (char*) malloc(sizeof(char) * 3);

    printf("Enter your guess: ");
    scanf("%2s", guess);

    return guess;
}

int main() {
    Element* elements = allocate_elements();
    char *user_guess;
    int correct_guesses = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("Guess the element based on its symbol.\n");
    printf("Type 'exit' to end the game.\n\n");

    while(correct_guesses < MAX_ELEMENTS) {
        // Get a random element
        int random_index = rand() % MAX_ELEMENTS;
        Element random_element = elements[random_index];

        // Print out the symbol with underscores in place of letters
        for(int i=0; i<strlen(random_element.symbol); i++) {
            printf("_ ");
        }
        printf("\n");

        // Get the user's guess
        user_guess = get_user_guess();

        // Check if the user wants to exit the game
        if(strcmp(user_guess, "exit") == 0) {
            printf("Thanks for playing!\n");
            break;
        }
        
        // Check if the user's guess is correct
        if(strcmp(user_guess, random_element.symbol) == 0) {
            printf("\nCorrect! The element was: ");
            print_element(random_element);
            correct_guesses++;
        } else {
            printf("Incorrect. Try again.\n\n");
        }
    }

    free(elements);
    free(user_guess);

    return 0;
}