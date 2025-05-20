//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    return (a < b) ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshteinDistance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int **d = (int **)malloc((len_s1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_s1; i++) {
        d[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len_s1; i++) {
        d[i][0] = i; // Deletion
    }
    for (int j = 0; j <= len_s2; j++) {
        d[0][j] = j; // Insertion
    }

    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            d[i][j] = min(d[i - 1][j] + 1,  // Deletion
                           d[i][j - 1] + 1,  // Insertion
                           d[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = d[len_s1][len_s2];

    for (int i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);

    return distance;
}

void getUserInput(char *buffer, size_t size, const char *prompt) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline character
}

int main() {
    char s1[100], s2[100];

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Curious about how similar two strings are? Let's find out!\n");

    getUserInput(s1, sizeof(s1), "Please enter the first string: ");
    getUserInput(s2, sizeof(s2), "Now, please enter the second string: ");

    int distance = levenshteinDistance(s1, s2);
    printf("The Levenshtein distance between '%s' and '%s' is: %d\n", s1, s2, distance);

    printf("Thank you for using the program!\n");
    return 0;
}