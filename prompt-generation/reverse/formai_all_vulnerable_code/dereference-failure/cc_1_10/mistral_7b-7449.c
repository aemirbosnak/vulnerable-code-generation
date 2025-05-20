//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    char name[50];
    struct Node* next;
} Node;

Node* head = NULL;

void createList(int data, char name[]) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    strcpy(newNode->name, name);
    newNode->next = head;
    head = newNode;
}

void printList() {
    Node* temp = head;
    printf("\nList: \n");
    while (temp != NULL) {
        printf("Data: %d, Name: %s\n", temp->data, temp->name);
        temp = temp->next;
    }
}

bool find(int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data)
            return true;
        temp = temp->next;
    }
    return false;
}

Node* findNode(int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void delete(int data) {
    Node* temp = head, * prev;
    if (temp != NULL && temp->data == data) {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

int main() {
    int choice, data;
    char name[50];
    while (true) {
        printf("\n1. Create\n2. Print\n3. Find\n4. Delete\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter name: ");
                scanf("%s", name);
                createList(data, name);
                break;
            case 2:
                printList();
                break;
            case 3:
                printf("Enter data to find: ");
                scanf("%d", &data);
                if (find(data))
                    printf("Found!\n");
                else
                    printf("Not Found!\n");
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}