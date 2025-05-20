//FormAI DATASET v1.0 Category: Linked list operations ; Style: distributed
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
} LinkedList;

// Initialize the linked list
LinkedList* initializeList(){
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Insert a node at the end of the linked list
void insertAtEnd(LinkedList *list, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

// Insert a node at the beginning of the linked list
void insertAtBeginning(LinkedList *list, int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    if(list->tail == NULL){
        list->tail = newNode;
    }
}

// Insert a node at a given index of the linked list
void insertAtIndex(LinkedList *list, int data, int index){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(index == 0){
        insertAtBeginning(list, data);
    } else {
        Node *current = list->head;
        int i;
        for(i=0; i<index-1; i++){
            current = current->next;
            if(current == NULL){
                printf("Invalid index! (Out of range)\n");
                return;
            }
        }
        newNode->next = current->next;
        current->next = newNode;
        if(newNode->next == NULL){
            list->tail = newNode;
        }
    }
}

// Delete a node from the linked list by data value
void deleteByData(LinkedList *list, int data){
    Node *current = list->head;
    Node *prev = NULL;
    while(current != NULL){
        if(current->data == data){
            if(prev == NULL){
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            if(current->next == NULL){
                list->tail = prev;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("%d not found in the list!\n", data);
}

// Delete a node from the linked list by index
void deleteByIndex(LinkedList *list, int index){
    if(index == 0){
        Node *toDelete = list->head;
        list->head = toDelete->next;
        if(list->tail == toDelete){
            list->tail = NULL;
        }
        free(toDelete);
    } else {
        Node *current = list->head;
        int i;
        for(i=0; i<index-1; i++){
            current = current->next;
            if(current == NULL){
                printf("Invalid index! (Out of range)\n");
                return;
            }
        }
        Node *toDelete = current->next;
        if(toDelete == NULL){
            printf("Invalid index! (Out of range)\n");
            return;
        }
        current->next = toDelete->next;
        if(toDelete == list->tail){
            list->tail = current;
        }
        free(toDelete);
    }
}

// Get the length of the linked list
int length(LinkedList *list){
    int len = 0;
    Node *current = list->head;
    while(current != NULL){
        len++;
        current = current->next;
    }
    return len;
}

// Get the data value of a node at a given index
int get(LinkedList *list, int index){
    Node *current = list->head;
    int i;
    for(i=0; i<index; i++){
        current = current->next;
        if(current == NULL){
            printf("Invalid index! (Out of range)\n");
            return -1;
        }
    }
    return current->data;
}

// Reverse the linked list
void reverse(LinkedList *list){
    Node *current = list->head;
    Node *prev = NULL;
    while(current != NULL){
        Node *temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    list->tail = list->head;
    list->head = prev;
}

// Print the linked list
void print(LinkedList *list){
    Node *current = list->head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    LinkedList *list = initializeList();
    insertAtEnd(list, 10);
    insertAtEnd(list, 20);
    insertAtEnd(list, 30);
    insertAtIndex(list, 15, 1);
    print(list);
    printf("Length of list: %d\n", length(list));
    printf("Data value at index 2: %d\n", get(list, 2));
    deleteByData(list, 20);
    print(list);
    deleteByIndex(list, 2);
    print(list);
    reverse(list);
    print(list);
    return 0;
}