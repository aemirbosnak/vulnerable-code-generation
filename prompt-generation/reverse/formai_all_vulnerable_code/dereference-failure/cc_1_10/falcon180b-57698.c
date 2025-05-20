//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;
int count = 0;

void enqueue(int data) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    count++;
    printf("%d enqueued to the queue\n", data);
}

int dequeue() {
    int data;
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    node* temp = front;
    data = temp->data;
    front = front->next;
    free(temp);
    count--;
    printf("%d dequeued from the queue\n", data);
    return data;
}

int peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return front->data;
}

int is_empty() {
    return (front == NULL);
}

int size() {
    return count;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        node* temp = front;
        printf("Queue: ");
        while (temp!= NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    enqueue(90);
    display();
    printf("Size of the queue: %d\n", size());
    printf("Peek: %d\n", peek());
    dequeue();
    dequeue();
    display();
    printf("Size of the queue: %d\n", size());
    return 0;
}