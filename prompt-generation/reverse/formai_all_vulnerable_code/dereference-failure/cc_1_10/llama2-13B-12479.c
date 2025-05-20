//LLAMA2-13B DATASET v1.0 Category: Log analysis ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_LEN 1024
#define MAX_DEPTH 5

typedef struct node {
    char *message;
    struct node *prev;
    struct node *next;
} node_t;

typedef struct log {
    node_t *head;
    node_t *tail;
} log_t;

void init_log(log_t *log) {
    log->head = NULL;
    log->tail = NULL;
}

void add_log(log_t *log, char *message) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->message = message;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (log->head == NULL) {
        log->head = new_node;
        log->tail = new_node;
    } else {
        log->tail->next = new_node;
        log->tail = new_node;
    }
}

void print_log(log_t *log) {
    node_t *current = log->head;

    while (current != NULL) {
        printf("%s\n", current->message);
        current = current->next;
    }
}

void analyze_log(log_t *log) {
    int depth = 0;
    node_t *current = log->head;

    while (current != NULL) {
        if (strlen(current->message) > depth) {
            depth = strlen(current->message);
        }

        current = current->next;
    }

    printf("Max message length: %d\n", depth);
}

int main() {
    log_t log;
    init_log(&log);

    add_log(&log, "Hello, world!");
    add_log(&log, "This is a test message");
    add_log(&log, "This is another test message");

    print_log(&log);

    analyze_log(&log);

    return 0;
}