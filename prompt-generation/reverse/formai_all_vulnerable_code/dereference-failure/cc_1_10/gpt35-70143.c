//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: post-apocalyptic
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

int min(int x, int y, int z) 
{ 
    if (x < y && x < z) return x; 
    else if (y < x && y < z) return y; 
    else return z; 
} 

int dist(char* s1, char* s2, int len1, int len2) 
{ 
    int** d = malloc((len1+1) * sizeof(int*)); 
    
    for(int i=0; i<=len1; i++) 
        d[i] = malloc((len2+1) * sizeof(int)); 

    for(int i=0;i<=len1;i++) 
        d[i][0] = i; 
    for(int i=0;i<=len2;i++) 
        d[0][i] = i; 

    for(int i=1;i<=len1;i++) 
    { 
        for(int j=1;j<=len2;j++) 
        { 
            int delta = s1[i-1] == s2[j-1] ? 0 : 1; 
            d[i][j] = min(d[i-1][j]+1, d[i][j-1]+1, d[i-1][j-1]+delta); 
        } 
    } 

    return d[len1][len2]; 
} 

int main() 
{ 
    char str1[100], str2[100]; 
    printf("Enter String 1: "); 
    scanf("%s",str1); 

    printf("Enter String 2: "); 
    scanf("%s",str2); 

    int len1 = strlen(str1), len2 = strlen(str2); 
    int result = dist(str1, str2, len1, len2); 

    printf("The Levenshtein Distance between %s and %s is %d\n",str1,str2,result); 

    return 0; 
}