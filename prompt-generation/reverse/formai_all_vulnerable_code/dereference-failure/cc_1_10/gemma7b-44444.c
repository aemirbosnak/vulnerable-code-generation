//Gemma-7B DATASET v1.0 Category: Data mining ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int main()
{
    // Allocate memory for the data
    char *data = malloc(MAX_SIZE);

    // Get the data
    printf("Enter data: ");
    fgets(data, MAX_SIZE, stdin);

    // Tokenize the data
    char *token = strtok(data, ",");

    // Create an array of tokens
    char **tokens = malloc(MAX_SIZE * sizeof(char *));

    // Store the tokens
    int i = 0;
    while (token)
    {
        tokens[i++] = token;
        token = strtok(NULL, ",");
    }

    // Analyze the tokens
    for (i = 0; tokens[i] != NULL; i++)
    {
        // Print the token
        printf("Token: %s\n", tokens[i]);

        // Check if the token is a number
        if (isdigit(tokens[i]))
        {
            // Convert the token to an integer
            int number = atoi(tokens[i]);

            // Print the number
            printf("Number: %d\n", number);
        }
    }

    // Free the memory
    free(data);
    free(tokens);

    return 0;
}