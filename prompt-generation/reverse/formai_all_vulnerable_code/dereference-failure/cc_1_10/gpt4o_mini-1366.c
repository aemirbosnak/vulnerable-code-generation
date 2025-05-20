//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

int levenshtein_distance(const char *str1, const char *str2) {
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    int **dp = (int **)malloc((len_str1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_str1; i++) {
        dp[i] = (int *)malloc((len_str2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len_str1; i++) {
        dp[i][0] = i;  // Cost of deletions
    }

    for (int j = 0; j <= len_str2; j++) {
        dp[0][j] = j;  // Cost of insertions
    }

    for (int i = 1; i <= len_str1; i++) {
        for (int j = 1; j <= len_str2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // No cost if characters are equal
            } else {
                dp[i][j] = min(dp[i - 1][j] + 1,  // Deletion
                               dp[i][j - 1] + 1,  // Insertion
                               dp[i - 1][j - 1] + 1); // Substitution
            }
        }
    }

    int distance = dp[len_str1][len_str2];

    // Free memory
    for (int i = 0; i <= len_str1; i++) {
        free(dp[i]);
    }
    free(dp);

    return distance;
}

void print_menu() {
    printf("\nLevenshtein Distance Calculator\n");
    printf("1. Calculate distance\n");
    printf("2. Exit\n");
    printf("Choose an option: ");
}

int main() {
    while (1) {
        print_menu();
        int choice;
        scanf("%d", &choice);
        
        if (choice == 1) {
            char str1[256], str2[256];
            printf("Enter first string: ");
            scanf("%s", str1);
            printf("Enter second string: ");
            scanf("%s", str2);

            int distance = levenshtein_distance(str1, str2);
            printf("Levenshtein Distance between '%s' and '%s' is: %d\n", str1, str2, distance);
        } else if (choice == 2) {
            printf("Exiting the program. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}