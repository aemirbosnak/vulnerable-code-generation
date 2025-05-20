//MISTRAL-7B DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LENGTH 256
#define SAFE_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-"

bool is_safe_char(char c) {
    int i;
    for (i = 0; i < strlen(SAFE_CHARS); i++) {
        if (c == SAFE_CHARS[i]) {
            return true;
        }
    }
    return false;
}

char* sanitize_string(char* input) {
    int i, j = 0;
    int length = strlen(input);
    char* output = malloc(length * sizeof(char));

    for (i = 0; i < length; i++) {
        if (is_safe_char(input[i])) {
            output[j++] = input[i];
        }
    }

    output[j] = '\0';
    return output;
}

char* read_input(int* size) {
    char* buffer = NULL;
    size_t length = 0;
    getline(&buffer, &length, stdin);

    if (length > MAX_LENGTH) {
        fprintf(stderr, "Input too long!\n");
        if (buffer != NULL) {
            free(buffer);
        }
        exit(EXIT_FAILURE);
    }

    *size = length;
    char* input = malloc((length + 1) * sizeof(char));
    strncpy(input, buffer, length + 1);
    free(buffer);
    return input;
}

int main(int argc, char* argv[]) {
    int size;
    char* input = read_input(&size);
    char* sanitized_input = sanitize_string(input);

    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening file");
        free(sanitized_input);
        free(input);
        exit(EXIT_FAILURE);
    }

    write(fd, sanitized_input, strlen(sanitized_input));
    close(fd);

    printf("Sanitized input: %s\n", sanitized_input);
    free(sanitized_input);
    free(input);

    return EXIT_SUCCESS;
}