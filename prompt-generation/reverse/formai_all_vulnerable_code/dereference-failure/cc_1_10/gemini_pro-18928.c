//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *head = NULL;
pthread_mutex_t lock;

void insert_at_beginning(int data) {
    pthread_mutex_lock(&lock);
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    pthread_mutex_unlock(&lock);
}

void insert_at_end(int data) {
    pthread_mutex_lock(&lock);
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node_t *current_node = head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    pthread_mutex_unlock(&lock);
}

void insert_at_index(int index, int data) {
    pthread_mutex_lock(&lock);
    if (index == 0) {
        insert_at_beginning(data);
    } else {
        node_t *new_node = malloc(sizeof(node_t));
        new_node->data = data;
        node_t *current_node = head;
        for (int i = 0; i < index - 1; i++) {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
    pthread_mutex_unlock(&lock);
}

void delete_at_beginning() {
    pthread_mutex_lock(&lock);
    if (head != NULL) {
        node_t *temp = head;
        head = head->next;
        free(temp);
    }
    pthread_mutex_unlock(&lock);
}

void delete_at_end() {
    pthread_mutex_lock(&lock);
    if (head != NULL) {
        if (head->next == NULL) {
            free(head);
            head = NULL;
        } else {
            node_t *current_node = head;
            while (current_node->next->next != NULL) {
                current_node = current_node->next;
            }
            free(current_node->next);
            current_node->next = NULL;
        }
    }
    pthread_mutex_unlock(&lock);
}

void delete_at_index(int index) {
    pthread_mutex_lock(&lock);
    if (index == 0) {
        delete_at_beginning();
    } else {
        node_t *current_node = head;
        for (int i = 0; i < index - 1; i++) {
            current_node = current_node->next;
        }
        node_t *temp = current_node->next;
        current_node->next = current_node->next->next;
        free(temp);
    }
    pthread_mutex_unlock(&lock);
}

void print_list() {
    pthread_mutex_lock(&lock);
    node_t *current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_mutex_init(&lock, NULL);
    insert_at_beginning(1);
    insert_at_end(2);
    insert_at_index(1, 3);
    print_list();
    delete_at_beginning();
    delete_at_end();
    delete_at_index(0);
    print_list();
    return 0;
}