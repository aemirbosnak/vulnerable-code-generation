//Falcon-180B DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Function to print the error message and exit the program
void error(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Function to open a file and return the file pointer
FILE* open_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        error("Failed to open file");
    }
    return fp;
}

// Function to read a line from a file and return the string
char* read_line(FILE* fp) {
    char* line = NULL;
    size_t size = 0;
    ssize_t read;
    if ((read = getline(&line, &size, fp)) == -1) {
        error("Failed to read line");
    }
    return line;
}

// Function to parse a line of text and return the integer value
int parse_int(const char* line) {
    int value = 0;
    if (sscanf(line, "%d", &value)!= 1) {
        error("Invalid integer value");
    }
    return value;
}

// Function to calculate the sum of the integers in the file
int sum_file(const char* filename) {
    FILE* fp = open_file(filename);
    char* line = read_line(fp);
    int sum = 0;
    while (line!= NULL) {
        int value = parse_int(line);
        if (value == 0) {
            error("Zero value not allowed");
        }
        sum += value;
        line = read_line(fp);
    }
    fclose(fp);
    return sum;
}

// Function to call the sum_file function recursively
int sum_file_recursive(const char* filename) {
    int sum = sum_file(filename);
    if (sum == 0) {
        error("File contains no valid integers");
    }
    return sum;
}

// Main function to call the sum_file_recursive function
int main(int argc, char** argv) {
    if (argc!= 2) {
        error("Usage:./program filename");
    }
    int sum = sum_file_recursive(argv[1]);
    printf("Sum of integers in file: %d\n", sum);
    return 0;
}