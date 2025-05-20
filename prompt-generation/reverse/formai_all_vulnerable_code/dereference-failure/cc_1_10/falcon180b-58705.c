//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Node structure for linked list
typedef struct node {
    char name[50];
    char email[100];
    struct node* next;
} Node;

//Function to add a new node at the end of the list
void addNode(Node** head, char* name, char* email) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while(temp->next!= NULL)
        temp = temp->next;

    temp->next = newNode;
}

//Function to search for a node with given email
Node* searchNode(Node* head, char* email) {
    Node* temp = head;
    while(temp!= NULL) {
        if(strcmp(temp->email, email) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

//Function to delete a node with given email
void deleteNode(Node** head, char* email) {
    Node* temp = *head;
    Node* prev = NULL;

    if(strcmp(temp->email, email) == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && strcmp(temp->email, email)!= 0) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

//Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while(temp!= NULL) {
        printf("%s - %s\n", temp->name, temp->email);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    //Add nodes
    addNode(&head, "John Doe", "johndoe@example.com");
    addNode(&head, "Jane Smith", "janesmith@example.com");
    addNode(&head, "Alice Johnson", "alicejohnson@example.com");

    //Print list
    printList(head);

    //Search for a node
    Node* foundNode = searchNode(head, "janesmith@example.com");
    if(foundNode!= NULL)
        printf("Found node: %s - %s\n", foundNode->name, foundNode->email);
    else
        printf("Node not found.\n");

    //Delete a node
    deleteNode(&head, "janesmith@example.com");

    //Print list after deletion
    printList(head);

    return 0;
}