//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_KEYWORDS 10

typedef struct {
    char *keyword;
    int line_num;
} Keyword;

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *filename = "example.c";
    int line_num = 1;
    int num_keywords = 0;
    Keyword keywords[MAX_KEYWORDS];

    if (argc > 1) {
        filename = argv[1];
    }

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        line[strcspn(line, "\n")] = '\0'; // remove newline character
        for (int i = 0; i < num_keywords; i++) {
            if (strstr(line, keywords[i].keyword)!= NULL) {
                printf("Keyword '%s' found on line %d\n", keywords[i].keyword, keywords[i].line_num);
            }
        }
        line_num++;
        for (int i = 0; i < MAX_KEYWORDS; i++) {
            if (keywords[i].keyword == NULL) {
                break;
            }
            if (strstr(line, keywords[i].keyword)!= NULL) {
                keywords[i].line_num = line_num;
                printf("Keyword '%s' found on line %d\n", keywords[i].keyword, keywords[i].line_num);
            }
        }
    }

    fclose(fp);

    return 0;
}