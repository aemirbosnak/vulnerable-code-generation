//Falcon-180B DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

// Function to read a line from the file
char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_SIZE);
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (i == MAX_LINE_SIZE - 1) {
            printf("Error: Line too long\n");
            exit(1);
        }
        line[i++] = ch;
    }
    line[i] = '\0';
    return line;
}

// Function to write a line to the file
void write_line(FILE* file, char* line) {
    fprintf(file, "%s", line);
}

// Function to read a file and print its contents
void print_file(FILE* file) {
    char* line;
    while ((line = read_line(file))!= NULL) {
        printf("%s", line);
    }
}

// Function to write a string to a file
void write_string(FILE* file, char* string) {
    fprintf(file, "%s", string);
}

// Function to read a string from a file
char* read_string(FILE* file) {
    char* string = malloc(MAX_LINE_SIZE);
    char ch;
    int i = 0;
    while ((ch = fgetc(file))!= EOF) {
        if (i == MAX_LINE_SIZE - 1) {
            printf("Error: String too long\n");
            exit(1);
        }
        string[i++] = ch;
    }
    string[i] = '\0';
    return string;
}

// Function to read and write a file
void file_io() {
    FILE* file = fopen("file.txt", "r+");
    if (file == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    char* line;
    while ((line = read_line(file))!= NULL) {
        printf("%s", line);
    }
    char* string = read_string(file);
    printf("%s", string);
    write_string(file, "Hello, world!");
    fseek(file, 0, SEEK_SET);
    print_file(file);
    fclose(file);
}

int main() {
    file_io();
    return 0;
}