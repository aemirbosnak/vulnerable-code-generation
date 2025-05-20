//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: introspective
#include <stdio.h> 

int main() 
{ 
    printf("Welcome to the Traffic Flow Simulation Program!\n\n"); 

    int numCars = 10; // set initial number of cars 
    int numLanes = 2; // set initial number of lanes 
    int totalTime = 0; // initialize total time 
    int i, j; // loop variables 

    // prompt user for input 
    printf("Enter number of cars: "); 
    scanf("%d", &numCars); 

    printf("Enter number of lanes: "); 
    scanf("%d", &numLanes); 

    // create 2D array for traffic flow 
    int trafficFlow[numLanes][numCars]; 

    // initialize array to all zeros 
    for(i=0; i<numLanes; i++) 
    { 
        for(j=0; j<numCars; j++) 
        { 
            trafficFlow[i][j] = 0; 
        } 
    } 

    // simulate traffic flow 
    for(i=0; i<numCars; i++) 
    { 
        int shortestLane = 0; 
        int shortestLaneLength = numCars; 

        // find shortest lane 
        for(j=0; j<numLanes; j++) 
        { 
            int laneLength = 0; 

            // calculate length of current lane 
            for(int k=i; k>=0; k--) 
            { 
                if(trafficFlow[j][k] == 1) 
                { 
                    laneLength++; 
                } 
                else 
                { 
                    break; 
                } 
            } 

            // update shortest lane if applicable 
            if(laneLength < shortestLaneLength) 
            { 
                shortestLane = j; 
                shortestLaneLength = laneLength; 
            } 
        } 

        // add car to shortest lane 
        trafficFlow[shortestLane][i] = 1; 

        // display current traffic flow 
        printf("\nTraffic flow at time %d:\n", i+1); 
        for(j=0; j<numLanes; j++) 
        { 
            printf("Lane %d: ", j+1); 
            for(int k=0; k<numCars; k++) 
            { 
                printf("%d ", trafficFlow[j][k]); 
            } 
            printf("\n"); 
        } 

        // increment total time 
        totalTime++; 
    } 

    // display total time 
    printf("\nTotal time to clear traffic: %d seconds\n", totalTime); 

    return 0; 
}