//Falcon-180B DATASET v1.0 Category: Error handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_FILE_SIZE 1000000 // 1 MB
#define MAX_LINE_SIZE 1000 // 1 KB

int main(int argc, char *argv[]) {
    FILE *file;
    char *filename = argv[1];
    char *buffer = malloc(MAX_FILE_SIZE);
    char line[MAX_LINE_SIZE];
    int line_count = 0;
    int total_words = 0;
    int total_chars = 0;
    int longest_line = 0;
    int longest_word = 0;
    int shortest_line = MAX_LINE_SIZE;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if ((file = fopen(filename, "r")) == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        line_count++;
        total_words += count_words(line);
        total_chars += strlen(line);

        if (strlen(line) > longest_line) {
            longest_line = strlen(line);
        }

        if (strlen(line) < shortest_line) {
            shortest_line = strlen(line);
        }

        if (count_words(line) > longest_word) {
            longest_word = count_words(line);
        }
    }

    printf("File: %s\n", filename);
    printf("Total lines: %d\n", line_count);
    printf("Total words: %d\n", total_words);
    printf("Total characters: %d\n", total_chars);
    printf("Longest line: %d\n", longest_line);
    printf("Shortest line: %d\n", shortest_line);
    printf("Longest word: %d\n", longest_word);

    fclose(file);
    free(buffer);
    return 0;
}

int count_words(char *line) {
    int count = 0;
    char *token = strtok(line, " ");

    while (token!= NULL) {
        count++;
        token = strtok(NULL, " ");
    }

    return count;
}