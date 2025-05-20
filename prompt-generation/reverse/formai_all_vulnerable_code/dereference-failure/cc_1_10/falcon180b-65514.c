//Falcon-180B DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_SIZE);
    char ch = fgetc(file);
    int index = 0;

    while (ch!= EOF && ch!= '\n') {
        line[index++] = ch;
        ch = fgetc(file);
    }

    line[index] = '\0';

    return line;
}

// Function to write a line to the file
void write_line(FILE* file, char* line) {
    fprintf(file, "%s", line);
}

// Function to read a file and print its contents
void read_file(FILE* file) {
    char* line = read_line(file);

    while (line!= NULL) {
        printf("%s", line);
        line = read_line(file);
    }
}

// Function to write to a file
void write_to_file(FILE* file) {
    char input[MAX_LINE_SIZE];

    printf("Enter text to write to file: ");
    fgets(input, MAX_LINE_SIZE, stdin);

    write_line(file, input);
}

int main() {
    FILE* file;
    char filename[MAX_LINE_SIZE];

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file for reading and writing
    file = fopen(filename, "r+");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read contents of file
    printf("Contents of file:\n");
    read_file(file);

    // Write to file
    write_to_file(file);

    // Close file
    fclose(file);

    return 0;
}