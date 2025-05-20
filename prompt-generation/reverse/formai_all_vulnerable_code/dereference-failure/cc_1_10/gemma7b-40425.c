//Gemma-7B DATASET v1.0 Category: String manipulation ; Style: expert-level
#include <stdio.h>
#include <string.h>

int main()
{
    char str[] = "This is a string";
    char *ptr = str;
    char delimiter[] = ",";
    int i = 0;
    int count = 0;

    // Find the number of delimiters in the string
    for (i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == delimiter[0])
        {
            count++;
        }
    }

    // Split the string into chunks
    char **chunks = (char **)malloc((count + 1) * sizeof(char *));
    char *chunk = NULL;
    int j = 0;

    for (i = 0; ptr[i] != '\0'; i++)
    {
        if (ptr[i] == delimiter[0])
        {
            chunks[j++] = chunk;
            chunk = ptr + i + 1;
        }
        else
        {
            if (chunk)
            {
                *chunk++ = ptr[i];
            }
        }
    }

    // Print the chunks
    for (i = 0; chunks[i] != NULL; i++)
    {
        printf("%s\n", chunks[i]);
    }

    free(chunks);

    return 0;
}