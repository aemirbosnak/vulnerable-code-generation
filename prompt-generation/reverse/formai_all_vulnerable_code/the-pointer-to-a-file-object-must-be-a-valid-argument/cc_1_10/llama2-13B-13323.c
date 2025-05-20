//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 32

// Function to count the number of words in a string
int count_words(const char *str) {
    int word_count = 0;
    char *token;

    while ((token = strtok(str, " \t")) != NULL) {
        word_count++;
    }

    return word_count;
}

// Function to print the first line of a file
void print_first_line(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];

    if (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s\n", line);
    }

    fclose(file);
}

// Function to print the last line of a file
void print_last_line(const char *filename) {
    FILE *file = fopen(filename, "r");
    char line[MAX_LINE_LENGTH];

    if (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s\n", line);
    }

    fseek(file, -1, SEEK_END);
    char last_line[MAX_LINE_LENGTH];

    if (fgets(last_line, MAX_LINE_LENGTH, file) != NULL) {
        printf("%s\n", last_line);
    }

    fclose(file);
}

int main(void) {
    // Print the first line of a file
    print_first_line("example.txt");

    // Print the last line of a file
    print_last_line("example.txt");

    // Count the number of words in a string
    char str[] = "This is a sample string with multiple words.";
    int word_count = count_words(str);

    printf("Number of words: %d\n", word_count);

    return 0;
}