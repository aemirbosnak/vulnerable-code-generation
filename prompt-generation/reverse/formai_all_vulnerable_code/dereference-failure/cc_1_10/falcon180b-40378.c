//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 20
#define MAX_KEYWORD_LENGTH 32

typedef struct {
    char name[MAX_KEYWORD_LENGTH];
    int id;
    char *description;
} Keyword;

typedef struct {
    int num_keywords;
    Keyword *keywords;
} KeywordList;

void read_keywords_from_file(const char *filename, KeywordList *keywords) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *keyword = strtok(line, " ");
        if (keyword == NULL) {
            continue;
        }

        char *description = strtok(NULL, " ");
        if (description == NULL) {
            fprintf(stderr, "Error: missing description for keyword %s\n", keyword);
            exit(1);
        }

        int id = strtol(keyword, NULL, 10);
        Keyword *k = malloc(sizeof(Keyword));
        strncpy(k->name, keyword, MAX_KEYWORD_LENGTH);
        k->id = id;
        k->description = strdup(description);

        if (keywords->num_keywords >= MAX_KEYWORDS) {
            fprintf(stderr, "Error: too many keywords\n");
            exit(1);
        }

        keywords->keywords[keywords->num_keywords++] = *k;
    }

    fclose(fp);
}

void print_keywords(const KeywordList *keywords) {
    for (int i = 0; i < keywords->num_keywords; ++i) {
        printf("%d: %s - %s\n", keywords->keywords[i].id, keywords->keywords[i].name, keywords->keywords[i].description);
    }
}

int main() {
    KeywordList keywords;
    keywords.num_keywords = 0;

    read_keywords_from_file("keywords.txt", &keywords);

    print_keywords(&keywords);

    for (int i = 0; i < keywords.num_keywords; ++i) {
        free(keywords.keywords[i].description);
    }
    free(keywords.keywords);

    return 0;
}