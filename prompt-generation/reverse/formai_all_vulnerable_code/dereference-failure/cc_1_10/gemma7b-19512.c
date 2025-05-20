//Gemma-7B DATASET v1.0 Category: Error handling ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ERROR_MSG_LEN 256

typedef struct Error {
    char *message;
    struct Error *next;
} Error;

Error *error_list = NULL;

void add_error(char *message)
{
    Error *new_error = malloc(sizeof(Error));
    new_error->message = strdup(message);
    new_error->next = error_list;
    error_list = new_error;
}

int main()
{
    int i = 0;
    char *buffer = NULL;

    add_error("Memory allocation failed");
    add_error("File not found");
    add_error("Syntax error");

    buffer = malloc(1024);
    if (buffer == NULL) {
        add_error("Memory allocation failed");
    }

    FILE *file = fopen("non-existent.txt", "r");
    if (file == NULL) {
        add_error("File not found");
    }

    // Attempt to read data from the file
    if (fscanf(file, "%d", &i) != 1) {
        add_error("Syntax error");
    }

    printf("Error messages:\n");
    for (Error *error = error_list; error; error = error->next) {
        printf("%s\n", error->message);
    }

    return 1;
}