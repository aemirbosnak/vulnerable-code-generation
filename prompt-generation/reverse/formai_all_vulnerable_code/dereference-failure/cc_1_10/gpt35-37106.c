//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Node struct to represent a piece of luggage in the system.
struct Node {
    int id;
    int weight;
    char destination[30];
    struct Node* nextLuggage;
};

typedef struct Node Luggage;

// Queue struct to represent the conveyor belt in the system.
struct Queue {
    int capacity;
    int currentSize;
    Luggage* front;
    Luggage* rear;
};

typedef struct Queue ConveyorBelt;

// Function prototypes.
ConveyorBelt* createQueue(int);
void enqueue(ConveyorBelt*, Luggage*);
Luggage* dequeue(ConveyorBelt*);
void generateLuggage(ConveyorBelt*);
void printConveyorBelt(ConveyorBelt*);
void printLuggage(Luggage*);

int main() {
    srand(time(NULL)); // Seed the random number generator for luggage generation.

    printf("Welcome to the Airport Baggage Handling Simulation!\n\n");

    // Ask the user for the capacity of the conveyor belt.
    int capacity;
    printf("Please enter the capacity of the conveyor belt: ");
    scanf("%d", &capacity);

    ConveyorBelt* belt = createQueue(capacity); // Create the conveyor belt.

    bool isRunning = true;
    while (isRunning) {
        printf("\nWhat would you like to do?\n");
        printf("(1) Add luggage to the conveyor belt\n");
        printf("(2) Remove luggage from the conveyor belt\n");
        printf("(3) View the current contents of the conveyor belt\n");
        printf("(4) Quit\n\n");

        int choice;
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            generateLuggage(belt); // Generate luggage and add it to the conveyor belt.
            break;
        case 2:
            dequeue(belt); // Remove the first piece of luggage from the conveyor belt.
            break;
        case 3:
            printConveyorBelt(belt); // Print out the current contents of the conveyor belt.
            break;
        case 4:
            isRunning = false; // Exit the program loop.
            break;
        default:
            printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
            break;
        }
    }

    printf("Thank you for using the Airport Baggage Handling Simulation!\n");
    return 0;
}

/*
 * Function to create a new queue (conveyor belt) with the specified
 * capacity and return a pointer to it.
 */
ConveyorBelt* createQueue(int capacity) {
    ConveyorBelt* belt = (ConveyorBelt*)malloc(sizeof(ConveyorBelt));
    belt->capacity = capacity;
    belt->currentSize = 0;
    belt->front = NULL;
    belt->rear = NULL;
    return belt;
}

/*
 * Function to add a new piece of luggage to the end of the conveyor belt.
 * If the conveyor belt is full, the luggage is not added.
 */
void enqueue(ConveyorBelt* belt, Luggage* newLuggage) {
    if (belt->currentSize < belt->capacity) {
        if (belt->rear == NULL) {
            belt->rear = newLuggage;
            belt->front = newLuggage;
        }
        else {
            belt->rear->nextLuggage = newLuggage;
            belt->rear = newLuggage;
        }
        ++belt->currentSize;
        printf("\nLuggage added to the conveyor belt.\n");
    }
    else {
        printf("\nConveyor belt is full. Luggage not added.\n");
    }
}

/*
 * Function to remove the first piece of luggage from the conveyor belt.
 * If the conveyor belt is empty, nothing is removed.
 */
Luggage* dequeue(ConveyorBelt* belt) {
    if (belt->currentSize > 0) {
        Luggage* luggageToRemove = belt->front;
        belt->front = belt->front->nextLuggage;
        --belt->currentSize;
        printf("\nLuggage removed from the conveyor belt.\n");
        printLuggage(luggageToRemove);
        free(luggageToRemove);
        return luggageToRemove;
    }
    else {
        printf("\nConveyor belt is empty. No luggage removed.\n");
        return NULL;
    }
}

/*
 * Function to generate a new piece of luggage and add it to the conveyor belt.
 * Luggage id is a random number between 1000 and 9999.
 * Luggage weight is a random number between 10 and 100.
 * Luggage destination is a random string (either "domestic" or "international").
 */
void generateLuggage(ConveyorBelt* belt) {
    Luggage* newLuggage = (Luggage*)malloc(sizeof(Luggage));
    newLuggage->id = rand() % 9000 + 1000;
    newLuggage->weight = rand() % 91 + 10;
    strcpy(newLuggage->destination, (rand() % 2 == 0) ? "domestic" : "international");
    newLuggage->nextLuggage = NULL;
    enqueue(belt, newLuggage);
}

/*
 * Function to print out the current contents of the conveyor belt.
 */
void printConveyorBelt(ConveyorBelt* belt) {
    if (belt->currentSize == 0) {
        printf("\nThe conveyor belt is empty.\n");
    }
    else {
        printf("\nCurrent contents of the conveyor belt:\n");
        Luggage* currentLuggage = belt->front;
        while (currentLuggage != NULL) {
            printLuggage(currentLuggage);
            currentLuggage = currentLuggage->nextLuggage;
        }
    }
}

/*
 * Function to print out the details of a single luggage item.
 */
void printLuggage(Luggage* luggage) {
    printf("\nLuggage ID: %d\n", luggage->id);
    printf("Luggage weight: %d kg\n", luggage->weight);
    printf("Luggage destination: %s\n", luggage->destination);
}