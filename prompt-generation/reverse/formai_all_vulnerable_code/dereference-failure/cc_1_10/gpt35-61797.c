//FormAI DATASET v1.0 Category: Error handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_FILE_SIZE 1000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char file_contents[MAX_FILE_SIZE];
    size_t bytes_read = fread(file_contents, sizeof(char), MAX_FILE_SIZE, input_file);
    if (bytes_read == 0) {
        if (ferror(input_file)) {
            perror("fread");
        } else {
            fprintf(stderr, "ERROR: input file is empty\n");
        }
        exit(EXIT_FAILURE);
    }

    char output_file_name[100];
    sprintf(output_file_name, "%s.out", argv[1]);
    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    size_t bytes_written = fwrite(file_contents, sizeof(char), bytes_read, output_file);
    if (bytes_written != bytes_read) {
        perror("fwrite");
        exit(EXIT_FAILURE);
    }

    printf("File copied successfully.\n");

    if (fclose(input_file) != 0) {
        perror("fclose");
        exit(EXIT_FAILURE);
    }

    if (fclose(output_file) != 0) {
        perror("fclose");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}