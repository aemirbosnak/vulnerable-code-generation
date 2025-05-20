//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: protected
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Define stucture for bag details */
typedef struct {
    int id;
    int weight;
    char flight[10];
} Bag;

/* Variable for number of bags */
int num_bags = 0;

/* Function to randomly generate bag details */
void generate_bag_details(Bag* bag) {
    bag->id = rand() % 1000 + 1;
    bag->weight = rand() % 50 + 1;
    sprintf(bag->flight, "FLIGHT-%d", rand() % 5 + 1);
}

/* Function to simulate baggage conveyor belt */
void conveyor_belt_simulation(Bag bags[]) {
    printf("Conveyor belt started!\n");
    for(int i=0; i<num_bags; i++) {
        generate_bag_details(&bags[i]);
        printf("Bag with ID %d and weight %d kgs added on conveyor belt for flight %s\n", bags[i].id, bags[i].weight, bags[i].flight);
    }
    printf("Conveyor belt stopped!\n");
}

/* Function to simulate sorting of bags based on flight */
void sorting_simulation(Bag bags[]) {
    printf("Sorting machine started!\n");
    for(int i=0; i<num_bags; i++) {
        printf("Sorting bag with ID %d for flight %s\n", bags[i].id, bags[i].flight);
    }
    printf("Sorting machine stopped!\n");
}

/* Main function */
int main() {
    srand(time(NULL)); // seed for random generation
    
    printf("Enter the number of bags to be simulated: ");
    scanf("%d", &num_bags);
    
    Bag bags[num_bags]; // create array of bags
    
    conveyor_belt_simulation(bags);
    sorting_simulation(bags);
    
    return 0;
}