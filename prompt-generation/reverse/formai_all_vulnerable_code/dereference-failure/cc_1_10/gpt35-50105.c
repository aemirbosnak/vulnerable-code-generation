//FormAI DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// define the structure of list
typedef struct node {
    int data;
    struct node *next;
} Node; 

// create a new empty list
Node* createList() {
    return NULL;
}

// check if the list is empty
int isEmpty(Node *root) {
    return root == NULL;
}

// add a new node to the list
Node* addNode(Node *root, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = root;
    return newNode;
}

// get the size of list
int getSize(Node *root) {
    int size = 0;
    Node *temp = root;
    while(temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

// remove a node from the list
Node* removeNode(Node *root, int data) {
    Node *temp = root;
    Node *prev = NULL;
    while(temp != NULL) {
        if(temp->data == data) {
            if(prev != NULL) {
                prev->next = temp->next;
                free(temp);
                return root;
            }
            else {
                Node *next = temp->next;
                free(temp);
                return next;
            }
        }
        prev = temp;
        temp = temp->next;
    }
    return root;
}

// print the list
void printList(Node *root) {
    printf("List: ");
    Node *temp = root;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// reverse the list
Node* reverseList(Node *root) {
    Node *prev = NULL;
    Node *current = root;
    Node *next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// main function
int main() {

    Node *root = createList();

    root = addNode(root, 1);
    root = addNode(root, 2);
    root = addNode(root, 3);
    root = addNode(root, 4);

    printf("Size of List: %d \n", getSize(root));
    printList(root);

    root = removeNode(root, 3);
    printf("Size of List: %d \n", getSize(root));
    printList(root);
   
    root = reverseList(root);
    printList(root);

    return 0;
}