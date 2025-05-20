//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(Queue* q) {
    if(q->front == NULL)
        return 1;
    else
        return 0;
}

int isFull(Queue* q) {
    Node* temp = q->front;
    int count = 0;
    while(temp!= NULL) {
        count++;
        temp = temp->next;
    }
    if(count == MAX_SIZE)
        return 1;
    else
        return 0;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if(isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    int value = -1;
    
    if(!isEmpty(q)) {
        Node* temp = q->front;
        value = temp->data;
        q->front = temp->next;
        if(q->front == NULL)
            q->rear = NULL;
        free(temp);
    }
    return value;
}

void display(Queue* q) {
    Node* temp = q->front;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    int choice, value;
    
    do {
        printf("Enter your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the value to be enqueued:\n");
                scanf("%d", &value);
                enqueue(q, value);
                break;
            case 2:
                value = dequeue(q);
                if(value!= -1)
                    printf("The dequeued value is %d\n", value);
                break;
            case 3:
                display(q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(1);
    
    return 0;
}