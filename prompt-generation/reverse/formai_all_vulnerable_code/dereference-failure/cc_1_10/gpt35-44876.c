//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    if(x <= y && x <= z) {
        return x;
    } else if(y <= x && y <= z) {
        return y;
    } else {
        return z;
    }
}

int levenshteinDistance(char* str1, char* str2, int len1, int len2) {
    int** dp = (int**)malloc((len1+1)*sizeof(int*));
    for(int i = 0; i <= len1; i++) {
        dp[i] = (int*)malloc((len2+1)*sizeof(int));
    }
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0) {
                dp[i][j] = j;
            } else if(j == 0) {
                dp[i][j] = i;
            } else if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
    }
    int distance = dp[len1][len2];
    for(int i = 0; i <= len1; i++) {
        free(dp[i]);
    }
    free(dp);
    return distance;
}

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    fgets(str1, 100, stdin);
    printf("Enter second string: ");
    fgets(str2, 100, stdin);
    int len1 = strlen(str1)-1, len2 = strlen(str2)-1; // subtract 1 to ignore newline character
    int distance = levenshteinDistance(str1, str2, len1, len2);
    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);
    return 0;
}