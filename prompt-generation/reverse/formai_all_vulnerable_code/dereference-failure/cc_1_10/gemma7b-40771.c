//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char operator;
    double number;
    struct Node* next;
} Node;

Node* createNode(char operator, double number) {
    Node* newNode = malloc(sizeof(Node));
    newNode->operator = operator;
    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}

double calculate(Node* head) {
    double result = head->number;
    while (head->next) {
        switch (head->operator) {
            case '+':
                result += head->next->number;
                break;
            case '-':
                result -= head->next->number;
                break;
            case '*':
                result *= head->next->number;
                break;
            case '/':
                if (head->next->number == 0) {
                    return -1;
                }
                result /= head->next->number;
                break;
            default:
                return -1;
        }
        head = head->next;
    }
    return result;
}

int main() {
    char buffer[MAX_BUFFER_SIZE];
    printf("Enter an expression: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    Node* head = NULL;
    char* token = strtok(buffer, " ");
    while (token) {
        double number = atof(token);
        char operator = token[0];
        Node* newNode = createNode(operator, number);
        newNode->next = head;
        head = newNode;
        token = strtok(NULL, " ");
    }

    double result = calculate(head);
    if (result == -1) {
        printf("Error: Invalid expression.\n");
    } else {
        printf("The result is: %.2lf\n", result);
    }

    return 0;
}