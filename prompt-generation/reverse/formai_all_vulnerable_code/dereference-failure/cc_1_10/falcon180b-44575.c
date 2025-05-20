//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 100

// Function to extract metadata from a given file
void extract_metadata(char *filename, int *width, int *height, char *author, char *title) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read in the first line of the file, which should contain the metadata
    char line[MAX_TOKENS];
    if (fgets(line, MAX_TOKENS, file) == NULL) {
        printf("Error reading file.\n");
        fclose(file);
        exit(1);
    }

    // Parse the metadata from the line
    char *token = strtok(line, " ");
    int num_tokens = 0;
    while (token!= NULL && num_tokens < MAX_TOKENS) {
        if (num_tokens == 0) {
            *width = atoi(token);
        } else if (num_tokens == 1) {
            *height = atoi(token);
        } else if (num_tokens == 2) {
            strcpy(author, token);
        } else if (num_tokens == 3) {
            strcpy(title, token);
        }
        num_tokens++;
        token = strtok(NULL, " ");
    }

    // Check if all expected metadata was found
    if (num_tokens < 4) {
        printf("Error: Missing metadata.\n");
        fclose(file);
        exit(1);
    }

    // Print the extracted metadata
    printf("Width: %d\n", *width);
    printf("Height: %d\n", *height);
    printf("Author: %s\n", author);
    printf("Title: %s\n", title);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char filename[MAX_TOKENS];
    strcpy(filename, argv[1]);

    int width, height;
    char author[MAX_TOKENS], title[MAX_TOKENS];

    extract_metadata(filename, &width, &height, author, title);

    printf("Metadata for %s:\n", filename);
    printf("Width: %d\n", width);
    printf("Height: %d\n", height);
    printf("Author: %s\n", author);
    printf("Title: %s\n", title);

    return 0;
}