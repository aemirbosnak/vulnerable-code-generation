//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateRandomArray(int arr[], int size);
void displayArray(int arr[], int size);
int linearSearch(int arr[], int size, int target);
void displayResult(int index, int target);

// The main function - the heart of our puzzle
int main() {
    int size, target, index;
    
    // Setting the stage - Ask the user for the size of the array
    printf("Welcome to the Great Searching Quest!\n");
    printf("Tell me, brave seeker, how large shall your array be? ");
    scanf("%d", &size);
    
    // The treasure map - An array to hold random treasures
    int arr[size];

    // Generating treasures
    generateRandomArray(arr, size);
    
    // Show the treasures
    printf("\nBehold the treasures!\n");
    displayArray(arr, size);
    
    // Defining the target - What are we looking for?
    printf("\nNow, noble adventurer, enter your target treasure value: ");
    scanf("%d", &target);

    // Let's begin the search!
    index = linearSearch(arr, size, target);
    
    // Present the spoils of the search
    displayResult(index, target);
    
    // Ending message
    printf("\nThank you for participating in the Great Searching Quest. Farewell!\n");
    
    return 0;
}

// Function to generate a random array of treasures
void generateRandomArray(int arr[], int size) {
    srand(time(NULL)); // Seed for randomness
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Treasures between 0 and 99
    }
}

// Function to display the array of treasures
void displayArray(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Linear Search function - the quest for the target treasure
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Treasure found!
        }
    }
    return -1; // No treasure found
}

// Function to display the search result
void displayResult(int index, int target) {
    if (index != -1) {
        printf("Huzzah! You have found the treasure: %d at index %d!\n", target, index);
    } else {
        printf("Alas! The treasure %d is not among these riches!\n", target);
    }
}