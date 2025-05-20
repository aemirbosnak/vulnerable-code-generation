//Falcon-180B DATASET v1.0 Category: Syntax parsing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_LINE_LENGTH 1000

char *tokens[MAX_TOKENS];
int num_tokens;

char *line;
int line_length;

void get_line() {
    line = (char*)malloc(MAX_LINE_LENGTH);
    line_length = 0;
    char c;
    while ((c = fgetc(stdin))!= '\n') {
        if (line_length >= MAX_LINE_LENGTH - 1) {
            printf("Error: Line too long.\n");
            exit(1);
        }
        line[line_length++] = c;
    }
    line[line_length] = '\0';
}

void tokenize() {
    char *token;
    int i = 0;
    while ((token = strtok(line, " \t\n\r\f\v"))!= NULL) {
        if (i >= MAX_TOKENS - 1) {
            printf("Error: Too many tokens.\n");
            exit(1);
        }
        tokens[i++] = token;
    }
    num_tokens = i;
}

void print_tokens() {
    for (int i = 0; i < num_tokens; i++) {
        printf("%s ", tokens[i]);
    }
    printf("\n");
}

int main() {
    get_line();
    tokenize();
    print_tokens();
    return 0;
}