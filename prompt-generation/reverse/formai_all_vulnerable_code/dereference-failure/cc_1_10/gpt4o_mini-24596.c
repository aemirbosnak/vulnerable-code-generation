//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 256
#define FILE_NAME "example.txt"

void check_allocation(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void check_file(FILE *file) {
    if (file == NULL) {
        fprintf(stderr, "File error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void read_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    check_file(file);

    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Read from file: %s", buffer);
    }

    if (ferror(file)) {
        fprintf(stderr, "Error reading from file: %s\n", strerror(errno));
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

void write_to_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");
    check_file(file);

    if (fprintf(file, "%s\n", content) < 0) {
        fprintf(stderr, "Error writing to file: %s\n", strerror(errno));
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

char *get_user_input() {
    char *input = malloc(MAX_BUFFER_SIZE);
    check_allocation(input);

    printf("Enter your content (max %d characters): ", MAX_BUFFER_SIZE - 1);
    if (fgets(input, MAX_BUFFER_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading input: %s\n", strerror(errno));
        free(input);
        exit(EXIT_FAILURE);
    }

    // Remove newline character from the end
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    return input;
}

void display_welcome_message() {
    printf("Welcome to the Simple File Writer!\n");
    printf("You can write content to a file and read it back.\n\n");
}

int main() {
    display_welcome_message();

    char *user_content = get_user_input();
    write_to_file(FILE_NAME, user_content);

    printf("Content written to '%s'.\n", FILE_NAME);
    printf("Reading content from the file...\n");
    read_from_file(FILE_NAME);

    free(user_content);
    return EXIT_SUCCESS;
}