//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char shape[20];
    struct Node* next;
} Node;

Node* createNode(const char* shape) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->shape, shape);
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, const char* shape) {
    Node* newNode = createNode(shape);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

void displayList(Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (node != NULL) {
        printf("Shape: %s\n", node->shape);
        node = node->next;
    }
}

void shapeShiftList(Node** head, const char* inputShape) {
    Node* current = *head;
    while (current != NULL) {
        if (strcmp(current->shape, inputShape) == 0) {
            if (strcmp(inputShape, "Triangle") == 0) {
                strcpy(current->shape, "Square");
            } else if (strcmp(inputShape, "Square") == 0) {
                strcpy(current->shape, "Circle");
            } else if (strcmp(inputShape, "Circle") == 0) {
                strcpy(current->shape, "Triangle");
            }
        }
        current = current->next;
    }
}

void deleteShape(Node** head, const char* shape) {
    Node* temp = *head;
    Node* prev = NULL;

    // If the head node itself holds the shape to be deleted
    while (temp != NULL && strcmp(temp->shape, shape) == 0) {
        *head = temp->next; // Changed head
        free(temp);         // Free old head
        temp = *head;       // Changed Temp
    }

    // Delete other occurrences
    while (temp != NULL) {
        while (temp != NULL && strcmp(temp->shape, shape) != 0) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) return; // If shape not found

        // Unlink the node
        prev->next = temp->next;
        free(temp); // Free memory
        temp = prev->next; // Move to the next node
    }
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    // Populate the linked list with shapes
    append(&head, "Triangle");
    append(&head, "Square");
    append(&head, "Circle");
    append(&head, "Triangle");
    
    printf("Original List:\n");
    displayList(head);

    // Let's shift shapes
    shapeShiftList(&head, "Triangle");
    printf("\nAfter Shape Shifting from Triangle:\n");
    displayList(head);

    // Now we delete squares
    deleteShape(&head, "Square");
    printf("\nAfter Deleting Squares:\n");
    displayList(head);

    // Clean up memory
    freeList(head);
    return 0;
}