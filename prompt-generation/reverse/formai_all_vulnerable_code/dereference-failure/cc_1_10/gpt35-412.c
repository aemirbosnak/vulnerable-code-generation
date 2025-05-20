//FormAI DATASET v1.0 Category: Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef enum {ADD, SUBTRACT, MULTIPLY, DIVIDE, MODULO} operation_type;

typedef struct {
    operation_type type;
    double num1;
    double num2;
    double result;
    bool is_complete;
    bool has_error;
    void (*callback_function)(char*);
} calculator_task;

void handle_error(calculator_task* task, char* error_message) {
    printf("%s\n", error_message);
    task->has_error = true;
    task->is_complete = true;
    task->callback_function("Error!");
}

void perform_operation(calculator_task* task) {
    switch(task->type) {
        case ADD:
            task->result = task->num1 + task->num2;
            break;   
        case SUBTRACT:
            task->result = task->num1 - task->num2;
            break;
        case MULTIPLY:
            task->result = task->num1 * task->num2;
            break;
        case DIVIDE:
            if(task->num2 == 0) {
                handle_error(task, "Cannot divide by zero!");
                return;
            }
            task->result = task->num1 / task->num2;
            break;
        case MODULO:
            task->result = (int)task->num1 % (int)task->num2;
            break;
        default:
            handle_error(task, "Invalid operation type!");
            return;
    }
    task->is_complete = true;
    task->callback_function("Done!");
}

void parse_input(char* input_string, calculator_task* task) {
    char* token = strtok(input_string, " ");
    int token_count = 0;
    
    while(token != NULL) {
        switch(token_count) {
            case 0:
                if(strcmp(token, "add") == 0) {
                    task->type = ADD;
                } else if(strcmp(token, "subtract") == 0) {
                    task->type = SUBTRACT;
                } else if(strcmp(token, "multiply") == 0) {
                    task->type = MULTIPLY;
                } else if(strcmp(token, "divide") == 0) {
                    task->type = DIVIDE;
                } else if(strcmp(token, "modulo") == 0) {
                    task->type = MODULO;
                } else {
                    handle_error(task, "Invalid operation!");
                    return;
                }
                break;
            case 1:
                if(!isdigit(token[0])) {
                    handle_error(task, "Invalid first operand!");
                    return;
                }
                task->num1 = atof(token);
                break;
            case 2:
                if(!isdigit(token[0])) {
                    handle_error(task, "Invalid second operand!");
                    return;
                }
                task->num2 = atof(token);
                break;
            default:
                handle_error(task, "Too many operands!");
                return;
        }
        token = strtok(NULL, " ");
        token_count++;
    }

    if(token_count != 3) {
        handle_error(task, "Not enough operands!");
        return;
    }

    perform_operation(task);
}

void start_calculator_task(char* input_string, void (*callback_function)(char*)) {
    calculator_task* task = calloc(1, sizeof(calculator_task));
    task->callback_function = callback_function;
    task->is_complete = false;
    task->has_error = false;
    parse_input(input_string, task);
    free(task);
}

int main() {
    char input[100];
    printf("Enter an arithmetic operation (e.g. add 2 3): ");
    fgets(input, 100, stdin);
    start_calculator_task(input, &printf);
    return 0;
}