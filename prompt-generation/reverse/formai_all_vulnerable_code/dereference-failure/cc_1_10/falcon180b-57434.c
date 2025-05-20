//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_NODES 1000

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct thread_data {
    int thread_id;
    Node *head;
} ThreadData;

Node *create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node *head) {
    Node *current = head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void *thread_function(void *data) {
    ThreadData *thread_data = (ThreadData *)data;
    Node *head = thread_data->head;
    int thread_id = thread_data->thread_id;

    Node *current = head;
    while (current!= NULL) {
        printf("Thread %d processing node %d\n", thread_id, current->data);
        current = current->next;
    }
}

int main() {
    Node *head = NULL;
    for (int i = 0; i < MAX_NODES; i++) {
        head = create_node(i);
    }

    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].head = head;
        pthread_create(&threads[i], NULL, thread_function, &thread_data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    print_list(head);

    return 0;
}