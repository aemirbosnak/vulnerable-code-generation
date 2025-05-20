//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return a < c ? a : c;
    }
    return b < c ? b : c;
}

// Function to calculate the Levenshtein distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **dp = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        dp[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i; // Deletion
    }
    
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j; // Insertion
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            dp[i][j] = min(dp[i - 1][j] + 1,    // Deletion
                           dp[i][j - 1] + 1,    // Insertion
                           dp[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = dp[len1][len2];

    for (int i = 0; i <= len1; i++) {
        free(dp[i]);
    }
    free(dp);

    return distance;
}

// Menu function for user interaction
void display_menu() {
    printf("Levenshtein Distance Calculator\n");
    printf("1. Calculate Distance\n");
    printf("2. Exit\n");
}

int main() {
    char str1[100], str2[100];
    int choice, distance;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                
                distance = levenshtein_distance(str1, str2);
                printf("Levenshtein distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}