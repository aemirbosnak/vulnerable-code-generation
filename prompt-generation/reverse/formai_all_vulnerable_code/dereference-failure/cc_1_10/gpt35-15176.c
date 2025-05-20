//FormAI DATASET v1.0 Category: Syntax parsing ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node node;

struct Node {
    char data;
    node* next;
};

// Function to push elements onto the stack
void push(node** head, char value) {

    node* new_node = (node*) malloc(sizeof(node));

    if (new_node == NULL) {
        printf("Error: Memory allocation failed");
        exit(1);
    }

    new_node->data = value;
    new_node->next = (*head);
    (*head) = new_node;
}

// Function to pop elements from the stack
char pop(node** head) {

    if (*head == NULL) {
        printf("Error: Stack underflow");
        exit(1);
    }

    char value = (*head)->data;
    node* temp = (*head);
    (*head) = (*head)->next;
    free(temp);
    return value;
}

// Function to check whether the given character is an opening bracket or not
int isOpeningBracket(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

// Function to check whether the given character is a closing bracket or not
int isClosingBracket(char ch) {
    return (ch == ')' || ch == '}' || ch == ']');
}

// Function to check whether the given brackets match or not
int areBracketsMatching(char opening_bracket, char closing_bracket) {

    if (opening_bracket == '(' && closing_bracket == ')') {
        return 1;
    } else if (opening_bracket == '{' && closing_bracket == '}') {
        return 1;
    } else if (opening_bracket == '[' && closing_bracket == ']') {
        return 1;
    } else {
        return 0;
    }
}

// Function to check whether the given syntax is valid or not
int isSyntaxValid(char* code) {

    node* stack = NULL;

    for (int i=0; i < strlen(code); i++) {

        // If the current character is an opening bracket, push it onto the stack
        if (isOpeningBracket(code[i])) {
            push(&stack, code[i]);
        }

        // If the current character is a closing bracket, pop an element from the stack and check whether they match or not
        if (isClosingBracket(code[i])) {

            if (stack == NULL) {
                return 0;
            }

            char popped_element = pop(&stack);
            if (!areBracketsMatching(popped_element, code[i])) {
                return 0;
            }
        }
    }

    // If the stack is not empty, return 0 (invalid syntax)
    if (stack != NULL) {
        return 0;
    }

    return 1;
}

int main() {

    // Sample C syntax code
    char code[] = "#include<stdio.h>\n\nint main() {\n\n\tint a = 10;\n\tint b = 20;\n\tint sum = a + b;\n\n\tprintf(\"Sum of %d and %d is %d\", a, b, sum);\n\n\treturn 0;\n}\n";

    // Check whether the syntax is valid or not
    int is_valid = isSyntaxValid(code);

    if (is_valid) {
        printf("Valid syntax!");
    } else {
        printf("Invalid syntax!");
    }

    return 0;
}