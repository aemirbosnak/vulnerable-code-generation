//Gemma-7B DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    // Allocate memory for the buffer
    char *buffer = (char *)malloc(MAX_BUFFER_SIZE);

    // Read the source code from the user
    printf("Enter source code: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    // Strip the newline character from the end of the buffer
    buffer[strcspn(buffer, "\n")] = '\0';

    // Convert the source code into uppercase
    char *upper_buffer = (char *)malloc(MAX_BUFFER_SIZE);
    strcpy(upper_buffer, buffer);
    for (int i = 0; upper_buffer[i] != '\0'; i++)
    {
        upper_buffer[i] = toupper(upper_buffer[i]);
    }

    // Insert line numbers
    int line_number = 1;
    char *formatted_buffer = (char *)malloc(MAX_BUFFER_SIZE);
    strcpy(formatted_buffer, upper_buffer);
    for (int i = 0; formatted_buffer[i] != '\0'; i++)
    {
        if (formatted_buffer[i] == '\n')
        {
            sprintf(formatted_buffer + i, "%d ", line_number);
            line_number++;
        }
    }

    // Print the formatted code
    printf("Formatted code:\n\n");
    printf("%s\n", formatted_buffer);

    // Free the allocated memory
    free(buffer);
    free(upper_buffer);
    free(formatted_buffer);

    return 0;
}