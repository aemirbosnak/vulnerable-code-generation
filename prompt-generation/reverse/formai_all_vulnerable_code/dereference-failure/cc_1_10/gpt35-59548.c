//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int num_of_cars, max_speed, total_time;
    srand(time(NULL));
    
    printf("Enter the number of cars on the road: ");
    scanf("%d", &num_of_cars);
    printf("Enter the maximum speed limit on the road: ");
    scanf("%d", &max_speed);
    printf("Enter the total simulation time: ");
    scanf("%d", &total_time);
    
    int* car_positions = (int*) malloc(num_of_cars * sizeof(int));
    int* car_speeds = (int*) malloc(num_of_cars * sizeof(int));
    
    for(int i=0; i<num_of_cars; i++) {
        car_positions[i] = rand() % 100;
        car_speeds[i] = (rand() % max_speed) + 1; // ensuring minimum speed of 1
    }
    
    printf("\nSimulation Started....\n\n");
    
    for(int t=0; t<=total_time; t++) {
        printf("Time: %d seconds\n", t);
        for(int i=0; i<num_of_cars; i++) {
            printf("Car %d:", i+1);
            
            if(car_positions[i] >= 100) {
                printf(" ARRIVED\n");
                continue;
            }
            
            printf(" Speed: %d kph | Position: %d meters\n", car_speeds[i], car_positions[i]);
            
            int next_pos = car_positions[i] + car_speeds[i];
            
            if(next_pos >= 100) {
                next_pos = 100;
            }
            else {
                for(int j=0; j<num_of_cars; j++) {
                    if(i!=j && car_positions[j] > car_positions[i]) {
                        int dist = car_positions[j] - car_positions[i];
                        int min_gap = 4*(car_speeds[i]+car_speeds[j]); // using 4 seconds gap rule
                        if(dist < min_gap) {
                            next_pos = car_positions[j] - min_gap;
                            break;
                        }
                    }
                }
            }
            
            car_positions[i] = next_pos;
        }
        
        printf("\n");
    }
    
    free(car_positions);
    free(car_speeds);
    
    return 0;
}