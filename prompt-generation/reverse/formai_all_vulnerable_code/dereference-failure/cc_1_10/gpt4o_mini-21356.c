//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 100
#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256

typedef struct {
    char filename[MAX_LINE_LENGTH];
    long line_count;
    long word_count;
    long char_count;
} FileMetadata;

int count_lines(FILE *file) {
    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        count++;
    }
    return count;
}

void count_words_and_chars(FILE *file, long *words, long *chars) {
    char ch;
    *words = 0;
    *chars = 0;
    while ((ch = fgetc(file)) != EOF) {
        (*chars)++;
        if (isspace(ch)) {
            if (ch == '\n') {
                (*words)++;
            }
        } else {
            if (ch == ' ' || ch == '\t' || ch == '\n') {
                (*words)++;
            }
        }
    }
}

void extract_metadata(const char *filenames[], int file_count, FileMetadata metadata[]) {
    for (int i = 0; i < file_count; i++) {
        strcpy(metadata[i].filename, filenames[i]);
        FILE *file = fopen(filenames[i], "r");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
        
        metadata[i].line_count = count_lines(file);
        fseek(file, 0, SEEK_SET); // Reset file pointer to the start
        count_words_and_chars(file, &metadata[i].word_count, &metadata[i].char_count);
        fclose(file);
    }
}

void print_metadata(FileMetadata metadata[], int file_count) {
    printf("%-30s %-10s %-10s %-10s\n", "Filename", "Lines", "Words", "Chars");
    printf("%-30s %-10s %-10s %-10s\n", "=========", "=====", "=====", "=====");
    for (int i = 0; i < file_count; i++) {
        printf("%-30s %-10ld %-10ld %-10ld\n", metadata[i].filename, metadata[i].line_count, metadata[i].word_count, metadata[i].char_count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int file_count = argc - 1;
    FileMetadata metadata[MAX_FILES];

    extract_metadata((const char **)argv + 1, file_count, metadata);
    print_metadata(metadata, file_count);

    return EXIT_SUCCESS;
}