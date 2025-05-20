//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to calculate the minimum of 3 numbers
int min(int x, int y, int z) {
    if(x <= y && x <= z) {
        return x;
    }
    else if(y <= x && y <= z) {
        return y;
    }
    else {
        return z;
    }
}

//function to calculate levenshtein distance between two given strings
int levenshtein_distance(char *str1, char *str2) {
    int i, j;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **dp = (int **)malloc((len2+1) * sizeof(int *));
    for(i = 0; i <= len2; i++) {
        dp[i] = (int *)malloc((len1+1) * sizeof(int));
    }
    for(i = 0; i <= len2; i++) {
        dp[i][0] = i;
    }
    for(j = 0; j <= len1; j++) {
        dp[0][j] = j;
    }
    for(i = 1; i <= len2; i++) {
        for(j = 1; j <= len1; j++) {
            if(str1[j-1] == str2[i-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }
    int result = dp[len2][len1];
    for(i = 0; i <= len2; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}

int main() {
    char str1[100], str2[100];
    printf("Enter two strings:\n");
    scanf("%s %s", str1, str2);
    int distance = levenshtein_distance(str1, str2);
    printf("The levenshtein distance between '%s' and '%s' is %d.\n", str1, str2, distance);
    return 0;
}