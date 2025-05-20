//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_TIME_STEPS 1000
#define MAX_VARS 10
#define MAX_VALUE_LENGTH 10

typedef struct Variable {
    char name[MAX_VALUE_LENGTH];
    int value;
    struct Variable* next;
} Variable;

Variable* time_line = NULL;

void print_time_line() {
    Variable* current = time_line;
    int step = 0;
    printf("\nTime Line:\n");
    while (current != NULL) {
        printf("%d: ", step);
        printf("%s = %d\n", current->name, current->value);
        current = current->next;
        step++;
    }
}

void set_variable(char* name, int value) {
    Variable* new_variable = (Variable*) malloc(sizeof(Variable));
    strcpy(new_variable->name, name);
    new_variable->value = value;

    if (time_line == NULL) {
        time_line = new_variable;
    } else {
        Variable* current = time_line;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_variable;
    }
}

int get_variable(char* name) {
    Variable* current = time_line;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void time_step() {
    int i;
    for (i = 0; i < MAX_VARS; i++) {
        char var_name[MAX_VALUE_LENGTH];
        sprintf(var_name, "var%d", i);

        int value = get_variable(var_name);
        if (value < 0) {
            set_variable(var_name, value + 1);
            continue;
        }

        int next_value = value + 1;

        set_variable(var_name, next_value);

        if (next_value >= MAX_VALUE_LENGTH) {
            // Reset the variable to 0 and go back to the previous step
            set_variable(var_name, value);
            time_line = time_line->next;
            time_step();
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_TIME_STEPS; i++) {
        set_variable("a", rand() % 10);
        time_step();
        print_time_line();
    }

    return 0;
}