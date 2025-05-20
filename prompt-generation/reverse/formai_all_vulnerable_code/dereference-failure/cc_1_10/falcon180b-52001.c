//Falcon-180B DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH);
    char c = fgetc(file);
    int length = 0;

    while (c!= EOF && c!= '\n' && length < MAX_LINE_LENGTH) {
        line[length] = c;
        c = fgetc(file);
        length++;
    }

    if (c == EOF) {
        line[length - 1] = '\0';
    } else {
        line[length] = '\0';
    }

    return line;
}

// Function to write a line to the file
void write_line(FILE* file, char* line) {
    fprintf(file, "%s", line);
}

// Function to reverse the lines in the file
void reverse_lines(FILE* file) {
    char* line = read_line(file);
    while (line!= NULL) {
        char* reversed_line = malloc(MAX_LINE_LENGTH);
        int length = strlen(line);
        int i;

        for (i = 0; i < length / 2; i++) {
            char temp = line[i];
            line[i] = line[length - i - 1];
            line[length - i - 1] = temp;
        }

        write_line(file, reversed_line);
        free(reversed_line);

        line = read_line(file);
    }
}

int main() {
    FILE* file = fopen("input.txt", "r+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    reverse_lines(file);
    fclose(file);

    return 0;
}