//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 20
#define MAX_KEYWORD_LENGTH 64

typedef struct {
    char *keyword;
    int count;
} Keyword;

typedef struct {
    Keyword *keywords;
    int num_keywords;
} LogAnalyzer;

void initialize_analyzer(LogAnalyzer *analyzer) {
    analyzer->keywords = (Keyword *)malloc(MAX_KEYWORDS * sizeof(Keyword));
    analyzer->num_keywords = 0;
}

void add_keyword(LogAnalyzer *analyzer, char *keyword) {
    if (analyzer->num_keywords >= MAX_KEYWORDS) {
        printf("Error: Maximum number of keywords reached.\n");
        return;
    }

    Keyword *new_keyword = (Keyword *)malloc(sizeof(Keyword));
    strncpy(new_keyword->keyword, keyword, MAX_KEYWORD_LENGTH);
    new_keyword->count = 0;

    analyzer->keywords[analyzer->num_keywords++] = *new_keyword;
}

void analyze_log(LogAnalyzer *analyzer, char *line) {
    char *token = strtok(line, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < analyzer->num_keywords; i++) {
            if (strcmp(token, analyzer->keywords[i].keyword) == 0) {
                analyzer->keywords[i].count++;
                break;
            }
        }
        if (i == analyzer->num_keywords) {
            add_keyword(analyzer, token);
        }
        token = strtok(NULL, " ");
    }
}

void print_results(LogAnalyzer *analyzer) {
    printf("Keyword\tCount\n");
    for (int i = 0; i < analyzer->num_keywords; i++) {
        printf("%s\t%d\n", analyzer->keywords[i].keyword, analyzer->keywords[i].count);
    }
}

int main() {
    LogAnalyzer analyzer;
    initialize_analyzer(&analyzer);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, stdin)!= NULL) {
        analyze_log(&analyzer, line);
    }

    print_results(&analyzer);

    return 0;
}