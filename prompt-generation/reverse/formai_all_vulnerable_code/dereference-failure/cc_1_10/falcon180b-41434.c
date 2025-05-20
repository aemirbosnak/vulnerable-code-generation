//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/* Function to handle errors */
void error(const char *msg) {
    fprintf(stderr, "ERROR: %s\n", msg);
    exit(1);
}

/* Function to read a line from a file */
char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if (fp == NULL) {
        error("Invalid file pointer");
    }

    line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        error("Could not allocate memory");
    }

    do {
        read = getline(&line, &len, fp);
        if (read == -1) {
            if (ferror(fp)) {
                error("Error reading file");
            } else {
                error("Unexpected end of file");
            }
        }
    } while (read == -1);

    return line;
}

/* Function to count the number of words in a line */
int count_words(const char *line) {
    int count = 0;
    char *word;

    word = strtok(line, " ");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char *line;
    int word_count;

    if (argc!= 2) {
        error("Usage:./program <filename>");
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        error("Could not open file");
    }

    line = read_line(fp);
    word_count = count_words(line);

    printf("Line: %s\n", line);
    printf("Number of words: %d\n", word_count);

    free(line);
    fclose(fp);

    return 0;
}