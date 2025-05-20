//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_LINES 10000
#define MAX_WORD_LENGTH 100

// Function to split a line into words
void split_line(char* line, char* words[MAX_WORD_LENGTH]) {
    int num_words = 0;
    char* word = strtok(line, " ");
    while (word!= NULL && num_words < MAX_WORD_LENGTH) {
        strcpy(words[num_words], word);
        word = strtok(NULL, " ");
        num_words++;
    }
}

// Function to search for a word in a file
int search_file(FILE* file, char* word) {
    char line[MAX_LINE_LENGTH];
    char* words[MAX_WORD_LENGTH];
    int line_num = 1;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        split_line(line, words);
        for (int i = 0; i < MAX_WORD_LENGTH; i++) {
            if (strcmp(words[i], word) == 0) {
                printf("Line %d: %s\n", line_num, line);
                return 1;
            }
        }
        line_num++;
    }
    return 0;
}

// Function to read a file into memory
void read_file(char* filename, char* buffer) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);
    fread(buffer, 1, file_size, file);
    fclose(file);
}

// Main function
int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <word>\n", argv[0]);
        exit(1);
    }
    char* filename = argv[1];
    char* word = argv[2];
    char buffer[MAX_LINES];
    read_file(filename, buffer);
    search_file(fopen(filename, "r"), word);
    return 0;
}