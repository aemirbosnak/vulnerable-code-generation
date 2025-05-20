//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = (char*) malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error reading line from file.\n");
        exit(1);
    }
    return line;
}

// Function to split a line into words
char** split_line(char* line) {
    int num_words = 0;
    char** words = (char**) malloc(MAX_LINE_LENGTH * sizeof(char*));
    char* word = strtok(line, " ");
    while (word!= NULL) {
        words[num_words] = word;
        num_words++;
        word = strtok(NULL, " ");
    }
    return words;
}

// Function to print the words in a line
void print_words(char** words) {
    for (int i = 0; words[i]!= NULL; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");
}

// Function to read and print the contents of a file
void read_file(FILE* file) {
    char* line = read_line(file);
    while (line!= NULL) {
        char** words = split_line(line);
        print_words(words);
        free(line);
        line = read_line(file);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    read_file(file);
    fclose(file);
    return 0;
}