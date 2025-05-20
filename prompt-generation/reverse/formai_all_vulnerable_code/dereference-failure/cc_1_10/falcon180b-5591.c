//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold our data
typedef struct {
    int data;
    struct node* next;
} node;

// Define a linked list
node* list = NULL;

// Define a function to insert data into the list
void insert(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (list == NULL) {
        list = newNode;
    } else {
        node* temp = list;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Define a function to search for data in the list
int search(int data) {
    node* temp = list;
    while (temp!= NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

// Define a function to print the list
void printList() {
    node* temp = list;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Insert some data into the list
    insert(5);
    insert(10);
    insert(15);

    // Print the list
    printList();

    // Search for data in the list
    int result = search(10);
    if (result == 1) {
        printf("Data found!\n");
    } else {
        printf("Data not found.\n");
    }

    return 0;
}