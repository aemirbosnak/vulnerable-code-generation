//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LEN 100

typedef struct {
    char *name;
    char *value;
} Token;

typedef struct {
    int count;
    Token tokens[MAX_TOKENS];
} Resume;

Resume *parse_resume(char *resume_text)
{
    Resume *result = malloc(sizeof(Resume));
    if (result == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    result->count = 0;

    char *token_start = resume_text;
    char *token_end;
    char *delimiter = ",";

    while ((token_end = strstr(token_start, delimiter))!= NULL) {
        int token_len = token_end - token_start;
        if (token_len > MAX_TOKEN_LEN) {
            printf("Error: Token too long\n");
            exit(1);
        }

        Token *token = malloc(sizeof(Token));
        if (token == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }

        strncpy(token->name, token_start, token_len);
        token->name[token_len] = '\0';
        token_start = token_end + 1;

        while (isspace(*token_start)) {
            token_start++;
        }

        token_end = strstr(token_start, delimiter);
        if (token_end == NULL) {
            token_end = token_start + strlen(token_start);
        }

        int value_len = token_end - token_start;
        if (value_len > MAX_TOKEN_LEN) {
            printf("Error: Value too long\n");
            exit(1);
        }

        strncpy(token->value, token_start, value_len);
        token->value[value_len] = '\0';

        result->tokens[result->count++] = *token;
    }

    return result;
}

void print_resume(Resume *resume)
{
    for (int i = 0; i < resume->count; i++) {
        printf("%s: %s\n", resume->tokens[i].name, resume->tokens[i].value);
    }
}

int main()
{
    char *resume_text = "John Doe, Software Engineer, 10 years experience, C++, Java, Python";
    Resume *resume = parse_resume(resume_text);
    print_resume(resume);

    free(resume);
    return 0;
}