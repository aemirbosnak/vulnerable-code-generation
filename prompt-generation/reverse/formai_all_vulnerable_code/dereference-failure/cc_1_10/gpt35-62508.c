//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minimum(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

int levenshtein_distance(char *a, char *b)
{
    int len_a = strlen(a);
    int len_b = strlen(b);

    //create distance array
    int **dist = (int **)malloc((len_a + 1) * sizeof(int *));
    for (int i = 0; i < len_a + 1; i++)
        dist[i] = (int *)malloc((len_b + 1) * sizeof(int));

    //set initial values
    for (int i = 0; i < len_a + 1; i++)
        dist[i][0] = i;
    for (int i = 0; i < len_b + 1; i++)
        dist[0][i] = i;

    //calculate levenshtein distance
    for (int i = 1; i < len_a + 1; i++)
    {
        for (int j = 1; j < len_b + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
                dist[i][j] = dist[i - 1][j - 1];
            else
                dist[i][j] = minimum(dist[i - 1][j], dist[i][j - 1], dist[i - 1][j - 1]) + 1;
        }
    }

    int result = dist[len_a][len_b];

    //free distance array memory
    for (int i = 0; i < len_a + 1; i++)
        free(dist[i]);
    free(dist);

    return result;
}

int main()
{
    char word1[] = "kitten";
    char word2[] = "sitting";
    int distance = levenshtein_distance(word1, word2);
    printf("Levenshtein distance between %s and %s is: %d\n", word1, word2, distance);

    return 0;
}