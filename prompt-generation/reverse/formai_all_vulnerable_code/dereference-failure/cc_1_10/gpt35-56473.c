//FormAI DATASET v1.0 Category: Compression algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_LENGTH 1000

// Define the compression algorithm function
void compress(char* str)
{
    int count = 1;
    int j = 0;
    int len = strlen(str);

    // Create a new string to store the compressed version of the input string
    char* compressed = (char*)malloc(sizeof(char) * (MAX_LENGTH + 1));
    compressed[0] = str[0];

    // Traverse the input string and count the number of consecutive characters
    for(int i = 1; i < len; i++)
    {
        if(str[i] == str[i-1])
        {
            count++;
        }
        else
        {
            // Store the count followed by the character
            compressed[++j] = count + '0';
            compressed[++j] = str[i];
            count = 1;
        }
    }

    // Store the last count followed by the character
    compressed[++j] = count + '0';
    compressed[++j] = '\0';

    // Print the compressed version of the input string
    printf("Compressed: %s\n", compressed);

    // Free the memory allocated to the compressed string
    free(compressed);
}

int main()
{
    // Define the input string
    char str[MAX_LENGTH];

    // Get the input string from the user
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    // Remove the newline character from the input string
    str[strcspn(str, "\n")] = '\0';

    // Call the compression algorithm function
    compress(str);

    return 0;
}