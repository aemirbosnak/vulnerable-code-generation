//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define QUEUE_SIZE 5

typedef struct Person {
    char name[NAME_LENGTH];
    int age;
} Person;

typedef struct Queue {
    Person *people[QUEUE_SIZE];
    int front;
    int rear;
    int count;
} Queue;

// Function prototypes
Queue *createQueue();
int isFull(Queue *q);
int isEmpty(Queue *q);
void enqueue(Queue *q, Person *p);
Person *dequeue(Queue *q);
Person *createPerson(const char *name, int age);
void displayQueue(Queue *q);
void freeQueue(Queue *q);

int main() {
    Queue *queue = createQueue();

    // Enqueue Persons
    enqueue(queue, createPerson("Alice", 30));
    enqueue(queue, createPerson("Bob", 25));
    enqueue(queue, createPerson("Charlie", 35));
    enqueue(queue, createPerson("David", 22));
    enqueue(queue, createPerson("Eve", 28));

    // Display queue
    printf("Queue after enqueuing 5 persons:\n");
    displayQueue(queue);

    // Dequeue a person
    printf("\nDequeuing a person:\n");
    Person *p = dequeue(queue);
    if (p != NULL) {
        printf("Dequeued: %s, Age: %d\n", p->name, p->age);
        free(p);
    }

    // Display queue after one dequeue
    printf("\nQueue after dequeuing one person:\n");
    displayQueue(queue);

    // Free the queue
    freeQueue(queue);
    return 0;
}

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    q->count = 0;
    return q;
}

int isFull(Queue *q) {
    return q->count == QUEUE_SIZE;
}

int isEmpty(Queue *q) {
    return q->count == 0;
}

void enqueue(Queue *q, Person *p) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %s.\n", p->name);
        free(p);
        return;
    }
    q->people[q->rear] = p;
    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->count++;
}

Person *dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return NULL;
    }
    Person *p = q->people[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;
    q->count--;
    return p;
}

Person *createPerson(const char *name, int age) {
    Person *p = (Person *)malloc(sizeof(Person));
    strncpy(p->name, name, NAME_LENGTH);
    p->age = age;
    return p;
}

void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("People in Queue:\n");
    int i;
    for (i = 0; i < q->count; i++) {
        int index = (q->front + i) % QUEUE_SIZE;
        printf("%s, Age: %d\n", q->people[index]->name, q->people[index]->age);
    }
}

void freeQueue(Queue *q) {
    while (!isEmpty(q)) {
        Person *p = dequeue(q);
        free(p);
    }
    free(q);
}