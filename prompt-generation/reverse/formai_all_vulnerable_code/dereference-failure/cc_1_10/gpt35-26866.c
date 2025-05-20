//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int levenshtein_distance(char* str1, char* str2) {
    int m = strlen(str1) + 1;
    int n = strlen(str2) + 1;
    int** distances = (int**)malloc(m * sizeof(int*));

    for(int i=0; i<m; i++) {
        distances[i] = (int*)malloc(n * sizeof(int));
        distances[i][0] = i;
    }

    for(int j=0; j<n; j++) {
        distances[0][j] = j;
    }

    for(int i=1; i<m; i++) {
        for(int j=1; j<n; j++) {
            int cost = (str1[i-1] == str2[j-1]) ? 0 : 1;
            distances[i][j] = min(
				distances[i-1][j] + 1, 
				distances[i][j-1] + 1, 
				distances[i-1][j-1] + cost
			);
        }
    }

    int result = distances[m-1][n-1];
    for(int i=0; i<m; i++)
        free(distances[i]);
    free(distances);
    return result;
}

int main() {
    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];

    printf("Enter string 1: ");
    scanf("%s", str1);

    printf("Enter string 2: ");
    scanf("%s", str2);

    int distance = levenshtein_distance(str1, str2);

    printf("The Levenshtein Distance between '%s' and '%s' is %d.", str1, str2, distance);

    return 0;
}