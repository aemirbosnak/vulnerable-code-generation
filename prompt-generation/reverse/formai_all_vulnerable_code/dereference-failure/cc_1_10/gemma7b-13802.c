//Gemma-7B DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[] = "Romeo loves Juliet";
    char str2[] = "Montague and Capulet feud";
    char str3[] = "Their forbidden love";

    int i = 0;
    char **arr = NULL;

    // Allocates memory for the array
    arr = (char **)malloc(sizeof(char *) * 3);

    // Stores the three strings in the array
    arr[0] = str1;
    arr[1] = str2;
    arr[2] = str3;

    // Iterate over the array and prints the words
    for (i = 0; i < 3; i++)
    {
        char *word = NULL;
        char *p = arr[i];

        // Splits the string into words
        while (p)
        {
            word = strchr(p, ' ');
            if (word)
            {
                printf("%s ", word);
                p = word + 1;
            }
            else
            {
                printf("%s ", p);
                p = NULL;
            }
        }

        printf("\n");
    }

    // Frees the memory allocated for the array
    free(arr);

    return 0;
}