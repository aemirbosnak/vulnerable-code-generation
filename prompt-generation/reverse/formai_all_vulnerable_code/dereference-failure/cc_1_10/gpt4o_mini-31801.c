//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    pthread_mutex_t lock;
} LinkedList;

LinkedList *createList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    pthread_mutex_init(&list->lock, NULL);
    return list;
}

Node* createNode(int data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addNode(LinkedList *list, int data) {
    pthread_mutex_lock(&list->lock);
    Node *newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
    printf("Added %d to the list\n", data);
    pthread_mutex_unlock(&list->lock);
}

void removeNode(LinkedList *list, int data) {
    pthread_mutex_lock(&list->lock);
    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Removed %d from the list\n", data);
            pthread_mutex_unlock(&list->lock);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("%d not found in the list\n", data);
    pthread_mutex_unlock(&list->lock);
}

void displayList(LinkedList *list) {
    pthread_mutex_lock(&list->lock);
    Node *current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    pthread_mutex_unlock(&list->lock);
}

void* addNodes(void* arg) {
    LinkedList *list = (LinkedList*)arg;
    for (int i = 1; i <= 5; i++) {
        addNode(list, i);
        sleep(1); // simulate delay
    }
    return NULL;
}

void* removeNodes(void* arg) {
    LinkedList *list = (LinkedList*)arg;
    for (int i = 1; i <= 5; i++) {
        removeNode(list, i);
        sleep(2); // simulate delay
    }
    return NULL;
}

void* displayLinkedList(void* arg) {
    LinkedList *list = (LinkedList*)arg;
    for (int i = 0; i < 5; i++) {
        displayList(list);
        sleep(1); // simulate delay
    }
    return NULL;
}

int main() {
    LinkedList *list = createList();
    
    pthread_t addThread, removeThread, displayThread;

    pthread_create(&addThread, NULL, addNodes, (void*)list);
    pthread_create(&removeThread, NULL, removeNodes, (void*)list);
    pthread_create(&displayThread, NULL, displayLinkedList, (void*)list);

    pthread_join(addThread, NULL);
    pthread_join(removeThread, NULL);
    pthread_join(displayThread, NULL);

    // Clean up
    pthread_mutex_destroy(&list->lock);
    free(list);
    
    return 0;
}