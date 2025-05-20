//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to extract metadata from a file
void extract_metadata(FILE *file, char *filename) {
    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    // Read each line of the file
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        line_number++;

        // Look for metadata
        if (strstr(line, "Author:")!= NULL) {
            char *author = strtok(line, " :");
            printf("Author: %s\n", author);
        } else if (strstr(line, "Title:")!= NULL) {
            char *title = strtok(line, " :");
            printf("Title: %s\n", title);
        } else if (strstr(line, "Date:")!= NULL) {
            char *date = strtok(line, " :");
            printf("Date: %s\n", date);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    char filename[MAX_LINE_LENGTH];
    strcpy(filename, argv[1]);

    // Extract metadata from the file
    extract_metadata(file, filename);

    // Close the file
    fclose(file);

    return 0;
}