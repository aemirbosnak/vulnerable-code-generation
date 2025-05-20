//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_STRING_LENGTH 1024
#define MAX_NUMBER_OF_STARS 10

// Structure to represent a star
typedef struct star {
    char name[MAX_STRING_LENGTH];
    int x;
    int y;
    int brightness;
} star;

// Function to print a star
void print_star(star s) {
    printf("[%s]%c", s.name, s.brightness > 5 ? '*' : ' ');
}

// Function to print a constellation
void print_constellation(star *constellation, int num_stars) {
    int i, j;

    // Print a horizontal line to separate the constellation from the stars
    for (i = 0; i < num_stars; i++) {
        printf("---");
    }

    // Print the stars in the constellation
    for (i = 0; i < num_stars; i++) {
        for (j = 0; j < num_stars; j++) {
            if (i == j) {
                print_star(constellation[i]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to generate a random constellation
star *generate_random_constellation(int num_stars) {
    star *constellation = malloc(num_stars * sizeof(star));
    int i;

    // Generate random names for the stars
    for (i = 0; i < num_stars; i++) {
        constellation[i].name[0] = 'A' + (rand() % 26);
    }

    // Generate random positions for the stars
    for (i = 0; i < num_stars; i++) {
        constellation[i].x = (rand() % 100) - 50;
        constellation[i].y = (rand() % 100) - 50;
    }

    // Generate random brightness for the stars
    for (i = 0; i < num_stars; i++) {
        constellation[i].brightness = (rand() % 10) + 1;
    }

    return constellation;
}

int main() {
    int num_stars = 5;
    star *constellation = generate_random_constellation(num_stars);

    printf("Here is a constellation with %d stars:\n", num_stars);
    print_constellation(constellation, num_stars);

    free(constellation);

    return 0;
}