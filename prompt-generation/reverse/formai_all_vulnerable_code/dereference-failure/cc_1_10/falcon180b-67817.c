//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_TOKENS 256

typedef struct {
    char *name;
    char *value;
} token_t;

typedef struct {
    token_t tokens[MAX_TOKENS];
    int num_tokens;
} resume_t;

token_t *tokenize(char *line, int *num_tokens) {
    char *token_start = line;
    char *token_end;
    token_t *tokens = malloc(sizeof(token_t) * MAX_TOKENS);
    int token_count = 0;

    while ((token_end = strchr(token_start, ','))!= NULL) {
        *token_end = '\0';
        token_start = token_end + 1;
        tokens[token_count++] = (token_t) {
           .name = strdup(token_start),
           .value = strdup(token_end + 1)
        };
    }

    if (token_count < MAX_TOKENS) {
        tokens[token_count] = (token_t) {
           .name = strdup(token_start),
           .value = NULL
        };
        token_count++;
    }

    *num_tokens = token_count;
    return tokens;
}

void free_tokens(token_t *tokens, int num_tokens) {
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].name);
        free(tokens[i].value);
    }
    free(tokens);
}

int main() {
    FILE *fp = fopen("resume.txt", "r");
    char line[MAX_LINE_LEN];
    int num_tokens;
    resume_t resume;

    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (line[0] == '#') {
            continue;
        }

        token_t *tokens = tokenize(line, &num_tokens);
        for (int i = 0; i < num_tokens; i++) {
            if (tokens[i].name!= NULL && tokens[i].value!= NULL) {
                resume.tokens[resume.num_tokens] = tokens[i];
                resume.num_tokens++;
            }
        }
        free_tokens(tokens, num_tokens);
    }

    fclose(fp);

    for (int i = 0; i < resume.num_tokens; i++) {
        printf("%s: %s\n", resume.tokens[i].name, resume.tokens[i].value);
    }

    return 0;
}