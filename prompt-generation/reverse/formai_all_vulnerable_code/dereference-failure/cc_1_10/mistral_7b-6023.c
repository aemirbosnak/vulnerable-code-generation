//MISTRAL-7B DATASET v1.0 Category: Metadata Extractor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define FILE_MAGIC_SIZE 8
#define MAX_LINE_LENGTH 1024
#define WORD_DELIMITER " \t\r\n\v\f"

typedef struct {
    char magic[FILE_MAGIC_SIZE];
    off_t file_size;
    int lines;
    float avg_word_length;
} metadata_t;

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    metadata_t metadata;
    int i, j;
    char filename[128], line[MAX_LINE_LENGTH];
    FILE *file;

    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    strcpy(filename, argv[1]);

    // Open file
    file = fopen(filename, "rb");
    if (file == NULL) {
        die("Failed to open file");
    }

    // Read magic number
    fread(metadata.magic, sizeof(metadata.magic), 1, file);
    if (strncmp(metadata.magic, "TEXT", 4) != 0) {
        fprintf(stderr, "Invalid file format: %s\n", metadata.magic);
        fclose(file);
        return EXIT_FAILURE;
    }

    // Seek to beginning of file and read lines
    fseek(file, 0, SEEK_SET);
    metadata.lines = 0;

    while (fgets(line, sizeof(line), file)) {
        ++metadata.lines;
        for (i = 0; line[i] != '\0'; ++i) {
            if (isalpha(line[i])) {
                for (j = i; isalnum(line[j]); ++j) {
                    ++metadata.avg_word_length;
                }
                metadata.avg_word_length /= (j - i);
                i = j;
                break;
            }
        }
    }

    fclose(file);

    printf("File metadata:\n");
    printf("  Type: Text\n");
    printf("  Lines: %d\n", metadata.lines);
    printf("  Average word length: %.2f\n", metadata.avg_word_length);

    return EXIT_SUCCESS;
}