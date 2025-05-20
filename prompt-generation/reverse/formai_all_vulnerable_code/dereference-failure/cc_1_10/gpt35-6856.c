//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CAPACITY 100 // Maximum capacity of the baggage conveyor belt

// Structure of a baggage object
typedef struct {
    int id; // ID of the baggage object
    int weight; // Weight of the baggage object
} Baggage;

int main() {
    srand(time(NULL)); // Seed the random number generator
    int remaining_capacity = MAX_CAPACITY; // Remaining capacity of the baggage conveyor belt
    int num_bags = 0; // Number of bags currently on the conveyor belt
    int total_weight = 0; // Total weight of bags currently on the conveyor belt
    Baggage* baggage_belt[MAX_CAPACITY]; // Conveyor belt represented as an array of pointers to baggage objects
    
    while (true) { // Infinite loop to simulate continuous operation of baggage handling system
        printf("Remaining capacity: %d\n", remaining_capacity);
        printf("Number of bags on belt: %d\n", num_bags);
        printf("Total weight of bags on belt: %d\n", total_weight);
        printf("Enter 1 to add baggage, 2 to remove baggage, or 3 to exit: ");
        int action;
        scanf("%d", &action);
        if (action == 1) { // Add baggage to conveyor belt
            if (remaining_capacity == 0) {
                printf("Conveyor belt is full!\n");
            } else {
                Baggage* new_baggage = (Baggage*) malloc(sizeof(Baggage)); // Allocate memory for new baggage object
                new_baggage->id = num_bags + 1; // Assign ID to new baggage object
                new_baggage->weight = rand() % 50 + 1; // Assign random weight between 1 and 50 to new baggage object
                num_bags++;
                total_weight += new_baggage->weight;
                remaining_capacity--;
                baggage_belt[MAX_CAPACITY - remaining_capacity - 1] = new_baggage;
                printf("Baggage with ID %d and weight %d added to conveyor belt.\n", new_baggage->id, new_baggage->weight);
            }
        } else if (action == 2) { // Remove baggage from conveyor belt
            if (num_bags == 0) {
                printf("No bags on conveyor belt!\n");
            } else {
                int index = rand() % num_bags; // Choose random index of baggage object to remove
                Baggage* removed_baggage = baggage_belt[index];
                num_bags--;
                total_weight -= removed_baggage->weight;
                remaining_capacity++;
                for (int i = index; i < num_bags; i++) { // Shift remaining baggage objects down by one index
                    baggage_belt[i] = baggage_belt[i+1];
                }
                printf("Baggage with ID %d and weight %d removed from conveyor belt.\n", removed_baggage->id, removed_baggage->weight);
                free(removed_baggage); // Deallocate memory used by removed baggage object
            }
        } else { // Exit program
            for (int i = 0; i < num_bags; i++) { // Deallocate memory used by remaining baggage objects
                free(baggage_belt[i]);
            }
            printf("Exiting program...");
            break;
        }
    }
    return 0;
}