//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LENGTH 20

typedef struct {
    char *keyword;
    int line_number;
} Keyword;

void parse_line(char *line, int line_number, Keyword *keywords, int num_keywords) {
    char *token = strtok(line, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_keywords; i++) {
            if (strcasecmp(token, keywords[i].keyword) == 0) {
                keywords[i].line_number = line_number;
                break;
            }
        }
        if (i == num_keywords) {
            if (num_keywords < MAX_KEYWORDS) {
                strcpy(keywords[num_keywords].keyword, token);
                keywords[num_keywords].line_number = line_number;
                num_keywords++;
            }
        }
        token = strtok(NULL, " ");
    }
}

void print_keywords(Keyword *keywords, int num_keywords) {
    printf("Keywords:\n");
    for (int i = 0; i < num_keywords; i++) {
        printf("%s: line %d\n", keywords[i].keyword, keywords[i].line_number);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 1;
    Keyword keywords[MAX_KEYWORDS];
    int num_keywords = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        parse_line(line, line_number, keywords, num_keywords);
        line_number++;
    }

    fclose(file);

    if (num_keywords == 0) {
        printf("No keywords found.\n");
    } else {
        print_keywords(keywords, num_keywords);
    }

    return 0;
}