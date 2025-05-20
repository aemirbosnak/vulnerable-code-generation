//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024
#define MAX_DEPTH 5

typedef struct node {
    char *message;
    size_t len;
    struct node *prev;
    struct node *next;
} node_t;

node_t *log_tree = NULL;

void insert_log(char *message, size_t len) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->message = message;
    new_node->len = len;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (log_tree == NULL) {
        log_tree = new_node;
    } else {
        node_t *cur = log_tree;
        while (cur->next != NULL) {
            if (strcmp(cur->message, new_node->message) > 0) {
                break;
            }
            cur = cur->next;
        }
        new_node->prev = cur;
        new_node->next = cur->next;
        cur->next = new_node;
    }
}

void print_log(void) {
    node_t *cur = log_tree;
    while (cur != NULL) {
        printf("%s (len: %zu)\n", cur->message, cur->len);
        cur = cur->next;
    }
}

int main(void) {
    char *messages[] = {"Hello", "World", "This", "is", "a", "test", NULL};
    size_t message_len[] = {5, 4, 4, 3, 3, 5};
    int i;

    for (i = 0; messages[i] != NULL; i++) {
        insert_log(messages[i], message_len[i]);
    }

    print_log();

    return 0;
}