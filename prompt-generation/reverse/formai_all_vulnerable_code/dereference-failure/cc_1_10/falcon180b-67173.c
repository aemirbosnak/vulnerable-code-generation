//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 64

typedef struct {
    char *keyword;
    int line_count;
} KeywordInfo;

void extract_metadata(FILE *file, KeywordInfo *keywords) {
    char line[MAX_LINE_SIZE];
    char *token;
    int i;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        for (i = 0; i < MAX_KEYWORDS; i++) {
            if (keywords[i].keyword == NULL) {
                break;
            }
            token = strtok(line, " ");
            while (token!= NULL) {
                if (strcmp(token, keywords[i].keyword) == 0) {
                    keywords[i].line_count++;
                }
                token = strtok(NULL, " ");
            }
        }
    }
}

void print_metadata(KeywordInfo *keywords) {
    int i;

    for (i = 0; i < MAX_KEYWORDS; i++) {
        if (keywords[i].keyword!= NULL) {
            printf("Keyword '%s' appears on %d lines.\n", keywords[i].keyword, keywords[i].line_count);
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    KeywordInfo keywords[MAX_KEYWORDS];
    int num_keywords = 0;

    if (argc < 2) {
        printf("Usage: %s <filename> <keyword1> <keyword2>...\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Cannot open file '%s'.\n", argv[1]);
        return 1;
    }

    while (num_keywords < MAX_KEYWORDS && argv[2]!= NULL) {
        int keyword_length = strlen(argv[2]);
        if (keyword_length > MAX_KEYWORD_LENGTH) {
            printf("Error: Keyword '%s' is too long (maximum length is %d).\n", argv[2], MAX_KEYWORD_LENGTH);
            return 1;
        }
        keywords[num_keywords].keyword = malloc(keyword_length + 1);
        strcpy(keywords[num_keywords].keyword, argv[2]);
        num_keywords++;
        argv++;
    }

    extract_metadata(file, keywords);
    print_metadata(keywords);

    fclose(file);
    return 0;
}