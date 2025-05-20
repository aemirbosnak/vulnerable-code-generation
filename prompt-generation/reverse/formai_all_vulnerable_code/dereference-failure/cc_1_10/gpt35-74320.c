//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: rigorous
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    return c;
}

int calculateLevenshteinDistance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int i, j;

    int **dist = (int **)malloc(sizeof(int *) * (m+1)); 
    for(i=0;i<=m;i++){
        dist[i] = (int *)malloc(sizeof(int) * (n+1));
    }

    for(i=0;i<=m;i++){
        dist[i][0] = i;
    }
    for(j=0;j<=n;j++){
        dist[0][j] = j;
    }

    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(s1[i-1] == s2[j-1]){
                dist[i][j] = dist[i-1][j-1];
            } else {
                dist[i][j] = min(
                                dist[i-1][j-1] + 1,
                                dist[i][j-1] + 1,
                                dist[i-1][j] + 1
                             );
            }
        }
    }

    int result = dist[m][n];

    for(i=0;i<=m;i++){
        free(dist[i]);
    }
    free(dist);

    return result;
}

int main() {
    char s1[100], s2[100];

    printf("Enter String 1: ");
    scanf("%s", s1);

    printf("Enter String 2: ");
    scanf("%s", s2);

    int distance = calculateLevenshteinDistance(s1, s2);

    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", s1, s2, distance);

    return 0;
}