//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*This program simulates the baggage handling system at an airport.*/

int main() {
    srand(time(NULL));
    int numOfBags, numOfConveyors;
    printf("Welcome to the Airport Baggage Handling System Simulation!\n\n");
    //Get user input for number of bags and conveyors
    printf("Enter the number of bags: ");
    scanf("%d", &numOfBags);
    printf("Enter the number of conveyors: ");
    scanf("%d", &numOfConveyors);
    printf("\nInitializing system...\n\n");

    //Create arrays for bags and conveyors
    int bags[numOfBags], conveyors[numOfConveyors];

    //Randomly place bags on conveyors
    for(int i = 0; i < numOfBags; i++) {
        bags[i] = rand() % numOfConveyors + 1;
    }

    //Initialize conveyors to empty
    for(int i = 0; i < numOfConveyors; i++) {
        conveyors[i] = 0;
    }

    //Simulate the movement of bags through the system
    int time = 0;
    while(1) {
        //Exit loop if all bags have been processed
        int bagsProcessed = 0;
        for(int i = 0; i < numOfBags; i++) {
            if(bags[i] == -1) {
                bagsProcessed++;
            }
        }
        if(bagsProcessed == numOfBags) {
            break;
        }

        //Move bags to next conveyor
        for(int i = 0; i < numOfConveyors; i++) {
            if(conveyors[i] != 0) {
                if(i == numOfConveyors - 1) {
                    bags[conveyors[i] - 1] = -1; //Bag has reached its destination
                    conveyors[i] = 0;
                } else {
                    conveyors[i + 1] = conveyors[i];
                    conveyors[i] = 0;
                }
            }
        }

        //Place new bags on the first conveyor
        for(int i = 0; i < numOfBags; i++) {
            if(bags[i] == 1) {
                for(int j = 0; j < numOfConveyors; j++) {
                    if(conveyors[j] == 0) {
                        conveyors[j] = i + 1;
                        break;
                    }
                }
            }
        }

        //Print updated system status
        printf("Time: %d\n", time);
        printf("Bags:");
        for(int i = 0; i < numOfBags; i++) {
            printf(" %d", bags[i]);
        }
        printf("\nConveyors:");
        for(int i = 0; i < numOfConveyors; i++) {
            printf(" %d", conveyors[i]);
        }
        printf("\n\n");
        time++;
    }

    printf("All bags have been processed. Simulation complete!\n");

    return 0;
}