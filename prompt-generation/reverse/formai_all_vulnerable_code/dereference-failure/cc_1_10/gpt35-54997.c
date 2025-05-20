//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_BAGS 1000 // maximum number of bags
#define MAX_FLIGHTS 10 // maximum number of flights
#define MAX_PASSENGERS 500 // maximum number of passengers
#define CONVEYOR_BELT_SIZE 10 // size of the conveyor belt
#define BAG_PICK_UP_TIME 1 // time for passenger to pick up bag
#define MAX_LUGGAGE_WEIGHT 50 // maximum weight of a bag

// Structure to represent a bag
typedef struct {
    int id; // Bag ID
    int weight; // Bag Weight
    int flightNumber; // Flight number of the bag
} Bag;

// Array to hold the bags
Bag bags[MAX_BAGS];

// Structure to represent a passenger
typedef struct {
    int id; // Passenger ID
    int flightNumber; // Flight number of the passenger
    int totalBags; // Total number of bags by passenger
    Bag* bags[MAX_BAGS]; // Array of bags of the passenger
} Passenger;

// Array to hold the passengers
Passenger passengers[MAX_PASSENGERS];

// Mutexes to prevent race conditions
pthread_mutex_t conveyorBeltMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t destinationBeltMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t passengerMutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variables for synchronization
pthread_cond_t conveyorBeltFullCond = PTHREAD_COND_INITIALIZER;
pthread_cond_t conveyorBeltEmptyCond = PTHREAD_COND_INITIALIZER;
pthread_cond_t destinationBeltFullCond = PTHREAD_COND_INITIALIZER;
pthread_cond_t destinationBeltEmptyCond = PTHREAD_COND_INITIALIZER;

// Conveyor belt array to hold the bags
Bag* conveyorBelt[CONVEYOR_BELT_SIZE];

// Destination belt array to hold the bags of a particular flight
Bag* destinationBelts[MAX_FLIGHTS][CONVEYOR_BELT_SIZE];

// Global variables for current conveyor belt index and destination belt indices
int conveyorBeltIndex = 0;
int destinationBeltIndices[MAX_FLIGHTS] = {0};

// Function to generate a random integer between a and b (both inclusive)
int getRandomInt(int a, int b) {
    return (rand() % (b - a + 1)) + a;
}

// Function to add a bag to the conveyor belt
void addToConveyorBelt(Bag* bag) {
    // Acquire the conveyor belt mutex
    pthread_mutex_lock(&conveyorBeltMutex);
    
    // Wait until the conveyor belt is not full
    while(conveyorBeltIndex == CONVEYOR_BELT_SIZE) {
        pthread_cond_wait(&conveyorBeltFullCond, &conveyorBeltMutex);
    }
    
    // Add the bag to the conveyor belt and update the index
    conveyorBelt[conveyorBeltIndex++] = bag;
    
    printf("\nBag with ID %d and Weight %d added to conveyor belt\n", bag->id, bag->weight);
    
    // Signal that the conveyor belt is not empty anymore
    pthread_cond_signal(&conveyorBeltEmptyCond);
    
    // Release the conveyor belt mutex
    pthread_mutex_unlock(&conveyorBeltMutex);
}

// Function to pick up a bag from the conveyor belt
Bag* pickUpFromConveyorBelt() {
    // Acquire the conveyor belt mutex
    pthread_mutex_lock(&conveyorBeltMutex);
    
    // Wait until the conveyor belt is not empty
    while(conveyorBeltIndex == 0) {
        pthread_cond_wait(&conveyorBeltEmptyCond, &conveyorBeltMutex);
    }
    
    // Remove the bag from the conveyor belt and update the index
    Bag* bag = conveyorBelt[--conveyorBeltIndex];
    
    printf("\nBag with ID %d and Weight %d picked up from conveyor belt\n", bag->id, bag->weight);
    
    // Signal that the conveyor belt is not full anymore
    pthread_cond_signal(&conveyorBeltFullCond);
    
    // Release the conveyor belt mutex
    pthread_mutex_unlock(&conveyorBeltMutex);
    
    // Return the picked bag
    return bag;
}

// Function to add a bag to the destination belt of the flight
void addToDestinationBelt(Bag* bag) {
    // Acquire the destination belt mutex
    pthread_mutex_lock(&destinationBeltMutex);
    
    // Wait until the destination belt is not full
    while(destinationBeltIndices[bag->flightNumber] == CONVEYOR_BELT_SIZE) {
        pthread_cond_wait(&destinationBeltFullCond, &destinationBeltMutex);
    }
    
    // Add the bag to the destination belt of the flight and update the index
    destinationBelts[bag->flightNumber][destinationBeltIndices[bag->flightNumber]++] = bag;
    
    printf("\nBag with ID %d and Weight %d added to destination belt of Flight %d\n", bag->id, bag->weight, bag->flightNumber);
    
    // Signal that the destination belt is not empty anymore
    pthread_cond_signal(&destinationBeltEmptyCond);
    
    // Release the destination belt mutex
    pthread_mutex_unlock(&destinationBeltMutex);
}

