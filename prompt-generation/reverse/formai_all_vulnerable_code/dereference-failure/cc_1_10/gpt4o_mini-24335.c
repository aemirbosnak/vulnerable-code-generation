//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to get the minimum of three integers
int min(int x, int y, int z) {
    // Find the smallest value among x, y, z
    int temp = x < y ? x : y;
    return temp < z ? temp : z;
}

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Create a 2D array to hold the distance values
    int **distance = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        distance[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance array
    for (int i = 0; i <= len1; i++) {
        distance[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len2; j++) {
        distance[0][j] = j; // Insertion cost
    }

    // Calculate the distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1,       // Deletion
                                 distance[i][j - 1] + 1,       // Insertion
                                 distance[i - 1][j - 1] + cost); // Substitution
        }
    }

    int result = distance[len1][len2];

    // Free the allocated memory
    for (int i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);

    return result;
}

// Function to prompt user for input and calculate the distance
void input_and_calculate() {
    char s1[100], s2[100];

    printf("Enter the first string: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0; // Remove trailing newline

    printf("Enter the second string: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0; // Remove trailing newline

    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);
}

int main() {
    char choice;

    do {
        input_and_calculate();
        printf("Do you want to calculate the distance for another pair of strings? (y/n): ");
        scanf(" %c", &choice); // Use a space before %c to ignore any whitespace
        getchar(); // To consume the newline character left by scanf
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Levenshtein Distance Calculator.\n");
    return 0;
}