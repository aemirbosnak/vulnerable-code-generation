//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRINGS 100
#define MAX_CHARS 100

typedef struct StringData {
    char str[MAX_CHARS];
    int len;
    struct StringData *next;
} StringData;

void error_handler(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    StringData *head = NULL;
    StringData *current = NULL;
    StringData *new_string = NULL;
    char input_string[MAX_CHARS] = {0};
    int i = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string list file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        error_handler("Could not open file");
    }

    while (fgets(input_string, sizeof(input_string), file)) {
        new_string = (StringData *) malloc(sizeof(StringData));
        if (!new_string) {
            error_handler("Memory allocation failed");
        }

        strncpy(new_string->str, input_string, MAX_CHARS - 1);
        new_string->len = strlen(new_string->str);
        new_string->next = NULL;

        if (!head) {
            head = new_string;
            current = head;
        } else {
            current->next = new_string;
            current = new_string;
        }
    }

    fclose(file);

    current = head;
    while (current != NULL) {
        printf("%s\n", current->str);
        current = current->next;
    }

    while (current != NULL) {
        StringData *temp = current;
        current = current->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}