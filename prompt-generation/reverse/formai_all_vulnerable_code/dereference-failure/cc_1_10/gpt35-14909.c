//FormAI DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    pthread_mutex_t lock;
} LinkedList;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

LinkedList* create_linked_list() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    pthread_mutex_init(&list->lock, NULL);
    return list;
}

void push_front(LinkedList* list, int data) {
    Node* new_node = create_node(data);
    pthread_mutex_lock(&list->lock);
    new_node->next = list->head;
    list->head = new_node;
    pthread_mutex_unlock(&list->lock);
}

void push_back(LinkedList* list, int data) {
    Node* new_node = create_node(data);
    pthread_mutex_lock(&list->lock);
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    pthread_mutex_unlock(&list->lock);
}

void remove_node(LinkedList* list, int data) {
    pthread_mutex_lock(&list->lock);
    if (list->head == NULL) {
        printf("List Empty\n");
        pthread_mutex_unlock(&list->lock);
        return;
    } 
    if (list->head->data == data) {
        Node* old_head = list->head;
        list->head = list->head->next;
        free(old_head);
        pthread_mutex_unlock(&list->lock);
        return;
    }
    Node* current = list->head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            Node* to_delete = current->next;
            current->next = to_delete->next;
            free(to_delete);
            pthread_mutex_unlock(&list->lock);
            return;
        }
        current = current->next;
    }
    printf("Data not found\n");
    pthread_mutex_unlock(&list->lock);
}

void print(LinkedList* list) {
    printf("List Contents: ");
    pthread_mutex_lock(&list->lock);
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    pthread_mutex_unlock(&list->lock);
}

void* push_front_thread(void* args) {
    LinkedList* list = (LinkedList*)args;
    for (int i = 0; i < 5; i++) {
        push_front(list, i);
    }
    return NULL;
}

void* push_back_thread(void* args) {
    LinkedList* list = (LinkedList*)args;
    for (int i = 0; i < 5; i++) {
        push_back(list, i+5);
    }
    return NULL;
}

void* remove_node_thread(void* args) {
    LinkedList* list = (LinkedList*)args;
    for (int i = 0; i < 5; i++) {
        remove_node(list, i+2);
    }
    return NULL;
}

int main(void) {
    LinkedList* list = create_linked_list();
    pthread_t push_front_tid, push_back_tid, remove_node_tid;

    pthread_create(&push_front_tid, NULL, push_front_thread, list);
    pthread_create(&push_back_tid, NULL, push_back_thread, list);
    pthread_create(&remove_node_tid, NULL, remove_node_thread, list);

    pthread_join(push_front_tid, NULL);
    pthread_join(push_back_tid, NULL);
    pthread_join(remove_node_tid, NULL);

    print(list);

    pthread_mutex_destroy(&list->lock);
    free(list);
    return 0;
}