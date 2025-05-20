//FormAI DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Node structure definition
struct Node {
    char data[50];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char data[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end
void insertEnd(struct Node** head_ref, char data[]) {
    struct Node* newNode = createNode(data);
    if(*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* temp = *head_ref;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the list
void displayList(struct Node* head) {
    printf("\nPrinting linked list:\n");
    while(head != NULL) {
        printf("%s\n", head->data);
        head = head->next;
    }
}

// Function to delete a node at a given position
void deleteNode(struct Node** head_ref, int pos) {
    if(*head_ref == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    struct Node* temp = *head_ref;
    if(pos == 1) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for(int i=1; temp!=NULL && i<pos-1; i++) {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL) {
        printf("\nInvalid position!\n");
        return;
    }
    struct Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

// Main function
int main() {
    printf("Welcome to the Linked List operation program!\n");
    printf("We will be creating a linked list and performing some operations on it...\n");
    
    // Creating initial list
    struct Node* head = NULL;
    insertEnd(&head, "The");
    insertEnd(&head, "game");
    insertEnd(&head, "is");
    insertEnd(&head, "afoot");
    displayList(head);
    
    // Inserting a new node at the end
    printf("\nOh dear Watson, we have just obtained new evidence!\n");
    char newData[50];
    printf("What is the new evidence? ");
    scanf("%s", newData);
    insertEnd(&head, newData);
    displayList(head);
    
    // Deleting a node
    printf("\nOh no! It seems some of our evidence was tampered with...\n");
    int pos;
    printf("Watson, which node needs to be deleted? (Enter position) ");
    scanf("%d", &pos);
    deleteNode(&head, pos);
    displayList(head);
    
    printf("\nThat's it for today Watson! Until next time...\n");
    return 0;
}