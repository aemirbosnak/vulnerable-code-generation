//Gemma-7B DATASET v1.0 Category: Error handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>

void handle_error(int error_code, char *error_message)
{
    switch (error_code)
    {
        case 1:
            printf("Error: Invalid input.\n");
            break;
        case 2:
            printf("Error: Memory allocation failed.\n");
            break;
        case 3:
            printf("Error: File not found.\n");
            break;
        default:
            printf("Error: Unknown error.\n");
            break;
    }

    exit(1);
}

int main()
{
    int result = 0;
    char *memory = NULL;

    // Attempt to allocate memory
    memory = malloc(10);
    if (memory == NULL)
    {
        handle_error(2, "Memory allocation failed.");
    }

    // Use the memory
    result = memcpy(memory, "Hello, world!", 11);
    if (result != 0)
    {
        handle_error(1, "Invalid input.");
    }

    // Free the memory
    free(memory);

    // Print the result
    printf("%s", memory);

    return 0;
}