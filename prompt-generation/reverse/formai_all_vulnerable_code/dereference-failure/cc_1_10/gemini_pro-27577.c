//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters in a line
#define MAX_LINE_LENGTH 1024

// Define the maximum number of lines in a file
#define MAX_LINES 100

// Read a line from a file
char* read_line(FILE* fp) {
    char* line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        return NULL;
    }
    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        free(line);
        return NULL;
    }
    return line;
}

// Write a line to a file
void write_line(FILE* fp, char* line) {
    fputs(line, fp);
    fputc('\n', fp);
}

// Convert a string to uppercase
void to_uppercase(char* str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

// Convert a string to lowercase
void to_lowercase(char* str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

// Reverse a string
void reverse(char* str) {
    char* end = str + strlen(str) - 1;
    while (str < end) {
        char tmp = *str;
        *str = *end;
        *end = tmp;
        str++;
        end--;
    }
}

// Main function
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    // Open the output file
    FILE* fp_out = fopen("out.txt", "w");
    if (fp_out == NULL) {
        printf("Error opening file out.txt\n");
        fclose(fp);
        return 1;
    }

    // Process the file
    char* line;
    int line_count = 0;
    while ((line = read_line(fp)) != NULL) {
        // Convert the line to uppercase
        to_uppercase(line);

        // Reverse the line
        reverse(line);

        // Write the line to the output file
        write_line(fp_out, line);

        // Keep track of the number of lines
        line_count++;

        // Free the line
        free(line);
    }

    // Close the input and output files
    fclose(fp);
    fclose(fp_out);

    // Print the number of lines processed
    printf("%d lines processed.\n", line_count);

    return 0;
}