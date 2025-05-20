//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function declarations
void extractMetadata(const char *filename);
void processLine(const char *line);
int isComment(const char *line);
int isEmptyLine(const char *line);
void recurseLines(FILE *file);

// Metadata struct to hold extracted data
typedef struct Metadata {
    char **comments;
    int commentCount;
} Metadata;

Metadata metadata;

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize metadata
    metadata.comments = NULL;
    metadata.commentCount = 0;

    // Extract metadata from the provided file
    extractMetadata(argv[1]);

    // Print the extracted comments
    if (metadata.commentCount > 0) {
        printf("Extracted Comments:\n");
        for (int i = 0; i < metadata.commentCount; i++) {
            printf("%s\n", metadata.comments[i]);
            free(metadata.comments[i]);  // Free individual comment strings
        }
        free(metadata.comments);  // Free comments array
    } else {
        printf("No comments found in the file.\n");
    }

    return EXIT_SUCCESS;
}

void extractMetadata(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    recurseLines(file);
    fclose(file);
}

void recurseLines(FILE *file) {
    char line[MAX_LINE_LENGTH];
    
    // Read line-by-line
    while (fgets(line, sizeof(line), file)) {
        // Check if the line is empty or a comment before recursive call
        if (isComment(line) && !isEmptyLine(line)) {
            // Store the comment
            metadata.comments = realloc(metadata.comments, sizeof(char*) * (metadata.commentCount + 1));
            metadata.comments[metadata.commentCount] = strdup(line);
            metadata.commentCount++;
        }
        
        // Continue processing recursively by calling processLine
        processLine(line);
    }
}

void processLine(const char *line) {
    // Process non-comment lines if needed, for now it does nothing
    // You can expand this function to extract more metadata or perform other tasks
}

int isComment(const char *line) {
    // Check for single-line comments (//) and multi-line (/* ... */)
    return (strstr(line, "//") != NULL || strstr(line, "/*") != NULL);
}

int isEmptyLine(const char *line) {
    // Check if the line is empty or contains only whitespace
    return line[0] == '\n' || strlen(line) == 0;
}