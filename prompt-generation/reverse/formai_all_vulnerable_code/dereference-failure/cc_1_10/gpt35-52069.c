//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// struct to store baggage details
typedef struct{
    int baggageID;
    int weight;
    int destination;
} Baggage;

// function to simulate baggage handling
void baggageHandlingSimulation(){
    // generate random number of bags
    int numBags = rand() % 50 + 1;

    // allocate memory for array of Baggage structs
    Baggage* bags = (Baggage*) malloc(sizeof(Baggage) * numBags);

    // initialize baggage details
    for(int i=0; i<numBags; i++){
        bags[i].baggageID = i+1;
        bags[i].weight = rand() % 30 + 1;
        bags[i].destination = rand() % 3 + 1;
    }

    // print initial baggage details
    printf("Initial Baggage Details: \n");
    for(int i=0; i<numBags; i++){
        printf("Baggage ID: %d, Weight: %d kg, Destination: %d\n", bags[i].baggageID, bags[i].weight, bags[i].destination);
    }

    // sort the bags based on their destination
    for(int i=0; i<numBags-1; i++){
        for(int j=0; j<numBags-i-1; j++){
            if(bags[j].destination > bags[j+1].destination){
                // swap the two bags
                Baggage temp = bags[j];
                bags[j] = bags[j+1];
                bags[j+1] = temp;
            }
        }
    }

    // print the sorted baggage details
    printf("\nSorted Baggage Details: \n");
    for(int i=0; i<numBags; i++){
        printf("Baggage ID: %d, Weight: %d kg, Destination: %d\n", bags[i].baggageID, bags[i].weight, bags[i].destination);
    }

    // allocate memory for arrays to store bags for each destination
    int* dest1Bags = (int*) malloc(sizeof(int) * numBags);
    int* dest2Bags = (int*) malloc(sizeof(int) * numBags);
    int* dest3Bags = (int*) malloc(sizeof(int) * numBags);

    // initialize arrays to store bags for each destination
    int dest1Count = 0, dest2Count = 0, dest3Count = 0;
    for(int i=0; i<numBags; i++){
        if(bags[i].destination == 1){
            dest1Bags[dest1Count] = bags[i].baggageID;
            dest1Count++;
        }
        else if(bags[i].destination == 2){
            dest2Bags[dest2Count] = bags[i].baggageID;
            dest2Count++;
        }
        else{
            dest3Bags[dest3Count] = bags[i].baggageID;
            dest3Count++;
        }
    }

    // print the bags for each destination
    printf("\nBags for Destination 1: ");
    for(int i=0; i<dest1Count; i++){
        printf("%d ", dest1Bags[i]);
    }
    printf("\nBags for Destination 2: ");
    for(int i=0; i<dest2Count; i++){
        printf("%d ", dest2Bags[i]);
    }
    printf("\nBags for Destination 3: ");
    for(int i=0; i<dest3Count; i++){
        printf("%d ", dest3Bags[i]);
    }

    // free the allocated memory
    free(bags);
    free(dest1Bags);
    free(dest2Bags);
    free(dest3Bags);
}

int main(){
    // seed the random number generator
    srand(time(NULL));

    // call the baggage handling simulation function
    baggageHandlingSimulation();

    return 0;
}