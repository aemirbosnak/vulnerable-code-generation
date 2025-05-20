//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    if (a < b) {
        return (a < c) ? a : c;
    } else {
        return (b < c) ? b : c;
    }
}

// Function to compute Levenshtein distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int **d = (int **)malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        d[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }
    
    for (int i = 0; i <= len1; i++) {
        d[i][0] = i;  // Deletion
    }
    
    for (int j = 0; j <= len2; j++) {
        d[0][j] = j;  // Insertion
    }
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,      // Deletion
                          d[i][j - 1] + 1,      // Insertion
                          d[i - 1][j - 1] + cost); // Substitution
        }
    }
    
    int result = d[len1][len2];

    // Free allocated memory
    for (int i = 0; i <= len1; i++) {
        free(d[i]);
    }
    free(d);
    
    return result;
}

int main() {
    printf("🎉🎊 Welcome to the Levenshtein Distance Calculator! 🎊🎉\n");
    printf("Let's measure the distance between two strings, shall we? 🌟\n\n");
    
    char str1[100], str2[100];
    
    printf("Please enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = 0;  // Remove trailing newline

    printf("Great! Now, please enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = 0;  // Remove trailing newline

    printf("\n💫 Calculating the Levenshtein distance...\n");
    int distance = levenshtein_distance(str1, str2);
    
    printf("The Levenshtein distance between \"%s\" and \"%s\" is: %d 💖\n", str1, str2, distance);
    
    if (distance == 0) {
        printf("🎉 Hooray! The two strings are identical! 🎉\n");
    } else if (distance <= 2) {
        printf("🌈 The strings are quite similar! 🥳\n");
    } else {
        printf("🤔 Looks like the strings are quite different. Don't worry, it happens!\n");
    }
    
    printf("\nThank you for using the Levenshtein Distance Calculator! Goodbye! 👋✨\n");
    return 0;
}