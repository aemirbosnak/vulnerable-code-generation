//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int minimum(int a, int b, int c){
    int min;
    min = a;
    if(min > b){
        min = b;
    }
    if(min > c){
        min = c;
    }
    return min;
}

int levenshtein_distance(char *str1, char *str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j, x, y, res;
    
    int **mat = (int **)malloc((len1 + 1) * sizeof(int *));
    for (i=0; i<=len1; i++){
        mat[i] = (int *)malloc((len2 + 1) * sizeof(int));
    }
    
    for(i=0; i<=len1; i++){
        mat[i][0] = i;
    }
    for(i=0; i<=len2; i++){
        mat[0][i] = i;
    }
    
    for(i=1; i<=len1; i++){
        for(j=1; j<=len2; j++){
            if(str1[i-1] == str2[j-1]){
                mat[i][j] = mat[i-1][j-1];
            }
            else{
                mat[i][j] = minimum(mat[i-1][j-1], mat[i][j-1], mat[i-1][j]) + 1;
            }
        }
    }
    res = mat[len1][len2];
    
    for (i=0; i<=len1; i++){
        free(mat[i]);
    }
    free(mat);
    
    return res;
}

int main(){
    char str1[100], str2[100];
    int distance;
   
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    
    distance = levenshtein_distance(str1, str2);
    
    printf("The Levenshtein distance between '%s' and '%s' is %d\n", str1, str2, distance);
    
    return 0;
}