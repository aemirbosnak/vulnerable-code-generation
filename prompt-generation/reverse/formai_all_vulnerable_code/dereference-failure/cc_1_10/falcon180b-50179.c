//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEYWORDS 10

typedef struct {
    char *name;
    int line_number;
} Keyword;

void extract_keywords(FILE *file, char **keywords, int num_keywords) {
    char line[MAX_LINE_SIZE];
    int i = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        int j;
        for (j = 0; j < num_keywords; j++) {
            if (strstr(line, keywords[j])!= NULL) {
                Keyword keyword = {keywords[j], i+1};
                printf("Keyword '%s' found on line %d\n", keyword.name, keyword.line_number);
                break;
            }
        }
        if (j == num_keywords) {
            printf("No keywords found on line %d\n", i+1);
        }
        i++;
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <filename> <keyword1> [<keyword2>...]\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", argv[1]);
        return 1;
    }

    char **keywords = malloc(sizeof(char *) * (argc-2));
    int num_keywords = 0;

    for (int i = 2; i < argc; i++) {
        keywords[num_keywords] = argv[i];
        num_keywords++;
    }

    extract_keywords(file, keywords, num_keywords);

    for (int i = 0; i < num_keywords; i++) {
        free(keywords[i]);
    }
    free(keywords);

    fclose(file);

    return 0;
}