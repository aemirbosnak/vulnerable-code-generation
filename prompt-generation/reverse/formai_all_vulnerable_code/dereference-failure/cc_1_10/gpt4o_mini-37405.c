//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

void count_characters(const char *text, int *frequency) {
    while (*text) {
        frequency[(unsigned char)*text]++;
        text++;
    }
}

void print_frequencies(int *frequency) {
    for (int i = 0; i < MAX_CHAR; i++) {
        if (frequency[i] > 0) {
            printf("%c: %d\n", i, frequency[i]);
        }
    }
}

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(length + 1);
    if (!buffer) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, length, file);
    buffer[length] = '\0';
    fclose(file);

    return buffer;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int frequency[MAX_CHAR] = {0};
    char *text = read_file(argv[1]);
    if (!text) {
        return EXIT_FAILURE;
    }

    count_characters(text, frequency);
    print_frequencies(frequency);

    free(text);
    return EXIT_SUCCESS;
}