//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void push(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    pthread_mutex_lock(&lock);
    if (head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    pthread_mutex_unlock(&lock);
}

void pop() {
    pthread_mutex_lock(&lock);
    if (head == NULL) {
        printf("List is empty\n");
        pthread_mutex_unlock(&lock);
        return;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    pthread_mutex_unlock(&lock);
}

void print_list() {
    pthread_mutex_lock(&lock);
    Node* temp = head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    pthread_mutex_unlock(&lock);
}

void* thread_push(void* arg) {
    int data = *(int*) arg;
    push(data);
    return NULL;
}

void* thread_pop(void* arg) {
    pop();
    return NULL;
}

void* thread_print(void* arg) {
    print_list();
    return NULL;
}

int main() {
    pthread_t push_thread, pop_thread, print_thread;

    int push_data = 1;
    pthread_create(&push_thread, NULL, thread_push, &push_data);

    int pop_data = 2;
    pthread_create(&pop_thread, NULL, thread_pop, &pop_data);

    int print_data = 3;
    pthread_create(&print_thread, NULL, thread_print, &print_data);

    pthread_join(push_thread, NULL);
    pthread_join(pop_thread, NULL);
    pthread_join(print_thread, NULL);

    return 0;
}