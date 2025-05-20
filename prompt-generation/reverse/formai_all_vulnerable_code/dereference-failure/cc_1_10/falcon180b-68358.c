//Falcon-180B DATASET v1.0 Category: Error handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to print error message and exit program
void error(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(1);
}

// Function to read a line from the file
char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, fp)) == -1) {
        if (errno == EINVAL) {
            error("Line too long");
        } else {
            error("Error reading file");
        }
    }

    if (line[read - 1] == '\n') {
        line[--read] = '\0';
    }

    return line;
}

// Function to count the number of words in a line
int count_words(char *line) {
    int count = 0;
    char *word;

    while ((word = strtok(line, " "))!= NULL) {
        count++;
    }

    return count;
}

// Function to calculate the average word length in a line
double avg_word_length(char *line) {
    int count = 0;
    char *word;
    int len = 0;

    while ((word = strtok(line, " "))!= NULL) {
        len += strlen(word);
        count++;
    }

    return (double) len / count;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *line;
    int line_count = 0;
    int total_words = 0;
    double avg_word_len = 0.0;

    if (argc!= 2) {
        error("Usage:./program <filename>");
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        error("Error opening file");
    }

    while ((line = read_line(fp))!= NULL) {
        line_count++;
        total_words += count_words(line);
        avg_word_len += avg_word_length(line);
        free(line);
    }

    printf("Total lines: %d\n", line_count);
    printf("Total words: %d\n", total_words);
    printf("Average word length: %.2f\n", avg_word_len / line_count);

    fclose(fp);
    return 0;
}