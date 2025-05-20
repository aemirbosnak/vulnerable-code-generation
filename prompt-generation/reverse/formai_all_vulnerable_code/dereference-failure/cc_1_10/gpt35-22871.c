//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Global Variables
int numPassengers = 0;
int numLuggageBags = 0;
int numSecurityChecks = 0;
int numSatisfiedPassengers = 0;
int numUnsatisfiedPassengers = 0;
int numBagsChecked = 0;

// Function Prototypes
void generatePassengers(int* ar, int size, int max);
void sortPassengers(int* ar, int size);
void printStatistics();

int main(void) {

    // Struct for Luggage Bag
    typedef struct LuggageBag {
        int bagID;
        bool isChecked;
    } LuggageBag;

    // Struct for Passenger
    typedef struct Passenger {
        int passengerID;
        LuggageBag* luggageBags;
        bool isSatisfied;
    } Passenger;

    srand(time(NULL));    // Seed for Random Number Generation
    numPassengers = rand() % 1000 + 1;    // Generate Random Number of Passengers

    // Memory Allocation and Initialization
    LuggageBag* allBags = (LuggageBag*)calloc(numPassengers, sizeof(LuggageBag));
    Passenger* allPassengers = (Passenger*)calloc(numPassengers, sizeof(Passenger));

    // Generate Random Number of Luggage Bags for Each Passenger
    for (int i = 0; i < numPassengers; i++) {
        numLuggageBags += rand() % 5 + 1;    // Generate Random Number of Luggage Bags
        allPassengers[i].passengerID = i + 1;    // Set Passenger ID

        // Memory Allocation and Initialization
        allPassengers[i].luggageBags = (LuggageBag*)calloc(numLuggageBags, sizeof(LuggageBag));
        for (int j = 0; j < numLuggageBags; j++) {
            allPassengers[i].luggageBags[j].bagID = j + 1;    // Set Bag ID
            allBags[numBagsChecked++] = allPassengers[i].luggageBags[j];    // Add to All Bags Array
        }

        numLuggageBags = 0;    // Reset Number of Luggage Bags
    }

    // Generate Random Number of Security Checks
    numSecurityChecks = rand() % 10 + 1;

    // Perform Security Checks
    for (int i = 0; i < numSecurityChecks; i++) {
        int randomNum = rand() % numBagsChecked;    // Generate Random Bag Number

        // If Bag is Not Checked, Set as Checked
        if (!allBags[randomNum].isChecked) {
            allBags[randomNum].isChecked = true;
            numBagsChecked--;
        }
    }

    // Check Passenger Satisfaction
    for (int i = 0; i < numPassengers; i++) {
        int numCheckedBags = 0;
        for (int j = 0; j < sizeof(allPassengers[i].luggageBags) / sizeof(LuggageBag); j++) {
            if (allPassengers[i].luggageBags[j].isChecked)
                numCheckedBags++;    // Count Number of Checked Bags
        }

        // If All Bags Checked, Passenger is Satisfied
        if (numCheckedBags == sizeof(allPassengers[i].luggageBags) / sizeof(LuggageBag)) {
            allPassengers[i].isSatisfied = true;
            numSatisfiedPassengers++;
        }
        else {
            allPassengers[i].isSatisfied = false;
            numUnsatisfiedPassengers++;
        }
    }

    // Free Memory
    for (int i = 0; i < numPassengers; i++) {
        free(allPassengers[i].luggageBags);
    }
    free(allBags);
    free(allPassengers);

    // Print Statistics
    printStatistics();

    return 0;
}

// Function to Generate Random Number of Passengers
void generatePassengers(int* ar, int size, int max) {
    for (int i = 0; i < size; i++) {
        ar[i] = rand() % max + 1;
        numPassengers += ar[i];
    }
}

// Function for Bubble Sort on Passengers Array
void sortPassengers(int* ar, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (ar[j] > ar[j + 1]) {
                temp = ar[j];
                ar[j] = ar[j + 1];
                ar[j + 1] = temp;
            }
        }
    }
}

// Function to Print Statistics
void printStatistics() {
    printf("Number of Passengers: %d\n", numPassengers);
    printf("Number of Luggage Bags: %d\n", numBagsChecked);
    printf("Number of Security Checks: %d\n", numSecurityChecks);
    printf("Number of Satisfied Passengers: %d\n", numSatisfiedPassengers);
    printf("Number of Unsatisfied Passengers: %d\n", numUnsatisfiedPassengers);
}