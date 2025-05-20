//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of fortunes to choose from
#define NUM_FORTUNES 100

// Define the structure to hold each fortune
typedef struct {
    char* message;
    int length;
} Fortune;

// Function to initialize the fortunes
void initFortunes(Fortune* fortunes) {
    int i;
    for (i = 0; i < NUM_FORTUNES; i++) {
        fortunes[i].message = malloc(256);
        fortunes[i].length = rand() % 256;
        sprintf(fortunes[i].message, "Fortune %d: ", i+1);
        int j;
        for (j = 0; j < fortunes[i].length; j++) {
            fortunes[i].message[j+15] = rand() % 26 + 'A';
        }
        fortunes[i].message[fortunes[i].length+14] = '\0';
    }
}

// Function to print a fortune
void printFortune(Fortune fortune) {
    printf("%s\n", fortune.message);
}

// Function to choose a random fortune
Fortune chooseFortune(Fortune* fortunes) {
    return fortunes[rand() % NUM_FORTUNES];
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Initialize the fortunes
    Fortune fortunes[NUM_FORTUNES];
    initFortunes(fortunes);

    // Choose a fortune
    Fortune chosenFortune = chooseFortune(fortunes);

    // Print the chosen fortune
    printFortune(chosenFortune);

    return 0;
}