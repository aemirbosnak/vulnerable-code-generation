//FormAI DATASET v1.0 Category: Compression algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_SIZE 1000

// function to compress a given string
char* compress(char* str)
{
    int count = 0, i, j, k;
    char* result = (char*)malloc(MAX_STRING_SIZE*sizeof(char));
    int len = strlen(str);
     
    // handling the first character
    result[count++] = str[0];
 
    // compressing the remaining characters
    for (i = 1; i < len; i++)
    {
        if (str[i] == str[i-1])
        {
            // character is repeated, incrementing count
            k = i;
            while (str[k] == str[i-1] && k < len-1)
                k++;
            j = k-i+1;
            char buffer[10];
            sprintf(buffer, "%d", j);
            int buf_size = strlen(buffer);
            strncpy(result+count, buffer, buf_size);
            count += buf_size;
            result[count++] = str[i-1];
            i = k-1;
        }
        else
        {
            // character is not repeated
            result[count++] = str[i];
        }
    }
    result[count] = '\0';
    return result;
}
 
int main()
{
    char str[MAX_STRING_SIZE];
    printf("Enter a string to compress:\n");
    gets(str);
    char* compressed_str = compress(str);
    printf("Compressed string: %s\n", compressed_str);
    free(compressed_str);
    return 0;
}