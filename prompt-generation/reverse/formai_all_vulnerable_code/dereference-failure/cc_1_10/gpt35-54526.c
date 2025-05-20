//FormAI DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct StackNode {
    char data;
    struct StackNode* next;
};

typedef struct StackNode StackNode;

StackNode* createStackNode(char data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode* top) {
    return top == NULL;
}

void push(StackNode** top, char data) {
    StackNode* node = createStackNode(data);
    node->next = *top;
    *top = node;
}

char pop(StackNode** top) {
    if (isEmpty(*top)) {
        return '\0';
    }
    StackNode* temp = *top;
    *top = (*top)->next;
    char data = temp->data;
    free(temp);
    return data;
}

int isOperator(char c) {
    return c == '<' || c == '>' || c == '/' || c == '=';
}

void beautifyHTML(char* input, char* output) {
    StackNode* stack = NULL;
    int indent = 0;
    char* curr = input;
    while (*curr != '\0') {
        if (*curr == '<') {
            output[indent++] = *curr++;
            if (*curr == '/') {
                indent -= 2;
            }
            if (!isEmpty(stack)) {
                output[indent++] = '\n';
                for (StackNode* temp = stack; temp != NULL; temp = temp->next) {
                    output[indent++] = '\t';
                }
            }
            push(&stack, '<');
        }
        while (*curr != '>' && !isOperator(*curr)) {
            output[indent++] = *curr++;
        }
        if (*curr == '>') {
            output[indent++] = *curr++;
            if (!isEmpty(stack) && *(curr - 2) == '/') {
                indent -= 4;
                stack = stack->next;
            } else if (!isEmpty(stack) && *(curr - 2) != '/') {
                stack = stack->next;
            }
            output[indent++] = '\n';
            for (StackNode* temp = stack; temp != NULL; temp = temp->next) {
                output[indent++] = '\t';
            }
        }
        if (isOperator(*curr++)) {
            output[indent++] = *curr;
        }
    }
    output[indent] = '\0';
}

int main() {
    char input[] = "<html><head><title>My Website</title></head><body><h1>Welcome to my website!</h1><p>This is a paragraph.</p></body></html>";
    char output[1000];
    beautifyHTML(input, output);
    printf("%s", output);
    return 0;
}