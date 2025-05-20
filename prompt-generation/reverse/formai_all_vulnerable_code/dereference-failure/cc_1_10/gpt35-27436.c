//FormAI DATASET v1.0 Category: Syntax parsing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    float value;
} variable;

variable *symbol_table;

int symbol_table_size = 0;
int symbol_table_capacity = 0;

void init_symbol_table() {
    symbol_table = malloc(sizeof(variable) * 10);
    symbol_table_capacity = 10;
}

void insert_symbol(char *name, float value) {
    if (symbol_table_size == symbol_table_capacity) {
        symbol_table_capacity *= 2;
        symbol_table = realloc(symbol_table, sizeof(variable) * symbol_table_capacity);
    }
    symbol_table[symbol_table_size].name = malloc(sizeof(char) * strlen(name) + 1);
    strcpy(symbol_table[symbol_table_size].name, name);
    symbol_table[symbol_table_size].value = value;
    symbol_table_size++;
}

int find_symbol(char *name) {
    for (int i = 0; i < symbol_table_size; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

float evaluate_expression(char *expression) {
    // implementation of parsing and evaluating the expression
    // returns the float value of the expression
}

int main() {
    init_symbol_table();

    char input[100];
    while (1) {
        printf("> ");
        fgets(input, 100, stdin);

        if (strcmp(input, "quit\n") == 0) {
            exit(0);
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Check if input is an assignment statement
        char *equals_sign = strchr(input, '=');
        if (equals_sign != NULL) {
            *equals_sign = '\0';
            char *variable_name = input;
            char *expression = equals_sign + 1;
            float value = evaluate_expression(expression);
            int symbol_index = find_symbol(variable_name);
            if (symbol_index == -1) {
                insert_symbol(variable_name, value);
            } else {
                symbol_table[symbol_index].value = value;
            }
        } else {
            // Not an assignment statement, so evaluate the expression
            float value = evaluate_expression(input);
            printf("%f\n", value);
        }
    }
    return 0;
}