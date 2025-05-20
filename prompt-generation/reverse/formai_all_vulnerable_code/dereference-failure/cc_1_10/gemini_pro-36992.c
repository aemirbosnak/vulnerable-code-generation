//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT_SIZE 2

typedef struct node {
    char* data;
    struct node* next;
} node;

typedef struct stack {
    node* top;
} stack;

void push(stack* s, char* data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = s->top;
    s->top = new_node;
}

char* pop(stack* s) {
    if (s->top == NULL) {
        return NULL;
    }
    char* data = s->top->data;
    node* next = s->top->next;
    free(s->top);
    s->top = next;
    return data;
}

char* peek(stack* s) {
    if (s->top == NULL) {
        return NULL;
    }
    return s->top->data;
}

int is_empty(stack* s) {
    return s->top == NULL;
}

int main() {
    stack* tags = (stack*)malloc(sizeof(stack));
    tags->top = NULL;

    char* html = (char*)malloc(10000);
    scanf("%s", html);

    char* output = (char*)malloc(10000);
    int output_index = 0;

    int indent_level = 0;

    for (int i = 0; i < strlen(html); i++) {
        char c = html[i];

        if (c == '<') {
            char* tag = (char*)malloc(100);
            int tag_index = 0;
            i++;
            while (html[i] != '>') {
                tag[tag_index++] = html[i++];
            }
            tag[tag_index] = '\0';
            push(tags, tag);
            for (int j = 0; j < indent_level * INDENT_SIZE; j++) {
                output[output_index++] = ' ';
            }
            output[output_index++] = '<';
            output[output_index++] = tag[0];
            for (int j = 1; j < strlen(tag); j++) {
                if (tag[j] == ' ') {
                    output[output_index++] = ' ';
                } else {
                    output[output_index++] = tag[j];
                }
            }
            output[output_index++] = '>';
            indent_level++;
        } else if (c == '\n') {
            output[output_index++] = '\n';
            indent_level = 0;
        } else if (c == ' ') {
            if (output[output_index - 1] != ' ') {
                output[output_index++] = ' ';
            }
        } else {
            output[output_index++] = c;
        }
    }

    output[output_index] = '\0';

    printf("%s", output);

    return 0;
}