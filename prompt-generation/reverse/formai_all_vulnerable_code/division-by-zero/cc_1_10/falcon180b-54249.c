//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to print a pattern
void print_pattern(int n) {
    int i, j, k;

    // Print the first half of the pattern
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (k = 0; k < 2 * i + 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    // Print the second half of the pattern
    for (i = n - 1; i >= 0; i--) {
        for (j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for (k = 0; k < 2 * i + 1; k++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to generate a random number between min and max
int rand_num(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int n, i, j, k;

    // Get the size of the pattern from the user
    printf("Enter the size of the pattern: ");
    scanf("%d", &n);

    // Print the pattern
    print_pattern(n);

    // Generate a random number between 0 and n-1
    i = rand_num(0, n - 1);

    // Print the pattern with the random row highlighted
    for (j = 0; j < n; j++) {
        if (j == i) {
            for (k = 0; k < 2 * i + 1; k++) {
                printf("*");
            }
        } else {
            for (k = 0; k < 2 * i + 1; k++) {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Generate a random number between 0 and n-1
    j = rand_num(0, n - 1);

    // Print the pattern with the random column highlighted
    for (i = 0; i < n; i++) {
        if (i == j) {
            for (k = 0; k < 2 * j + 1; k++) {
                printf("*");
            }
        } else {
            for (k = 0; k < 2 * j + 1; k++) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}