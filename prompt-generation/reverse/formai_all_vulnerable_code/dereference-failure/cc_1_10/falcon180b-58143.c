//Falcon-180B DATASET v1.0 Category: File handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

char* read_file(FILE* file) {
    char* buffer = NULL;
    size_t buffer_size = 0;
    int c;

    while ((c = fgetc(file))!= EOF) {
        if (buffer_size == MAX_LINE_LENGTH) {
            char* temp_buffer = realloc(buffer, buffer_size + 1);
            if (temp_buffer == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = temp_buffer;
            buffer_size += 1;
        }
        if (c == '\n') {
            buffer[buffer_size] = '\0';
            break;
        }
        buffer[buffer_size] = c;
        buffer_size++;
    }

    if (buffer == NULL) {
        buffer = malloc(1);
        buffer[0] = '\0';
    }

    return buffer;
}

int count_words(char* line) {
    int count = 0;
    int in_word = 0;

    for (int i = 0; i < strlen(line); i++) {
        if (isspace(line[i])) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }

    return count;
}

int main() {
    FILE* file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char* buffer = read_file(file);

    if (buffer == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    printf("File content:\n%s\n", buffer);

    int word_count = count_words(buffer);

    printf("Word count: %d\n", word_count);

    free(buffer);
    fclose(file);

    return 0;
}