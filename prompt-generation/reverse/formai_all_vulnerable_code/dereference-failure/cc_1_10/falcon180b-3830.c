//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 64

// Function to trim leading and trailing whitespace from a string
char* trim(char* str) {
    int start = 0;
    int end = strlen(str) - 1;

    while(isspace(str[start])) {
        start++;
    }

    while(isspace(str[end])) {
        end--;
    }

    str[end+1] = '\0';

    return str;
}

// Function to split a string into an array of tokens
int split(char* str, char* tokens[], int max_tokens) {
    int num_tokens = 0;
    char* token;
    char* context = str;

    while(*context!= '\0') {
        if(isspace(*context)) {
            *context = '\0';
            token = trim(context);

            if(num_tokens >= max_tokens) {
                break;
            }

            strcpy(tokens[num_tokens++], token);

            context += strlen(token) + 1;
        } else {
            context++;
        }
    }

    return num_tokens;
}

// Function to extract metadata from a line of text
int extract_metadata(char* line, char* filename, char* author, char* date) {
    char* tokens[MAX_TOKENS];
    int num_tokens;

    // Split the line into tokens
    num_tokens = split(line, tokens, MAX_TOKENS);

    // Check if the line contains metadata
    if(num_tokens >= 3 && strcmp(tokens[0], "Author:") == 0 && strcmp(tokens[1], "Filename:") == 0) {
        strcpy(author, tokens[2]);
        strcpy(filename, tokens[3]);
        strcpy(date, "N/A");
        return 1;
    }

    return 0;
}

// Function to open and read a text file
int read_file(FILE* fp, char* filename, char* author, char* date) {
    char line[MAX_LINE_LENGTH];
    int line_num = 0;
    int found_metadata = 0;

    while(fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        line_num++;

        // Check if the line contains metadata
        if(extract_metadata(line, filename, author, date) == 1) {
            found_metadata = 1;
            break;
        }
    }

    if(found_metadata == 0) {
        fprintf(stderr, "Error: Metadata not found in file '%s'.\n", filename);
        return 0;
    }

    return 1;
}

int main(int argc, char* argv[]) {
    FILE* fp;
    char filename[MAX_LINE_LENGTH];
    char author[MAX_LINE_LENGTH];
    char date[MAX_LINE_LENGTH];
    int found_metadata = 0;

    if(argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);

    // Open the file for reading
    fp = fopen(filename, "r");

    if(fp == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", filename);
        return 1;
    }

    // Read the file and extract metadata
    if(read_file(fp, filename, author, date) == 0) {
        return 1;
    }

    printf("Author: %s\n", author);
    printf("Filename: %s\n", filename);
    printf("Date: %s\n", date);

    fclose(fp);
    return 0;
}