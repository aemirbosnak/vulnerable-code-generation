//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

// Function to remove trailing whitespace from a string
void trim(char* str) {
    int len = strlen(str);
    while (isspace(str[len - 1])) {
        str[--len] = '\0';
    }
}

// Function to split a string into words
int split(char* str, char** words) {
    char* word = strtok(str, " \t\n\r\f\v");
    int count = 0;
    while (word!= NULL) {
        words[count++] = word;
        word = strtok(NULL, " \t\n\r\f\v");
    }
    return count;
}

// Function to read a line of text from a file
char* read_line(FILE* file) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        return NULL;
    }
    trim(line);
    return strdup(line);
}

// Function to read a word from a line of text
char* read_word(char* line) {
    char* word = strtok(line, " \t\n\r\f\v");
    if (word == NULL) {
        return NULL;
    }
    trim(word);
    return strdup(word);
}

// Function to print a line of text to the console
void print_line(char* line) {
    printf("%s", line);
}

// Function to print a word to the console
void print_word(char* word) {
    if (word == NULL) {
        printf("<NULL>");
    } else {
        printf("%s", word);
    }
}

// Function to print the contents of an array of words to the console
void print_words(char** words, int count) {
    for (int i = 0; i < count; i++) {
        print_word(words[i]);
        printf(" ");
    }
    printf("\n");
}

int main() {
    // Open the input file
    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read the first line of text from the input file
    char* line = read_line(input_file);
    if (line == NULL) {
        printf("Error: Input file is empty.\n");
        fclose(input_file);
        return 1;
    }

    // Split the first line of text into words
    char** words = malloc(sizeof(char*) * MAX_WORD_LENGTH);
    int count = split(line, words);

    // Print the contents of the first line to the console
    printf("Line 1:\n");
    print_words(words, count);

    // Read the remaining lines of text from the input file
    char* next_line = read_line(input_file);
    while (next_line!= NULL) {
        // Split the next line of text into words
        strcpy(line, next_line);
        count = split(line, words);

        // Print the contents of the next line to the console
        printf("Line %d:\n", count + 1);
        print_words(words, count);

        // Read the next line of text from the input file
        next_line = read_line(input_file);
    }

    // Close the input file
    fclose(input_file);

    return 0;
}