//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

typedef struct token {
    char *text;
    int length;
} Token;

typedef struct {
    Token tokens[MAX_TOKENS];
    int num_tokens;
} Resume;

Resume *parse_resume(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    Resume *resume = malloc(sizeof(Resume));
    resume->num_tokens = 0;

    char line[1000];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        Token token = {.text = line,.length = strlen(line)};
        resume->tokens[resume->num_tokens++] = token;
    }

    fclose(fp);
    return resume;
}

void print_resume(Resume *resume) {
    for (int i = 0; i < resume->num_tokens; i++) {
        printf("%s\n", resume->tokens[i].text);
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    Resume *resume = parse_resume(argv[1]);
    print_resume(resume);

    return 0;
}