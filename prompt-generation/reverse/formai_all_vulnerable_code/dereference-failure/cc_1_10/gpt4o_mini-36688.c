//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void paranoidPrint(const char *msg);
void recursiveAlert(int depth);
int isEven(int num);

int main() {
    // Paranoid welcome message
    paranoidPrint("Welcome to the Paranoid Recursive Alert System!");
    
    // Starting the recursive alert system
    paranoidPrint("Initiating recursive alert sequence...");
    
    // Set a maximum depth for recursion
    const int maxDepth = 5; 
    recursiveAlert(maxDepth);
    
    // Paranoid conclusion
    paranoidPrint("Recursive alert system has completed. Proceed with caution!");
    
    return 0;
}

// Function to print messages in a paranoid style
void paranoidPrint(const char *msg) {
    // Print each character with a pause to add to the paranoia
    for (int i = 0; msg[i] != '\0'; i++) {
        putchar(msg[i]);
        fflush(stdout);  // Ensure immediate output
        usleep(100000);  // Sleep for 0.1 seconds (100000 microseconds)
    }
    putchar('\n');
}

// Recursive function that alerts the user about its depth
void recursiveAlert(int depth) {
    // Base case to stop recursion
    if (depth < 0) {
        return;
    }
    
    // Paranoia regarding depth
    paranoidPrint("WARNING: Current depth of recursion is critical!"); 
    char msg[50]; 
    sprintf(msg, "You are at depth: %d", depth);
    paranoidPrint(msg);
    
    // Check if the depth is even or odd and alert accordingly
    if (isEven(depth)) {
        paranoidPrint("This is an even depth... Are we safe?");
    } else {
        paranoidPrint("This is an odd depth... Danger lurks nearby!");
    }

    // Recursive call
    recursiveAlert(depth - 1);
}

// Function to determine if a number is even
int isEven(int num) {
    return num % 2 == 0;
}