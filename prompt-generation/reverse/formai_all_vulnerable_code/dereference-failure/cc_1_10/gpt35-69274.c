//FormAI DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* head = NULL;
int size = 0;

void insertAtBeginning(int value);
void insertAtEnd(int value);
void insertAtPosition(int value, int position);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int position);
void display();

int main() {
    printf("Welcome to the Amazing Linked List Operations Program!\n\n");
    
    while(1) {
        printf("Please choose an operation to perform:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Display list\n");
        printf("8. Exit\n\n");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                printf("\nEnter value to insert at beginning: ");
                int value;
                scanf("%d", &value);
                insertAtBeginning(value);
                printf("Value %d inserted at the beginning!\n\n", value);
                break;
            }
            case 2: {
                printf("\nEnter value to insert at end: ");
                int value;
                scanf("%d", &value);
                insertAtEnd(value);
                printf("Value %d inserted at the end!\n\n", value);
                break;
            }
            case 3: {
                printf("\nEnter value to insert: ");
                int value;
                scanf("%d", &value);
                
                printf("Enter position to insert at: ");
                int position;
                scanf("%d", &position);
                
                insertAtPosition(value, position);
                printf("Value %d inserted at position %d!\n\n", value, position);
                break;
            }
            case 4: {
                if(size == 0) {
                    printf("\nCannot delete from an empty list!\n\n");
                }
                else {
                    deleteAtBeginning();
                    printf("\nDeleted at beginning!\n\n");
                }
                break;
            }
            case 5: {
                if(size == 0) {
                    printf("\nCannot delete from an empty list!\n\n");
                }
                else {
                    deleteAtEnd();
                    printf("\nDeleted at end!\n\n");
                }
                break;
            }
            case 6: {
                if(size == 0) {
                    printf("\nCannot delete from an empty list!\n\n");
                }
                else {
                    printf("\nEnter position to delete at: ");
                    int position;
                    scanf("%d", &position);
                    
                    deleteAtPosition(position);
                    printf("\nDeleted at position %d!\n\n", position);
                }
                break;
            }
            case 7: {
                display();
                printf("\n");
                break;
            }
            case 8: {
                printf("\nThank you for using the Amazing Linked List Operations Program! Goodbye!\n");
                exit(0);
                break;
            }
            default: {
                printf("\nInvalid choice! Please try again!\n\n");
            }
        }
    }
    
    return 0;
}

void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    size++;
}

void insertAtEnd(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if(size == 0) {
        head = newNode;
    }
    else {
        struct Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

void insertAtPosition(int value, int position) {
    if(position < 1 || position > size+1) {
        printf("Invalid position!\n");
        return;
    }
    
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if(position == 1) {
        newNode->next = head;
        head = newNode;
    }
    else {
        struct Node* temp = head;
        int i;
        for(i = 1; i < position-1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    size++;
}

void deleteAtBeginning() {
    struct Node *temp = head;
    head = head->next;
    free(temp);
    size--;
}

void deleteAtEnd() {
    if(size == 1) {
        free(head);
        head = NULL;
    }
    else {
        struct Node *temp1 = head;
        struct Node *temp2 = head->next;
        while(temp2->next != NULL) {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = NULL;
        free(temp2);
    }
    size--;
}

void deleteAtPosition(int position) {
    if(position < 1 || position > size) {
        printf("Invalid position!\n");
        return;
    }
    
    if(position == 1) {
        deleteAtBeginning();
    }
    else if(position == size) {
        deleteAtEnd();
    }
    else {
        struct Node *temp1 = head;
        struct Node *temp2 = head->next;
        int i;
        for(i = 1; i < position-1; i++) {
            temp1 = temp2;
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        free(temp2);
        size--;
    }
}

void display() {
    if(size == 0) {
        printf("\nList is empty!\n");
    }
    else {
        struct Node *temp = head;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}