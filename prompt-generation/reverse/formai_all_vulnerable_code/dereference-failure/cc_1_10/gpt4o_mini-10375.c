//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Mysterious Linked List Node
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new Node 
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Puzzle 1: Add a Node to the End of the List
void addNodeEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref; 
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

// Puzzle 2: Print the Linked List
void printList(struct Node* node) {
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Puzzle 3: Reverse the Linked List
void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// Puzzle 4: Delete a Node by Key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; 

    prev->next = temp->next;
    free(temp);
}

// Puzzle 5: Find the Length of the List
int getLength(struct Node* head) {
    int length = 0;
    while (head) {
        length++;
        head = head->next;
    }
    return length;
}

// Puzzle 6: Insert a Node at a Specific Position
void insertAtPosition(struct Node** head_ref, int position, int new_data) {
    if (position < 1) {
        printf("Position must be greater than 0\n");
        return;
    }
    struct Node* new_node = createNode(new_data);
    if (position == 1) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* prev = *head_ref;
    for (int i = 1; (i < position - 1) && (prev != NULL); i++) {
        prev = prev->next;
    }
    if (prev == NULL) {
        printf("Position is greater than the length of the list\n");
        free(new_node);
        return;
    }
    
    new_node->next = prev->next;
    prev->next = new_node;
}

// Master of Puzzles: A Concocted Function to Resolve the Puzzles
void masterPuzzle(struct Node** head) {
    addNodeEnd(head, 10);
    addNodeEnd(head, 20);
    addNodeEnd(head, 30);
    printf("Adding elements: 10, 20, 30\n");
    printList(*head);
    
    printf("Reversing the list...\n");
    reverseList(head);
    printList(*head);
    
    printf("Length of list: %d\n", getLength(*head));
    
    deleteNode(head, 20);
    printf("Deleting node with value 20...\n");
    printList(*head);
    
    insertAtPosition(head, 2, 15);
    printf("Inserting 15 at position 2...\n");
    printList(*head);
}

// The Grand Finale: Execute the Grand Performance
int main() {
    struct Node* head = NULL; 
    masterPuzzle(&head);
    
    // Clean-up and empty the list
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    
    printf("All nodes freed. The show is over!\n");
    return 0;
}