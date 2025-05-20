//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LEN 100

typedef struct {
    char *token;
    int token_len;
} Token;

typedef struct {
    int num_tokens;
    Token tokens[MAX_TOKENS];
} Resume;

Resume parse_resume(char *resume_text) {
    int i = 0;
    int num_tokens = 0;
    char *token = (char *)malloc(MAX_TOKEN_LEN * sizeof(char));
    Resume resume;

    while (*resume_text) {
        if (isspace(*resume_text)) {
            if (num_tokens >= MAX_TOKENS) {
                printf("Error: Too many tokens\n");
                exit(1);
            }
            resume.tokens[num_tokens].token = strdup(token);
            resume.tokens[num_tokens].token_len = strlen(token);
            num_tokens++;
            i = 0;
        } else {
            token[i++] = *resume_text;
        }
        resume_text++;
    }

    if (i > 0) {
        if (num_tokens >= MAX_TOKENS) {
            printf("Error: Too many tokens\n");
            exit(1);
        }
        resume.tokens[num_tokens].token = strdup(token);
        resume.tokens[num_tokens].token_len = strlen(token);
        num_tokens++;
    }

    resume.num_tokens = num_tokens;
    return resume;
}

void print_tokens(Resume resume) {
    int i;

    for (i = 0; i < resume.num_tokens; i++) {
        printf("%s (%d)\n", resume.tokens[i].token, resume.tokens[i].token_len);
    }
}

int main() {
    char *resume_text = "John Doe\n123 Main St.\nAnytown, USA\n(555) 555-5555\n";
    Resume resume = parse_resume(resume_text);
    print_tokens(resume);

    return 0;
}