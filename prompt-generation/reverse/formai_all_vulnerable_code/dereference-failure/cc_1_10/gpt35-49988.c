//FormAI DATASET v1.0 Category: Queue Implementation ; Style: funny
/* Welcome to the Circus Queue Implementation! */
#include <stdio.h>
#include <stdlib.h>

#define MAX_CIRCUS_QUEUES 3
#define MAX_CIRCUS_ANIMALS 10

/* Our circus animals need some extra flair */
typedef struct Animal {
    char name[10];
    int tricks;
} Animal;

/* Our Circus Queue */
typedef struct CircusQueue {
    int front;
    int rear;
    int size;
    Animal animals[MAX_CIRCUS_ANIMALS];
} CircusQueue;

/* CREATING NEW CIRCUS QUEUE */
CircusQueue* createCircusQueue() {
    CircusQueue* queue = (CircusQueue*) malloc(sizeof(CircusQueue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    printf("Welcome to the Circus Queue!\n");
    return queue;
}

/* ENQUEUE AN ANIMAL (SHOWTIME!) */
void enqueue(Animal animal, CircusQueue* queue) {
    if (queue->size == MAX_CIRCUS_ANIMALS) {
        printf("Circus is full. No more animals allowed. Try again next time!\n");
        return;
    }
  
    if (queue->front == -1) { 
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_CIRCUS_ANIMALS;
    }
    queue->animals[queue->rear] = animal;
    printf("%s the %d-circus-trick %s has joined the queue!\n", animal.name, animal.tricks, (animal.tricks==1)?"animal":"animals");
    queue->size++;
}

/* DEQUEUE THE FRONT ANIMAL (GOODBYE!) */
void dequeue(CircusQueue* queue) {
    if (queue->size == 0) {
        printf("The circus queue is empty. Nothing to remove!\n");
        return;
    }
    int front = queue->front;
    printf("%s the %d-circus-trick %s has completed their act and left the circus!\n", queue->animals[front].name, queue->animals[front].tricks, (queue->animals[front].tricks==1)?"animal":"animals");
    queue->front = (queue->front + 1) % MAX_CIRCUS_ANIMALS;
    queue->size--;
}

/* SHOW THE FRONT ANIMAL */
void showFrontAnimal(CircusQueue* queue) {
    if (queue->size == 0) {
        printf("The circus queue is empty. Nothing to show the audience!\n");
        return;
    }
    printf("Welcome to the circus! The next performer is %s the %d-circus-trick %s!\n", queue->animals[queue->front].name, queue->animals[queue->front].tricks, (queue->animals[queue->front].tricks==1)?"animal":"animals");
}

int main() {
    CircusQueue* queue = createCircusQueue();

    Animal animal1 = {"Bubbles", 2};
    Animal animal2 = {"Hercules", 5};
    Animal animal3 = {"Mimi", 1};

    enqueue(animal1, queue);
    enqueue(animal2, queue);
    enqueue(animal3, queue);

    dequeue(queue);
    dequeue(queue);

    showFrontAnimal(queue);

    Animal animal4 = {"Buddy", 3};
    Animal animal5 = {"Pinky", 4};

    enqueue(animal4, queue);
    enqueue(animal5, queue);

    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    
    return 0;
}