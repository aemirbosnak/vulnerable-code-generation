//Falcon-180B DATASET v1.0 Category: Log analysis ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 100

// function prototypes
void tokenize(char *line, char **tokens);
void print_word_counts(char **words, int counts[MAX_WORDS]);

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char **tokens;
    int num_tokens;
    int word_counts[MAX_WORDS] = {0};

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        num_tokens = 0;
        tokens = malloc(sizeof(char *) * MAX_WORDS);
        if (tokens == NULL) {
            printf("Error allocating memory.\n");
            return 1;
        }

        tokenize(line, tokens);
        for (int i = 0; i < num_tokens; i++) {
            word_counts[i]++;
        }
    }

    print_word_counts(tokens, word_counts);

    free(tokens);
    fclose(file);

    return 0;
}

void tokenize(char *line, char **tokens) {
    char *token;
    int num_tokens = 0;

    token = strtok(line, " \t\n\r\f\v.,!?;:");
    while (token!= NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " \t\n\r\f\v.,!?;:");
    }
}

void print_word_counts(char **words, int counts[MAX_WORDS]) {
    int i;

    for (i = 0; i < MAX_WORDS; i++) {
        if (counts[i] > 0) {
            printf("%s: %d\n", words[i], counts[i]);
        }
    }
}