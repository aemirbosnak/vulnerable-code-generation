//Falcon-180B DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024

/**
 * This function reads a line from a file and stores it in a buffer.
 * It returns the number of characters read or -1 if an error occurs.
 *
 * @param file The file to read from.
 * @param buffer The buffer to store the line in.
 * @param size The size of the buffer.
 * @return The number of characters read or -1 if an error occurs.
 */
int read_line(FILE *file, char *buffer, int size) {
    int count = 0;
    int c;

    while ((c = fgetc(file))!= EOF) {
        if (count >= size - 1) {
            fprintf(stderr, "Error: Line too long.\n");
            return -1;
        }
        buffer[count++] = c;
    }

    if (ferror(file)) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return -1;
    }

    buffer[count] = '\0';
    return count;
}

/**
 * This function reads a file and counts the number of lines, words, and characters.
 * It returns 0 if the file could not be opened or -1 if an error occurs.
 *
 * @param filename The name of the file to read.
 * @param line_count The number of lines in the file.
 * @param word_count The number of words in the file.
 * @param char_count The number of characters in the file.
 * @return 0 if the file could not be opened or -1 if an error occurs.
 */
int count_file(const char *filename, int *line_count, int *word_count, int *char_count) {
    FILE *file;
    char buffer[MAX_LINE_SIZE];
    int count = 0;
    int line_count_local = 0;
    int word_count_local = 0;
    int char_count_local = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", filename);
        return -1;
    }

    while (read_line(file, buffer, MAX_LINE_SIZE)!= -1) {
        count++;
        line_count_local++;
        char_count_local += strlen(buffer);

        char *word = strtok(buffer, " ");
        while (word!= NULL) {
            word_count_local++;
            word = strtok(NULL, " ");
        }
    }

    *line_count = line_count_local;
    *word_count = word_count_local;
    *char_count = char_count_local;

    fclose(file);
    return count;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    int line_count = 0;
    int word_count = 0;
    int char_count = 0;

    int count = count_file(argv[1], &line_count, &word_count, &char_count);
    if (count == -1) {
        return 1;
    }

    printf("File '%s' contains:\n", argv[1]);
    printf("  %d lines\n", line_count);
    printf("  %d words\n", word_count);
    printf("  %d characters\n", char_count);

    return 0;
}