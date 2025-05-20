//Falcon-180B DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *name;
    int value;
} variable_t;

variable_t *variables;
int num_variables;

void initialize() {
    variables = (variable_t *)malloc(sizeof(variable_t));
    num_variables = 0;
}

void add_variable(char *name, int value) {
    variables = (variable_t *)realloc(variables, sizeof(variable_t) * ++num_variables);
    variables[num_variables - 1].name = strdup(name);
    variables[num_variables - 1].value = value;
}

int get_variable_value(char *name) {
    for (int i = 0; i < num_variables; i++) {
        if (strcmp(variables[i].name, name) == 0) {
            return variables[i].value;
        }
    }
    return -1;
}

void free_variables() {
    for (int i = 0; i < num_variables; i++) {
        free(variables[i].name);
    }
    free(variables);
    variables = NULL;
    num_variables = 0;
}

char *read_line(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    getline(&line, &len, file);
    return line;
}

int main() {
    initialize();
    char *line;
    while ((line = read_line(stdin))!= NULL) {
        int pos = 0;
        while (isspace(line[pos])) {
            pos++;
        }
        if (line[pos] == '\0') {
            continue;
        }
        char *eq_pos = strchr(line, '=');
        if (eq_pos == NULL) {
            printf("Invalid syntax\n");
            continue;
        }
        *eq_pos = '\0';
        add_variable(line, atoi(eq_pos + 1));
    }
    return 0;
}