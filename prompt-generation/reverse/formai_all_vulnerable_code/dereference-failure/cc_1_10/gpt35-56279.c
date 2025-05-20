//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct metadata {
    char source[50];
    char author[50];
    char creation_date[50];
    char description[100];
    int version;
};

typedef struct metadata Metadata;

Metadata extract_metadata(char* file_path) {
    Metadata data;

    FILE* fp = fopen(file_path, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, ":");
        char* value = strtok(NULL, "\n");

        if (strcmp(token, "Source") == 0) {
            strcpy(data.source, value);
        }
        else if (strcmp(token, "Author") == 0) {
            strcpy(data.author, value);
        }
        else if (strcmp(token, "Creation Date") == 0) {
            strcpy(data.creation_date, value);
        }
        else if (strcmp(token, "Description") == 0) {
            strcpy(data.description, value);
        }
        else if (strcmp(token, "Version") == 0) {
            data.version = atoi(value);
        }
    }

    fclose(fp);

    return data;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    Metadata data = extract_metadata(argv[1]);

    printf("Metadata extracted:\n");
    printf("Source: %s\n", data.source);
    printf("Author: %s\n", data.author);
    printf("Creation date: %s\n", data.creation_date);
    printf("Description: %s\n", data.description);
    printf("Version: %d\n", data.version);

    return 0;
}