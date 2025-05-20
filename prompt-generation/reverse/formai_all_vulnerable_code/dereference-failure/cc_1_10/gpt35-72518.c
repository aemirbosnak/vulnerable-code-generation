//FormAI DATASET v1.0 Category: Memory management ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KINGDOM_SIZE 1000
#define MIN_ALLOC 20
#define MAX_ALLOC 200

int *kingdom;
int gold_reserve = 1000;

// Function to randomly generate a number between min and max
int generate_random(int min, int max) {
    static int init = 0;
    if (init == 0) {
        srand(time(NULL));
        init = 1;
    }
    return min + rand() % (max - min + 1);
}

// Function to allocate memory for a knight's castle
int *allocate_castle(int size) {
    if (size < MIN_ALLOC || size > MAX_ALLOC) {
        printf("Sorry, cannot allocate memory for castle of size %d. Must be between %d and %d.\n", size, MIN_ALLOC, MAX_ALLOC);
        return NULL;
    }

    int cost = size * 10; // Cost to build a castle
    if (cost > gold_reserve) {
        printf("Sorry, cannot allocate memory for castle of size %d. Insufficient gold reserves.\n", size);
        return NULL;
    }

    gold_reserve -= cost; // Deduct the cost of the castle from the gold reserve

    int *castle = (int *) malloc(size * sizeof(int)); // Allocate memory for the castle
    if (castle == NULL) {
        printf("Sorry, unable to allocate memory for castle of size %d.\n", size);
        return NULL;
    }

    // Fill the castle with random values between 1 and 100 inclusive
    for (int i = 0; i < size; i++) {
        castle[i] = generate_random(1, 100);
    }

    return castle; // Return the pointer to the castle
}

// Function to free memory previously allocated for a knight's castle
void free_castle(int *castle) {
    // Check if the castle pointer is null
    if (castle == NULL) {
        printf("Sorry, cannot free null pointer.\n");
        return;
    }

    int size = *(&castle + 1) - castle; // Calculate the size of the castle
    gold_reserve += size * 5; // Add gold to the reserve (half the cost of building the castle)

    free(castle); // Free the memory allocated for the castle
}

int main() {
    kingdom = (int *) malloc(KINGDOM_SIZE * sizeof(int)); // Allocate memory for the kingdom

    // Fill the kingdom with random values between 1 and 1000 inclusive
    for (int i = 0; i < KINGDOM_SIZE; i++) {
        kingdom[i] = generate_random(1, 1000);
    }

    // Allocate memory for 5 knight's castles
    int *castle1 = allocate_castle(50);
    int *castle2 = allocate_castle(30);
    int *castle3 = allocate_castle(80);
    int *castle4 = allocate_castle(150);
    int *castle5 = allocate_castle(200);

    // Print the contents of the castles
    if (castle1 != NULL) {
        printf("Castle 1:\n");
        for (int i = 0; i < 50; i++) {
            printf("%d ", castle1[i]);
        }
        printf("\n");
    }

    if (castle2 != NULL) {
        printf("Castle 2:\n");
        for (int i = 0; i < 30; i++) {
            printf("%d ", castle2[i]);
        }
        printf("\n");
    }

    if (castle3 != NULL) {
        printf("Castle 3:\n");
        for (int i = 0; i < 80; i++) {
            printf("%d ", castle3[i]);
        }
        printf("\n");
    }

    if (castle4 != NULL) {
        printf("Castle 4:\n");
        for (int i = 0; i < 150; i++) {
            printf("%d ", castle4[i]);
        }
        printf("\n");
    }

    if (castle5 != NULL) {
        printf("Castle 5:\n");
        for (int i = 0; i < 200; i++) {
            printf("%d ", castle5[i]);
        }
        printf("\n");
    }

    // Free the memory previously allocated for the castles
    free_castle(castle1);
    free_castle(castle2);
    free_castle(castle3);
    free_castle(castle4);
    free_castle(castle5);

    free(kingdom); // Free the memory allocated for the kingdom

    printf("Gold reserve after memory management: %d\n", gold_reserve);

    return 0;
}