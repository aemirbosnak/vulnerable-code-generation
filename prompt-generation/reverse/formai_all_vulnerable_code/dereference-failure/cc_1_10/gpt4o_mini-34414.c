//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function prototype
int linearSearch(char *sequence[], int size, char *target);

// A function to print a helpful guide
void printInstructions() {
    printf("Welcome to the Great Detective's Search Engine!\n");
    printf("In this program, you will help Sherlock Holmes search for clues.\n");
    printf("We will use a linear search to find our desired target in a series of clues.\n");
    printf("Please enter the clues you would like to enter, followed by the target clue to search for.\n");
    printf("When you are done entering clues, enter 'END' to stop.\n");
    printf("--------------------------------------------------\n");
}

// Function to conduct a linear search
int linearSearch(char *sequence[], int size, char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(sequence[i], target) == 0) {
            return i; // Target found, return index
        }
    }
    return -1; // Target not found
}

int main() {
    // Sherlock's clue array
    char *clues[100];
    int clueCount = 0;
    char input[50];
    char target[50];

    // Instructions for the user
    printInstructions();

    // Gather clues from the user
    printf("Enter your clues (type 'END' to finish):\n");
    while (true) {
        printf("Clue %d: ", clueCount + 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        // Check for end of input
        if (strcmp(input, "END") == 0) {
            break;
        }

        // Store the clue in the array
        clues[clueCount] = strdup(input); // Dynamically allocate memory for the clue
        clueCount++;
    }

    // Ask for the target clue Sherlock wishes to find
    printf("Now, enter the target clue Sherlock wants to find:\n");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = 0; // Remove newline character

    // Perform the linear search
    int index = linearSearch(clues, clueCount, target);

    // Provide the results of the search
    if (index != -1) {
        printf("Aha! The target clue '%s' was found at index %d.\n", target, index);
    } else {
        printf("Alas! The clue '%s' could not be found in our gathered clues.\n", target);
    }

    // Free dynamically allocated memory
    for (int i = 0; i < clueCount; i++) {
        free(clues[i]);
    }

    printf("Thank you for assisting Sherlock Holmes in his quest for truth!\n");
    return 0;
}