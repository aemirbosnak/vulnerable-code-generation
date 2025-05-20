//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    //initialize variables
    int numBags, i;
    srand(time(0));

    //ask user for number of bags
    printf("Enter number of bags: ");
    scanf("%d", &numBags);

    //initialize arrays to hold bag information
    int* bagIDs = (int*)malloc(numBags*sizeof(int));
    int* bagWeights = (int*)malloc(numBags*sizeof(int));
    int* conveyorIDs = (int*)malloc(numBags*sizeof(int));

    //fill in bag information randomly
    for(i=0;i<numBags;i++){
        bagIDs[i] = i+1;
        bagWeights[i] = rand()%31 + 20; //random weight between 20 and 50 kg
        conveyorIDs[i] = rand()%5 + 1; //random conveyor between 1 and 5
    }

    //print out bag information
    printf("BAGS:\n");
    for(i=0;i<numBags;i++){
        printf("Bag %d: weight=%dkg, conveyor=%d\n", bagIDs[i], bagWeights[i], conveyorIDs[i]);
    }

    //initialize variables for tracking conveyor usage
    int conveyor1=0, conveyor2=0, conveyor3=0, conveyor4=0, conveyor5=0;
    int totalWeight1=0, totalWeight2=0, totalWeight3=0, totalWeight4=0, totalWeight5=0;

    //place bags on respective conveyors and track usage
    for(i=0;i<numBags;i++){
        switch(conveyorIDs[i]){
            case 1:
                conveyor1++;
                totalWeight1 += bagWeights[i];
                break;
            case 2:
                conveyor2++;
                totalWeight2 += bagWeights[i];
                break;
            case 3:
                conveyor3++;
                totalWeight3 += bagWeights[i];
                break;
            case 4:
                conveyor4++;
                totalWeight4 += bagWeights[i];
                break;
            case 5:
                conveyor5++;
                totalWeight5 += bagWeights[i];
                break;
            default:
                printf("Invalid conveyor number!\n");
                break;
        }
    }

    //print out conveyor usage and weight statistics
    printf("\nCONVEYOR USAGE:\n");
    printf("Conveyor 1: %d bags\n", conveyor1);
    printf("Conveyor 2: %d bags\n", conveyor2);
    printf("Conveyor 3: %d bags\n", conveyor3);
    printf("Conveyor 4: %d bags\n", conveyor4);
    printf("Conveyor 5: %d bags\n\n", conveyor5);
    printf("WEIGHT STATISTICS:\n");
    printf("Conveyor 1: total weight=%dkg, average weight=%.2fkg\n", totalWeight1, ((float)totalWeight1)/conveyor1);
    printf("Conveyor 2: total weight=%dkg, average weight=%.2fkg\n", totalWeight2, ((float)totalWeight2)/conveyor2);
    printf("Conveyor 3: total weight=%dkg, average weight=%.2fkg\n", totalWeight3, ((float)totalWeight3)/conveyor3);
    printf("Conveyor 4: total weight=%dkg, average weight=%.2fkg\n", totalWeight4, ((float)totalWeight4)/conveyor4);
    printf("Conveyor 5: total weight=%dkg, average weight=%.2fkg\n", totalWeight5, ((float)totalWeight5)/conveyor5);

    //free allocated memory
    free(bagIDs);
    free(bagWeights);
    free(conveyorIDs);

    return 0;
}