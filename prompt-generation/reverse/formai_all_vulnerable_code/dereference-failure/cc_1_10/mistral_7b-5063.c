//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_INPUT_SIZE 1024
#define BUFFER_SIZE 4096

void sanitize_input(char *input) {
    int i, j;
    for (i = 0; i < strlen(input); i++) {
        if ((input[i] >= 'A' && input[i] <= 'Z') ||
            (input[i] >= 'a' && input[i] <= 'z') ||
            input[i] == ' ' || input[i] == '\t' ||
            input[i] == '.' || input[i] == '_' ||
            input[i] == '-') {
            continue;
        }
        for (j = 0; j < i; j++) {
            if (input[i] == input[j]) {
                input[i] = '\0';
                fprintf(stderr, "Invalid character '%c' detected in input.\n", input[i]);
                exit(1);
            }
        }
        if (input[i] == '\0') {
            input[i] = '?';
        }
    }
    input[strlen(input)] = '\0';
}

void write_to_file(char *filename, char *input) {
    int fd;

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening file");
        exit(1);
    }

    write(fd, input, strlen(input));
    close(fd);
}

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE];
    char *filename;
    struct stat file_stats;
    int random_number;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input>\n", argv[0]);
        exit(1);
    }

    strcpy(input, argv[1]);
    sanitize_input(input);

    filename = malloc(strlen(input) + 10);
    strcpy(filename, input);
    strcat(filename, ".txt");

    if (stat(filename, &file_stats) == 0) {
        unlink(filename);
    }

    random_number = rand() % 1000000;
    printf("Sanitized input: %s\n", input);
    printf("Writing to file %s...\n", filename);
    write_to_file(filename, input);
    printf("File %s created successfully.\n", filename);
    printf("Random number: %d\n", random_number);

    return 0;
}