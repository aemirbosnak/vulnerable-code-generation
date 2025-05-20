//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a <= b && a <= c) return a;
    if (b <= a && b <= c) return b;
    return c;
}

// Function to calculate the Levenshtein Distance
int levenshtein_distance(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // Allocate memory for the distance array
    int **dist = (int**) malloc((len1 + 1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        dist[i] = (int*) malloc((len2 + 1) * sizeof(int));
    }

    // Initialize the distance array
    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j;
    }

    // Calculate the Levenshtein distance
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (str1[i - 1] == str2[j - 1]) ? 0 : 1;
            dist[i][j] = min(dist[i - 1][j] + 1,       // Deletion
                             dist[i][j - 1] + 1,       // Insertion
                             dist[i - 1][j - 1] + cost  // Substitution
                            );
        }
    }

    // Get the final distance
    int distance = dist[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

int main() {
    printf("🎉 Welcome to the Cheery Levenshtein Distance Calculator! 🎉\n");
    
    char str1[100], str2[100];

    // Get user inputs
    printf("Please enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0; // Remove the newline character

    printf("Great! Now, please enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0; // Remove the newline character
    
    // Calculate the distance
    int distance = levenshtein_distance(str1, str2);
    
    // Output the result
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", str1, str2, distance);
    printf("✨ Thank you for using our Levenshtein Distance Calculator! Have a wonderful day! ✨\n");

    return 0;
}