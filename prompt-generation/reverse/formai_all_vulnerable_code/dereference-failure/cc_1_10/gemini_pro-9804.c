//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct tag_node {
    char *name;
    char *value;
    struct tag_node *next;
};

struct tag_stack {
    struct tag_node *top;
};

void push_tag(struct tag_stack *stack, char *name, char *value) {
    struct tag_node *new_node = malloc(sizeof(struct tag_node));
    new_node->name = strdup(name);
    new_node->value = strdup(value);
    new_node->next = stack->top;
    stack->top = new_node;
}

void pop_tag(struct tag_stack *stack) {
    if (stack->top != NULL) {
        struct tag_node *old_top = stack->top;
        stack->top = stack->top->next;
        free(old_top->name);
        free(old_top->value);
        free(old_top);
    }
}

char *get_tag_value(struct tag_stack *stack, char *name) {
    struct tag_node *node = stack->top;
    while (node != NULL) {
        if (strcmp(node->name, name) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}

int main() {
    char *html = "<html>\n<head>\n<title>My Website</title>\n</head>\n<body>\n<h1>Hello World!</h1>\n</body>\n</html>";

    struct tag_stack stack;
    stack.top = NULL;

    char *start = html;
    char *end = strchr(start, '<');
    while (end != NULL) {
        char *name = end + 1;
        char *value = strchr(name, '>');
        *value = '\0';
        if (*name == '/') {
            pop_tag(&stack);
        } else {
            push_tag(&stack, name, value + 1);
        }
        start = value + 1;
        end = strchr(start, '<');
    }

    printf("Title: %s\n", get_tag_value(&stack, "title"));

    return 0;
}