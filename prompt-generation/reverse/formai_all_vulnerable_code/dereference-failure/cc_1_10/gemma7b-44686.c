//Gemma-7B DATASET v1.0 Category: Data mining ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int main()
{
    char **arr = (char **)malloc(MAX * sizeof(char *));
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = (char *)malloc(20 * sizeof(char));
    }

    arr[0] = "John Doe";
    arr[1] = "Jane Doe";
    arr[2] = "Billy Bob";
    arr[3] = "Mary Sue";
    arr[4] = "Tom Cruise";
    arr[5] = "Arnold Schwarzenegger";
    arr[6] = "Bruce Willis";
    arr[7] = "Robert Downey Jr.";
    arr[8] = "Chris Hemsworth";
    arr[9] = "Mark Ruffalo";

    // Data Mining Algorithm - Find the shortest name
    int min_len = MAX;
    for (int i = 0; i < MAX; i++)
    {
        int len = strlen(arr[i]);
        if (len < min_len)
        {
            min_len = len;
        }
    }

    // Print the shortest name
    for (int i = 0; i < MAX; i++)
    {
        int len = strlen(arr[i]);
        if (len == min_len)
        {
            printf("%s\n", arr[i]);
        }
    }

    // Free memory
    for (int i = 0; i < MAX; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}