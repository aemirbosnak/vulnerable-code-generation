//FormAI DATASET v1.0 Category: Compression algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Function to compress an input string
void compress(char* input)
{
    char* output = malloc(sizeof(char) * 1000);
    int count = 0;
    int j = 0;
    int len = strlen(input);
    
    for(int i = 0; i < len; i++)
    {
        count = 0;

        // Check if it is a repeat character
        while(input[i] == input[i + 1])
        {
            count++;
            i++;
        }

        // Store the character count in the output string
        if(count > 0)
        {
            int n = sprintf(&output[j], "%d", count);
            j += n;
        }

        // Store the current character in the output string
        output[j] = input[i];
        j++;
    }

    // Append NULL character to the output string
    output[j] = '\0';

    // Print the compressed string
    printf("Compressed string: %s\n", output);

    // Free allocated memory
    free(output);
}

int main()
{
    char input[1000];

    // Prompt user for input string
    printf("Enter a string to compress: ");
    fgets(input, 1000, stdin);

    // Remove newline character from input string
    input[strcspn(input, "\n")] = 0;

    // Call the compress function
    compress(input);

    return 0;
}