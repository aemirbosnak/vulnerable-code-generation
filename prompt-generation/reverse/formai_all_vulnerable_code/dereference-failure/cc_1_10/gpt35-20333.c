//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: detailed
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int levenshteinDistance(char *s1, char *s2)
{
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    int **d;
    int i, j, distance;
    
    d = (int**)calloc(s1_len + 1, sizeof(int*)); // allocate memory for 2D array
    for(i = 0; i < s1_len + 1; i++)
        d[i] = (int*)calloc(s2_len + 1, sizeof(int));
    
    // initialize the first row and column of matrix d
    for(i = 0; i < s1_len + 1; i++) d[i][0] = i;
    for(j = 0; j < s2_len + 1; j++) d[0][j] = j;

    // compute the distance
    for(j = 1; j < s2_len + 1; j++)
    {
        for(i = 1; i < s1_len + 1; i++)
        {
            if(s1[i-1] == s2[j-1])
                d[i][j] = d[i-1][j-1];
            else
                d[i][j] = 1 + MAX(MAX(d[i-1][j-1], d[i-1][j]), d[i][j-1]);
        }
    }

    // the final answer is at d[s1_len][s2_len]
    distance = d[s1_len][s2_len];

    // free the allocated memory
    for(i = 0; i < s1_len + 1; i++)
        free(d[i]);
    free(d);
    
    return distance;
}

int main()
{
    char s1[100], s2[100], c;
    int i = 0;

    // get first string
    printf("Enter first string: ");
    while((c = getchar()) != '\n' && i < 100)
    {
        s1[i] = tolower(c); // convert to lowercase
        i++;
    }
    s1[i] = '\0';

    // reset counter to get second string
    i = 0;

    // get second string
    printf("Enter second string: ");
    while((c = getchar()) != '\n' && i < 100)
    {
        s2[i] = tolower(c); // convert to lowercase
        i++;
    }
    s2[i] = '\0';

    // calculate distance and print result
    printf("\nThe Levenshtein Distance between '%s' and '%s' is %d.\n\n", s1, s2, levenshteinDistance(s1, s2));

    return 0;
}