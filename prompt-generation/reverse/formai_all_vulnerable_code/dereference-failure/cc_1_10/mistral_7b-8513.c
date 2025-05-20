//MISTRAL-7B DATASET v1.0 Category: Benchmarking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Define structures and constants for the game
typedef struct {
    int strength;
    int agility;
    char name[50];
} Knight;

#define NUM_KNIGHTS 100000
#define MAX_NAME_LENGTH 50

// Function to generate random names for knights
void generate_name(char* name) {
    strcpy(name, "");
    int roll = rand() % 26;
    name[0] = 'K' + roll;
    for (int i = 1; i < MAX_NAME_LENGTH; i++) {
        roll = rand() % 26;
        name[i] = 'A' + (roll % 14) + (i % 2 == 0 ? 'a' : 'A');
    }
}

// Function to create a new knight
Knight create_knight() {
    Knight knight;
    generate_name(knight.name);
    knight.strength = rand() % 100 + 1;
    knight.agility = rand() % 100 + 1;
    return knight;
}

// Function to initialize the array of knights
void init_knights(Knight* knights) {
    for (int i = 0; i < NUM_KNIGHTS; i++) {
        knights[i] = create_knight();
    }
}

// Function to calculate the total strength and agility of all knights
int total_stats(Knight* knights) {
    int total_strength = 0;
    int total_agility = 0;
    for (int i = 0; i < NUM_KNIGHTS; i++) {
        total_strength += knights[i].strength;
        total_agility += knights[i].agility;
    }
    return total_strength * total_agility;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Allocate memory for the array of knights
    Knight* knights = (Knight*) malloc(NUM_KNIGHTS * sizeof(Knight));

    // Initialize the knights
    init_knights(knights);

    // Calculate the total stats of all knights
    clock_t start = clock();
    int total = total_stats(knights);
    clock_t end = clock();

    // Print the results
    printf("The total stats of %d Mighty Integer Knights is: %d\n", NUM_KNIGHTS, total);
    printf("Time taken to calculate the total stats: %.3f ms\n", (end - start) * 1000.0 / CLOCKS_PER_SEC);

    // Free the memory allocated for the knights
    free(knights);

    // Exit the program
    return 0;
}