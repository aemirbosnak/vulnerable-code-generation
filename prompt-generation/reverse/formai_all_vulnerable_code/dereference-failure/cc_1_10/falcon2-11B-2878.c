//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a line from the file
int read_line(FILE* file) {
    int ch;
    ch = fgetc(file);
    while (ch!= EOF && ch!= '\n') {
        ch = fgetc(file);
    }
    if (ch == EOF) {
        return -1;
    } else {
        return ch;
    }
}

// Function to write a line to the file
void write_line(FILE* file, char* line) {
    fputc('\n', file);
    fputs(line, file);
}

// Function to copy lines from one file to another
void copy_lines(FILE* source, FILE* destination) {
    char line[1000];
    while (fgets(line, sizeof(line), source)!= NULL) {
        if (feof(source)) {
            break;
        }
        write_line(destination, line);
    }
}

int main() {
    FILE* source = fopen("input.txt", "r");
    FILE* destination = fopen("output.txt", "w");

    if (source == NULL || destination == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    copy_lines(source, destination);

    fclose(source);
    fclose(destination);

    return 0;
}