//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int minimum(int a, int b, int c){
    int min = a;
    if(b < min){
        min = b;
    }
    if(c < min){
        min = c;
    }
    return min;
}

int levenshteinDistance(char* s, char* t){
    int m = strlen(s);
    int n = strlen(t);
    
    if(m == 0){
        return n;
    }else if(n == 0){
        return m;
    }
    
    int** distanceMatrix = (int**) malloc((m + 1) * sizeof(int*));
    for(int i = 0; i <= m; i++){
        distanceMatrix[i] = (int*) malloc((n + 1) * sizeof(int));
    }
    
    for(int i = 0; i <= m; i++){
        distanceMatrix[i][0] = i;
    }
    
    for(int j = 0; j <= n; j++){
        distanceMatrix[0][j] = j;
    }
    
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= m; i++){
            int cost = (s[i - 1] == t[j - 1]) ? 0 : 1; 
            distanceMatrix[i][j] = minimum(distanceMatrix[i - 1][j] + 1,
                                            distanceMatrix[i][j - 1] + 1,
                                            distanceMatrix[i - 1][j - 1] + cost);
        }
    }
    
    int distance = distanceMatrix[m][n];
    
    for(int i = 0; i <= m; i++){
        free(distanceMatrix[i]);
    }
    free(distanceMatrix);
    
    return distance;
}

int main(){
    char* str1 = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
    char* str2 = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
    
    printf("Enter the first string: ");
    fgets(str1, MAX_STRING_LENGTH, stdin);
    str1[strcspn(str1, "\n")] = '\0';
    
    printf("Enter the second string: ");
    fgets(str2, MAX_STRING_LENGTH, stdin);
    str2[strcspn(str2, "\n")] = '\0';
    
    int distance = levenshteinDistance(str1, str2);
    
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d.\n", str1, str2, distance);
    
    free(str1);
    free(str2);
    
    return 0;
}