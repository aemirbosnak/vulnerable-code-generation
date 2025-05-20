//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_FLOOR 10    // Maximum number of floors in the building
#define MAX_PERSONS 5   // Maximum number of people in elevator

/* enum for directions */
enum direction {
    UP, DOWN
};

/* Person struct */
typedef struct {
    int id;         // Unique ID of the person
    int floor;      // Floor where the person is going
    enum direction dir;      // Direction the person is heading in
} Person;

/* Elevator struct */
typedef struct {
    int currentFloor;       // Current floor of the elevator
    int numPersons;         // Number of persons in the elevator
    Person persons[MAX_PERSONS];    // Array of Persons in the elevator
    enum direction dir;     // Direction of elevator
} Elevator;

/* Queue struct */
typedef struct Queue {
    int front, rear;
    unsigned capacity;
    Person* array;
} Queue;

/* Create a new queue */
Queue* createQueue(unsigned capacity) {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (Person*) malloc(queue->capacity * sizeof(Person));
    return queue;
}

/* Check if queue is full */
bool isFull(Queue* queue) {
    return ((queue->rear+1) % queue->capacity == queue->front);
}

/* Check if queue is empty */
bool isEmpty(Queue* queue) {
    return (queue->front == -1);
}

/* Add Person to the queue */
void enqueue(Queue* queue, Person p) {
    if(isFull(queue)) {
        return;
    }
    if(isEmpty(queue)) {
        queue->front = 0; 
    }
    queue->rear = (queue->rear+1) % queue->capacity;
    queue->array[queue->rear] = p;
}

/* Remove Person from the queue */
Person dequeue(Queue* queue) {
    if(isEmpty(queue)) {
        Person p;
        p.id = -1;
        return p;
    } else {
        Person p = queue->array[queue->front];
        if(queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front+1) % queue->capacity;
        }
        return p;
    }
}

/* Elevator struct pointer */
Elevator* newElevator(int currentFloor) {
    Elevator* e = (Elevator*) malloc(sizeof(Elevator));
    e->currentFloor = currentFloor;
    e->numPersons = 0;
    return e; 
}

/* Movement of the elevator */
void moveElevator(Elevator* e) {
    if(e->dir == UP) {
        e->currentFloor++;
    } else {
        e->currentFloor--;
    } 
    printf("Elevator at floor %d\n", e->currentFloor);
}

/* Move elevator to next floor */
void moveNextFloor(Elevator* e, Queue** queues) {
    if(e->dir == UP) {
        if(!isEmpty(queues[e->currentFloor]->front)) {
            Person p = dequeue(queues[e->currentFloor]);
            e->persons[e->numPersons++] = p;
            printf("Person %d enters the elevator at floor %d\n", p.id, e->currentFloor);
        }
    } else {
        for(int i = 0; i < e->numPersons; i++) {
            if(e->persons[i].floor == e->currentFloor) {
                printf("Person %d exits the elevator at floor %d\n", e->persons[i].id, e->currentFloor);
                e->persons[i--] = e->persons[--e->numPersons];
            }
        }
    }
    moveElevator(e);
    if(e->currentFloor == MAX_FLOOR) {
        e->dir = DOWN;
    } else if(e->currentFloor == 0) {
        e->dir = UP;
    }
}

/* Generate random direction */
enum direction randomDirection() {
    if(rand()%2 == 0) {
        return UP;
    } else {
        return DOWN;
    }
}

/* Generate random floor */
int randomFloor() {
    return rand()%MAX_FLOOR;
}

int main() {
    /* Seed for random number generator */
    srand(time(NULL));

    /* Create array of queues */
    Queue* queues[MAX_FLOOR];
    for(int i = 0; i < MAX_FLOOR; i++) {
        queues[i] = createQueue(MAX_PERSONS);
    }

    /* Create elevator */
    Elevator* elevator = newElevator(randomFloor());

    /* Create and add people to queues */
    for(int i = 0; i < MAX_FLOOR*MAX_PERSONS; i++) {
        Person p;
        p.id = i;
        p.floor = randomFloor();
        p.dir = randomDirection();
        enqueue(queues[p.floor], p);
    }

    /* Move elevator to next floor */
    printf("Elevator starting at floor %d\n", elevator->currentFloor);
    while(true) {
        moveNextFloor(elevator, queues);
    }

    return 0;
}