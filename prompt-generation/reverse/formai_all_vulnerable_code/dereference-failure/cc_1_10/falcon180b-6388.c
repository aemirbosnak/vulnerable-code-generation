//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 10

typedef struct {
    char *name;
    char *value;
} Metadata;

typedef struct {
    char *keyword;
    int index;
} Keyword;

Metadata *metadata = NULL;
Keyword *keywords[MAX_KEYWORDS];
int num_keywords = 0;

void init() {
    metadata = malloc(sizeof(Metadata));
    if (metadata == NULL) {
        printf("Error: Failed to allocate memory for metadata.\n");
        exit(1);
    }
    memset(metadata, 0, sizeof(Metadata));

    num_keywords = 0;
}

void add_metadata(const char *name, const char *value) {
    if (num_keywords >= MAX_KEYWORDS) {
        printf("Error: Too many metadata keywords.\n");
        exit(1);
    }

    Metadata *m = metadata;
    while (m->name!= NULL) {
        if (strcmp(m->name, name) == 0) {
            printf("Warning: Duplicate metadata name: %s\n", name);
            return;
        }
        m++;
    }

    m->name = strdup(name);
    m->value = strdup(value);

    num_keywords++;
}

void add_keyword(const char *keyword) {
    if (num_keywords >= MAX_KEYWORDS) {
        printf("Error: Too many metadata keywords.\n");
        exit(1);
    }

    Keyword *k = keywords[num_keywords];
    strncpy(k->keyword, keyword, MAX_LINE_LENGTH - 1);
    k->keyword[MAX_LINE_LENGTH - 1] = '\0';
    k->index = num_keywords;

    num_keywords++;
}

void print_metadata() {
    Metadata *m = metadata;
    while (m->name!= NULL) {
        printf("%s: %s\n", m->name, m->value);
        m++;
    }
}

void print_keywords() {
    printf("Keywords:\n");
    for (int i = 0; i < num_keywords; i++) {
        printf("%d. %s\n", i + 1, keywords[i]->keyword);
    }
}

int main() {
    init();

    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (strncmp(token, "title:", 6) == 0) {
                add_metadata("title", token + 6);
            } else if (strncmp(token, "author:", 7) == 0) {
                add_metadata("author", token + 7);
            } else if (strncmp(token, "date:", 5) == 0) {
                add_metadata("date", token + 5);
            } else if (strncmp(token, "keyword:", 8) == 0) {
                add_keyword(token + 8);
            }
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    print_metadata();
    print_keywords();

    return 0;
}