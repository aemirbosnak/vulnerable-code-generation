//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_BAGS 50
#define MAX_WEIGHT 50

// Struct to represent a baggage
typedef struct {
    int id;
    float weight;
} Baggage;

// Struct to represent a passenger
typedef struct {
    int id;
    char name[50];
    int num_bags;
    Baggage bags[MAX_BAGS];
} Passenger;

// Struct to represent a conveyor belt
typedef struct {
    int capacity;
    int num_bags;
    Baggage bags[MAX_BAGS];
} ConveyorBelt;

// Function declarations
void add_passenger(Passenger* passenger);
void add_baggage(Passenger* passenger, int index);
ConveyorBelt* initialize_conveyor_belt();
bool put_on_conveyor_belt(ConveyorBelt* conveyor_belt, Baggage* baggage);
void print_conveyor_belt(ConveyorBelt* conveyor_belt);
void print_passenger(Passenger* passenger);
void print_baggage(Baggage* baggage);

int main() {
    // Initialize the conveyor belt
    ConveyorBelt* conveyor_belt = initialize_conveyor_belt();
    
    // Initialize Romeo and Juliet
    Passenger romeo = {1, "Romeo Montague", 2};
    Passenger juliet = {2, "Juliet Capulet", 2};
    
    // Add Romeo and Juliet's baggage to their respective passengers
    add_baggage(&romeo, 0);
    add_baggage(&romeo, 1);
    add_baggage(&juliet, 0);
    add_baggage(&juliet, 1);
    
    // Add Romeo and Juliet to the conveyor belt
    add_passenger(&romeo);
    add_passenger(&juliet);
    
    // Print the conveyor belt
    printf("Initially:\n");
    print_conveyor_belt(conveyor_belt);
    
    // Romeo puts his bags on the conveyor belt
    for(int i=0; i<romeo.num_bags; i++) {
        bool success = put_on_conveyor_belt(conveyor_belt, &romeo.bags[i]);
        if(success) {
            printf("%s puts a bag on the conveyor belt.\n", romeo.name);
        } else {
            printf("The conveyor belt is full and %s cannot put a bag on the conveyor belt.\n", romeo.name);
        }
    }
    
    // Juliet puts her bags on the conveyor belt
    for(int i=0; i<juliet.num_bags; i++) {
        bool success = put_on_conveyor_belt(conveyor_belt, &juliet.bags[i]);
        if(success) {
            printf("%s puts a bag on the conveyor belt.\n", juliet.name);
        } else {
            printf("The conveyor belt is full and %s cannot put a bag on the conveyor belt.\n", juliet.name);
        }
    }
    
    // Print the conveyor belt again
    printf("\nAfter Romeo and Juliet add their bags:\n");
    print_conveyor_belt(conveyor_belt);
    
    // Free the memory used by the conveyor belt
    free(conveyor_belt);
    
    return 0;
}

// Function to add a passenger to the conveyor belt
void add_passenger(Passenger* passenger) {
    printf("%s arrives at the airport with %d bags.\n", passenger->name, passenger->num_bags);
}

// Function to add a baggage to a passenger
void add_baggage(Passenger* passenger, int index) {
    Baggage baggage;
    baggage.id = index + 1;
    
    printf("%s, please enter the weight of your bag %d: ", passenger->name, index+1);
    scanf("%f", &baggage.weight);

    while(baggage.weight<0 || baggage.weight>MAX_WEIGHT) {
        printf("The weight of a baggage should be between 0 and %d.\n", MAX_WEIGHT);
        printf("%s, please enter the weight of your bag %d: ", passenger->name, index+1);
        scanf("%f", &baggage.weight);
    }
    
    passenger->bags[index] = baggage;
    printf("%s's bag %d is checked in.\n", passenger->name, index+1);
}

// Function to initialize the conveyor belt
ConveyorBelt* initialize_conveyor_belt() {
    ConveyorBelt* conveyor_belt = (ConveyorBelt*) malloc(sizeof(ConveyorBelt));
    conveyor_belt->capacity = MAX_BAGS;
    conveyor_belt->num_bags = 0;
    return conveyor_belt;
}

// Function to put a baggage on the conveyor belt
bool put_on_conveyor_belt(ConveyorBelt* conveyor_belt, Baggage* baggage) {
    if(conveyor_belt->num_bags >= conveyor_belt->capacity) {
        return false;
    }
    conveyor_belt->bags[conveyor_belt->num_bags] = *baggage;
    conveyor_belt->num_bags++;
    return true;
}

// Function to print the conveyor belt
void print_conveyor_belt(ConveyorBelt* conveyor_belt) {
    printf("The conveyor belt currently has %d bags:\n", conveyor_belt->num_bags);
    for(int i=0; i<conveyor_belt->num_bags; i++) {
        print_baggage(&conveyor_belt->bags[i]);
    }
}

// Function to print a passenger
void print_passenger(Passenger* passenger) {
    printf("%s has %d bags:\n", passenger->name, passenger->num_bags);
    for(int i=0; i<passenger->num_bags; i++) {
        print_baggage(&passenger->bags[i]);
    }
}

// Function to print a baggage
void print_baggage(Baggage* baggage) {
    printf("Bag %d, Weight: %.2f\n", baggage->id, baggage->weight);
}