//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: shocked
#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) 
{
    int m = a;
    
    if (b < m) 
    {
        m = b;
    }
    
    if (c < m) 
    {
        m = c;
    }
    
    return m;
}

int ld(char *s1, char *s2) 
{
    int l1 = strlen(s1), l2 = strlen(s2);
    int i, j, cost, *d, distance;
    d = calloc(sizeof(int), (l1 + 1) * (l2 + 1));
    
    for (i = 0; i <= l1; i++)
    {
        d[i] = i;
    }
    
    for (j = 0; j <= l2; j++) 
    {
        d[j * (l1 + 1)] = j;
    }
    
    for (j = 1; j <= l2; j++) 
    {
        for (i = 1; i <= l1; i++) 
        {
            if (s1[i - 1] == s2[j - 1]) 
            {
                cost = 0;
            } 
            else 
            {
                cost = 1;
            }
            
            d[j * (l1 + 1) + i] = min(d[(j - 1) * (l1 + 1) + i] + 1,
                                       d[j * (l1 + 1) + i - 1] + 1,
                                       d[(j - 1) * (l1 + 1) + i - 1] + cost);
        }
    }
    
    distance = d[l2 * (l1 + 1) + l1];
    free(d);
    
    return distance;
}

int main() 
{
    char *s1 = "dynamic";
    char *s2 = "programming";
    int distance = ld(s1, s2);
    
    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n", s1, s2, distance);
    
    return 0;
}