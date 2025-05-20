//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

//constants for floor and elevator
#define FLOORS 10
#define ELEVATORS 4

//function to find the closest elevator to the floor
int find_nearest_elevator(int curr_floor, int* floor_status, int** elevator_status)
{
    int min_dist = FLOORS + 1; //set the minimum distance to the maximum possible value
    int nearest_elevator = -1; //set the elevator number to an invalid value
    
    //iterate over each elevator
    for(int i=0; i<ELEVATORS; i++)
    {
        //if the elevator is idle, use it
        if(elevator_status[i][0] == 0)
        {
            nearest_elevator = i;
            break;
        }
        else //otherwise, check if it can be used to reach the desired floor sooner
        {
            int elevator_floor = elevator_status[i][0];
            int dist = abs(elevator_floor - curr_floor);
            if(dist < min_dist)
            {
                min_dist = dist;
                nearest_elevator = i;
            }
        }
    }
    
    return nearest_elevator;
}

int main()
{
    int floor_status[FLOORS] = {0}; //all floors start with no requests
    int** elevator_status;
    elevator_status = (int**) malloc(ELEVATORS * sizeof(int*));
    for(int i=0; i<ELEVATORS; i++)
    {
        elevator_status[i] = (int*) malloc(2 * sizeof(int)); //each elevator has 2 values - current floor and direction
        elevator_status[i][0] = 1; //all elevators start at ground floor
        elevator_status[i][1] = 0; //all elevators start by going up
    }
    
    while(1) //infinite loop to simulate continuous operation
    {
        //get input from user
        int curr_floor;
        printf("Enter current floor (1 - %d): ", FLOORS);
        scanf("%d", &curr_floor);
        
        //check if there is any request on the current floor
        if(floor_status[curr_floor-1] != 0)
        {
            int curr_direction = floor_status[curr_floor-1];
            int nearest_elevator = find_nearest_elevator(curr_floor, floor_status, elevator_status);
            elevator_status[nearest_elevator][0] = curr_floor;
            elevator_status[nearest_elevator][1] = curr_direction;
            floor_status[curr_floor-1] = 0;
            printf("Elevator %d has been assigned to floor %d\n", nearest_elevator+1, curr_floor);
        }
        else
        {
            printf("No requests on floor %d\n", curr_floor);
        }
        
        //move all elevators one floor in their current direction
        for(int i=0; i<ELEVATORS; i++)
        {
            if(elevator_status[i][0] == 1)
            {
                elevator_status[i][1] = 1;
            }
            else if(elevator_status[i][0] == FLOORS)
            {
                elevator_status[i][1] = 0;
            }
            
            if(elevator_status[i][1] == 0)
            {
                elevator_status[i][0]--;
            }
            else
            {
                elevator_status[i][0]++;
            }
        }
        
        //display current elevator status
        printf("\nCurrent Elevator Status:\n");
        for(int i=0; i<ELEVATORS; i++)
        {
            printf("Elevator %d is on floor %d\n", i+1, elevator_status[i][0]);
        }
        
        //wait for user input before continuing
        printf("\nPress enter to continue...");
        fflush(stdin);
        getchar();
    }
    
    return 0;
}