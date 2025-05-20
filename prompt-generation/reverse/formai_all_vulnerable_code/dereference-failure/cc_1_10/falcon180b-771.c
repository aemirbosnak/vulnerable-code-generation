//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to extract metadata from a file
void extract_metadata(FILE* file) {
    char line[MAX_LINE_LENGTH];
    char* author = NULL;
    char* title = NULL;
    int year = 0;

    // Read the first line of the file, which should contain the author and title
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error: Failed to read first line of file.\n");
        exit(1);
    }

    // Extract the author and title from the first line
    char* p = strtok(line, " \n");
    if (p == NULL) {
        printf("Error: Invalid first line of file.\n");
        exit(1);
    }
    author = p;

    p = strtok(NULL, " \n");
    if (p == NULL) {
        printf("Error: Invalid first line of file.\n");
        exit(1);
    }
    title = p;

    // Read the second line of the file, which should contain the year
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        printf("Error: Failed to read second line of file.\n");
        exit(1);
    }

    // Extract the year from the second line
    p = strtok(line, " \n");
    if (p == NULL) {
        printf("Error: Invalid second line of file.\n");
        exit(1);
    }
    year = atoi(p);

    printf("Author: %s\n", author);
    printf("Title: %s\n", title);
    printf("Year: %d\n", year);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }

    extract_metadata(file);

    fclose(file);
    return 0;
}