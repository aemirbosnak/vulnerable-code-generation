//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define MAX_LINE_SIZE 1000

typedef struct {
    char *filename;
    char *author;
    char *title;
    char *subject;
    int year;
} Metadata;

Metadata *extract_metadata(FILE *file) {
    Metadata *metadata = malloc(sizeof(Metadata));
    char line[MAX_LINE_SIZE];
    char *token;

    // Extract filename
    rewind(file);
    fgets(line, MAX_LINE_SIZE, file);
    metadata->filename = strtok(line, " ");

    // Extract author
    fgets(line, MAX_LINE_SIZE, file);
    token = strtok(line, " ");
    while (token!= NULL) {
        if (strcmp(token, "Author") == 0) {
            metadata->author = strtok(NULL, " ");
            break;
        }
        token = strtok(NULL, " ");
    }

    // Extract title
    fgets(line, MAX_LINE_SIZE, file);
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (strcmp(line, "Title:") == 0) {
            metadata->title = strtok(line, " ");
            break;
        }
    }

    // Extract subject
    fgets(line, MAX_LINE_SIZE, file);
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (strcmp(line, "Subject:") == 0) {
            metadata->subject = strtok(line, " ");
            break;
        }
    }

    // Extract year
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (strcmp(line, "Year:") == 0) {
            metadata->year = atoi(strtok(line, " "));
            break;
        }
    }

    return metadata;
}

void print_metadata(Metadata *metadata) {
    printf("Filename: %s\n", metadata->filename);
    printf("Author: %s\n", metadata->author);
    printf("Title: %s\n", metadata->title);
    printf("Subject: %s\n", metadata->subject);
    printf("Year: %d\n", metadata->year);
}

int main() {
    FILE *file;
    Metadata *metadata;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    metadata = extract_metadata(file);
    print_metadata(metadata);

    free(metadata);
    fclose(file);

    return 0;
}