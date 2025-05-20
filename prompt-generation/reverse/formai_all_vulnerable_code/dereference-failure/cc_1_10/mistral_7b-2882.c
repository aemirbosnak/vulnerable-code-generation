//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct error {
    const char *message;
    struct error *next;
} Error;

void error_push(Error **head, const char *msg) {
    Error *new_error = malloc(sizeof(Error));
    new_error->message = strdup(msg);
    new_error->next = *head;
    *head = new_error;
}

void error_print(const Error *err) {
    for (; err != NULL; err = err->next) {
        printf("Error: %s\n", err->message);
    }
}

void read_file(const char *path, Error **errors) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        error_push(errors, "Could not open file");
        return;
    }

    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            error_push(errors, "Invalid character in file: \\n");
            break;
        }
    }

    fclose(file);
}

int main() {
    Error *errors = NULL;
    const char *file_path = "example.txt";

    read_file(file_path, &errors);

    error_print(errors);

    for (Error *err = errors; err != NULL; err = err->next) {
        free(err->message);
        free(err);
    }

    return 0;
}