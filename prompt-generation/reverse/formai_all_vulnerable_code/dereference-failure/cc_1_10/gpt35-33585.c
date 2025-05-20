//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findMin(int a, int b, int c)
{
    if(a<b)
    {
        if(a<c)
            return a;
        else
            return c;
    }
    else
    {
        if(b<c)
            return b;
        else
            return c;
    }
}

int levenshteinDistance(char* str1, char* str2, int len1, int len2)
{
    int** dist= (int**) malloc((len1+1)*sizeof(int *));
    for(int i=0; i<=len1; i++)
        dist[i]= (int*) malloc((len2+1)*sizeof(int));
    for(int i=0; i<=len1; i++)
        dist[i][0]=i;
    for(int j=0; j<=len2; j++)
        dist[0][j]=j;
    for(int i=1; i<=len1; i++)
    {
        for(int j=1; j<=len2; j++)
        {
            int cost= (str1[i-1]!=str2[j-1]);
            dist[i][j]= findMin(dist[i-1][j]+1, dist[i][j-1]+1, dist[i-1][j-1]+cost);
        }
    }
    int result= dist[len1][len2];
    for(int i=0; i<=len1; i++)
        free(dist[i]);
    free(dist);
    return result;
}

int main()
{
    printf("Enter the string 1:\n");
    char str1[1000];
    scanf("%s", str1);
    printf("Enter the string 2:\n");
    char str2[1000];
    scanf("%s", str2);
    int len1= strlen(str1);
    int len2= strlen(str2);
    int result= levenshteinDistance(str1, str2, len1, len2);
    printf("The levenshtein distance between the two strings is: %d\n", result);
    return 0;
}