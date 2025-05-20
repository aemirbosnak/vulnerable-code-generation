//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

// Function to find minimum of three numbers
int min(int a, int b, int c) {
    int min_val = a < b ? a : b;
    return min_val < c ? min_val : c;
}

// Function to calculate Levenshtein distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    
    // Create a distance matrix
    int **d = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_s1; i++) {
        d[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    // Initialize the distance matrix
    for (int i = 0; i <= len_s1; i++) {
        d[i][0] = i;
    }
    for (int j = 0; j <= len_s2; j++) {
        d[0][j] = j;
    }

    // Calculate the distance
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = d[len_s1][len_s2];

    // Free memory allocation
    for (int i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

// Function to display the menu
void display_menu() {
    printf("Levenshtein Distance Calculator\n");
    printf("1. Calculate Distance\n");
    printf("2. Exit\n");
}

// Main function
int main() {
    char str1[MAX_STR_LEN], str2[MAX_STR_LEN];
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                
                int distance = levenshtein_distance(str1, str2);
                printf("Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
                break;
            case 2:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}