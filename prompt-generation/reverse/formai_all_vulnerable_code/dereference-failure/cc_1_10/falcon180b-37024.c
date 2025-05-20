//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_KEYWORDS 100

char* keywords[MAX_KEYWORDS];
int num_keywords;

char* read_line(FILE* file) {
    char* line = malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(line, MAX_LINE_LENGTH, file);
    return line;
}

void remove_whitespace(char* str) {
    char* dest = str;
    char* src = str;
    while (*src!= '\0') {
        if (!isspace(*src)) {
            *dest++ = *src;
        }
        src++;
    }
    *dest = '\0';
}

void add_keyword(char* keyword) {
    if (num_keywords >= MAX_KEYWORDS) {
        printf("Error: Too many keywords\n");
        exit(1);
    }
    keywords[num_keywords++] = keyword;
}

int is_keyword(char* word) {
    int i;
    for (i = 0; i < num_keywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void parse_line(char* line) {
    char* word = strtok(line, " \t\n\r");
    while (word!= NULL) {
        remove_whitespace(word);
        if (is_keyword(word)) {
            printf("Keyword: %s\n", word);
        }
        word = strtok(NULL, " \t\n\r");
    }
}

int main() {
    FILE* file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    char* line;
    while ((line = read_line(file))!= NULL) {
        parse_line(line);
    }
    fclose(file);
    return 0;
}