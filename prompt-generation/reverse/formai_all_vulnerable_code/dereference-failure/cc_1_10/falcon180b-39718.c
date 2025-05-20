//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 256
#define MAX_TOKENS 100

// token structure
typedef struct {
    char *token;
    int line_num;
} Token;

// function prototypes
void parse_line(Token *tokens, int num_tokens, char *line);
int add_token(Token *tokens, int num_tokens, char *token);

int main() {
    FILE *fp;
    char filename[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];
    char *token;
    int num_tokens = 0;
    Token tokens[MAX_TOKENS];

    // get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // open file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // read each line and parse
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        num_tokens = 0;
        parse_line(tokens, num_tokens, line);
        printf("Line %d:\n", tokens[0].line_num);
        for (int i = 0; i < num_tokens; i++) {
            printf("%s\n", tokens[i].token);
        }
    }

    // close file
    fclose(fp);
    return 0;
}

// parse a line and add tokens to array
void parse_line(Token *tokens, int num_tokens, char *line) {
    char *ptr = strtok(line, " \t\n\r");
    while (ptr!= NULL) {
        if (num_tokens >= MAX_TOKENS) {
            printf("Error: too many tokens on line.\n");
            exit(1);
        }
        tokens[num_tokens].token = ptr;
        tokens[num_tokens].line_num = 0;
        num_tokens++;
        ptr = strtok(NULL, " \t\n\r");
    }
    tokens[num_tokens - 1].line_num = 1;
}

// add a token to array if there is space
int add_token(Token *tokens, int num_tokens, char *token) {
    if (num_tokens >= MAX_TOKENS) {
        return 0;
    }
    tokens[num_tokens].token = token;
    tokens[num_tokens].line_num = 0;
    num_tokens++;
    return 1;
}