//FormAI DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char email[100];
    struct Node* next;
} Node;

typedef struct List{
    Node* head;
    int size;
} List;

void init(List* list){
    list->head = NULL;
    list->size = 0;
}

int isEmpty(List* list){
    return (list->size == 0);
}

void insert(List* list, char* email){
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if (list->head == NULL){
        list->head = newNode;
    }
    else{
        Node* cur = list->head;
        while (cur->next != NULL){
            cur = cur->next;
        }
        cur->next = newNode;
    }
    list->size++;
}

void removeEmail(List* list, char* email){
    if (isEmpty(list)){
        printf("List is empty\n");
        return;
    }

    Node* cur = list->head;
    Node* prev = NULL;

    while (cur != NULL && strcmp(cur->email, email) != 0){
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL){
        printf("Email not found\n");
        return;
    }
    if (prev == NULL){ // deleting the head
        list->head = cur->next;
    }
    else{
        prev->next = cur->next;
    }
    free(cur);
    list->size--;
}

void printList(List* list){
    if (isEmpty(list)){
        printf("List is empty\n");
        return;
    }
    Node* cur = list->head;
    while (cur != NULL){
        printf("%s\n", cur->email);
        cur = cur->next;
    }
}

int main(){
    List list;
    init(&list);

    insert(&list, "example1@example.com");
    insert(&list, "example2@example.com");
    insert(&list, "example3@example.com");
    insert(&list, "example4@example.com");
    
    printf("The mailing list:\n");
    printList(&list);

    printf("\nDeleting example2@example.com:\n");
    removeEmail(&list, "example2@example.com");

    printf("\nThe mailing list after deletion:\n");
    printList(&list);

    return 0;
}