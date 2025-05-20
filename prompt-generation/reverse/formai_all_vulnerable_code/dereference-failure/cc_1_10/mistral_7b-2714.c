//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024)
#define MAX_LINE_LENGTH 256
#define MAX_METADATA_KEYS 16

struct metadata {
    char key[32];
    char value[MAX_LINE_LENGTH];
};

void extract_metadata(FILE *file) {
    char line[MAX_LINE_LENGTH];
    struct metadata metadata[MAX_METADATA_KEYS];
    int num_keys = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (num_keys >= MAX_METADATA_KEYS) {
            fprintf(stderr, "Error: Too many metadata keys\n");
            exit(EXIT_FAILURE);
        }

        char *key_start = line;
        while (*key_start && isalnum(*key_start)) key_start++;
        *key_start = '\0';
        key_start--;

        strcpy(metadata[num_keys].key, key_start);

        char *value_start = line;
        while (*value_start && *value_start != ':') value_start++;
        *value_start = '\0';
        value_start++;

        strcpy(metadata[num_keys].value, value_start);

        num_keys++;
    }

    printf("Metadata:\n");
    for (int i = 0; i < num_keys; i++) {
        printf("Key: %s, Value: %s\n", metadata[i].key, metadata[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char file_content[MAX_FILE_SIZE];
    size_t num_bytes_read = fread(file_content, sizeof(char), MAX_FILE_SIZE, file);
    if (num_bytes_read > MAX_FILE_SIZE) {
        fprintf(stderr, "Error: File too large\n");
        exit(EXIT_FAILURE);
    }
    fclose(file);

    extract_metadata(stdin);

    for (size_t i = 0; i < num_bytes_read; i++) {
        putchar(file_content[i]);
    }

    return EXIT_SUCCESS;
}