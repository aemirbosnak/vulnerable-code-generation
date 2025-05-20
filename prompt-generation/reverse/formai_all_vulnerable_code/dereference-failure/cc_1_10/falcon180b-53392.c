//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 64
#define MAX_VALUE_SIZE 256

typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} metadata_t;

void trim(char* str) {
    int i, j;
    for (i = strlen(str) - 1; i >= 0; i--) {
        if (isspace(str[i])) {
            str[i] = '\0';
        } else {
            break;
        }
    }
    for (j = 0; j < strlen(str); j++) {
        if (!isspace(str[j])) {
            strcpy(str, &str[j]);
            break;
        }
    }
}

void parse_metadata(char* line, metadata_t* meta) {
    char* token;
    token = strtok(line, ":");
    trim(token);
    strcpy(meta->key, token);

    token = strtok(NULL, ":");
    trim(token);
    strcpy(meta->value, token);
}

int main() {
    FILE* fp;
    char line[MAX_LINE_SIZE];
    metadata_t meta;

    fp = fopen("metadata.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open metadata file.\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        parse_metadata(line, &meta);
        printf("Key: %s\nValue: %s\n\n", meta.key, meta.value);
    }

    fclose(fp);
    return 0;
}