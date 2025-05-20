//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 50
#define DATA_TYPE float

typedef struct Node {
    DATA_TYPE data;
    int next;
} Node;

typedef struct List {
    Node* nodes;
    int length;
} List;

void printList(List* list) {
    int i;
    printf("List size: %d\n", list->length);
    for (i = 0; i < list->length; i++) {
        printf("Element %d: %f\n", i, list->nodes[i].data);
    }
}

void push(List* list, DATA_TYPE data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->length;

    list->length++;
    list->nodes = (Node*) realloc(list->nodes, (list->length + 1) * sizeof(Node));

    list->nodes[list->length - 1] = *newNode;
}

List createList() {
    List list;
    list.nodes = (Node*) malloc(SIZE * sizeof(Node));
    list.length = 0;
    return list;
}

int main() {
    List myList = createList();

    int i;
    for (i = 0; i < 10; i++) {
        push(&myList, (DATA_TYPE) (rand() % 100));
    }

    printf("List before sharing:\n");
    printList(&myList);

    key_t key = 5678;
    int shmid = shmget(key, sizeof(List), IPC_CREAT | 0666);
    List* sharedList = (List*) shmat(shmid, NULL, 0);

    *sharedList = myList;

    printf("\nList after sharing:\n");
    printList(sharedList);

    shmdt(sharedList);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}