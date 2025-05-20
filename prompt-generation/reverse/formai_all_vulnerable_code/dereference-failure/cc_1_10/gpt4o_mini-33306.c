//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct LinkedList* createList() {
    struct LinkedList* list = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    list->head = NULL;
    return list;
}

void addNode(struct LinkedList* list, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void visualizeList(struct LinkedList* list) {
    struct Node* current = list->head;
    printf("Linked List Visualization:\n");
    printf("Head -> ");
    while (current != NULL) {
        printf("[%d] -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(struct LinkedList* list) {
    struct Node* current = list->head;
    struct Node* nextNode;
    
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    free(list);
}

struct Stack {
    struct LinkedList* list;
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->list = createList();
    return stack;
}

void push(struct Stack* stack, int data) {
    addNode(stack->list, data);
}

int pop(struct Stack* stack) {
    if (stack->list->head == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* topNode = stack->list->head;
    int poppedValue = topNode->data;
    stack->list->head = topNode->next;
    free(topNode);
    return poppedValue;
}

void visualizeStack(struct Stack* stack) {
    printf("Stack Visualization (Top to Bottom):\n");
    struct Node* current = stack->list->head;
    while (current != NULL) {
        printf("[%d]\n", current->data);
        current = current->next;
    }
}

int main() {
    struct LinkedList* myList = createList();
    addNode(myList, 10);
    addNode(myList, 20);
    addNode(myList, 30);
    
    visualizeList(myList);
    
    struct Stack* myStack = createStack();
    push(myStack, 5);
    push(myStack, 10);
    push(myStack, 15);
    
    visualizeStack(myStack);
    
    printf("Popping element: %d\n", pop(myStack));
    visualizeStack(myStack);
    
    printf("Popping element: %d\n", pop(myStack));
    printf("Popping element: %d\n", pop(myStack));
    printf("Popping element: %d\n", pop(myStack)); // Stack Underflow example
    
    freeList(myList);
    free(myStack->list);
    free(myStack);
    
    return 0;
}