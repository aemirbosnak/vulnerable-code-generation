//FormAI DATASET v1.0 Category: Linked list operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    pthread_mutex_t mutex;
    Node* head;
    int size;
} List;

void initialize(List* list) {
    pthread_mutex_init(&list->mutex, NULL);
    list->head = NULL;
    list->size = 0;
}

void insert(List* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    pthread_mutex_lock(&list->mutex);
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
    pthread_mutex_unlock(&list->mutex);
}

void delete(List* list, int data) {
    pthread_mutex_lock(&list->mutex);
    Node* current_node = list->head;
    Node* previous_node = NULL;
    while (current_node != NULL && current_node->data != data) {
        previous_node = current_node;
        current_node = current_node->next;
    } 
    if (current_node == NULL) {
        printf("Node with data %d not found\n", data);
    }
    else {
        if (previous_node == NULL) {
            list->head = current_node->next;
        } 
        else {
            previous_node->next = current_node->next;
        }
        free(current_node);
        list->size--;
    }
    pthread_mutex_unlock(&list->mutex);
}

void display(List* list) {
    pthread_mutex_lock(&list->mutex);
    Node* current_node = list->head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
    pthread_mutex_unlock(&list->mutex);
}

void* thread_function_1(void* arg) {
    List* list = (List*)arg;
    for (int i = 1; i <= 5; i++) {
        insert(list, i*10);
        display(list);
    }
    return NULL;
}

void* thread_function_2(void* arg) {
    List* list = (List*)arg;
    for (int i = 1; i <= 2; i++) {
        delete(list, i*10);
        display(list);
    }
    return NULL;
}

int main() {
    List* list = (List*)malloc(sizeof(List));
    initialize(list);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, &thread_function_1, (void*)list);
    pthread_create(&thread2, NULL, &thread_function_2, (void*)list);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Final list: ");
    display(list);
    return 0;
}