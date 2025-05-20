//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function declarations
struct Node* createNode(int data);
struct Node* insertAtEnd(struct Node* head, int data);
struct Node* deleteNode(struct Node* head, int key);
void displayList(struct Node* head);
void freeList(struct Node* head);
struct Node* searchNode(struct Node* head, int key);
int lengthOfList(struct Node* head);

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, key;
    
    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert Node at End\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Search Node\n");
        printf("5. Length of List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter integer data to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                printf("Inserted %d into the list.\n", data);
                break;
                
            case 2:
                printf("Enter integer data to delete: ");
                scanf("%d", &key);
                head = deleteNode(head, key);
                break;
                
            case 3:
                displayList(head);
                break;

            case 4:
                printf("Enter integer data to search: ");
                scanf("%d", &key);
                struct Node* found = searchNode(head, key);
                if (found) {
                    printf("Node with data %d found in the list.\n", key);
                } else {
                    printf("Node with data %d not found in the list.\n", key);
                }
                break;

            case 5:
                printf("Length of the list: %d\n", lengthOfList(head));
                break;

            case 6:
                freeList(head);
                printf("Exiting... Memory freed.\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (!head) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to delete a node with a specific key
struct Node* deleteNode(struct Node* head, int key) {
    if (!head) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        printf("Deleted node with data %d from the list.\n", key);
        return head;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with data %d not found in the list.\n", key);
        return head;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted node with data %d from the list.\n", key);
    return head;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Contents of the list: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for a node in the list
struct Node* searchNode(struct Node* head, int key) {
    struct Node* temp = head;
    while (temp) {
        if (temp->data == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to return the length of the linked list
int lengthOfList(struct Node* head) {
    int length = 0;
    struct Node* temp = head;
    while (temp) {
        length++;
        temp = temp->next;
    }
    return length;
}

// Function to free the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}