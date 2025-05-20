//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else
        return c;
}

int levenshtein_distance(char *s1, char *s2, int len1, int len2) {
    int **D = (int **)malloc((len1+1)*sizeof(int *));
    for(int i = 0; i <= len1; i++)
        D[i] = (int *)malloc((len2+1)*sizeof(int));

    for(int i = 0; i <= len1; i++)
        D[i][0] = i;

    for(int j = 0; j <= len2; j++)
        D[0][j] = j;

    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(s1[i-1] == s2[j-1]) {
                D[i][j] = D[i-1][j-1];
            }
            else {
                D[i][j] = min(D[i-1][j], D[i][j-1], D[i-1][j-1]) + 1;
            }
        }
    }

    int result = D[len1][len2];

    for(int i = 0; i <= len1; i++)
        free(D[i]);
    free(D);

    return result;
}

int main() {
    char str1[] = "ultraprecise";
    char str2[] = "example";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int distance = levenshtein_distance(str1, str2, len1, len2);

    printf("Levenshtein distance between %s and %s is %d\n", str1, str2, distance);

    return 0;
}