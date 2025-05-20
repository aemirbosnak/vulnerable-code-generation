//Falcon-180B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_HISTORY 10

typedef struct {
    char *line;
    int line_length;
} Line;

typedef struct {
    Line *lines;
    int num_lines;
} History;

Line *new_line(char *s) {
    Line *line = malloc(sizeof(Line));
    line->line = s;
    line->line_length = strlen(s);
    return line;
}

History *new_history() {
    History *history = malloc(sizeof(History));
    history->lines = malloc(MAX_LINE_LENGTH * MAX_NUM_HISTORY);
    history->num_lines = 0;
    return history;
}

void add_line(History *history, char *s) {
    Line *line = new_line(s);
    history->lines[history->num_lines] = *line;
    free(line);
    history->num_lines++;
}

void print_history(History *history) {
    for (int i = 0; i < history->num_lines; i++) {
        printf("%s\n", history->lines[i].line);
    }
}

void clear_history(History *history) {
    history->num_lines = 0;
}

int is_number(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        if (!isdigit(s[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[MAX_LINE_LENGTH];
    char *token;
    History *history = new_history();

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE_LENGTH, stdin);
        add_line(history, input);

        token = strtok(input, " ");
        while (token!= NULL) {
            if (is_number(token)) {
                printf("%s = %f\n", token, atof(token));
            } else {
                printf("Invalid input: %s\n", token);
            }
            token = strtok(NULL, " ");
        }
    }

    return 0;
}