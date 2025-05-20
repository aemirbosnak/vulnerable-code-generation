//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stddef.h>

#define BUFFER_SIZE 1024

size_t file_size(FILE *stream) {
    size_t position = 0;
    char c;

    while ((c = getc(stream)) != EOF) {
        position++;
    }

    rewind(stream);
    return position;
}

int main(void) {
    FILE *file = NULL;
    char *content = NULL;
    size_t file_length = 0;
    size_t buffer_size = BUFFER_SIZE;
    char buffer[BUFFER_SIZE];
    size_t apple_count = 0;
    int read_result;

    file = fopen("data.txt", "r");

    if (file == NULL) {
        perror("Error opening file:");
        return EXIT_FAILURE;
    }

    file_length = file_size(file);

    content = malloc(file_length + 1);
    if (content == NULL) {
        perror("Error allocating memory:");
        fclose(file);
        return EXIT_FAILURE;
    }

    if (file_length > 0) {
        read_result = fread(buffer, 1, BUFFER_SIZE, file);

        while (read_result > 0 && file_length > BUFFER_SIZE) {
            buffer_size += BUFFER_SIZE;
            content = realloc(content, buffer_size + 1);
            read_result = fread(buffer + file_length - BUFFER_SIZE, 1, BUFFER_SIZE, file);
        }

        if (read_result > 0) {
            memcpy(content + file_length - read_result, buffer, read_result);
        }

        fclose(file);

        if (strstr(content, "apple") != NULL) {
            char *position = content;

            while ((position = strstr(position, "apple")) != NULL) {
                apple_count++;
                position += 5;
            }
        }

        printf("Number of occurrences of 'apple': %zu\n", apple_count);
        printf("File content:\n%s\n", content);

        free(content);
    }

    return EXIT_SUCCESS;
}