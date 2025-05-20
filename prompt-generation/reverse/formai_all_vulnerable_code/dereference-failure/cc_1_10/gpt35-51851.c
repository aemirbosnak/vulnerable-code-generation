//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int len1, len2, i, j, cost, result;
    
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    len1 = strlen(str1);
    len2 = strlen(str2);
    
    int **arr = (int**)malloc((len1+1)*sizeof(int*));
    for(i=0; i<=len1; i++){
        arr[i] = (int*)malloc((len2+1)*sizeof(int));
    }

    for(i=0; i<=len1; i++){
        for(j=0; j<=len2; j++){
            if(i==0){
                arr[i][j]=j;
            }
            else if(j==0){
                arr[i][j]=i;
            }
            else{
                cost = (str1[i-1] == str2[j-1]) ? 0 : 1;
                arr[i][j] = minimum(arr[i-1][j]+1, arr[i][j-1]+1, arr[i-1][j-1]+cost);
            }
        }
    }
    
    result = arr[len1][len2];

    printf("Levenshtein Distance: %d\n", result);

    for(i=0; i<=len1; i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}

int minimum(int a, int b, int c)
{
    int min = a;
    if(b<min){
        min = b;
    }
    if(c<min){
        min = c;
    }
    return min;
}