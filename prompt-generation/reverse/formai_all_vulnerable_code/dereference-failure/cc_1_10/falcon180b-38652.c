//Falcon-180B DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_TOKENS 100

typedef struct {
    char *key;
    char *value;
} token_t;

int main(int argc, char *argv[]) {
    FILE *fp;
    char line[MAX_LINE];
    char *ptr;
    char *header = NULL;
    int num_tokens = 0;
    token_t tokens[MAX_TOKENS];

    if (argc!= 2) {
        printf("Usage: %s <email_file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        if (header == NULL) {
            header = strdup(line);
            continue;
        }

        ptr = strtok_r(line, ":", &ptr);
        while (ptr!= NULL) {
            if (num_tokens >= MAX_TOKENS) {
                printf("Error: Too many tokens.\n");
                exit(1);
            }

            tokens[num_tokens].key = strdup(ptr);
            ptr = strtok_r(NULL, ":", &ptr);

            if (ptr == NULL) {
                tokens[num_tokens].value = NULL;
            } else {
                tokens[num_tokens].value = strdup(ptr);
            }

            num_tokens++;
        }
    }

    fclose(fp);

    printf("Subject: %s\n", tokens[0].value);
    printf("From: %s\n", tokens[1].value);
    printf("To: %s\n", tokens[2].value);
    printf("Content-Type: %s\n", tokens[3].value);

    for (int i = 4; i < num_tokens; i++) {
        printf("%s: %s\n", tokens[i].key, tokens[i].value);
    }

    free(header);
    for (int i = 0; i < num_tokens; i++) {
        free(tokens[i].key);
        free(tokens[i].value);
    }

    return 0;
}