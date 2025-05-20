//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILES 10
#define MAX_FILENAME_LENGTH 256

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int lineCount;
    int wordCount;
    int charCount;
} FileStats;

void initializeStats(FileStats *stats, const char *filename) {
    strncpy(stats->filename, filename, MAX_FILENAME_LENGTH);
    stats->lineCount = 0;
    stats->wordCount = 0;
    stats->charCount = 0;
}

void processFile(const char *filename, FileStats *stats) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char ch;
    int inWord = 0;
    while ((ch = fgetc(file)) != EOF) {
        stats->charCount++;
        if (ch == '\n') {
            stats->lineCount++;
        }

        if (isspace(ch) && inWord) {
            inWord = 0;
            stats->wordCount++;
        } else if (!isspace(ch)) {
            inWord = 1;
        }
    }

    if (inWord) { // If the last character was a part of a word
        stats->wordCount++;
    }

    fclose(file);
}

void printStats(const FileStats *stats) {
    printf("Filename: %s\n", stats->filename);
    printf("Lines: %d\n", stats->lineCount);
    printf("Words: %d\n", stats->wordCount);
    printf("Characters: %d\n", stats->charCount);
    printf("----------------------------------\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ... <fileN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileStats fileStats[MAX_FILES];
    int fileCount = 0;

    for (int i = 1; i < argc && fileCount < MAX_FILES; i++, fileCount++) {
        initializeStats(&fileStats[fileCount], argv[i]);
        processFile(argv[i], &fileStats[fileCount]);
    }

    int totalLines = 0, totalWords = 0, totalChars = 0;

    printf("Word Count Report\n");
    printf("==================\n");

    for (int i = 0; i < fileCount; i++) {
        printStats(&fileStats[i]);
        totalLines += fileStats[i].lineCount;
        totalWords += fileStats[i].wordCount;
        totalChars += fileStats[i].charCount;
    }

    printf("Summary for %d files:\n", fileCount);
    printf("Total Lines: %d\n", totalLines);
    printf("Total Words: %d\n", totalWords);
    printf("Total Characters: %d\n", totalChars);

    return EXIT_SUCCESS;
}