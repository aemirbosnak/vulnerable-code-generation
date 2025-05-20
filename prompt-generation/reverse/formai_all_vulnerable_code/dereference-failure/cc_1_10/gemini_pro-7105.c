//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the file into a buffer
    char *buffer = malloc(1024);
    size_t buffer_size = 1024;
    size_t buffer_length = 0;
    while (1) {
        size_t bytes_read = fread(buffer + buffer_length, 1, buffer_size - buffer_length, fp);
        if (bytes_read == 0) {
            break;
        }
        buffer_length += bytes_read;
        if (buffer_length == buffer_size) {
            buffer_size *= 2;
            buffer = realloc(buffer, buffer_size);
            if (buffer == NULL) {
                perror("realloc");
                fclose(fp);
                return EXIT_FAILURE;
            }
        }
    }

    // Count the words in the buffer
    int word_count = 0;
    int in_word = 0;
    for (size_t i = 0; i < buffer_length; i++) {
        char c = buffer[i];
        if (isspace(c)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            word_count++;
        }
    }

    // Print the word count
    printf("%d words\n", word_count);

    // Free the buffer
    free(buffer);

    // Close the file
    fclose(fp);

    return EXIT_SUCCESS;
}