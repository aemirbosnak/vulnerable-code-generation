//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the struct for each piece of luggage
typedef struct Luggage {
    int id;
    char airline[10];
    int weight;
    int destination;
} Luggage;

// Define the struct for each conveyor belt (queue)
typedef struct ConveyorBelt {
    Luggage* belt;
    int front;
    int rear;
    int capacity;
    int count;
} ConveyorBelt;

// Function prototypes
void initialize(ConveyorBelt* belt, int cap);
int isFull(ConveyorBelt* belt);
int isEmpty(ConveyorBelt* belt);
void enqueue(ConveyorBelt* belt, Luggage item);
Luggage dequeue(ConveyorBelt* belt);
void printLuggage(Luggage item);

int main() {
    srand(time(NULL)); // Initialize random seed
    int capacity, duration, numLuggage = 0;
    ConveyorBelt belt;
    
    // Get user input for conveyor belt capacity and duration of simulation
    printf("Enter capacity of conveyor belt: ");
    scanf("%d", &capacity);
    initialize(&belt, capacity);
    
    printf("Enter duration of simulation (in seconds): ");
    scanf("%d", &duration);
    printf("\nSimulation starting...\n");
    
    // Main simulation loop
    for (int i = 0; i < duration; i++) {
        
        // 70% chance of generating new luggage
        if (rand() % 10 < 7) {
            Luggage newLuggage;
            newLuggage.id = ++numLuggage;
            strcpy(newLuggage.airline, "AA");
            newLuggage.weight = rand() % 51 + 10; // Random weight between 10 and 60 lbs
            newLuggage.destination = rand() % 3 + 1; // Random destination between 1 and 3
            
            // Check if conveyor belt is full before adding new luggage
            if (isFull(&belt)) {
                printf("The conveyor belt is full. Luggage #%d was not added.\n", newLuggage.id);
            } else {
                printf("New luggage added to the conveyor belt:\n");
                printLuggage(newLuggage);
                enqueue(&belt, newLuggage);
            }
        }
        
        // 50% chance of removing luggage from conveyor belt
        if (rand() % 10 < 5) {
            if (isEmpty(&belt)) {
                printf("The conveyor belt is empty.\n");
            } else {
                Luggage removedLuggage = dequeue(&belt);
                printf("Luggage removed from the conveyor belt:\n");
                printLuggage(removedLuggage);
            }
        }
        
        // Pause for one second before next simulation cycle
        sleep(1);
    }
    
    printf("Simulation complete.\n");
    return 0;
}

// Function to initialize a new conveyor belt
void initialize(ConveyorBelt* belt, int cap) {
    belt->capacity = cap;
    belt->front = 0;
    belt->rear = -1;
    belt->count = 0;
    belt->belt = (Luggage*) malloc(sizeof(Luggage) * cap);
}

// Function to check if conveyor belt is full
int isFull(ConveyorBelt* belt) {
    return belt->count == belt->capacity;
}

// Function to check if conveyor belt is empty
int isEmpty(ConveyorBelt* belt) {
    return belt->count == 0;
}

// Function to add new luggage to conveyor belt
void enqueue(ConveyorBelt* belt, Luggage item) {
    belt->rear = (belt->rear + 1) % belt->capacity;
    belt->belt[belt->rear] = item;
    belt->count++;
}

// Function to remove luggage from conveyor belt
Luggage dequeue(ConveyorBelt* belt) {
    Luggage removedItem = belt->belt[belt->front];
    belt->front = (belt->front + 1) % belt->capacity;
    belt->count--;
    return removedItem;
}

// Function to print luggage information
void printLuggage(Luggage item) {
    printf("- ID: %d\n", item.id);
    printf("- Airline: %s\n", item.airline);
    printf("- Weight: %d lbs\n", item.weight);
    printf("- Destination: %d\n", item.destination);
}