//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define MAX_KEYWORDS 10

typedef struct {
    char keyword[MAX_KEYWORDS][20];
    int count[MAX_KEYWORDS];
} Metadata;

void read_file(char* filename, char* buffer) {
    FILE* file = fopen(filename, "r");
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);
    fread(buffer, size, 1, file);
    fclose(file);
}

void count_keywords(Metadata* metadata, char* buffer) {
    int i, j;
    for (i = 0; i < MAX_KEYWORDS; i++) {
        metadata->count[i] = 0;
    }
    char* token = strtok(buffer, " ");
    while (token!= NULL) {
        for (j = 0; j < MAX_KEYWORDS; j++) {
            if (strcasecmp(token, metadata->keyword[j]) == 0) {
                metadata->count[j]++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
}

void print_metadata(Metadata* metadata) {
    int i;
    for (i = 0; i < MAX_KEYWORDS; i++) {
        if (metadata->count[i] > 0) {
            printf("%s: %d\n", metadata->keyword[i], metadata->count[i]);
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <keyword1> [<keyword2>...]\n", argv[0]);
        return 1;
    }
    char* filename = argv[1];
    char* keywords[MAX_KEYWORDS];
    int num_keywords = 0;
    int i;
    for (i = 2; i < argc; i++) {
        if (num_keywords >= MAX_KEYWORDS) {
            printf("Maximum number of keywords exceeded\n");
            return 1;
        }
        strcpy(keywords[num_keywords], argv[i]);
        num_keywords++;
    }
    Metadata metadata;
    char* buffer = malloc(MAX_FILE_SIZE);
    read_file(filename, buffer);
    count_keywords(&metadata, buffer);
    print_metadata(&metadata);
    free(buffer);
    return 0;
}