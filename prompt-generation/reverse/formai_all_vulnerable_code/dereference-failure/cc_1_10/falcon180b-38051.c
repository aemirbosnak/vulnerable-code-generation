//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void delete_node(Node* node) {
    free(node);
}

void print_list(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void* add_node(void* arg) {
    Node** head_ref = (Node**)arg;
    Node* new_node = create_node(rand() % 100);
    pthread_mutex_lock((pthread_mutex_t*)head_ref);
    new_node->next = *head_ref;
    *head_ref = new_node;
    pthread_mutex_unlock((pthread_mutex_t*)head_ref);
    return NULL;
}

int main() {
    pthread_t threads[10];
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    Node* head = NULL;

    int i;
    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, add_node, &head);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    print_list(head);

    pthread_mutex_destroy(&mutex);
    return 0;
}