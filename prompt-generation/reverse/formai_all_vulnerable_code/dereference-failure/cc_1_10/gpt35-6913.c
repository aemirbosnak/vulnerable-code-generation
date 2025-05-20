//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct metadata {
    char artist[MAX_LEN];
    char title[MAX_LEN];
    char album[MAX_LEN];
    char year[MAX_LEN];
} Metadata;

Metadata extract_metadata(char *file_name) {
    Metadata metadata;
    FILE *fp;
    char line[MAX_LEN];
    char *token;

    fp = fopen(file_name, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, ":");

        if (strcmp(token, "ARTIST") == 0) {
            token = strtok(NULL, "\n");
            strcpy(metadata.artist, token);
        }
        else if (strcmp(token, "TITLE") == 0) {
            token = strtok(NULL, "\n");
            strcpy(metadata.title, token);
        }
        else if (strcmp(token, "ALBUM") == 0) {
            token = strtok(NULL, "\n");
            strcpy(metadata.album, token);
        }
        else if (strcmp(token, "YEAR") == 0) {
            token = strtok(NULL, "\n");
            strcpy(metadata.year, token);
        }
    }

    fclose(fp);

    return metadata;
}

int main() {
    char file_name[MAX_LEN];
    Metadata metadata;

    printf("Enter file name: ");
    fgets(file_name, sizeof(file_name), stdin);
    file_name[strcspn(file_name, "\n")] = 0;

    metadata = extract_metadata(file_name);

    printf("Artist: %s\n", metadata.artist);
    printf("Title: %s\n", metadata.title);
    printf("Album: %s\n", metadata.album);
    printf("Year: %s\n", metadata.year);

    return 0;
}