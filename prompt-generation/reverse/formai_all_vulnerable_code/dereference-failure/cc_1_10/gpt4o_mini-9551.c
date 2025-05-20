//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to calculate the Levenshtein distance
int levenshteinDistance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **d = malloc((len1 + 1) * sizeof(int *));
    
    // Create distance matrix
    for (int i = 0; i <= len1; i++) {
        d[i] = malloc((len2 + 1) * sizeof(int));
        d[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j; // Insertion cost
    }
    
    // Fill the distance matrix
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            d[i][j] = fmin(fmin(d[i - 1][j] + 1,    // Deletion
                                 d[i][j - 1] + 1),   // Insertion
                                 d[i - 1][j - 1] + cost); // Substitution
        }
    }
    
    int distance = d[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);
    
    return distance;
}

int main() {
    // Welcome to the Levenshtein distance calculator!
    printf("🎉 Welcome to the Levenshtein Distance Calculator! 🎉\n");
    
    char str1[100], str2[100];
    
    // Prompt the user for input
    printf("Please enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove newline character
    
    printf("Please enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove newline character

    // Calculate the distance
    int distance = levenshteinDistance(str1, str2);
    
    // Display the result with enthusiasm!
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d 🎯\n", str1, str2, distance);
    
    // Bit of encouragement
    if (distance == 0) {
        printf("Wow! The strings are identical! 🥳\n");
    } else if (distance <= 2) {
        printf("Not bad! Just a few tweaks needed! ✂️\n");
    } else {
        printf("Looks like they are quite different! Keep trying! 🔄\n");
    }

    return 0;
}