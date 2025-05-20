//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKENS 1000
#define MAX_TOKEN_LENGTH 100

struct token {
    char *text;
    int count;
};

struct token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *text) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Too many tokens\n");
        exit(1);
    }
    tokens[num_tokens].text = strdup(text);
    tokens[num_tokens].count = 1;
    num_tokens++;
}

void train(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    char line[1024];
    while (fgets(line, sizeof(line), file)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            add_token(token);
            token = strtok(NULL, " ");
        }
    }
    fclose(file);
}

int classify(char *text) {
    int score = 0;
    int i;
    for (i = 0; i < num_tokens; i++) {
        int j;
        for (j = 0; j < strlen(text); j++) {
            if (text[j] == tokens[i].text[j]) {
                score++;
            }
        }
    }
    return score;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s train <filename> | classify <text>\n", argv[0]);
        return 1;
    }
    if (strcmp(argv[1], "train") == 0) {
        train(argv[2]);
        return 0;
    } else if (strcmp(argv[1], "classify") == 0) {
        int score = classify(argv[2]);
        if (score >= 3) {
            printf("Spam\n");
        } else {
            printf("Not spam\n");
        }
        return 0;
    }
    printf("Error: Invalid command\n");
    return 1;
}