//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUF_SIZE 1024

void read_file(const char *filename, char **buffer, size_t *size) {
    FILE *file = fopen(filename, "rb");
    size_t current_size = 0;
    size_t bytes_read = 0;
    char *buffer_ptr = NULL;

    if (file == NULL) {
        *buffer = NULL;
        *size = 0;
        return;
    }

    buffer_ptr = malloc(BUF_SIZE);
    if (buffer_ptr == NULL) {
        fclose(file);
        *buffer = NULL;
        *size = 0;
        return;
    }

    while (true) {
        bytes_read = fread(buffer_ptr, 1, BUF_SIZE, file);
        if (bytes_read > 0) {
            current_size += bytes_read;
            if (current_size + BUF_SIZE >= *size) {
                *size *= 2;
                *buffer = realloc(*buffer, *size);
            }
            memcpy(*buffer + current_size, buffer_ptr, bytes_read);
        } else {
            break;
        }
    }

    fclose(file);
    free(buffer_ptr);
}

size_t count_occurrences(const char *buffer, size_t size, const char *word, size_t word_len) {
    size_t count = 0;
    size_t pos = 0;

    while ((pos = memmem(buffer + pos, size - pos, word, word_len)) != NULL) {
        count++;
        pos += word_len;
    }

    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <word>\n", argv[0]);
        return 1;
    }

    char *buffer = NULL;
    size_t size = 0;

    read_file(argv[1], &buffer, &size);
    if (buffer == NULL) {
        printf("Error: Unable to read file '%s'\n", argv[1]);
        return 1;
    }

    const char *word = argv[2];
    size_t word_len = strlen(word);

    size_t count = count_occurrences(buffer, size, word, word_len);

    printf("The word '%s' occurs %ld times in the file '%s'.\n", word, count, argv[1]);

    free(buffer);

    return 0;
}