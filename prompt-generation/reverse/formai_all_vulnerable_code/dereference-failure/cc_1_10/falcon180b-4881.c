//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FILES 100

typedef struct {
    char filename[MAX_LINE_LENGTH];
    int num_lines;
    int num_words;
    int num_chars;
} FileStats;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage:./program <filename>\n");
        exit(1);
    }

    char filename[MAX_LINE_LENGTH];
    strcpy(filename, argv[1]);

    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    int num_files = 1;
    FileStats files[MAX_NUM_FILES];
    files[0].filename[0] = '\0';
    files[0].num_lines = 0;
    files[0].num_words = 0;
    files[0].num_chars = 0;

    char line[MAX_LINE_LENGTH];
    int num_lines = 0;
    int num_words = 0;
    int num_chars = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        num_lines++;
        num_chars += strlen(line);
        int i = 0;
        while (line[i]!= '\0') {
            if (isalpha(line[i])) {
                num_words++;
            }
            i++;
        }
    }

    files[0].filename[strlen(filename)] = '\0';
    files[0].num_lines = num_lines;
    files[0].num_words = num_words;
    files[0].num_chars = num_chars;

    fclose(fp);

    printf("File: %s\n", filename);
    printf("Number of lines: %d\n", num_lines);
    printf("Number of words: %d\n", num_words);
    printf("Number of characters: %d\n", num_chars);

    return 0;
}