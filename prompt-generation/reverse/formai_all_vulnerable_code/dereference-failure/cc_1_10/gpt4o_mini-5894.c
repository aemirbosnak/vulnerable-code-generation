//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    else if (b <= a && b <= c) return b;
    else return c;
}

// Function to compute Levenshtein distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Create a distance matrix
    int **distance = (int **)malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        distance[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len1; i++) {
        distance[i][0] = i; // deletion
    }
    for (int j = 0; j <= len2; j++) {
        distance[0][j] = j; // insertion
    }

    // Compute the distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            distance[i][j] = min(distance[i - 1][j] + 1, // deletion
                                 distance[i][j - 1] + 1, // insertion
                                 distance[i - 1][j - 1] + cost); // substitution
        }
    }

    // Get the Levenshtein distance
    int lev_distance = distance[len1][len2];

    // Free the distance matrix
    for (int i = 0; i <= len1; i++) {
        free(distance[i]);
    }
    free(distance);
    
    return lev_distance;
}

// Main function to interact with the user
int main() {
    char str1[MAX_LEN];
    char str2[MAX_LEN];

    printf("Welcome to the Enchanted Levenshtein Distance Calculator!\n");
    printf("Please enter the first magical string: ");
    fgets(str1, MAX_LEN, stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove trailing newline

    printf("Now, provide the second mystical string: ");
    fgets(str2, MAX_LEN, stdin);
    str2[strcspn(str2, "\n")] = '\0'; // Remove trailing newline

    int distance = levenshtein_distance(str1, str2);
    
    printf("The mystical transformation distance between '%s' and '%s' is: %d\n", str1, str2, distance);

    // Engaging the user to play more
    char choice;
    printf("Would you like to calculate another distance? (y/n): ");
    scanf(" %c", &choice); // Adding space before %c to consume any newline

    while (choice == 'y' || choice == 'Y') {
        printf("Please enter the first magical string: ");
        getchar(); // Consume newline
        fgets(str1, MAX_LEN, stdin);
        str1[strcspn(str1, "\n")] = '\0'; 

        printf("Now, provide the second mystical string: ");
        fgets(str2, MAX_LEN, stdin);
        str2[strcspn(str2, "\n")] = '\0'; 

        distance = levenshtein_distance(str1, str2);
        
        printf("The mystical transformation distance between '%s' and '%s' is: %d\n", str1, str2, distance);
        printf("Would you like to calculate another distance? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using the Enchanted Levenshtein Distance Calculator! Farewell!\n");
    return 0;
}