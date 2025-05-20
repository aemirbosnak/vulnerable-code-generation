//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORD_LENGTH 32

typedef struct {
    char keyword[MAX_KEYWORD_LENGTH];
    int value;
} keyword_value_pair;

typedef struct {
    keyword_value_pair *keywords;
    int num_keywords;
} resume_parser;

void init_parser(resume_parser *parser) {
    parser->keywords = NULL;
    parser->num_keywords = 0;
}

void add_keyword(resume_parser *parser, char *keyword, int value) {
    keyword_value_pair *new_keyword = malloc(sizeof(keyword_value_pair));
    strcpy(new_keyword->keyword, keyword);
    new_keyword->value = value;
    parser->keywords = realloc(parser->keywords, parser->num_keywords + 1);
    parser->keywords[parser->num_keywords++] = *new_keyword;
}

int parse_line(resume_parser *parser, char *line) {
    char *token = strtok(line, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < parser->num_keywords; i++) {
            if (strcmp(token, parser->keywords[i].keyword) == 0) {
                return parser->keywords[i].value;
            }
        }
        token = strtok(NULL, " ");
    }
    return -1;
}

int main() {
    char line[MAX_LINE_LENGTH];
    resume_parser parser;
    init_parser(&parser);

    add_keyword(&parser, "Education", 1);
    add_keyword(&parser, "Experience", 2);
    add_keyword(&parser, "Skills", 3);

    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        int value = parse_line(&parser, line);
        if (value!= -1) {
            printf("Keyword found: %s\n", parser.keywords[value].keyword);
        }
    }

    return 0;
}