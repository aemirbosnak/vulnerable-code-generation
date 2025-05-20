//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: calm
#include<stdio.h>

int main()
{
    int num_of_cars, num_of_lanes, time_interval, i, j;
    printf("Enter the number of cars: ");
    scanf("%d", &num_of_cars);
    printf("Enter the number of lanes: ");
    scanf("%d", &num_of_lanes);
    printf("Enter the time interval (in seconds): ");
    scanf("%d", &time_interval);
    
    //Initializing the array to store the number of cars in each lane
    int lane[num_of_lanes];
    for(i=0; i<num_of_lanes; i++)
    {
        lane[i] = 0;
    }
    
    //Simulating the traffic flow for given number of intervals
    for(i=1; i<=10; i++)
    {
        printf("Interval %d\n", i);
        
        //Generating the random number of cars entering each lane in this interval
        int car_count[num_of_lanes];
        for(j=0; j<num_of_lanes; j++)
        {
            car_count[j] = rand()%11;
            printf("\t%d cars enter lane %d\n", car_count[j], j+1);
        }
        
        //Updating the number of cars in each lane
        for(j=0; j<num_of_lanes; j++)
        {
            lane[j] += car_count[j];
        }
        
        //Displaying the number of cars in each lane at the end of this interval
        printf("\tCars in each lane:\n");
        for(j=0; j<num_of_lanes; j++)
        {
            printf("\tLane %d: %d\n", j+1, lane[j]);
        }
        
        //Waiting for the given time interval before simulating the next interval
        sleep(time_interval);
    }
    return 0;
}