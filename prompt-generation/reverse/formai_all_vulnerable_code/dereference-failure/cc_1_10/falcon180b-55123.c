//Falcon-180B DATASET v1.0 Category: Error handling ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// define medieval error codes
#define ERR_SUCCESS 0
#define ERR_INVALID_INPUT 1
#define ERR_OUT_OF_MEMORY 2
#define ERR_FILE_NOT_FOUND 3
#define ERR_INVALID_OPERATION 4

// function prototypes
int read_input(FILE *input_file);
int calculate_result(int num1, int num2, int operation);
void print_result(int result);

int main() {
    FILE *input_file;
    int num1, num2, operation, result = ERR_SUCCESS;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return ERR_FILE_NOT_FOUND;
    }

    result = read_input(input_file);
    if (result!= ERR_SUCCESS) {
        return result;
    }

    result = calculate_result(num1, num2, operation);
    if (result!= ERR_SUCCESS) {
        return result;
    }

    print_result(result);

    return ERR_SUCCESS;
}

int read_input(FILE *input_file) {
    int num1, num2, operation, result = ERR_SUCCESS;

    if (fscanf(input_file, "%d %c %d", &num1, &operation, &num2)!= 3) {
        printf("Error: Invalid input format.\n");
        return ERR_INVALID_INPUT;
    }

    if (operation!= '+' && operation!= '-' && operation!= '*' && operation!= '/') {
        printf("Error: Invalid operation.\n");
        return ERR_INVALID_OPERATION;
    }

    return ERR_SUCCESS;
}

int calculate_result(int num1, int num2, int operation) {
    int result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero.\n");
                return ERR_INVALID_OPERATION;
            }
            result = num1 / num2;
            break;
        default:
            printf("Error: Invalid operation.\n");
            return ERR_INVALID_OPERATION;
    }

    return result;
}

void print_result(int result) {
    printf("Result: %d\n", result);
}