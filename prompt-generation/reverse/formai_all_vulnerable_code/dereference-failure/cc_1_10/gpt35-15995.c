//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct MetaData {
    char title[50];
    char author[50];
    char date[20];
} MetaData;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    char filename[MAX_FILE_SIZE];
    strcpy(filename, argv[1]);

    if (strcmp(filename + strlen(filename) - 4, ".txt") != 0) {
        printf("Invalid file type. Must be .txt file.\n");
        return 1;
    }

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Could not open file '%s'\n", filename);
        return 1;
    }

    MetaData metadata;
    char line[MAX_FILE_SIZE];
    while (fgets(line, MAX_FILE_SIZE, fp)) {
        if (strstr(line, "Title:") != NULL) {
            sscanf(line, "Title: %[^\n]", metadata.title);
        } else if (strstr(line, "Author:") != NULL) {
            sscanf(line, "Author: %[^\n]", metadata.author);
        } else if (strstr(line, "Date:") != NULL) {
            sscanf(line, "Date: %[^\n]", metadata.date);
        }
    }

    printf("Title: %s\n", metadata.title);
    printf("Author: %s\n", metadata.author);
    printf("Date: %s\n", metadata.date);

    fclose(fp);

    return 0;
}