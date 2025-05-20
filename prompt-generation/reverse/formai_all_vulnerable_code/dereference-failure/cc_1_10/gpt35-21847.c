//FormAI DATASET v1.0 Category: Linked list operations ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
    printf("%d inserted at the beginning.\n", data);
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("%d inserted at the end.\n", data);
}

void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
    } else if(position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* temp = *head;
        int count = 1;
        while(count < position-1 && temp->next != NULL) {
            temp = temp->next;
            count++;
        }
        if(count < position-1) {
            printf("Position out of range\n");
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("%d inserted at position %d.\n", data, position);
}

void deleteAtBeginning(Node** head) {
    if(*head == NULL) {
        printf("Linked list empty\n");
        return;
    }
    printf("%d deleted from the beginning.\n", (*head)->data);
    Node* temp = (*head)->next;
    free(*head);
    *head = temp;
}

void deleteAtEnd(Node** head) {
    if(*head == NULL) {
        printf("Linked list empty\n");
        return;
    } else if((*head)->next == NULL) {
        printf("%d deleted from the end.\n", (*head)->data);
        free(*head);
        *head = NULL;
    } else {
        Node* temp = *head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        printf("%d deleted from the end.\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteAtPosition(Node** head, int position) {
    if(*head == NULL) {
        printf("Linked list empty\n");
        return;
    } else if(position == 1) {
        printf("%d deleted from position %d.\n", (*head)->data, position);
        Node* temp = (*head)->next;
        free(*head);
        *head = temp;
    } else {
        Node* temp = *head;
        int count = 1;
        while(count < position-1 && temp->next != NULL) {
            temp = temp->next;
            count++;
        }
        if(count < position-1 || temp->next == NULL) {
            printf("Position out of range\n");
            return;
        }
        printf("%d deleted from position %d.\n", temp->next->data, position);
        Node* temp2 = temp->next->next;
        free(temp->next);
        temp->next = temp2;
    }
}

void traverse(Node* head) {
    if(head == NULL) {
        printf("Linked list empty\n");
    } else {
        printf("Linked list: ");
        while(head != NULL) {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    int choice, data, position;
    while(1) {
        printf("Choose an option:\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Traverse\n8. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                traverse(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}