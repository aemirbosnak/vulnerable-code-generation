//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 20
#define NUM_OF_CONVEYOR_BELTS 2

typedef struct Baggage {
    int id;
    int weight;
} Baggage;

typedef struct ConveyorBelt {
    int capacity;
    Baggage** baggages;
    int curr_num_of_baggages;
} ConveyorBelt;

Baggage* createBaggage(int id) {
    Baggage* baggage = (Baggage*) malloc(sizeof(Baggage));
    baggage->id = id;
    baggage->weight = rand() % 50 + 1;
    return baggage;
}

ConveyorBelt* createConveyorBelt(int capacity) {
    ConveyorBelt* conveyorBelt = (ConveyorBelt*) malloc(sizeof(ConveyorBelt));
    conveyorBelt->capacity = capacity;
    conveyorBelt->baggages = (Baggage**) malloc(sizeof(Baggage*) * capacity);
    conveyorBelt->curr_num_of_baggages = 0;
    return conveyorBelt;
}

void destroyConveyorBelt(ConveyorBelt* conveyorBelt) {
    for (int i = 0; i < conveyorBelt->curr_num_of_baggages; i++) {
        free(conveyorBelt->baggages[i]);
    }
    free(conveyorBelt->baggages);
    free(conveyorBelt);
}

void addBaggageToConveyorBelt(ConveyorBelt* conveyorBelt) {
    if (conveyorBelt->curr_num_of_baggages >= conveyorBelt->capacity) {
        printf("Conveyor belt is already at maximum capacity!\n");
        return;
    }
    Baggage* new_baggage = createBaggage(conveyorBelt->curr_num_of_baggages);
    conveyorBelt->baggages[conveyorBelt->curr_num_of_baggages++] = new_baggage;
    printf("New baggage with ID %d and weight %d has been added to conveyor belt.\n", new_baggage->id, new_baggage->weight);
}

void transferBeltToBelt(ConveyorBelt* conveyorBelt1, ConveyorBelt* conveyorBelt2) {
    if (conveyorBelt1->curr_num_of_baggages == 0) {
        printf("There are no bags on conveyor belt 1 to transfer!\n");
        return;
    }
    if (conveyorBelt1->curr_num_of_baggages + conveyorBelt2->curr_num_of_baggages > conveyorBelt2->capacity) {
        printf("There is not enough space on conveyor belt 2 for all bags to be transferred!\n");
        return;
    }
    for (int i = 0; i < conveyorBelt1->curr_num_of_baggages; i++) {
        Baggage* transfer_baggage = conveyorBelt1->baggages[i];
        conveyorBelt1->baggages[i] = NULL;
        conveyorBelt2->baggages[conveyorBelt2->curr_num_of_baggages++] = transfer_baggage;
    }
    conveyorBelt1->curr_num_of_baggages = 0;
    printf("All bags have been transferred from conveyor belt 1 to conveyor belt 2.\n");
}

int main() {
    srand(time(NULL));
    
    ConveyorBelt* conveyor_belts[NUM_OF_CONVEYOR_BELTS];
    conveyor_belts[0] = createConveyorBelt(10);
    conveyor_belts[1] = createConveyorBelt(15);

    printf("Simulation of airport baggage handling system started.\n");
    printf("Two conveyor belts have been created with the following capacities: Belt 1: 10   Belt 2: 15\n");
    
    while (1) {
        int option;
        printf("\nSelect an option from the menu:\n");
        printf("1 - Add baggage to conveyor belt 1\n");
        printf("2 - Add baggage to conveyor belt 2\n");
        printf("3 - Transfer all bags from conveyor belt 1 to conveyor belt 2\n");
        printf("4 - Quit simulation\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addBaggageToConveyorBelt(conveyor_belts[0]);
                break;
            case 2:
                addBaggageToConveyorBelt(conveyor_belts[1]);
                break;
            case 3:
                transferBeltToBelt(conveyor_belts[0], conveyor_belts[1]);
                break;
            case 4:
                printf("Simulation has ended.\n");
                destroyConveyorBelt(conveyor_belts[0]);
                destroyConveyorBelt(conveyor_belts[1]);
                return 0;
            default:
                printf("Please select a valid option.\n");
                break;
        }
    }
}