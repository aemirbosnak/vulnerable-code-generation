//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_NUM_LINES 1000

// Function to read the log file and store the lines in an array
void read_log_file(char *filename, char lines[MAX_NUM_LINES][MAX_LINE_LENGTH]) {
    FILE *fp;
    int line_num = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fgets(lines[line_num], MAX_LINE_LENGTH, fp)!= NULL) {
        line_num++;
        if (line_num >= MAX_NUM_LINES) {
            printf("Error: too many lines in log file.\n");
            exit(1);
        }
    }

    fclose(fp);
}

// Function to count the number of occurrences of a word in a line
int count_word_occurrences(char line[], char word[]) {
    int count = 0;
    char *pos = strtok(line, " ");

    while (pos!= NULL) {
        if (strcmp(pos, word) == 0) {
            count++;
        }
        pos = strtok(NULL, " ");
    }

    return count;
}

// Function to print the number of occurrences of a word in each line
void print_word_occurrences(char lines[MAX_NUM_LINES][MAX_LINE_LENGTH], char word[]) {
    int i, j, count;

    for (i = 0; i < MAX_NUM_LINES; i++) {
        count = count_word_occurrences(lines[i], word);
        printf("Line %d: %d occurrences of '%s'\n", i + 1, count, word);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s log_file word\n", argv[0]);
        exit(1);
    }

    char lines[MAX_NUM_LINES][MAX_LINE_LENGTH];
    char word[MAX_LINE_LENGTH];

    strcpy(word, argv[2]);

    read_log_file(argv[1], lines);
    print_word_occurrences(lines, word);

    return 0;
}