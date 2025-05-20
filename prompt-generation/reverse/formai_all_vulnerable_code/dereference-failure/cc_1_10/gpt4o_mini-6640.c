//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100  // Maximum number of files to process
#define MAX_LINE_LENGTH 256  // Maximum length of a line

typedef struct {
    char filename[50];
    int lineCount;
    int wordCount;
    int charCount;
} FileStats;

void initializeStats(FileStats *fs, const char *filename) {
    strcpy(fs->filename, filename);
    fs->lineCount = 0;
    fs->wordCount = 0;
    fs->charCount = 0;
}

void processFile(const char *filename, FileStats *fs) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        fs->lineCount++;
        fs->charCount += strlen(line);
        
        // Count words in the line
        char *token = strtok(line, " \t\n");
        while (token) {
            fs->wordCount++;
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(file);
}

void displayStats(FileStats *fs, int count) {
    printf("%-20s %-10s %-10s %-10s\n", "Filename", "Lines", "Words", "Chars");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-10d %-10d %-10d\n",
               fs[i].filename,
               fs[i].lineCount,
               fs[i].wordCount,
               fs[i].charCount);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileStats fileStats[MAX_FILES];
    int fileCount = 0;

    for (int i = 1; i < argc && fileCount < MAX_FILES; i++) {
        initializeStats(&fileStats[fileCount], argv[i]);
        processFile(argv[i], &fileStats[fileCount]);
        fileCount++;
    }

    displayStats(fileStats, fileCount);

    return EXIT_SUCCESS;
}