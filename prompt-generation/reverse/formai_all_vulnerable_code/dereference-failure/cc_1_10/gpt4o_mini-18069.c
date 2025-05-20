//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three integers
int min(int a, int b, int c) {
    int m = a < b ? a : b; 
    return m < c ? m : c; 
}

// Function to calculate Levenshtein Distance
int levenshtein_distance(const char *s1, const char *s2) {
    int len_s1 = strlen(s1);
    int len_s2 = strlen(s2);
    int **d = malloc((len_s1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len_s1; i++) {
        d[i] = malloc((len_s2 + 1) * sizeof(int));
        d[i][0] = i; // deletion
    }
    
    for (int j = 0; j <= len_s2; j++) {
        d[0][j] = j; // insertion
    }

    for (int i = 1; i <= len_s1; i++) {
        for (int j = 1; j <= len_s2; j++) {
            int cost = (s1[i-1] == s2[j-1]) ? 0 : 1;
            d[i][j] = min(d[i-1][j] + 1,       // deletion
                           d[i][j-1] + 1,       // insertion
                           d[i-1][j-1] + cost); // substitution
        }
    }

    int distance = d[len_s1][len_s2];
    
    for (int i = 0; i <= len_s1; i++) {
        free(d[i]);
    }
    free(d);
    
    return distance;
}

int main() {
    char s1[100], s2[100];
    
    printf("In the enchanted garden of words, where every letter is a petal, \n");
    printf("Let your heart whisper the first string of love: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0; // Remove the newline character

    printf("And now, dear heart, speak your second string of affection: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0; // Remove the newline character

    printf("\nCalculating the distance between your words...\n");

    int distance = levenshtein_distance(s1, s2);

    printf("Oh my dear, the Levenshtein Distance between '%s' and '%s' is: %d\n",
           s1, s2, distance);
    
    if (distance == 0) {
        printf("What a beautiful harmony! Your words are one, intertwined like lovers in a dance.\n");
    } else if (distance <= 3) {
        printf("Ah, my sweet; just a few whispers separate your hearts.\n");
    } else {
        printf("Love may require some distance, but fear not! It can be bridged with patience and affection.\n");
    }

    printf("May your love story bloom like the most fragrant roses!\n");

    return 0;
}