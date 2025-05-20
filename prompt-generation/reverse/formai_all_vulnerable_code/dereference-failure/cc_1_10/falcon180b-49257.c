//Falcon-180B DATASET v1.0 Category: File handling ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line from a file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (line == NULL) {
        printf("Error: Could not allocate memory for line.\n");
        exit(1);
    }

    char c = fgetc(file);
    int length = 0;

    while (c!= EOF && c!= '\n') {
        line[length] = c;
        length++;
        c = fgetc(file);
    }

    line[length] = '\0';
    return line;
}

// Function to write a line to a file
void write_line(FILE* file, char* line) {
    fputs(line, file);
    fputc('\n', file);
}

// Function to count the number of words in a line
int count_words(char* line) {
    int count = 0;
    char* word = strtok(line, " ");

    while (word!= NULL) {
        count++;
        word = strtok(NULL, " ");
    }

    return count;
}

// Function to print the contents of a file
void print_file(FILE* file) {
    char* line = NULL;

    while ((line = read_line(file))!= NULL) {
        printf("%s", line);
        free(line);
    }
}

int main() {
    FILE* file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    print_file(file);

    fclose(file);

    return 0;
}