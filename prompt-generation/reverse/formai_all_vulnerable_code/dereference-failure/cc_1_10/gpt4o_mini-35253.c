//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Creating a structure for linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void append(struct Node** head_ref, int new_data);
void printList(struct Node* node);
struct Node* reverseList(struct Node* head);
int countNodes(struct Node* head);
void insertAtPosition(struct Node** head_ref, int new_data, int position);
void freeList(struct Node* head);

// Entry point of the program
int main() {
    struct Node* head = NULL;
    int choice, data, position;
    
    printf("Welcome to the Linked List Puzzle Adventure!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Append a node\n");
        printf("2. Print the list\n");
        printf("3. Reverse the list\n");
        printf("4. Count nodes in the list\n");
        printf("5. Insert at a position\n");
        printf("6. Free the list memory\n");
        printf("7. Exit\n");
        printf("Choose an option (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to append: ");
                scanf("%d", &data);
                append(&head, data);
                printf("Node appended: %d\n", data);
                break;
                
            case 2:
                printf("Current List: ");
                printList(head);
                break;

            case 3:
                head = reverseList(head);
                printf("The list has been reversed!\n");
                break;

            case 4:
                printf("The list contains %d nodes.\n", countNodes(head));
                break;

            case 5:
                printf("Enter a number to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert (0 for head): ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                printf("Inserted %d at position %d.\n", data, position);
                break;

            case 6:
                freeList(head);
                head = NULL;
                printf("List memory freed!\n");
                break;

            case 7:
                printf("Exiting the Linked List Puzzle Adventure. Farewell!\n");
                freeList(head);
                break;

            default:
                printf("Invalid choice! Please select between (1-7).\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node at the end
void append(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
}

// Function to print the linked list
void printList(struct Node* node) {
    if (node == NULL) {
        printf("Empty List!\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    return prev; // New head
}

// Function to count nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to insert a new node at a given position
void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    struct Node* newNode = createNode(new_data);
    if (position == 0) {
        newNode->next = *head_ref;
        *head_ref = newNode;
        return;
    }
    struct Node* current = *head_ref;
    for (int i = 0; current != NULL && i < position - 1; i++)
        current = current->next;

    if (current == NULL) return; // Position is greater than the list length

    newNode->next = current->next;
    current->next = newNode;
}

// Function to free the linked list memory
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}