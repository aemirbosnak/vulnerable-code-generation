//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int levenshtein(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **arr;
    
    arr = (int **) malloc((len1 + 1) * sizeof(int *));
    
    for (int i = 0; i <= len1; i++) {
        arr[i] = (int *) malloc((len2 + 1) * sizeof(int));
    }
    
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                arr[i][j] = j;
            } else if (j == 0) {
                arr[i][j] = i;
            } else {
                int del = arr[i-1][j] + 1;
                int ins = arr[i][j-1] + 1;
                int sub = arr[i-1][j-1] + (str1[i-1] != str2[j-1]);
                arr[i][j] = del < ins ? (del < sub ? del : sub) : (ins < sub ? ins : sub);
            }
        }
    }
    
    int editDistance = arr[len1][len2];
    
    for (int i = 0; i <= len1; i++) {
        free(arr[i]);
    }
    
    free(arr);
    
    return editDistance;
}

int main() {
    char str1[100], str2[100];
    
    printf("Welcome to the surreal Levenshtein Distance Calculator!\n");
    printf("Please enter your first surreal string: ");
    scanf("%s", str1);
    
    printf("Please enter your second surreal string: ");
    scanf("%s", str2);
    
    int distance = levenshtein(str1, str2);
    
    printf("\nThe surreal edit distance between '%s' and '%s' is %d.\n", str1, str2, distance);
    
    return 0;
}