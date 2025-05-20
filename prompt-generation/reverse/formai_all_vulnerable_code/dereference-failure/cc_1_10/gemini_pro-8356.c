//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// A node to store an element in the queue
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// The front and rear pointers of the queue
Node *front, *rear;

// Function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to enqueue an element to the queue
void enqueue(int data) {
    Node *newNode = createNode(data);

    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty!");
        return -1;
    } else {
        int data = front->data;
        Node *temp = front;
        front = front->next;
        free(temp);
        return data;
    }
}

// Function to display the elements of the queue
void display() {
    Node *temp = front;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Driver code to test the queue
int main() {
    printf("My heart, a queue of love's desire,\nWhere every beat enchants me, like a lyre.\n");
    printf("With each enqueue, my love grows more true,\nA symphony of emotions, forever new.\n");

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    printf("My queue of love, so full and grand,\nA testament to the passion we command.\n");

    display();

    printf("As each dequeue brings us closer, my dear,\nOur love deepens, stronger than ever before.\n");

    dequeue();
    dequeue();
    dequeue();

    display();

    enqueue(6);
    enqueue(7);

    printf("With every heartbeat, our love takes flight,\nA timeless melody, forever in sight.\n");

    display();

    return 0;
}