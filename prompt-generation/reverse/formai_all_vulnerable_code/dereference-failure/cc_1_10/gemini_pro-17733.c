//GEMINI-pro DATASET v1.0 Category: Syntax parsing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
    struct node_t *next;
    struct node_t *prev;
    char *data;
} node_t;

typedef struct list_t {
    struct node_t *head;
    struct node_t *tail;
} list_t;

void list_init(list_t *list) {
    list->head = list->tail = NULL;
}

void list_append(list_t *list, char *data) {
    struct node_t *node = malloc(sizeof(struct node_t));
    if (!node) {
        perror("malloc");
        exit(1);
    }
    node->data = strdup(data);
    if (!list->head) {
        list->head = list->tail = node;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
}

char *list_pop(list_t *list) {
    if (!list->tail) {
        return NULL;
    }
    char *data = list->tail->data;
    struct node_t *prev = list->tail->prev;
    free(list->tail);
    if (prev) {
        prev->next = NULL;
    } else {
        list->head = list->tail = NULL;
    }
    list->tail = prev;
    return data;
}

void list_free(list_t *list) {
    while (list->head) {
        char *data = list_pop(list);
        free(data);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <expression>\n", argv[0]);
        exit(1);
    }

    char *expression = argv[1];
    int len = strlen(expression);
    int i, j;
    list_t tokens;
    list_init(&tokens);

    for (i = 0; i < len; i++) {
        if (expression[i] == ' ') {
            continue;
        }
        if (expression[i] == '(' || expression[i] == ')' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '%') {
            char token[2] = {expression[i], '\0'};
            list_append(&tokens, token);
        } else {
            j = i + 1;
            while (j < len && expression[j] != ' ' && expression[j] != '(' && expression[j] != ')' && expression[j] != '+' && expression[j] != '-' && expression[j] != '*' && expression[j] != '/' && expression[j] != '%') {
                j++;
            }
            char *token = malloc(j - i + 1);
            if (!token) {
                perror("malloc");
                exit(1);
            }
            strncpy(token, expression + i, j - i);
            token[j - i] = '\0';
            list_append(&tokens, token);
            i = j - 1;
        }
    }

    node_t *node = tokens.head;
    while (node) {
        printf("%s\n", node->data);
        node = node->next;
    }
    list_free(&tokens);
    return 0;
}