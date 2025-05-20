//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char name[20];
    char email[50];
    struct node* next;
} Node;

Node* head = NULL;

void addToList(char* name, char* email) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printList() {
    Node* current = head;
    int i = 1;
    while(current != NULL) {
        printf("%d. %s --> %s\n", i, current->name, current->email);
        current = current->next;
        i++;
    }
}

void deleteFromList(char* name) {
    Node* current = head;
    Node* previous = NULL;

    while(current != NULL) {
        if(strcmp(current->name, name) == 0) {
            if(previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("%s not found in the mailing list!\n", name);
}

int main() {
    addToList("John Doe", "johndoe@gmail.com");
    addToList("Adam Smith", "asmith@yahoo.com");
    addToList("Jane Doe", "janedoe@hotmail.com");
    addToList("Bob Johnson", "bjohnson@gmail.com");

    printf("Initial List:\n");
    printList();

    printf("\nAfter deleting Jane Doe:\n");
    deleteFromList("Jane Doe");
    printList();

    printf("\nAfter adding Emily Lee:\n");
    addToList("Emily Lee", "elee@gmail.com");
    printList();

    return 0;
}