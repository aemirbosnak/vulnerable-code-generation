//GPT-4o-mini DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum of three numbers
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

// Function to calculate the Levenshtein distance
int levenshtein(const char *s1, const char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int **dist = malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        dist[i] = malloc((len2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len1; i++) {
        dist[i][0] = i; // Deletion cost from s1 to ""
    }
    for (int j = 0; j <= len2; j++) {
        dist[0][j] = j; // Insertion cost from "" to s2
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1; // Cost of substitution
            dist[i][j] = min(dist[i - 1][j] + 1,    // Deletion
                             dist[i][j - 1] + 1,    // Insertion
                             dist[i - 1][j - 1] + cost); // Substitution
        }
    }

    int distance = dist[len1][len2];

    for (int i = 0; i <= len1; i++) {
        free(dist[i]);
    }
    free(dist);

    return distance;
}

// A fun declaration for main function
int main() {
    printf("Welcome to the Hilarious Levenshtein Distance Calculator!\n");
    printf("========================================\n");
    char s1[100], s2[100];
    
    printf("Please enter the first string (or a bad pun):\n");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0; // Remove newline character

    printf("Now, enter the second one (or another bad pun):\n");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0; // Remove newline character

    int distance = levenshtein(s1, s2);

    printf("The Levenshtein distance between '%s' and '%s' is: %d\n", s1, s2, distance);
    printf("But don't get too hung up on it, that's just the distance in edit operations!\n");
    
    if (distance == 0) {
        printf("Wow! They are identical! Just like two peas in a hilarious pod!\n");
    } else if (distance < 3) {
        printf("Not too far apart! Just a hop, skip, and a jump with a funny dance!\n");
    } else {
        printf("Whoa! That's quite a leap! You could start a reality show called 'Strings in Distress'!\n");
    }

    printf("That's all, folks! Don't forget to tip your programmer!\n");
    
    return 0;
}