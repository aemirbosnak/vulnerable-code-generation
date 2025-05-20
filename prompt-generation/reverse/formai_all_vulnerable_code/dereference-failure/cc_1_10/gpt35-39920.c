//FormAI DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

/* Node definition */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Linked List definition */
typedef struct {
    Node* head;
    pthread_mutex_t lock; // Thread synchronization
} List;

/* Initialize List */
void init_list(List* lst) {
    lst->head = NULL;
    if (pthread_mutex_init(&lst->lock, NULL) != 0) {
        perror("mutex init failed");
        exit(EXIT_FAILURE);
    }
}

/* Add Node to List */
void add_node(List* lst, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;

    /* Thread synchronization to avoid concurrent access */
    pthread_mutex_lock(&lst->lock);

    if (lst->head == NULL) {
        lst->head = new_node;
    } else {
        Node* cur = lst->head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
    }

    /* Release thread lock */
    pthread_mutex_unlock(&lst->lock);
}

/* Remove Node from List */
void remove_node(List* lst, int value) {
    /* Thread synchronization to avoid concurrent access */
    pthread_mutex_lock(&lst->lock);

    if (lst->head == NULL) {
        perror("List is empty");
        exit(EXIT_FAILURE);
    }

    Node* cur = lst->head;
    Node* prev = NULL;

    while (cur != NULL && cur->data != value) {
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        perror("Node not found");
        exit(EXIT_FAILURE);
    }

    if (prev == NULL) {
        lst->head = cur->next;
    } else {
        prev->next = cur->next;
    }

    free(cur);

    /* Release thread lock */
    pthread_mutex_unlock(&lst->lock);
}

/* Print List */
void print_list(List* lst) {
    /* Thread synchronization to avoid concurrent access */
    pthread_mutex_lock(&lst->lock);

    if (lst->head == NULL) {
        printf("List is empty\n");
    } else {
        Node* cur = lst->head;
        while (cur != NULL) {
            printf("%d -> ", cur->data);
            cur = cur->next;
        }
        printf("NULL\n");
    }

    /* Release thread lock */
    pthread_mutex_unlock(&lst->lock);
}

/* Main program */
int main(void) {
    List lst;
    init_list(&lst);

    add_node(&lst, 10);
    add_node(&lst, 20);
    add_node(&lst, 30);

    print_list(&lst);

    remove_node(&lst, 20);

    print_list(&lst);

    return 0;
}