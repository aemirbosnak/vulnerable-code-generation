//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Function to compute the Levenshtein distance between two strings
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **distance_matrix = (int **)malloc((len1 + 1) * sizeof(int *));
    
    // Allocate memory for the distance matrix
    for (int i = 0; i <= len1; i++) {
        distance_matrix[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }
    
    // Initialize the matrix
    for (int i = 0; i <= len1; i++) {
        distance_matrix[i][0] = i;  // Deletion
    }
    
    for (int j = 0; j <= len2; j++) {
        distance_matrix[0][j] = j;  // Insertion
    }
    
    // Compute the distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            distance_matrix[i][j] = min(distance_matrix[i - 1][j] + 1, // Deletion
                                         distance_matrix[i][j - 1] + 1, // Insertion
                                         distance_matrix[i - 1][j - 1] + cost); // Substitution
        }
    }
    
    int distance = distance_matrix[len1][len2];
    
    // Free the allocated memory
    for (int i = 0; i <= len1; i++) {
        free(distance_matrix[i]);
    }
    free(distance_matrix);
    
    return distance;
}

// Function to get a string input from the user and calculate the Levenshtein distance
void calculate_distance() {
    char s1[100], s2[100];

    printf("Enter the first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0; // Remove the newline character
    
    printf("Enter the second string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0; // Remove the newline character

    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);
}

int main() {
    printf("=== Levenshtein Distance Calculator ===\n");
    
    // Repeat until user chooses to exit
    while (1) {
        calculate_distance();

        char choice[10];
        printf("Do you want to calculate another distance? (yes/no): ");
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = 0; // Remove newline character

        if (strcmp(choice, "no") == 0) {
            printf("Thank you for using the Levenshtein Distance Calculator. Goodbye!\n");
            break;
        } else if (strcmp(choice, "yes") == 0) {
            continue;
        } else {
            printf("Invalid choice. Exiting...\n");
            break;
        }
    }

    return 0;
}