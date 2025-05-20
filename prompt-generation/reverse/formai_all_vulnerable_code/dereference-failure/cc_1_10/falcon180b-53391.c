//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
struct node {
    char data;
    int count;
    struct node* next;
};

void insertNode(struct node** head, char data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->count = 0;
    newNode->next = *head;
    *head = newNode;
}

void deleteNode(struct node** head, char data) {
    struct node* temp = *head;
    struct node* prev = NULL;

    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);
}

void printList(struct node* head) {
    while (head!= NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
}

int main() {
    FILE* file;
    char ch;
    int i = 0;
    struct node* head = NULL;

    // Open the file
    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the file and insert nodes into linked list
    while ((ch = fgetc(file))!= EOF) {
        insertNode(&head, ch);
        i++;
    }

    fclose(file);

    // Count the frequency of each character
    struct node* curr = head;
    while (curr!= NULL) {
        curr->count = i;
        curr = curr->next;
    }

    // Print the frequency of each character
    curr = head;
    while (curr!= NULL) {
        printf("%c : %d\n", curr->data, curr->count);
        curr = curr->next;
    }

    return 0;
}