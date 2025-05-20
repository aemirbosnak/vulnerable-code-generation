//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top_ref, int new_data);
int pop(struct Node** top_ref);
int peek(struct Node* top);
int is_empty(struct Node* top);

int main() {
    // Initialize top of the stack
    struct Node* top = (struct Node*) malloc(sizeof(struct Node));
    top = NULL;

    int choice, value;

    do {
        printf("\n*** STACK OPERATIONS ***\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if stack is empty\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            }
            case 2: {
                value = pop(&top);
                if(value!= -1)
                    printf("Popped value is: %d\n", value);
                break;
            }
            case 3: {
                value = peek(top);
                if(value!= -1)
                    printf("Topmost value is: %d\n", value);
                break;
            }
            case 4: {
                if(is_empty(top))
                    printf("Stack is empty\n");
                else
                    printf("Stack is not empty\n");
                break;
            }
            case 5: {
                printf("Exiting...\n");
                exit(0);
            }
            default: {
                printf("Invalid choice! Please enter again.\n");
            }
        }
    } while(1);

    return 0;
}

// Function to push an element onto the stack
void push(struct Node** top_ref, int new_data) {
    // Create a new node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    // Check if the stack is full
    if(new_node == NULL) {
        printf("Stack overflow! Cannot push %d\n", new_data);
        return;
    }

    // Add data to the new node
    new_node->data = new_data;
    new_node->next = (*top_ref);

    // Move the top pointer to the new node
    (*top_ref) = new_node;
}

// Function to pop an element from the stack
int pop(struct Node** top_ref) {
    // Initialize variables
    int popped_value = -1;
    struct Node* temp = (*top_ref);

    // Check if the stack is empty
    if(temp == NULL)
        return -1;

    // Store the value of the topmost node
    popped_value = temp->data;

    // Move the top pointer to the next node
    (*top_ref) = temp->next;

    // Free the memory allocated to the popped node
    free(temp);

    return popped_value;
}

// Function to peek at the topmost element in the stack
int peek(struct Node* top) {
    // Check if the stack is empty
    if(top == NULL)
        return -1;

    // Return the value of the topmost node
    return top->data;
}

// Function to check if the stack is empty
int is_empty(struct Node* top) {
    // Check if the topmost node is NULL
    if(top == NULL)
        return 1;
    else
        return 0;
}