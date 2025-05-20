//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000
#define MAX_VARIABLES 1000

char **variables;
int num_variables;

void initialize_variables() {
    variables = (char **)malloc(MAX_VARIABLES * sizeof(char *));
    num_variables = 0;
}

void add_variable(char *name) {
    variables[num_variables] = (char *)malloc(strlen(name) + 1);
    strcpy(variables[num_variables], name);
    num_variables++;
}

int is_variable(char *word) {
    int i;
    for(i = 0; i < num_variables; i++) {
        if(strcmp(variables[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_number(char *word) {
    int i;
    for(i = 0; i < strlen(word); i++) {
        if(!isdigit(word[i])) {
            return 0;
        }
    }
    return 1;
}

char **split_line(char *line) {
    char **words;
    int num_words, i, j;
    char *word;

    num_words = 0;
    word = strtok(line, " ");
    while(word!= NULL) {
        num_words++;
        word = strtok(NULL, " ");
    }

    words = (char **)malloc(num_words * sizeof(char *));

    i = 0;
    word = strtok(line, " ");
    while(word!= NULL) {
        words[i] = (char *)malloc(strlen(word) + 1);
        strcpy(words[i], word);
        i++;
        word = strtok(NULL, " ");
    }

    return words;
}

void execute_line(char **words) {
    int i;
    for(i = 0; i < num_variables; i++) {
        if(strcmp(words[0], variables[i]) == 0) {
            printf("%s = ", variables[i]);
            if(is_number(words[1])) {
                printf("%d\n", atoi(words[1]));
            } else {
                printf("%s\n", words[1]);
            }
            return;
        }
    }

    if(strcmp(words[0], "print") == 0) {
        printf("%s\n", words[1]);
    } else if(strcmp(words[0], "if") == 0) {
        if(is_number(words[1]) && atoi(words[1]) == 0) {
            execute_line(words + 2);
        }
    } else if(strcmp(words[0], "while") == 0) {
        while(is_number(words[1]) && atoi(words[1])!= 0) {
            execute_line(words + 2);
        }
    }
}

int main() {
    char line[MAX_SIZE];
    char **words;

    initialize_variables();

    while(fgets(line, MAX_SIZE, stdin)!= NULL) {
        words = split_line(line);
        execute_line(words);
        free(words);
    }

    return 0;
}