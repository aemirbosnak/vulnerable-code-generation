//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Levenshtein Distance Calculator Example Program

int min(int x, int y, int z) {
    if (x <= y && x <= z) 
        return x;
    if (y <= x && y <= z) 
        return y;
    else 
        return z;
}

int main() {
    char string1[50], string2[50];
    int len1, len2;
    int i, j, cost, **table;

    printf("Welcome to the Levenshtein Distance Calculator!\n");
    printf("Please enter the first string: ");
    scanf("%s", string1);
    printf("Please enter the second string: ");
    scanf("%s", string2);

    len1 = strlen(string1);
    len2 = strlen(string2);

    table = (int **)malloc((len1 + 1) * sizeof(int *));
    for (i = 0; i <= len1; i++)
        table[i] = (int *)malloc((len2 + 1) * sizeof(int));

    for (i = 0; i <= len1; i++)
        table[i][0] = i;
    for (j = 0; j <= len2; j++)
        table[0][j] = j;

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (string1[i - 1] == string2[j - 1])
                cost = 0;
            else
                cost = 1;

            table[i][j] = min(table[i - 1][j] + 1, 
                              table[i][j - 1] + 1, 
                              table[i - 1][j - 1] + cost);
        }
    }

    printf("\nThe Levenshtein Distance between %s and %s is: %d\n", string1, string2, table[len1][len2]);

    for (i = 0; i <= len1; i++)
        free(table[i]);
    free(table);

    return 0;
}