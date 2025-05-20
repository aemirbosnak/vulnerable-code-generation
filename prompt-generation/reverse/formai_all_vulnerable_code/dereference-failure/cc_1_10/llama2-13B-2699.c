//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BRAVE_MAX_SAFARI 5
#define BRAVE_MIN_SAFARI 2

// Structure to store safari information
typedef struct {
    int num_lions;   // Number of lions in the safari
    int num_zebras;  // Number of zebras in the safari
    int num_giraffes; // Number of giraffes in the safari
} safari_t;

// Function to generate a random safari
safari_t *generate_safari(void) {
    safari_t *safari = malloc(sizeof(safari_t));

    int num_lions = rand() % BRAVE_MAX_SAFARI + BRAVE_MIN_SAFARI;
    int num_zebras = rand() % BRAVE_MAX_SAFARI + BRAVE_MIN_SAFARI;
    int num_giraffes = rand() % BRAVE_MAX_SAFARI + BRAVE_MIN_SAFARI;

    safari->num_lions = num_lions;
    safari->num_zebras = num_zebras;
    safari->num_giraffes = num_giraffes;

    return safari;
}

// Function to print the safari
void print_safari(safari_t *safari) {
    printf("Safari: \n");
    printf("  Lions: %d\n", safari->num_lions);
    printf("  Zebras: %d\n", safari->num_zebras);
    printf("  Giraffes: %d\n", safari->num_giraffes);
}

int main(void) {
    safari_t *safari1 = generate_safari();
    safari_t *safari2 = generate_safari();

    print_safari(safari1);
    print_safari(safari2);

    // Randomly simulate a battle between the two safaris
    if (rand() % 2 == 0) {
        safari1->num_lions += safari2->num_zebras;
        safari2->num_zebras = 0;
    } else {
        safari2->num_giraffes += safari1->num_lions;
        safari1->num_lions = 0;
    }

    print_safari(safari1);
    print_safari(safari2);

    return 0;
}