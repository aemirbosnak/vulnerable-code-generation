//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000
#define MAX_TOKENS 1000

typedef struct {
    char *name;
    char *value;
} token_t;

token_t *tokens = NULL;
int num_tokens = 0;

void add_token(char *name, char *value) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    token_t *new_token = malloc(sizeof(token_t));
    new_token->name = strdup(name);
    new_token->value = strdup(value);
    tokens[num_tokens++] = *new_token;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].name, tokens[i].value);
    }
}

char *read_line(FILE *file) {
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, file);
    return strdup(line);
}

int is_metadata(char *line) {
    if (line[0] == '#' && line[1] == '!') {
        return 1;
    }
    return 0;
}

char *extract_name(char *line) {
    char *name = strtok(line, ":");
    if (name == NULL) {
        printf("Error: Invalid metadata format\n");
        exit(1);
    }
    return name;
}

char *extract_value(char *line) {
    char *value = strtok(NULL, ":");
    if (value == NULL) {
        printf("Error: Invalid metadata format\n");
        exit(1);
    }
    return value;
}

void process_metadata(char *line) {
    char *name = extract_name(line);
    char *value = extract_value(line);
    add_token(name, value);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <metadata_file>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    char *line;
    while ((line = read_line(file))!= NULL) {
        if (is_metadata(line)) {
            process_metadata(line);
        }
        free(line);
    }
    fclose(file);
    print_tokens();
    return 0;
}