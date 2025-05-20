//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_SIZE 1024 * 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

bool is_valid_file(const char *path) {
    struct stat st;
    if (stat(path, &st) < 0) {
        die("stat");
    }

    if (S_ISDIR(st.st_mode)) {
        die("Invalid file: Is a directory.");
    }

    if (st.st_size > MAX_FILE_SIZE) {
        die("Invalid file: Size exceeds limit.");
    }

    return true;
}

void parse_line(const char *line) {
    char token[MAX_LINE_LENGTH];
    char *token_ptr;

    memset(token, 0, sizeof(token));

    token_ptr = strtok(line, "\t");

    if (token_ptr == NULL) {
        die("Invalid line format.");
    }

    strncpy(token, token_ptr, sizeof(token) - 1);

    // Process the token here, for example:
    if (strcmp(token, "Name") != 0) {
        die("Invalid field name.");
    }

    token_ptr = strtok(NULL, "\t");

    if (token_ptr == NULL) {
        die("Invalid line format.");
    }

    strncpy(token, token_ptr, sizeof(token) - 1);

    // Process the value here, for example:
    if (strlen(token) > MAX_LINE_LENGTH) {
        die("Invalid value length.");
    }

    // ...
}

int main(int argc, char **argv) {
    char line[MAX_LINE_LENGTH];
    char *file_ptr;
    FILE *fp;

    if (argc != 2) {
        die("Usage: ./parser <resume_file>");
    }

    file_ptr = argv[1];

    if (is_valid_file(file_ptr) == false) {
        die("Invalid file path.");
    }

    fp = fopen(file_ptr, "r");

    if (fp == NULL) {
        die("Failed to open file.");
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        parse_line(line);
    }

    fclose(fp);

    printf("Parsing completed successfully.\n");

    return EXIT_SUCCESS;
}