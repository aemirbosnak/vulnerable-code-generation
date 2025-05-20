//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

// Function to count the number of words in a line of text
int count_words(char *line) {
    int count = 0;
    char *word = strtok(line, " \t\n\r\f\v");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " \t\n\r\f\v");
    }
    return count;
}

// Function to read a file and count the number of words in it
int count_file_words(FILE *file) {
    char line[MAX_LINE_LENGTH];
    int count = 0;
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        count += count_words(line);
    }
    return count;
}

// Function to print the word count for a file
void print_file_word_count(char *filename, int count) {
    printf("The file '%s' contains %d words.\n", filename, count);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    char filename[MAX_FILE_NAME_LENGTH];
    strcpy(filename, argv[1]);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", filename);
        exit(1);
    }

    int count = count_file_words(file);
    fclose(file);

    print_file_word_count(filename, count);

    return 0;
}