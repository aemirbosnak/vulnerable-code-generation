//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    } else if (b <= a && b <= c) {
        return b;
    } else {
        return c;
    }
}

int levenshtein_distance(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    int** matrix = (int**)malloc((len1+1) * sizeof(int*));
    for (int i = 0; i <= len1; i++) {
        matrix[i] = (int*)malloc((len2+1) * sizeof(int));
    }
    
    for (int i = 0; i <= len1; i++) {
        matrix[i][0] = i;
    }
    for (int i = 0; i <= len2; i++) {
        matrix[0][i] = i;
    }
    
    int cost;
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            cost = (str1[i-1] == str2[j-1]) ? 0 : 1;
            matrix[i][j] = min(matrix[i-1][j] + 1, matrix[i][j-1] + 1, matrix[i-1][j-1] + cost);
        }
    }
    
    int distance = matrix[len1][len2];
    
    for (int i = 0; i <= len1; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return distance;
}

int main() {
    printf("Enter two strings: \n");
    char str1[100], str2[100];
    scanf("%s%s", str1, str2);
    
    int distance = levenshtein_distance(str1, str2);
    
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", str1, str2, distance);
    
    return 0;
}