//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024

void read_file_into_memory(char *filename, char **buffer) {
    FILE *file;
    size_t file_size = 0;
    char *content = NULL;

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Failed to open %s for reading.\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    content = malloc(file_size + 1);
    if (content == NULL) {
        fprintf(stderr, "Failed to allocate memory for file content.\n");
        exit(1);
    }

    size_t bytes_read = fread(content, 1, file_size, file);
    if (bytes_read!= file_size) {
        fprintf(stderr, "Failed to read entire file into memory.\n");
        exit(1);
    }

    content[file_size] = '\0';
    *buffer = content;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];
    char *buffer = NULL;

    read_file_into_memory(filename, &buffer);

    char *token = strtok(buffer, "\n");
    while (token!= NULL) {
        printf("%s", token);
        token = strtok(NULL, "\n");
    }

    free(buffer);
    return 0;
}