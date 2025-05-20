//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 100
#define MAX_CARS 10
#define MAX_SPEED 5

int getPosition(int** road, int lane, int position){
    if(position < 0){
        return getPosition(road, lane, ROAD_LENGTH + position);
    }else if(position >= ROAD_LENGTH){
        return getPosition(road, lane, position - ROAD_LENGTH);
    }else{
        return road[lane][position];
    }
}

void updateCar(int** road, int lane, int position){
    // move the car at this position
    int speed = getPosition(road, lane, position);
    if(speed > 0){
        int emptySpace = 0;
        while(getPosition(road, lane, position + emptySpace + 1) == 0 && emptySpace + 1 <= speed){
            emptySpace++;
        }
        road[lane][position + emptySpace] = road[lane][position];
        road[lane][position] = 0;
    }
}

void updateLane(int** road, int lane){
    // move all cars in the lane
    for(int i = 0; i < ROAD_LENGTH; i++){
        if(getPosition(road, lane, i) > 0){
            updateCar(road, lane, i);
        }
    }
}

void updateRoad(int** road){
    // update all lanes
    for(int i = 0; i < 2; i++){
        updateLane(road, i);
    }
}

void insertCar(int** road, int lane, int position, int speed){
    road[lane][position] = speed;
}

int main(){
    srand(time(NULL));

    // initialize road
    int** road = (int**) malloc(sizeof(int*) * 2);
    for(int i = 0; i < 2; i++){
        road[i] = (int*) calloc(ROAD_LENGTH, sizeof(int));
    }

    // insert cars
    int numCars = rand() % (MAX_CARS + 1);
    for(int i = 0; i < numCars; i++){
        int lane = rand() % 2;
        int position = rand() % ROAD_LENGTH;
        int speed = rand() % (MAX_SPEED + 1);
        insertCar(road, lane, position, speed);
    }

    // run simulation
    for(int i = 0; i < 10; i++){
        updateRoad(road);

        // print road
        printf("Road state after %d seconds:\n", i);
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < ROAD_LENGTH; k++){
                printf("%d ", getPosition(road, j, k));
            }
            printf("\n");
        }
        printf("-------------------------\n");
    }

    // free memory
    for(int i = 0; i < 2; i++){
        free(road[i]);
    }
    free(road);

    return 0;
}