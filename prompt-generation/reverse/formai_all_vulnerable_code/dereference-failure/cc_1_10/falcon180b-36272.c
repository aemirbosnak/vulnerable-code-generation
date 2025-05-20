//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_WORD_LENGTH 50

// Function to tokenize a line
char *tokenize(char *line) {
    char *token = strtok(line, " ");
    char *result = malloc(MAX_WORD_LENGTH * sizeof(char));
    int i = 0;

    while (token!= NULL) {
        if (i >= MAX_WORD_LENGTH) {
            printf("Token too long\n");
            exit(1);
        }

        strncat(result, token, MAX_WORD_LENGTH - i);
        i += strlen(token);

        token = strtok(NULL, " ");
    }

    return result;
}

// Function to compare a token with a list of keywords
int is_keyword(char *token, char **keywords, int num_keywords) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// Function to check a line for suspicious activity
int check_line(char *line, char **keywords, int num_keywords) {
    char *token = tokenize(line);

    if (is_keyword(token, keywords, num_keywords)) {
        printf("Suspicious activity detected: %s\n", token);
        return 1;
    }

    free(token);
    return 0;
}

// Function to read a file and check each line for suspicious activity
void check_file(FILE *file, char **keywords, int num_keywords) {
    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        check_line(line, keywords, num_keywords);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <file> <keyword1> [<keyword2>...]\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char **keywords = malloc((argc - 2) * sizeof(char *));

    for (int i = 2; i < argc; i++) {
        keywords[i - 2] = strdup(argv[i]);
    }

    check_file(file, keywords, argc - 2);

    for (int i = 0; i < argc - 2; i++) {
        free(keywords[i]);
    }

    free(keywords);
    fclose(file);

    return 0;
}