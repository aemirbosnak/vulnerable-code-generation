//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int min(int a, int b, int c) {
    int smallest = a;
    if (b < smallest) {
        smallest = b;
    }
    if (c < smallest) {
        smallest = c;
    }
    return smallest;
}

int levenshtein_distance(char *s, char *t) {
    int s_length = strlen(s), t_length = strlen(t);
    int **distance_matrix = calloc(s_length + 1, sizeof(int *));
    for (int i = 0; i <= s_length; i++) {
        distance_matrix[i] = calloc(t_length + 1, sizeof(int));
    }

    for (int i = 0; i <= s_length; i++) {
        distance_matrix[i][0] = i;
    }

    for (int i = 0; i <= t_length; i++) {
        distance_matrix[0][i] = i;
    }

    for (int i = 1; i <= s_length; i++) {
        for (int j = 1; j <= t_length; j++) {
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1;
            int deletion = distance_matrix[i - 1][j] + 1;
            int insertion = distance_matrix[i][j - 1] + 1;
            int substitution = distance_matrix[i - 1][j - 1] + cost;
            distance_matrix[i][j] = min(deletion, insertion, substitution);
        }
    }

    int result = distance_matrix[s_length][t_length];
    for (int i = 0; i <= s_length; i++) {
        free(distance_matrix[i]);
    }
    free(distance_matrix);
    return result;
}

int main() {
    char word1[100], word2[100];

    printf("Welcome to the futuristic Levenshtein Distance Calculator!\n");
    printf("Please enter two words to calculate their distance:\n");

    scanf("%s %s", word1, word2);

    int distance = levenshtein_distance(word1, word2);

    printf("\nThe Levenshtein distance between %s and %s is %d.\n", word1, word2, distance);
    printf("Thank you for using our futuristic calculator!\n");

    return 0;
}