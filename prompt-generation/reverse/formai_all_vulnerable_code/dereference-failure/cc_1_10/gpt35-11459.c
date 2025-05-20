//FormAI DATASET v1.0 Category: Data structures visualization ; Style: scientific
/*
    This program implements the Stack data structure as a linked list, 
    and visualizes the changes in the structure as elements are pushed 
    and popped from the stack.
*/

#include <stdio.h>
#include <stdlib.h>

// Define the Stack node
struct Node {
    int data;
    struct Node* next;
};

// Initialize an empty stack
struct Node* top = NULL;

// Push function to add elements to the stack
void push(int num) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = top;
    top = newNode;
    
    // Visualization of the Stack after push operation
    printf("\n---------------------\n");
    printf("|  Pushed %d to the Stack  |\n", num);
    printf("---------------------\n");
    struct Node* current = top;
    while(current != NULL) {
        printf("|          %d          |\n", current->data);
        printf("---------------------\n");
        current = current->next;
    }
}

// Pop function to remove and return the top element of the stack
int pop() {
    if(top == NULL) {
        printf("\nStack Underflow Error!\n");
        return -1;
    }
    else {
        int num = top->data;
        struct Node* temp = top;
        top = top->next;
        free(temp);
        
        // Visualization of the Stack after pop operation
        printf("\n---------------------\n");
        printf("|  Popped %d from the Stack  |\n", num);
        printf("---------------------\n");
        struct Node* current = top;
        while(current != NULL) {
            printf("|          %d          |\n", current->data);
            printf("---------------------\n");
            current = current->next;
        }
        
        return num;
    }
}

// Main function to initialize and test the Stack data structure
int main() {
    // Push elements to the stack
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    
    // Pop elements from the stack
    pop();
    pop();
    pop();
    pop();
    pop();
    
    return 0;
}