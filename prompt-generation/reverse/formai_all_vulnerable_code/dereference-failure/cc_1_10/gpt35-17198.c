//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int levenshtein_distance(char *s1, char *s2)
{
    int len1 = strlen(s1), len2 = strlen(s2), i, j;
    int **dist = malloc((len1 + 1) * sizeof(int *));
    int cost, del, ins, sub, min_dist;

    for (i = 0; i <= len1; i++) {
        dist[i] = malloc((len2 + 1) * sizeof(int));
        dist[i][0] = i;
    }

    for (j = 0; j <= len2; j++)
        dist[0][j] = j;

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            cost = (tolower(s1[i - 1]) == tolower(s2[j - 1])) ? 0 : 1;
            del = dist[i - 1][j] + 1;
            ins = dist[i][j - 1] + 1;
            sub = dist[i - 1][j - 1] + cost;
            min_dist = del;

            if (ins < min_dist) min_dist = ins;
            if (sub < min_dist) min_dist = sub;

            dist[i][j] = min_dist;
        }
    }

    min_dist = dist[len1][len2];
    for (i = 0; i <= len1; i++)
        free(dist[i]);
    free(dist);

    return min_dist;
}

int main(void)
{
    char *word1 = "Sherlock", *word2 = "Holmes";
    int distance = levenshtein_distance(word1, word2);

    if (distance == 1) {
        printf("Ah, Watson, we are only one letter apart!\n");
    } else if (distance < 4) {
        printf("Elementary, my dear Watson, we are %d letters apart.\n", distance);
    } else {
        printf("How strange. We are %d letters apart. This case requires further investigation.\n", distance);
    }

    return 0;
}