//FormAI DATASET v1.0 Category: Data structures visualization ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    int size;
} List;

List *createList() {
    List *newList = malloc(sizeof(List));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

void addToList(List *list, int newData) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = newData;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

void printList(List *list) {
    Node *current = list->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    printf("Welcome to the Linked List Visualizer!\n\n");
    printf("We will be using a simple linked list data structure to visualize different operations performed on it.\n");
    printf("Let's start by creating an empty list.\n");

    List *list = createList();
    printList(list);

    printf("\nExcellent! Now let's add some elements to the list one by one.\n");
    addToList(list, 5);
    printList(list);
    addToList(list, 10);
    printList(list);
    addToList(list, 15);
    printList(list);

    printf("\nGreat! Now we have a list with three elements in it.\n");
    printf("Let's see what happens when we try to delete an element that isn't in the list.\n");

    Node *deleteNode = malloc(sizeof(Node));
    deleteNode->data = 20;
    deleteNode->next = NULL;

    Node *previous = NULL;
    Node *current = list->head;
    while (current != NULL && current->data != deleteNode->data) {
        previous = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("\nElement not found in list. Unable to delete.\n");
    } else {
        if (previous == NULL) {
            list->head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
        list->size--;
        printf("\nElement deleted successfully.\n");
        printList(list);
    }

    printf("\nNext, let's insert a new element into the list at a specified position.\n");
    printf("Here, we will insert the element 7 at position 2 in the list.\n");

    Node *newNode = malloc(sizeof(Node));
    newNode->data = 7;
    newNode->next = NULL;

    int position = 2;
    if (position < 0 || position > list->size) {
        printf("\nInvalid position. Unable to insert element.\n");
        free(newNode);
    } else if (position == 0) {
        newNode->next = list->head;
        list->head = newNode;
        list->size++;
        printf("\nElement inserted successfully.\n");
        printList(list);
    } else {
        Node *previous = NULL;
        Node *current = list->head;
        for (int i = 0; i < position; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = newNode;
        newNode->next = current;
        list->size++;
        printf("\nElement inserted successfully.\n");
        printList(list);
    }

    printf("\nFinally, let's delete the entire list.\n");

    Node *temp = list->head;
    while (temp != NULL) {
        free(temp);
        list->size--;
        temp = temp->next;
    }
    list->head = NULL;
    printf("\nList deleted successfully.\n");

    free(list);

    printf("\nThank you for using the Linked List Visualizer!\n");
    return 0;
}