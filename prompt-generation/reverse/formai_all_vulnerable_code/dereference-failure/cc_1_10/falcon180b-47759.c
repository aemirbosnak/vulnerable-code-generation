//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

// Function to split a line into tokens
void split_line(char *line, char **tokens) {
    int num_tokens = 0;
    char *token = strtok(line, " \t\r\n");

    while (token!= NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " \t\r\n");
    }
}

// Function to extract metadata from a file
void extract_metadata(FILE *file, char *title, char *author, char *date) {
    char line[MAX_LINE_LENGTH];
    char *tokens[MAX_TOKENS];

    // Read the first line, which should contain the title
    fgets(line, MAX_LINE_LENGTH, file);
    split_line(line, tokens);
    strcpy(title, tokens[0]);

    // Read the second line, which should contain the author
    fgets(line, MAX_LINE_LENGTH, file);
    split_line(line, tokens);
    strcpy(author, tokens[0]);

    // Read the third line, which should contain the date
    fgets(line, MAX_LINE_LENGTH, file);
    split_line(line, tokens);
    strcpy(date, tokens[0]);
}

int main() {
    FILE *file;
    char title[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    char date[MAX_LINE_LENGTH];

    // Open the file
    file = fopen("metadata.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Extract the metadata
    extract_metadata(file, title, author, date);

    // Print the metadata
    printf("Title: %s\n", title);
    printf("Author: %s\n", author);
    printf("Date: %s\n", date);

    // Close the file
    fclose(file);

    return 0;
}