//FormAI DATASET v1.0 Category: Data structures visualization ; Style: grateful
// Welcome to my Grateful C Data Structures Visualization Example Program!
// This program will demonstrate the implementation of various data structures using visualizations.
// Let's start by including the necessary libraries.

#include <stdio.h>
#include <stdlib.h>

// Let's first implement a stack data structure.

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

// Push function to add an element to the top of the stack.

void push(Stack *s, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop function to remove an element from the top of the stack.

int pop(Stack *s) {
    int data;
    Node *temp;

    if(s->top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    else {
        temp = s->top;
        data = temp->data;
        s->top = temp->next;
        free(temp);
        return data;
    }
}

// Display function to show the current state of the stack.

void display(Stack s) {
    Node *p;
    p = s.top;

    if(p == NULL) {
        printf("Stack is empty\n");
    }
    else {
        printf("Stack:\n");
        while(p != NULL) {
            printf("%d\n", p->data);
            p = p->next;
        }
    }
}

// Now, let's implement a queue data structure.

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

// Function to create an empty queue.

Queue* createQueue(int size) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)malloc(sizeof(int)*size);
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

// Function to add an element to the rear of the queue.

void enqueue(Queue *q, int data) {
    if(q->rear == q->size-1) {
        printf("Queue Overflow\n");
        return;
    }
    else {
        q->rear++;
        q->arr[q->rear] = data;

        if(q->front == -1) {
            q->front = 0;
        }
    }
}

// Function to remove an element from the front of the queue.

int dequeue(Queue *q) {
    int data;

    if(q->front == -1 || q->front > q->rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    else {
        data = q->arr[q->front];
        q->front++;
        return data;
    }
}

// Function to display the current state of the queue.

void displayQueue(Queue q) {
    int i;

    if(q.front == -1 || q.front > q.rear) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue: ");
        for(i=q.front; i<=q.rear; i++) {
            printf("%d ", q.arr[i]);
        }
        printf("\n");
    }
}

// Finally, let's implement a linked list data structure.

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

// Function to add an element to the end of the linked list.

void insertAtEnd(ListNode **head, int data) {
    ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->data = data;
    newNode->next = NULL;
    
    if(*head == NULL) {
        *head = newNode;
    }
    else {
        ListNode *temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to remove an element from the linked list.

void deleteNode(ListNode **head, int data) {
    ListNode *temp = *head, *prevNode = NULL;

    if(temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != data) {
        prevNode = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("%d not found in the list\n", data);
        return;
    }

    prevNode->next = temp->next;
    free(temp);
}

// Function to display the current state of the linked list.

void displayList(ListNode *head) {
    ListNode *temp = head;

    if(temp == NULL) {
        printf("List is empty\n");
    }
    else {
        printf("List: ");
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Now, let's test our implementations using some visualizations!

int main() {
    Stack s;
    s.top = NULL;

    Queue *q = createQueue(5);

    ListNode *head = NULL;

    int choice, data;

    do {
        printf("------- MENU -------\n");
        printf("1. Push to stack\n");
        printf("2. Pop from stack\n");
        printf("3. Enqueue to queue\n");
        printf("4. Dequeue from queue\n");
        printf("5. Insert to linked list\n");
        printf("6. Delete from linked list\n");
        printf("7. Display stack\n");
        printf("8. Display queue\n");
        printf("9. Display linked list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(&s, data);
                display(s);
                break;
            case 2:
                pop(&s);
                display(s);
                break;
            case 3:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(q, data);
                displayQueue(*q);
                break;
            case 4:
                dequeue(q);
                displayQueue(*q);
                break;
            case 5:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                displayList(head);
                break;
            case 6:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                displayList(head);
                break;
            case 7:
                display(s);
                break;
            case 8:
                displayQueue(*q);
                break;
            case 9:
                displayList(head);
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while(choice != 10);

    return 0;
}