//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 64

// Function to remove leading and trailing whitespace from a string
void trim(char* str) {
    int i = 0;
    while (isspace(str[i])) {
        i++;
    }
    int j = strlen(str) - 1;
    while (isspace(str[j])) {
        j--;
    }
    str[j] = '\0';
    memmove(str, str + i, j - i + 1);
}

// Function to split a string into key-value pairs
void split_key_value(char* line, char** key, char** value) {
    char* pos = strchr(line, '=');
    if (pos == NULL) {
        *key = strdup("");
        *value = strdup("");
    } else {
        *pos = '\0';
        trim(*key = strdup(line));
        trim(*value = strdup(pos + 1));
    }
}

// Function to extract metadata from a file
void extract_metadata(FILE* fp, char* filename) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char* key = NULL;
        char* value = NULL;
        split_key_value(line, &key, &value);
        printf("%s: %s\n", key, value);
    }
}

// Main function
int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }
    char* filename = strdup(argv[1]);
    extract_metadata(fp, filename);
    fclose(fp);
    free(filename);
    return 0;
}