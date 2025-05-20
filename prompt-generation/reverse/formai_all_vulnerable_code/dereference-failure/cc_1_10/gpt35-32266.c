//FormAI DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_INPUT_SIZE 10000

// Define the maximum size of the output string
#define MAX_OUTPUT_SIZE 20000

// Function to encode the input string using run-length encoding
char *runLengthEncode(char *input)
{
    char *output = (char *) malloc(MAX_OUTPUT_SIZE * sizeof(char));

    int i, j, count;
    char current;

    // Loop through the characters in the input string
    i = 0;
    j = 0;
    while (input[i] != '\0')
    {
        // Set the current character and count to the current input character
        current = input[i];
        count = 1;

        // Loop through the subsequent characters, counting the number of consecutive characters
        while (input[i + 1] == current)
        {
            count++;
            i++;
        }

        // Append the encoded character and count to the output string
        output[j] = current;
        output[j + 1] = count + '0';
        j += 2;

        // Move to the next character in the input string
        i++;
    }

    // Append the null terminator to the end of the output string
    output[j] = '\0';

    // Return the encoded output string
    return output;
}

// Function to decode the input string using run-length decoding
char *runLengthDecode(char *input)
{
    char *output = (char *) malloc(MAX_INPUT_SIZE * sizeof(char));

    int i, j, count;
    char current;

    // Loop through the characters in the input string
    i = 0;
    j = 0;
    while (input[i] != '\0')
    {
        // Set the current character and count to the current input character and the next character, respectively
        current = input[i];
        count = input[i + 1] - '0';

        // Append the decoded characters to the output string
        for (int k = 0; k < count; k++)
        {
            output[j] = current;
            j++;
        }

        // Move to the next character in the input string
        i += 2;
    }

    // Append the null terminator to the end of the output string
    output[j] = '\0';

    // Return the decoded output string
    return output;
}

int main()
{
    char input[MAX_INPUT_SIZE];
    char *output;

    // Prompt the user for the input string
    printf("Enter the input string:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Encode the input string using run-length encoding
    output = runLengthEncode(input);
    printf("Encoded string: %s\n", output);

    // Decode the encoded string using run-length decoding
    output = runLengthDecode(output);
    printf("Decoded string: %s\n", output);

    // Free the output string
    free(output);

    return 0;
}