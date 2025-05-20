//GPT-4o-mini DATASET v1.0 Category: Syntax parsing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 256

typedef struct {
    char *line;
    int lineNumber;
} SourceLine;

typedef struct {
    int count;
    SourceLine *lines;
} SourceCode;

void print_tokens(char **tokens, int count) {
    for (int i = 0; i < count; i++) {
        printf("Token[%d]: %s\n", i, tokens[i]);
    }
}

char **tokenize(const char *line, int *tokenCount) {
    char **tokens = malloc(MAX_LENGTH * sizeof(char *));
    char *lineCopy = strdup(line);
    char *token = strtok(lineCopy, " \t\n");

    int count = 0;
    while (token != NULL) {
        tokens[count++] = strdup(token);
        token = strtok(NULL, " \t\n");
    }
    free(lineCopy);
    *tokenCount = count;
    return tokens;
}

void free_tokens(char **tokens, int count) {
    for (int i = 0; i < count; i++) {
        free(tokens[i]);
    }
    free(tokens);
}

int is_keyword(const char *token) {
    const char *keywords[] = {
        "if", "else", "while", "do", "for", "return",
        "int", "float", "double", "char", "void", "struct"
    };
    int nKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < nKeywords; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

SourceCode read_source_code(const char *filename) {
    SourceCode source;
    source.count = 0;
    source.lines = malloc(MAX_LINES * sizeof(SourceLine));
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LENGTH];
    while (fgets(buffer, MAX_LENGTH, file) && source.count < MAX_LINES) {
        source.lines[source.count].line = strdup(buffer);
        source.lines[source.count].lineNumber = source.count + 1;
        source.count++;
    }
    fclose(file);
    
    return source;
}

void parse_source_code(SourceCode source) {
    for (int i = 0; i < source.count; i++) {
        int tokenCount = 0;
        char **tokens = tokenize(source.lines[i].line, &tokenCount);
        
        printf("Line %d:\n", source.lines[i].lineNumber);
        for (int j = 0; j < tokenCount; j++) {
            if (is_keyword(tokens[j])) {
                printf(" - Keyword: %s\n", tokens[j]);
            } else if (isdigit(tokens[j][0])) {
                printf(" - Number: %s\n", tokens[j]);
            } else {
                printf(" - Identifier: %s\n", tokens[j]);
            }
        }
        free_tokens(tokens, tokenCount);
        free(source.lines[i].line);
    }
    free(source.lines);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source_file.c>\n", argv[0]);
        return EXIT_FAILURE;
    }

    SourceCode source = read_source_code(argv[1]);
    parse_source_code(source);
    
    return EXIT_SUCCESS;
}