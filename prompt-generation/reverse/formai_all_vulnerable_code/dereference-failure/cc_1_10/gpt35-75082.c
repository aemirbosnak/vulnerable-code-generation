//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define NUM_BAGS 100
#define NUM_BELTS 8
#define MAX_WEIGHT 50
#define MIN_WEIGHT 10

// Define struct for bags
typedef struct {
    int id;
    int weight;
} Bag;

// Define struct for belt
typedef struct {
    int id;
    Bag* bags[NUM_BAGS];
    int start_index;
    int end_index;
} Belt;

// Global variables
Bag* bags[NUM_BAGS];
Belt* belts[NUM_BELTS];

// Function prototypes
void generate_bags();
void generate_belts();
void print_belts();
void run_simulation();

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Generate bags and belts
    generate_bags();
    generate_belts();
    
    // Print initial state of belts
    printf("Initial state of belts:\n");
    print_belts();
    
    // Run simulation
    run_simulation();
    
    return 0;
}

void generate_bags() {
    // Generate bags with random weights
    int i;
    for (i = 0; i < NUM_BAGS; i++) {
        Bag* bag = (Bag*)malloc(sizeof(Bag));
        bag->id = i + 1;
        bag->weight = (rand() % (MAX_WEIGHT - MIN_WEIGHT + 1)) + MIN_WEIGHT;
        bags[i] = bag;
    }
}

void generate_belts() {
    // Generate belts with random start and end indexes
    int i;
    for (i = 0; i < NUM_BELTS; i++) {
        Belt* belt = (Belt*)malloc(sizeof(Belt));
        belt->id = i + 1;
        belt->start_index = rand() % NUM_BAGS;
        belt->end_index = (belt->start_index + rand() % (NUM_BAGS - belt->start_index)) % NUM_BAGS;
        belts[i] = belt;
        
        // Add bags to belt
        int j, index = belt->start_index;
        for (j = 0; j < NUM_BAGS; j++) {
            belt->bags[index] = bags[j];
            index = (index + 1) % NUM_BAGS;
        }
    }
}

void print_belts() {
    // Print the state of all belts
    int i, j;
    for (i = 0; i < NUM_BELTS; i++) {
        Belt* belt = belts[i];
        printf("Belt %d: ", belt->id);
        for (j = belt->start_index; j != belt->end_index; j = (j + 1) % NUM_BAGS) {
            Bag* bag = belt->bags[j];
            printf("(%d, %d) ", bag->id, bag->weight);
        }
        Bag* end_bag = belt->bags[belt->end_index];
        printf("(%d, %d)\n", end_bag->id, end_bag->weight);
    }
}

void run_simulation() {
    // Move bags from one belt to another
    int i, j;
    for (i = 0; i < NUM_BELTS; i++) {
        Belt* belt1 = belts[i];
        for (j = i + 1; j < NUM_BELTS; j++) {
            Belt* belt2 = belts[j];
            int k, l;
            for (k = belt1->start_index; k != belt1->end_index; k = (k + 1) % NUM_BAGS) {
                Bag* bag = belt1->bags[k];
                if (bag != NULL && bag->weight <= MAX_WEIGHT) {
                    for (l = belt2->start_index; l != belt2->end_index; l = (l + 1) % NUM_BAGS) {
                        if (belt2->bags[l] == NULL) {
                            belt2->bags[l] = bag;
                            belt1->bags[k] = NULL;
                            printf("Bag %d moved from belt %d to belt %d\n", bag->id, belt1->id, belt2->id);
                            break;
                        }
                    }
                }
            }
        }
    }
    
    // Print final state of belts
    printf("Final state of belts:\n");
    print_belts();
}