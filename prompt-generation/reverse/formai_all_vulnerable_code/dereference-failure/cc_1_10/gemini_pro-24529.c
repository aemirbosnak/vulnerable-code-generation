//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Oho! A Queue! Who would've thunk it?
typedef struct Queue {
    int *elements;
    int front, rear, capacity;
} Queue;

// Wait, what? A function to create a Queue? How novel!
Queue *createQueue(int size) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->elements = (int*)malloc(size * sizeof(int));
    queue->front = -1;  // Watch out, kiddo, we start at -1 here!
    queue->rear = -1;
    queue->capacity = size;
    return queue;
}

// Woah, woah, woah! Enqueuing an element? You must be kidding me!
void enqueue(Queue *queue, int element) {
    if (queue->rear == queue->capacity - 1) {  // Oh noes, it's full!
        printf("Uh-oh, the Queue is full! Can't add %d.\n", element);
        return;
    } else if (queue->front == -1 && queue->rear == -1) {  // Queue is empty, let's fix that
        queue->front = queue->rear = 0;  // Set both to 0, it's all good
    } else {  // All good, let's add it to the rear
        queue->rear++;
    }
    queue->elements[queue->rear] = element;  // And don't forget to add the element!
}

// Hold yer horses there, cowboy! Dequeuing an element? Are you sure?
int dequeue(Queue *queue) {
    if (queue->front == -1) {  // Ouch, it's empty!
        printf("Oops, the Queue is empty! Nothing to dequeue.\n");
        return -1;
    } else if (queue->front == queue->rear) {  // Only one element left, let's clean up
        int element = queue->elements[queue->front];
        queue->front = queue->rear = -1;  // Reset the Queue
        return element;
    } else {  // More than one element, just remove the front one
        int element = queue->elements[queue->front];
        queue->front++;
        return element;
    }
}

// Hey there, slick! Peep the front element, if you dare
int peek(Queue *queue) {
    if (queue->front == -1) {  // Oops, it's empty!
        printf("Hold yer horses there, partner! The Queue is empty!\n");
        return -1;
    } else {  // All good, show me what you got
        return queue->elements[queue->front];
    }
}

// Hold your breath, it's time to see if the Queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1;  // If front is -1, it's empty, 'nuff said
}

// Are you ready for the big reveal? Let's see if the Queue is full
int isFull(Queue *queue) {
    return queue->rear == queue->capacity - 1;  // If rear is at the end, it's full, case closed
}

// To print or not to print, that is the question!
void printQueue(Queue *queue) {
    if (isEmpty(queue)) {  // If it's empty, don't bother me
        printf("Howdy there, the Queue is empty as a ghost town.\n");
    } else {  // If it's not empty, show me what you got
        printf("Yo, check out this Queue: ");
        for (int i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->elements[i]);
        }
        printf("\nNice, huh?\n");
    }
}

// And here's the main event, folks! Let's put this Queue through its paces
int main() {
    printf("Welcome to the Queue-a-palooza!\n");
    Queue *queue = createQueue(5);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);  // Oops, it's full!
    printQueue(queue);
    printf("Peek-a-boo! Front element: %d\n", peek(queue));
    int dequeued = dequeue(queue);
    printf("Howdy, I'm the element that just got dequeued: %d\n", dequeued);
    dequeued = dequeue(queue);
    printf("And here's another one: %d\n", dequeued);
    enqueue(queue, 60);
    printQueue(queue);
    if (isFull(queue)) {
        printf("Whoa there, partner! The Queue is full as a tick!\n");
    }
    if (isEmpty(queue)) {
        printf("Hold yer horses! The Queue is as empty as a desert.\n");
    } else {
        printf("Nope, the Queue is still kickin'.\n");
    }
    dequeued = dequeue(queue);
    dequeued = dequeue(queue);
    dequeued = dequeue(queue);
    dequeued = dequeue(queue);
    printf("Hold yer breath, I'm gonna dequeue 'em all!\n");
    dequeued = dequeue(queue);  // Oops, it's empty!
    return 0;
}