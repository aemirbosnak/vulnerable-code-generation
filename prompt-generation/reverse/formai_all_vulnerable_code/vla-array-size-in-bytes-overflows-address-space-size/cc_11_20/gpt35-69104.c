//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int no_of_bags, i, j, k, l;
    printf("Enter the number of bags to simulate: ");
    scanf("%d", &no_of_bags);
    int processing_time[no_of_bags], arrival_time[no_of_bags], departure_time[no_of_bags], total_wait_time[no_of_bags];
    for(i=0; i<no_of_bags; i++){
        processing_time[i] = (rand() % 5) + 1; //random processing time between 1 to 5
        arrival_time[i] = (rand() % 60) + 1; //random arrival time between 1 to 60 seconds
    }
    int conveyor_belt[3] = {-1, -1, -1}; //initializing belt with -1 indicating empty space
    int front_belt = 0, end_belt = 2; //defining belt positions
    int processing_queue[no_of_bags];
    int front_queue = -1, end_queue = -1;
    int current_time, waiting_bag;
    for(current_time=0; current_time<=60; current_time++){ //simulating for 60 seconds
        printf("Time: %d\n", current_time);
        for(j=0; j<3; j++){ //checking if any bag can be processed
            if(conveyor_belt[j] != -1 && processing_time[conveyor_belt[j]] < (current_time - arrival_time[conveyor_belt[j]])){
                printf("Bag %d processed.\n", conveyor_belt[j]);
                departure_time[conveyor_belt[j]] = current_time; //storing departure time
                if(front_queue == -1){ //if no bag in the queue
                    conveyor_belt[j] = -1; // free belt space
                }
                else{ //processing next waiting bag in the queue
                    waiting_bag = processing_queue[front_queue];
                    total_wait_time[waiting_bag] = current_time - arrival_time[waiting_bag];
                    processing_queue[front_queue] = -1;
                    front_queue++;
                    conveyor_belt[j] = waiting_bag;
                }
            }
        }
        for(k=0; k<no_of_bags; k++){ //checking if any bag has arrived for processing
            if(arrival_time[k] == current_time){
                printf("Bag %d arrived.\n", k);
                if(conveyor_belt[end_belt] == -1){ //if belt space available
                    conveyor_belt[end_belt] = k;
                    end_belt = (end_belt + 1) % 3;
                }
                else{ //placing bag in the queue
                    if(front_queue == -1){
                        front_queue = 0;
                    }
                    end_queue++;
                    processing_queue[end_queue] = k;
                }
            }
        }
    }
    double avg_wait_time = 0.0; //calculating average wait time
    for(l=0; l<no_of_bags; l++){
        avg_wait_time += total_wait_time[l];
    }
    avg_wait_time /= no_of_bags;
    printf("Average wait time for %d bags: %lf seconds.", no_of_bags, avg_wait_time);
    return 0;
}