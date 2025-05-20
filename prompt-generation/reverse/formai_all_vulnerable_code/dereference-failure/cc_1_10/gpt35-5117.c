//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c){
    if(a <= b && a <= c){
        return a;
    }
    else if(b <= a && b <= c){
        return b;
    }
    else{
        return c;
    }
}

int levenshtein(char *str1, char *str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int **matrix, i, j;
    
    matrix = (int **) malloc(sizeof(int*) * (len1 + 1));
    for(i = 0; i <= len1; i++){
        matrix[i] = (int *) malloc(sizeof(int) * (len2 + 1));
        matrix[i][0] = i;
    }
    
    for(j = 0; j <= len2; j++){
        matrix[0][j] = j;
    }
    
    for(i = 1; i <= len1; i++){
        for(j = 1; j <= len2; j++){
            if(str1[i - 1] == str2[j - 1]){
                matrix[i][j] = matrix[i - 1][j - 1];
            }
            else{
                matrix[i][j] = 1 + min(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]);
            }
        }
    }
    
    int distance = matrix[len1][len2];
    
    for(i = 0; i <= len1; i++){
        free(matrix[i]);
    }
    free(matrix);
    
    return distance;
}

int main(){
    char *str1 = "levenshtein";
    char *str2 = "frankenstein";
    int distance = levenshtein(str1, str2);
    
    printf("The Levenshtein distance between '%s' and '%s' is %d.\n", str1, str2, distance);
    
    return 0;
}