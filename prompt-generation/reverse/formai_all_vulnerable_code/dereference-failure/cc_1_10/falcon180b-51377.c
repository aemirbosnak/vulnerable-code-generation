//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

typedef struct token {
    char *text;
    int length;
} Token;

typedef struct {
    Token *tokens;
    int num_tokens;
} Resume;

Resume *parse_resume(char *resume_text) {
    Resume *resume = (Resume *)malloc(sizeof(Resume));
    resume->num_tokens = 0;
    resume->tokens = (Token *)malloc(MAX_TOKENS * sizeof(Token));

    char *token_text = (char *)malloc(MAX_TOKEN_LENGTH * sizeof(char));
    int token_length = 0;

    char *p = resume_text;
    while (*p!= '\0') {
        if (isspace(*p)) {
            token_text[token_length] = '\0';
            Token *token = (Token *)malloc(sizeof(Token));
            token->text = token_text;
            token->length = token_length;
            resume->tokens[resume->num_tokens++] = *token;
            token_length = 0;
        } else {
            token_text[token_length++] = *p;
        }
        p++;
    }

    token_text[token_length] = '\0';
    Token *token = (Token *)malloc(sizeof(Token));
    token->text = token_text;
    token->length = token_length;
    resume->tokens[resume->num_tokens++] = *token;

    return resume;
}

void print_resume(Resume *resume) {
    for (int i = 0; i < resume->num_tokens; i++) {
        printf("%s\n", resume->tokens[i].text);
    }
}

int main() {
    char *resume_text = "John Doe\n123 Main St.\nAnytown, USA 12345\n(123) 456-7890\n";
    Resume *resume = parse_resume(resume_text);
    print_resume(resume);
    return 0;
}