//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold metadata of a C file
typedef struct {
    char filename[100];
    int lines;
    int functions;
    int comments;
    int complexity;
} CFileMetadata;

// Function to calculate the complexity based on number of functions and lines
int calculate_complexity(int functions, int lines) {
    if (lines == 0) return 0;
    return functions * 100 / lines; // A simple complexity metric
}

// Function to analyze a C file
CFileMetadata analyze_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    CFileMetadata metadata = {0};
    strcpy(metadata.filename, filename);

    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return metadata;  // Return empty metadata on failure
    }

    char line[256];
    int in_comment_block = 0;

    while (fgets(line, sizeof(line), file)) {
        metadata.lines++;

        // Count function declarations (naive check)
        if (strstr(line, "void ") || strstr(line, "int ") || strstr(line, "float ") ||
            strstr(line, "double ") || strstr(line, "char ")) {
            metadata.functions++;
        }

        // Count comments
        if (strstr(line, "//")) {
            metadata.comments++;
        }
        if (strstr(line, "/*")) {
            in_comment_block = 1;
            metadata.comments++;
        }
        if (in_comment_block && strstr(line, "*/")) {
            in_comment_block = 0;
        }
        if (in_comment_block) {
            metadata.comments++;
        }
    }
    fclose(file);
    
    metadata.complexity = calculate_complexity(metadata.functions, metadata.lines);
    return metadata;
}

// Function to display the metadata
void display_metadata(const CFileMetadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Total Lines: %d\n", metadata->lines);
    printf("Total Functions: %d\n", metadata->functions);
    printf("Total Comments: %d\n", metadata->comments);
    printf("Complexity Score: %d\n", metadata->complexity);
    printf("-------------------------------\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <c_file1.c> <c_file2.c> ... <c_fileN.c>\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        CFileMetadata metadata = analyze_file(argv[i]);
        if (metadata.lines > 0) { // Only display valid metadata
            display_metadata(&metadata);
        } else {
            fprintf(stderr, "No valid data found in %s\n", argv[i]);
        }
    }
    
    return EXIT_SUCCESS;
}