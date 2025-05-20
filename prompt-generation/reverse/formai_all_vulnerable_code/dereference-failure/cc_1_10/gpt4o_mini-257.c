//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char filename[100];
    long size;
    int word_count;
    int line_count;
} FileMetadata;

void extract_metadata(FILE *file, FileMetadata *metadata) {
    char line[MAX_LINE_LENGTH];
    metadata->line_count = 0;
    metadata->word_count = 0;

    while (fgets(line, sizeof(line), file)) {
        metadata->line_count++;
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            metadata->word_count++;
            token = strtok(NULL, " \t\n");
        }
    }
}

void print_metadata(FileMetadata *metadata, int file_count) {
    printf("%-25s %-10s %-15s %s\n", "Filename", "Size (bytes)", "Line Count", "Word Count");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < file_count; i++) {
        printf("%-25s %-10ld %-15d %d\n", 
               metadata[i].filename, 
               metadata[i].size, 
               metadata[i].line_count, 
               metadata[i].word_count);
    }
}

void process_files(char *filenames[], int file_count) {
    FileMetadata metadata[MAX_FILES];
    for (int i = 0; i < file_count; i++) {
        FILE *file = fopen(filenames[i], "r");
        if (file == NULL) {
            perror("Failed to open file");
            continue;
        }
        
        fseek(file, 0L, SEEK_END);
        metadata[i].size = ftell(file);
        fseek(file, 0L, SEEK_SET);
        
        strncpy(metadata[i].filename, filenames[i], sizeof(metadata[i].filename) - 1);
        metadata[i].filename[sizeof(metadata[i].filename) - 1] = '\0';
        
        extract_metadata(file, &metadata[i]);
        fclose(file);
    }

    print_metadata(metadata, file_count);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [file2] [file3] ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_files(&argv[1], argc - 1);
    return EXIT_SUCCESS;
}