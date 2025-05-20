//FormAI DATASET v1.0 Category: Compression algorithms ; Style: relaxed
#include <stdio.h>

// Function to compress the input string
char* compress(char* input)
{
    char* output = (char*)malloc(sizeof(char) * strlen(input) * 2);
    int i = 0; // pointer to the input string
    int j = 0; // pointer to the output string
    int count = 1; // keeps track of consecutive characters

    while (input[i] != '\0')
    {
        if (input[i] == input[i+1]) // if current character and next character are the same
        {
            count++; // increase the count for this character
        }
        else // if current and next character are different or end of the input string
        {
            // add the current character to the output string
            output[j] = input[i];
            j++;

            // if the count is greater than 1, add it to the output string
            if (count > 1)
            {
                char count_str[10]; // temporary string to store the count
                sprintf(count_str, "%d", count); // convert the count integer to string
                int k;
                for (k=0; k<strlen(count_str); k++)
                {
                    output[j] = count_str[k];
                    j++;
                }
                count = 1; // reset the count for the next character
            }

        }

        i++;
    }

    // add the null terminator to the output string
    output[j] = '\0';

    return output;
}

int main()
{
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);

    char* output = compress(input);

    printf("Compressed string: %s", output);

    free(output); // free the memory allocated for the output string

    return 0;
}