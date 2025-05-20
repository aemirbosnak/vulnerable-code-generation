//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

/* Function to extract metadata from a file */
void extract_metadata(FILE *file, char *filename) {
    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    char *author = NULL;
    char *title = NULL;
    char *date = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_number++;

        /* Check for author */
        if (strstr(line, "Author:")!= NULL) {
            author = strtok(line, " ");
        }

        /* Check for title */
        if (strstr(line, "Title:")!= NULL) {
            title = strtok(line, " ");
        }

        /* Check for date */
        if (strstr(line, "Date:")!= NULL) {
            date = strtok(line, " ");
        }
    }

    printf("File: %s\n", filename);
    printf("Author: %s\n", author);
    printf("Title: %s\n", title);
    printf("Date: %s\n", date);
}

/* Function to get file extension */
char *get_file_extension(char *filename) {
    char *extension = strrchr(filename, '.');

    if (extension == NULL) {
        return "unknown";
    }

    return extension;
}

/* Main function */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *extension = get_file_extension(filename);

    if (strcmp(extension, ".txt")!= 0 && strcmp(extension, ".md")!= 0) {
        printf("Unsupported file type: %s\n", extension);
        return 1;
    }

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file: %s\n", filename);
        return 1;
    }

    extract_metadata(file, filename);

    fclose(file);

    return 0;
}