//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Calculate Levenshtein Distance
int levenshtein_distance(char *s, char *t) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    int i, j, x, y, cost;

    // Initialize distance matrix
    int **distance = malloc(sizeof(int *) * (s_len + 1));
    for(i = 0; i <= s_len; i++)
        distance[i] = malloc(sizeof(int) * (t_len + 1));

    for(i = 0; i <= s_len; i++)
        distance[i][0] = i;

    for(j = 0; j <= t_len; j++)
        distance[0][j] = j;

    // Calculate distance
    for(i = 1; i <= s_len; i++) {
        for(j = 1; j <= t_len; j++) {
            if(s[i - 1] == t[j - 1])
                cost = 0;
            else
                cost = 1;
            x = distance[i - 1][j] + 1;
            y = distance[i][j - 1] + 1;
            distance[i][j] = (x < y) ? x : y;
            if(distance[i][j] > distance[i - 1][j - 1] + cost)
                distance[i][j] = distance[i - 1][j - 1] + cost;
        }
    }

    // Get distance value
    int result = distance[s_len][t_len];

    // Free distance matrix
    for(i = 0; i <= s_len; i++)
        free(distance[i]);
    free(distance);

    return result;
}

int main() {
    // Test case
    char *str1 = "kitten";
    char *str2 = "sitting";
    int distance = levenshtein_distance(str1, str2);
    printf("Levenshtein Distance between %s and %s is %d\n", str1, str2, distance);

    return 0;
}