// Function to pick up a bag from the destination belt of the flight
Bag* pickUpFromDestinationBelt(int flightNumber) {
    // Acquire the destination belt mutex
    pthread_mutex_lock(&destinationBeltMutex);
    
    // Wait until the destination belt of the flight is not empty
    while(destinationBeltIndices[flightNumber] == 0) {
        pthread_cond_wait(&destinationBeltEmptyCond, &destinationBeltMutex);
    }
    
    // Remove the bag from the destination belt of the flight and update the index
    Bag* bag = destinationBelts[flightNumber][--destinationBeltIndices[flightNumber]];
    
    printf("\nBag with ID %d and Weight %d picked up from destination belt of Flight %d\n", bag->id, bag->weight, flightNumber);
    
    // Signal that the destination belt is not full anymore
    pthread_cond_signal(&destinationBeltFullCond);
    
    // Release the destination belt mutex
    pthread_mutex_unlock(&destinationBeltMutex);
    
    // Return the picked bag
    return bag;
}

// Function to generate the bags of a passenger and add them to the conveyor belt
void* generateBags(void* arg) {
    Passenger* passenger = (Passenger*) arg;
    
    // Generate random bags for the passenger
    for(int i = 0; i < passenger->totalBags; i++) {
        Bag* bag = (Bag*) malloc(sizeof(Bag));
        bag->id = i+1;
        bag->weight = getRandomInt(1, MAX_LUGGAGE_WEIGHT);
        bag->flightNumber = passenger->flightNumber;
        passenger->bags[i] = bag;
        
        // Add the bag to the conveyor belt
        addToConveyorBelt(bag);
    }
    
    pthread_exit(NULL);
}

// Function to simulate the process of a passenger picking up his bags from the conveyor belt
void* pickUpBags(void* arg) {
    Passenger* passenger = (Passenger*) arg;
    
    // Sleep for some time to simulate walking to the conveyor belt
    sleep(BAG_PICK_UP_TIME);
    
    // Loop through all the bags of the passenger and pick them up from the conveyor belt
    for(int i = 0; i < passenger->totalBags; i++) {
        Bag* bag = pickUpFromConveyorBelt();
        
        // Add the bag to the destination belt of the flight
        addToDestinationBelt(bag);
    }
    
    pthread_exit(NULL);
}

// Function to simulate the process of a passenger picking up his bags from the destination belt of the flight
void* pickUpDestinationBelt(void* arg) {
    Passenger* passenger = (Passenger*) arg;
    
    // Sleep for some time to simulate walking to the destination belt of the flight
    sleep(BAG_PICK_UP_TIME);
    
    // Loop through all the bags of the passenger and pick them up from the destination belt of the flight
    for(int i = 0; i < passenger->totalBags; i++) {
        Bag* bag = pickUpFromDestinationBelt(passenger->flightNumber);
    }
    
    pthread_exit(NULL);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate some random passengers with random flights and bags
    int totalPassengers = getRandomInt(1, MAX_PASSENGERS);
    int totalFlights = getRandomInt(1, MAX_FLIGHTS);
    for(int i = 0; i < totalPassengers; i++) {
        Passenger* passenger = (Passenger*) malloc(sizeof(Passenger));
        passenger->id = i+1;
        passenger->flightNumber = getRandomInt(1, totalFlights);
        passenger->totalBags = getRandomInt(1, MAX_BAGS);
        
        pthread_t generateBagsThread;
        pthread_create(&generateBagsThread, NULL, generateBags, passenger);
        
        pthread_t pickUpBagsThread;
        pthread_create(&pickUpBagsThread, NULL, pickUpBags, passenger);
        
        pthread_t pickUpDestinationBeltThread;
        pthread_create(&pickUpDestinationBeltThread, NULL, pickUpDestinationBelt, passenger);
        
        pthread_join(generateBagsThread, NULL);
        pthread_join(pickUpBagsThread, NULL);
        pthread_join(pickUpDestinationBeltThread, NULL);
        
        printf("\nPassenger with ID %d and Flight Number %d has picked up all his bags from the destination belt\n", passenger->id, passenger->flightNumber);
    }
    
    return 0;
}