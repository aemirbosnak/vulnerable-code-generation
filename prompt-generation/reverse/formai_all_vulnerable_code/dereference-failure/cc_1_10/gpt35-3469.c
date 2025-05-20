//FormAI DATASET v1.0 Category: Text processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_line() {
    char *line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    line[strcspn(line, "\r\n")] = '\0';
    return line;
}

char **split_string(char *str, char *delim) {
    char **tokens = NULL;
    int count = 0;

    char *token = strtok(str, delim);
    while (token != NULL) {
        count++;
        tokens = realloc(tokens, count * sizeof(char*));
        tokens[count-1] = token;
        token = strtok(NULL, delim);
    }
    tokens = realloc(tokens, (count+1) * sizeof(char*));
    tokens[count] = NULL;

    return tokens;
}

int main() {
    printf("Enter a sentence to process: ");
    char *sentence = read_line();

    printf("Enter a word to replace: ");
    char *replace = read_line();
    
    printf("Enter a replacement word: ");
    char *replacement = read_line();

    char **words = split_string(sentence, " ");
    int i = 0;

    while (words[i] != NULL) {
        if (strcmp(words[i], replace) == 0) {
            free(words[i]);
            words[i] = malloc(strlen(replacement) + 1);
            strcpy(words[i], replacement);
        }
        i++;
    }

    printf("The processed sentence is: ");
    i = 0;
    while (words[i] != NULL) {
        printf("%s ", words[i]);
        free(words[i]);
        i++;
    }
    free(words);
    printf("\n");

    free(sentence);
    free(replace);
    free(replacement);
    return 0;
}