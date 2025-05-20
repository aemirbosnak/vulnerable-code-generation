//FormAI DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function to compress the string
char* compress(char* str)
{
    int i=0,count=1,j=0,N=0;
    int length= strlen(str);
    char *compressed_str = (char*)malloc(sizeof(char)*length);

    while (str[i] != '\0')
    {
        char present_char = str[i];

        // check if the current character first occurred
        while (str[i+1] == present_char)
        {
            count++; // increment the count
            i++;    // move the pointer to the next character
        }

        // add the compressed character to the string
        compressed_str[j] = present_char;
        N++; j++;

        if (count > 1)
        {
            // add the count as a character
            char count_str[10];
            sprintf(count_str, "%d", count);
            for (int k=0; count_str[k] != '\0'; k++)
            {
                compressed_str[j] = count_str[k];
                N++; j++;
            }
            count = 1;
        }
        i++;
    }
    compressed_str[j] = '\0';

    return compressed_str;
}

int main()
{
    char str[100];
    printf("Enter the string to be compressed:");
    scanf("%[^\n]%*c", str);

    char *compressed_str = compress(str);
    printf("\nThe compressed string is: %s\n", compressed_str);

    return 0;
}