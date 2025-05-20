//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILENAME_LENGTH 256
#define MAX_WORD_LENGTH 64

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char metadata[MAX_LINE_LENGTH];
} Metadata;

char *strip_whitespace(char *str) {
    char *end;
    end = str + strlen(str) - 1;
    while (isspace(*end) && end > str) {
        *end = '\0';
        end--;
    }
    return str;
}

int main(int argc, char **argv) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char filename[MAX_FILENAME_LENGTH];
    char word[MAX_WORD_LENGTH];
    Metadata metadata;

    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token;
        char *metadata_str = strtok(line, ":");
        if (metadata_str == NULL) {
            continue;
        }
        strcpy(metadata.filename, filename);
        metadata.metadata[0] = '\0';
        token = strtok(NULL, ":");
        while (token!= NULL) {
            if (strlen(metadata.metadata) + strlen(token) + 1 >= MAX_LINE_LENGTH) {
                break;
            }
            strcat(metadata.metadata, token);
            strcat(metadata.metadata, " ");
            token = strtok(NULL, ":");
        }
        printf("%s\n", metadata.metadata);
    }

    fclose(file);
    return 0;
}