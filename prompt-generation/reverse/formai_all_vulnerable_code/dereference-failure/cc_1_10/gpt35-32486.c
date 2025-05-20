//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 100

typedef enum {false, true} bool;

char removeSpaces(char* str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
    return *str;
}

char removeSpecialChars(char* str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if(isalpha(str[i]) || isdigit(str[i]) || str[i] == '.' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
    return *str;
}

bool isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '%') {
        return true;
    }
    return false;
}

bool validateInput(char* input) {
    if(strlen(input) > MAX_INPUT_SIZE) {
        return false;
    }
    removeSpaces(input);
    removeSpecialChars(input);
    if(!isdigit(input[0]) && input[0] != '-') {
        return false;
    }
    for(int i=0; i<strlen(input); i++) {
        if(isOperator(input[i])) {
            if(input[i+1] == '\0' || !isdigit(input[i+1])) {
                return false;
            }
        }
        else if(isalpha(input[i])) {
            return false;
        }
    }
    return true;
}

double getResult(char* input) {
    double result;
    char operation;
    char* ptr = strtok(input, "+-*/%");
    double num1 = atof(ptr);
    ptr = strtok(NULL, "+-*/%");
    double num2 = atof(ptr);
    ptr = strtok(input, "0123456789.");
    operation = *ptr;
    switch(operation) {
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
            result = num1 / num2;
            break;
        case '%':
            result = ((int)num1) % ((int)num2);
            break;
        default:
            result = 0.0;
    }
    return result;
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter the numbers and operation separated by spaces: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';
    if(!validateInput(input)) {
        printf("Invalid input. Please try again.");
        return 1;
    }
    double result = getResult(input);
    printf("The result of %s is %.2f", input, result);
    return 0;
}