//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_INPUT_SIZE 1024
#define MAX_FILENAME_SIZE 100

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_FILENAME_SIZE];
    char input[MAX_INPUT_SIZE];
    int ch;
    regex_t regex;
    regmatch_t match;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    file = fopen(filename, "w");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    regcomp(&regex, "^[a-zA-Z0-9._-]+$", REG_NEWLINE | REG_EXTENDED);

    printf("Enter input to write to the file. Input must only contain alphanumeric characters, underscores, dots, and hyphens.\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (regexec(&regex, input, 1, &match, REG_NOTEOL) == 0) {
            fputs(input, file);
            printf("Input saved to file.\n");
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    regfree(&regex);
    fclose(file);

    return 0;
}