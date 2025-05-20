//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to find the minimum of three numbers
int min(int a, int b, int c) {
    int min_ab = (a < b) ? a : b;
    return (min_ab < c) ? min_ab : c;
}

// Function to calculate the Levenshtein distance
int levenshtein(const char *s, const char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    // Create a distance matrix
    int **d = (int **)malloc((len_s + 1) * sizeof(int *));
    for (int i = 0; i <= len_s; i++) {
        d[i] = (int *)malloc((len_t + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len_s; i++) {
        d[i][0] = i; // if t is empty
    }
    for (int j = 0; j <= len_t; j++) {
        d[0][j] = j; // if s is empty
    }

    // Compute the distances
    for (int i = 1; i <= len_s; i++) {
        for (int j = 1; j <= len_t; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,   // deletion
                           d[i][j - 1] + 1,   // insertion
                           d[i - 1][j - 1] + cost); // substitution
        }
    }

    int distance = d[len_s][len_t];

    // Free allocated memory
    for (int i = 0; i <= len_s; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Main function to take input and run the calculator
int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    printf("Enter the first string (LIMIT: %d characters): ", MAX_LEN - 1);
    if (fgets(str1, MAX_LEN, stdin) == NULL) {
        fprintf(stderr, "ERROR: Input error! Exiting...\n");
        return 1;
    }
    str1[strcspn(str1, "\n")] = 0; // Remove newline

    printf("Enter the second string (LIMIT: %d characters): ", MAX_LEN - 1);
    if (fgets(str2, MAX_LEN, stdin) == NULL) {
        fprintf(stderr, "ERROR: Input error! Exiting...\n");
        return 1;
    }
    str2[strcspn(str2, "\n")] = 0; // Remove newline

    // Shockingly display the lengths and strings
    printf("\n*** SHOCKED TO KNOW THIS! ***\n");
    printf("Length of First String: %zu\n", strlen(str1));
    printf("Length of Second String: %zu\n", strlen(str2));

    // OMG -- Calculate the distance!
    int distance = levenshtein(str1, str2);
    
    // That's unbelievable!
    printf("\nThe Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    
    // A final thought
    if (distance == 0) {
        printf("What an astonishing coincidence! These strings are identical!\n");
    } else if (distance < 3) {
        printf("Wow! There are only a few differences! Close call!\n");
    } else {
        printf("Yikes! Quite a difference between those two! Better luck next time.\n");
    }

    return 0;
}