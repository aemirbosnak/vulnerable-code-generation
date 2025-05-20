//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
    return *head;
}

struct Node* insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return *head;
}

struct Node* deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    struct Node* del = NULL;

    while (temp!= NULL && temp->data!= key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return *head;
    }

    if (prev == NULL) {
        *head = temp->next;
        free(temp);
        return *head;
    }

    prev->next = temp->next;
    free(temp);
    return *head;
}

struct Node* searchNode(struct Node* head, int key) {
    struct Node* temp = head;

    while (temp!= NULL && temp->data!= key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return NULL;
    }

    return temp;
}

void display(struct Node* head) {
    struct Node* temp = head;

    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nMenu: \n1. Insert at Beginning \n2. Insert at End \n3. Delete Node \n4. Search Node \n5. Display Linked List \n6. Exit \nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to search: ");
                scanf("%d", &data);
                printf("Linked list after deletion: \n");
                head = deleteNode(&head, data);
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                printf("Linked list after search: \n");
                struct Node* temp = searchNode(head, data);
                if (temp!= NULL) {
                    printf("Node found: %d\n", temp->data);
                } else {
                    printf("Node not found\n");
                }
                break;
            case 5:
                printf("Linked list: \n");
                display(head);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice!= 6);

    return 0;
}