//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three values
int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

// Function to compute the Levenshtein distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        d[i][0] = i;  // Deleting all characters from s1
    }
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j;  // Inserting all characters of s2
    }

    // Populate the distance matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                d[i][j] = d[i - 1][j - 1]; // No operation required
            } else {
                d[i][j] = min(d[i - 1][j] + 1,    // Deletion
                              d[i][j - 1] + 1,    // Insertion
                              d[i - 1][j - 1] + 1); // Substitution
            }
        }
    }

    int distance = d[len1][len2];

    // Free the allocated memory for the matrix
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Main function to run the program
int main() {
    char product1[100];
    char product2[100];

    printf("Welcome to the Product Name Similarity Checker!\n");
    printf("Please enter the name of the first product: ");
    fgets(product1, sizeof(product1), stdin);
    product1[strcspn(product1, "\n")] = 0; // Remove the newline character

    printf("Please enter the name of the second product: ");
    fgets(product2, sizeof(product2), stdin);
    product2[strcspn(product2, "\n")] = 0; // Remove the newline character

    int distance = levenshtein_distance(product1, product2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", product1, product2, distance);

    if (distance == 0) {
        printf("The product names are identical!\n");
    } else if (distance <= 3) {
        printf("The product names are quite similar.\n");
    } else {
        printf("The product names are quite different.\n");
    }

    printf("Thank you for using the Product Name Similarity Checker!\n");
    return 0;
}