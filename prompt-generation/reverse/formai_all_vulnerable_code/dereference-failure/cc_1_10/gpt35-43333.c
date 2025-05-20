//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: irregular
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

// Function to check if the given character is a whitespace character
bool is_whitespace(char ch) {
    if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
        return true;
    }
    return false;
}

// Function to retrieve metadata from a given file
char* extract_metadata(char* filename) {
    FILE* fp;
    char line[MAX_STRING_LENGTH];
    char* metadata = (char*) malloc(MAX_STRING_LENGTH * sizeof(char));
    int metadata_length = 0;
    bool metadata_started = false;
    bool metadata_ended = false;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Unable to open file!");
        exit(1);
    }

    while (fgets(line, MAX_STRING_LENGTH, fp) != NULL) {
        int line_length = strlen(line);
        if (!metadata_started) {
            if (line[0] == '/' && line[1] == '*') {
                metadata_started = true;
            }
        } else {
            for (int i = 0; i < line_length; i++) {
                if (line[i] == '*' && line[i+1] == '/') {
                    metadata_ended = true;
                    break;
                }
                if (!is_whitespace(line[i])) {
                    metadata[metadata_length++] = line[i];
                }
            }
        }
        if (metadata_ended) {
            break;
        }
    }

    fclose(fp);

    return metadata;
}

// Main function
int main() {
    char* filename = "example.c";
    char* metadata = extract_metadata(filename);
    printf("Metadata: %s", metadata);
    free(metadata);
    return 0;
}