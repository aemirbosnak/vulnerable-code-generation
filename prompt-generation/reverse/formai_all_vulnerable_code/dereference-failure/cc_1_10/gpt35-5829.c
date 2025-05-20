//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    } else if (y < x && y < z) {
        return y;
    } else {
        return z;
    }
}

int levenshtein_distance(char* str1, char* str2) {
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int** dp = (int**)malloc(sizeof(int*) * (len1 + 1));
    for (int i = 0; i <= len1; i++) {
        dp[i] = (int*)malloc(sizeof(int) * (len2 + 1));
        dp[i][0] = i;
    }
    for (int i = 0; i <= len2; i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }

    int result = dp[len1][len2];
    for (int i = 0; i <= len1; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    char str1[] = "Levenshtein";
    char str2[] = "Distance";
    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein distance between %s and %s is %d", str1, str2, distance);
    return 0;
}