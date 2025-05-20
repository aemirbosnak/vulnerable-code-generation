//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    
    // Create a distance matrix
    int **dist = (int **)malloc((len_s1 + 1) * sizeof(int *));
    for (int i = 0; i <= len_s1; i++) {
        dist[i] = (int *)malloc((len_s2 + 1) * sizeof(int));
    }
    
    // Initialize the distance matrix
    for (int i = 0; i <= len_s1; i++) {
        dist[i][0] = i; // Deletion cost
    }
    for (int j = 0; j <= len_s2; j++) {
        dist[0][j] = j; // Insertion cost
    }

    // Compute the distance
    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; // Substitution cost
            dist[i][j] = min(min(dist[i - 1][j] + 1,    // Deletion
                                 dist[i][j - 1] + 1),   // Insertion
                                 dist[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = dist[len_s1][len_s2];

    // Free memory
    for (int i = 0; i <= len_s1; i++) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

void get_input(char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character
    }
}

int main() {
    char s1[256];
    char s2[256];

    get_input("Enter the first string: ", s1, sizeof(s1));
    get_input("Enter the second string: ", s2, sizeof(s2));

    int distance = levenshtein_distance(s1, s2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is: %d\n", s1, s2, distance);

    return 0;
}