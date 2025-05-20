//FormAI DATASET v1.0 Category: Compression algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000 // Maximum input size

char *compress(char *input);

int main()
{
    char *input = (char *)malloc(MAX_INPUT_SIZE * sizeof(char));

    // Get input from user
    printf("Enter the string to be compressed: ");
    scanf("%[^\n]%*c", input);

    // Compress the input string
    char *compressed_str = compress(input);

    // Print the compressed string
    printf("\nCompressed string: %s\n", compressed_str);

    return 0;
}

char *compress(char *input)
{
    int input_len = strlen(input);
    char *compressed = (char *)malloc((input_len + 1) * sizeof(char));

    int i, j = 0, count = 1;
    char current_char;

    // Loop through each character of input string
    for (i = 0; i < input_len; i++)
    {
        current_char = input[i];

        // If current character matches next character, increase count
        if (input[i] == input[i + 1] && i < input_len - 1)
        {
            count++;
        }
        else
        {
            // Store current character and count in compressed string
            compressed[j++] = current_char;
            compressed[j++] = count + '0';
            count = 1;
        }
    }

    compressed[j] = '\0'; // Add null terminator to compressed string

    return compressed;
}