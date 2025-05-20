//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 10000
#define MAX_NUM_TOKENS 100
#define MAX_TOKEN_LENGTH 64

typedef struct {
    char *text;
    int length;
} Line;

typedef struct {
    char *text;
    int length;
} Token;

Line *lines = NULL;
int num_lines = 0;
Token *tokens = NULL;
int num_tokens = 0;

void add_line(char *line) {
    Line *new_line = malloc(sizeof(Line));
    new_line->text = strdup(line);
    new_line->length = strlen(line);
    lines = realloc(lines, sizeof(Line) * ++num_lines);
    lines[num_lines - 1] = *new_line;
}

void add_token(char *token) {
    Token *new_token = malloc(sizeof(Token));
    new_token->text = strdup(token);
    new_token->length = strlen(token);
    tokens = realloc(tokens, sizeof(Token) * ++num_tokens);
    tokens[num_tokens - 1] = *new_token;
}

void process_line(char *line) {
    char *delimiter = " ";
    char *token = strtok(line, delimiter);
    while (token!= NULL) {
        add_token(token);
        token = strtok(NULL, delimiter);
    }
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s\n", tokens[i].text);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        add_line(line);
    }

    for (int i = 0; i < num_lines; i++) {
        process_line(lines[i].text);
    }

    fclose(file);
    print_tokens();

    for (int i = 0; i < num_lines; i++) {
        free(lines[i].text);
    }
    free(lines);

    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].text);
    }
    free(tokens);

    return 0;
}