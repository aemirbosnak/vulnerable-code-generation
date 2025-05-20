//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

/* Define a struct for the node of the Linked List */
struct Node {
    int data;
    struct Node* next;
};

/* Define a struct for the Linked List */
struct List {
    struct Node* head;
    int size;
};

/* Function to create a Linked List */
struct List* createList() {
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->head = NULL;
    list->size = 0;
    return list;
}

/* Function to insert an element at the beginning of the Linked List */
void insertAtBeginning(struct List* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

/* Function to insert an element at the end of the Linked List */
void insertAtEnd(struct List* list, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (list->size == 0) {
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

/* Function to delete an element from the Linked List */
void deleteElement(struct List* list, int data) {
    if (list->size == 0) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = list->head;
    if (temp->data == data) {
        struct Node* temp2 = temp->next;
        free(temp);
        list->head = temp2;
        list->size--;
        return;
    }

    while (temp->next!= NULL) {
        if (temp->next->data == data) {
            struct Node* temp2 = temp->next;
            struct Node* temp3 = temp2->next;
            free(temp2);
            temp->next = temp3;
            list->size--;
            return;
        }
        temp = temp->next;
    }

    printf("Element not found in the list!\n");
}

/* Function to search for an element in the Linked List */
int searchElement(struct List* list, int data) {
    struct Node* temp = list->head;
    int found = 0;

    while (temp!= NULL) {
        if (temp->data == data) {
            found = 1;
            break;
        }
        temp = temp->next;
    }

    return found;
}

/* Function to print the elements of the Linked List */
void printList(struct List* list) {
    struct Node* temp = list->head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct List* list = createList();

    /* Insert elements at the beginning and end of the Linked List */
    insertAtBeginning(list, 5);
    insertAtEnd(list, 10);
    insertAtEnd(list, 15);

    /* Print the elements of the Linked List */
    printList(list);

    /* Delete the element 5 from the Linked List */
    deleteElement(list, 5);

    /* Print the elements of the Linked List after deletion */
    printList(list);

    /* Search for the element 15 in the Linked List */
    int found = searchElement(list, 15);

    if (found == 1) {
        printf("Element found in the list!\n");
    } else {
        printf("Element not found in the list!\n");
    }

    /* Free the memory allocated for the Linked List */
    free(list->head);
    free(list);

    return 0;
}