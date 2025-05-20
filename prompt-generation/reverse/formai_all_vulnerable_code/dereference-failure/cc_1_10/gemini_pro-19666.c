//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <text file>\n", argv[0]);
        return 1;
    }

    // read the text file into memory
    char *text = NULL;
    long len = 0;
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    text = malloc(len + 1);
    if (text == NULL) {
        perror("malloc");
        return 1;
    }
    fread(text, 1, len, fp);
    fclose(fp);

    // tokenize the text
    char *tokens[MAX_LEN];
    int num_tokens = 0;
    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // build the summary
    char summary[MAX_LEN];
    int summary_len = 0;
    for (int i = 0; i < num_tokens; i++) {
        if (strlen(tokens[i]) > 3) {
            strcat(summary, tokens[i]);
            strcat(summary, " ");
            summary_len += strlen(tokens[i]) + 1;
        }
        if (summary_len >= MAX_LEN) {
            break;
        }
    }

    // print the summary
    printf("%s\n", summary);

    // free the memory
    free(text);

    return 0;
}