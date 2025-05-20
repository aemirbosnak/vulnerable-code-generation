//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LUGGAGE 50 // Maximum number of luggage items
#define MAX_BELTS 5 // Maximum number of conveyor belts
#define MAX_TRUCKS 10 // Maximum number of trucks to transport luggage

// Enum for luggage status
enum LuggageStatus {
    NOT_HANDLED,
    ON_CONVEYOR_BELT,
    ON_TRUCK,
    DESTINATION_REACHED
};

// Structure for luggage
struct Luggage {
    int id;
    int weight;
    char destination[20];
    enum LuggageStatus status;
};

// Function to generate random destination
char* generateDestination() {
    char* destinations[] = {"New York", "London", "Paris", "Sydney", "Tokyo", "Dubai", "Mumbai", "Singapore", "Hong Kong", "Beijing", "Moscow"};
    int index = rand() % 11;
    return destinations[index];
}

// Function to generate random weight between 10 and 50 kgs
int generateWeight() {
    return (rand() % 41) + 10;
}

// Function to create a luggage item
struct Luggage createLuggage(int id) {
    struct Luggage luggage;
    luggage.id = id;
    luggage.weight = generateWeight();
    strcpy(luggage.destination, generateDestination());
    luggage.status = NOT_HANDLED;
    return luggage;
}

// Function to initialize luggage array with random luggage
void initLuggage(struct Luggage* luggage, int n) {
    int i;
    for(i=0;i<n;i++) {
        luggage[i] = createLuggage(i+1);
    }
}

// Function to print luggage details
void printLuggage(struct Luggage luggage) {
    printf("Luggage ID: %d, Weight: %d kgs, Destination: %s, Status: %d\n", luggage.id, luggage.weight, luggage.destination, luggage.status);
}

// Function to print list of luggage items
void printLuggageList(struct Luggage* luggage, int n) {
    int i;
    for(i=0;i<n;i++) {
        printLuggage(luggage[i]);
    }
}

// Function to handle luggage on conveyor belt
void handleLuggageOnBelt(struct Luggage* luggage, int index) {
    printf("Handling luggage with ID %d on conveyor belt\n", luggage[index].id);
    luggage[index].status = ON_CONVEYOR_BELT;
}

// Function to handle luggage on truck
void handleLuggageOnTruck(struct Luggage* luggage, int index) {
    printf("Loading luggage with ID %d on truck\n", luggage[index].id);
    luggage[index].status = ON_TRUCK;
}

// Function to handle luggage at destination
void handleLuggageAtDestination(struct Luggage* luggage, int index) {
    printf("Unloading luggage with ID %d at destination\n", luggage[index].id);
    luggage[index].status = DESTINATION_REACHED;
}

int main() {
    srand(time(0)); // Initialize random number generator with current time
    struct Luggage luggage[MAX_LUGGAGE];
    int n, i, j;
    printf("Enter number of luggage items: ");
    scanf("%d", &n);
    if(n > MAX_LUGGAGE) {
        printf("Maximum number of luggage items exceeded. Setting number of luggage items to %d\n", MAX_LUGGAGE);
        n = MAX_LUGGAGE;
    }
    initLuggage(luggage, n);
    printf("List of luggage items:\n");
    printLuggageList(luggage, n);
    // Simulating conveyor belt
    for(i=0;i<n;i++) {
        handleLuggageOnBelt(luggage, i);
    }
    // Simulating loading luggage onto trucks
    int numTrucks = (n % MAX_TRUCKS == 0) ? (n / MAX_TRUCKS) : (n / MAX_TRUCKS + 1);
    int luggagePerTruck = (n % numTrucks == 0) ? (n / numTrucks) : (n / numTrucks + 1);
    for(i=0;i<numTrucks;i++) {
        printf("Truck %d loading luggage:\n", i+1);
        for(j=0;j<luggagePerTruck;j++) {
            int index = i * luggagePerTruck + j;
            if(index < n) {
                handleLuggageOnTruck(luggage, index);
            }
        }
    }
    // Simulating unloading of luggage at destination
    for(i=0;i<n;i++) {
        if(luggage[i].status == ON_TRUCK) {
            handleLuggageAtDestination(luggage, i);
        }
    }
    printf("Final status of luggage items:\n");
    printLuggageList(luggage, n);
    return 0;
}