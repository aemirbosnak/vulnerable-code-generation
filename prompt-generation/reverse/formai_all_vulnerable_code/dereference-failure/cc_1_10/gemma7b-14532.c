//Gemma-7B DATASET v1.0 Category: Error handling ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_error(int error_code)
{
    switch (error_code)
    {
        case 1:
            fprintf(stderr, "Oops! You're out of memory. Sorry, try again.\n");
            break;
        case 2:
            fprintf(stderr, "File not found! Please check the file path.\n");
            break;
        case 3:
            fprintf(stderr, "Syntax error! Invalid format or data.\n");
            break;
        default:
            fprintf(stderr, "Unhandled error! Please consult the documentation.\n");
            break;
    }
    exit(error_code);
}

int main()
{
    int result = 0;

    // Attempt to allocate memory
    void* pointer = malloc(10);
    if (pointer == NULL)
    {
        handle_error(1);
    }

    // Attempt to open a file
    FILE* file = fopen("non_existent_file.txt", "r");
    if (file == NULL)
    {
        handle_error(2);
    }

    // Attempt to parse a string
    int number = atoi("invalid_format");
    if (number == -1)
    {
        handle_error(3);
    }

    // Everything went well, print a message
    printf("Congratulations! You've successfully completed the task.\n");

    // Free memory and close file
    free(pointer);
    fclose(file);

    return result;
}