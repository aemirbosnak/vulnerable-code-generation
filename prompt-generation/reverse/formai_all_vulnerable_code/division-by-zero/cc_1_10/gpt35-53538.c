//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct baggage{
    int id;
    int weight;
};

int main(){
    int numOfBags, maxWeight, capacity, currentTime;
    int checkerCount = 0, securityCount = 0, loaderCount = 0;
    struct baggage allBags[1000];
    srand(time(NULL));
    printf("Welcome to the Airport Baggage Handling Simulation!\n\n");
    printf("Enter the number of bags to be handled today: ");
    scanf("%d", &numOfBags);
    printf("Enter the maximum weight allowed for each bag: ");
    scanf("%d", &maxWeight);
    printf("Enter the capacity of the aircraft: ");
    scanf("%d", &capacity);
    printf("\nInitializing the baggage...");
    for(int i=0;i<numOfBags;i++){
        struct baggage currentBag = {i+1, rand()%(maxWeight+1)};
        allBags[i] = currentBag;
    }
    printf("\nInitialization complete!");
    printf("\nThe simulation has begun!\n");
    while(numOfBags > 0){
        printf("\nCurrent time: %d", currentTime);
        printf("\nLoader %d is loading bag %d...", loaderCount+1, allBags[checkerCount].id);
        capacity -= allBags[checkerCount].weight;
        loaderCount++;
        checkerCount++;
        if(checkerCount >= numOfBags){
            checkerCount = 0;
        }
        if(capacity <= 0){
            printf("\nThe aircraft has reached maximum capacity. Time to bring it to the aircraft...");
            loaderCount--;
            securityCount++;
            printf("\nSecurity is checking the bags...");
            for(int i=loaderCount;i<checkerCount;i++){
                printf("\nSecurity has completed checking bag %d.", allBags[i].id);
            }
            printf("\nAll bags have been checked.");
            printf("\nAircraft has taken off!");
            currentTime += 60;
            printf("\n========================");
            printf("\nFlight %d has landed!", currentTime/60);
            capacity = 2000;
            loaderCount = 0;
        }
        printf("\n%d bags left to handle...", numOfBags);
        currentTime++;
        numOfBags--;
    }
    printf("\nSimulation complete.");
    return 0;
}