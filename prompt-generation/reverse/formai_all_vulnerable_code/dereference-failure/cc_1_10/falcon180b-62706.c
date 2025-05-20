//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a person
typedef struct {
    char name[50];
    int age;
    float height;
} Person;

// Define a structure for a node in a linked list
typedef struct node {
    Person person;
    struct node* next;
} Node;

// Define a structure for a stack using linked lists
typedef struct stack {
    Node* top;
} Stack;

// Function to initialize an empty stack
void initStack(Stack* stack) {
    stack->top = NULL;
}

// Function to push a person onto the stack
void pushPerson(Stack* stack, Person person) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    newNode->person = person;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop a person from the stack
Person popPerson(Stack* stack) {
    Node* temp = stack->top;
    Person person;
    if (temp == NULL) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    person = temp->person;
    stack->top = temp->next;
    free(temp);
    return person;
}

// Function to display the contents of the stack
void displayStack(Stack* stack) {
    Node* current = stack->top;
    while (current!= NULL) {
        printf("Name: %s\nAge: %d\nHeight: %.2f\n", current->person.name, current->person.age, current->person.height);
        current = current->next;
    }
}

// Main function to test the stack implementation
int main() {
    Stack stack;
    initStack(&stack);

    Person person1 = {"John", 25, 1.80};
    Person person2 = {"Jane", 30, 1.65};
    Person person3 = {"Bob", 20, 1.90};

    pushPerson(&stack, person1);
    pushPerson(&stack, person2);
    pushPerson(&stack, person3);

    displayStack(&stack);

    Person poppedPerson = popPerson(&stack);
    printf("Popped person:\nName: %s\nAge: %d\nHeight: %.2f\n", poppedPerson.name, poppedPerson.age, poppedPerson.height);

    displayStack(&stack);

    return 0;
}