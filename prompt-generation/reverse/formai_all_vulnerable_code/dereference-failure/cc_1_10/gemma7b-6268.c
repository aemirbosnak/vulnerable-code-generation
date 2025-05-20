//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro to swap two pointers
void swap(void *a, void *b)
{
    void *temp = a;
    a = b;
    b = temp;
}

// Function to compress a string
int compress(char *str)
{
    char *ptr = str;
    int i = 0;
    int count = 1;

    // Iterate over the string
    for (; *ptr; ptr++)
    {
        if (*ptr == *(ptr - 1))
        {
            count++;
        }
        else
        {
            *(str + i) = *ptr;
            i++;
            count = 1;
        }

    }

    // Return the number of characters in the compressed string
    return i;
}

int main()
{
    char str[] = "aabbbbcccc";
    int len = compress(str);

    printf("Compressed string: ");
    for (int i = 0; i < len; i++)
    {
        printf("%c", str[i]);
    }

    printf("\nNumber of characters in the compressed string: %d", len);

    return 0;
}