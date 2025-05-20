//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function to extract metadata from a C file
void extract_metadata(FILE *fp, char *filename) {
    char line[MAX_LINE_LENGTH];
    char *key, *value;
    int lineno = 1;

    // Look for #pragma once
    rewind(fp);
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        lineno++;
        if (strstr(line, "#pragma once")) {
            printf("Found #pragma once on line %d\n", lineno);
            break;
        }
    }

    // Look for include guards
    rewind(fp);
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        lineno++;
        if (strstr(line, "#ifndef ")) {
            key = strtok(line, " ");
            value = strtok(NULL, " ");
            printf("Found include guard: %s = %s on line %d\n", key, value, lineno);
        }
    }

    // Look for function definitions
    rewind(fp);
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        lineno++;
        if (strstr(line, "int main")) {
            printf("Found main function on line %d\n", lineno);
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[256];

    // Check if correct number of arguments were provided
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Copy filename argument to local variable
    strcpy(filename, argv[1]);

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return 1;
    }

    // Extract metadata from file
    extract_metadata(fp, filename);

    // Close file
    fclose(fp);

    return 0;
}