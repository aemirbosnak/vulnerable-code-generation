//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct metadata {
    char* title;
    char* author;
    char* description;
    char* date;
} Metadata;

Metadata* extractMetadata(char* filePath) {
    FILE* file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return NULL;
    }

    Metadata* metadata = malloc(sizeof(Metadata));
    metadata->title = malloc(50 * sizeof(char));
    metadata->author = malloc(50 * sizeof(char));
    metadata->description = malloc(100 * sizeof(char));
    metadata->date = malloc(20 * sizeof(char));

    char line[256];

    while(fgets(line, sizeof(line), file)) {
        if (strstr(line, "Title:") != NULL) {
            sscanf(line, "Title: %s", metadata->title);
        } else if (strstr(line, "Author:") != NULL) {
            sscanf(line, "Author: %s", metadata->author);
        } else if (strstr(line, "Description:") != NULL) {
            sscanf(line, "Description: %s", metadata->description);
        } else if (strstr(line, "Date:") != NULL) {
            sscanf(line, "Date: %s", metadata->date);
        }
    }

    fclose(file);
    return metadata;
}

int main() {
    Metadata* metadata = extractMetadata("book.txt");

    if (metadata != NULL) {
        printf("Title: %s\n", metadata->title);
        printf("Author: %s\n", metadata->author);
        printf("Description: %s\n", metadata->description);
        printf("Date: %s\n", metadata->date);
    } else {
        printf("Metadata extraction failed.\n");
    }

    free(metadata->title);
    free(metadata->author);
    free(metadata->description);
    free(metadata->date);
    free(metadata);
    return 0;
}