//Falcon-180B DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int data;
    struct node* next;
} Node;

Node* createList(int arr[]) {
    Node* head = NULL;
    Node* tail = NULL;
    Node* newNode = NULL;

    for (int i = 0; i < SIZE; i++) {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void displayList(Node* head) {
    Node* temp = head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while (curr!= NULL) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

void writeToFile(Node* head, FILE* file) {
    Node* temp = head;

    while (temp!= NULL) {
        fprintf(file, "%d ", temp->data);
        temp = temp->next;
    }
}

Node* readFromFile(FILE* file) {
    int data;
    Node* head = NULL;
    Node* tail = NULL;
    Node* newNode = NULL;

    fscanf(file, "%d", &data);

    while (data!= -1) {
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        fscanf(file, "%d", &data);
    }

    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Node* head = createList(arr);
    displayList(head);
    reverseList(head);
    displayList(head);

    FILE* file = fopen("data.txt", "w");
    writeToFile(head, file);
    fclose(file);

    file = fopen("data.txt", "r");
    head = readFromFile(file);
    displayList(head);
    fclose(file);

    return 0;
}