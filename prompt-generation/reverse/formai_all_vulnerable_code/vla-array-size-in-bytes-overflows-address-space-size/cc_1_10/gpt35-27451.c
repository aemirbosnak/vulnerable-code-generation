//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to simulate traffic flow
void simulateTrafficFlow(int lanes, int hours){

    int i, j, current_traffic_density = 0, total_cars = 0, max_traffic_density = 100;
    int min_traffic_density = 0, min_speed = 20, max_speed = 80, max_cars_per_hour = 60, min_cars_per_hour = 30;
    float average_speed = 0.0, speed_sum = 0.0;
    int cars_per_hour[hours], car_speed[hours], traffic_density[hours];

    //initialize random number generator
    srand((unsigned)time(NULL));
    
    //initialize traffic density randomly for each hour
    for(i = 0; i < hours; i++){
        traffic_density[i] = (rand() % (max_traffic_density - min_traffic_density)) + min_traffic_density;
        cars_per_hour[i] = (rand() % (max_cars_per_hour - min_cars_per_hour)) + min_cars_per_hour;
        car_speed[i] = (rand() % (max_speed - min_speed)) + min_speed;
    }
    
    //simulate traffic for each hour
    for(i = 0; i < hours; i++){
        
        printf("Hour %d\n", i+1);
        printf("Traffic Density: %d\n", traffic_density[i]);
        printf("Cars per hour: %d\n", cars_per_hour[i]);
        printf("Average car speed: %d\n", car_speed[i]);
        
        total_cars += cars_per_hour[i];
        current_traffic_density = traffic_density[i];
        
        //if traffic is heavy flow slower and if traffic is light flow faster
        if(current_traffic_density >= 0 && current_traffic_density < 30){
            average_speed = car_speed[i] + 20;
        }
        else if(current_traffic_density >= 30 && current_traffic_density < 60){
            average_speed = car_speed[i] + 10;
        }
        else if(current_traffic_density >= 60 && current_traffic_density <= 100){
            average_speed = car_speed[i];
        }
        
        for(j = 1; j <= cars_per_hour[i]; j++){
            
            //calculate speed for each car
            int car_speed = (rand() % (int)average_speed) + 1;
            speed_sum += car_speed;
            
        }
        
        //calculate average speed for the hour
        printf("Average Speed: %.2f\n", speed_sum/cars_per_hour[i]);
        printf("\n");
        
    }
    
    //calculate overall average speed 
    printf("Overall Average Speed: %.2f", speed_sum/total_cars);

}

//driver code
int main(){
    
    int lanes, hours;
    printf("Enter number of lanes: ");
    scanf("%d", &lanes);
    
    printf("Enter number of hours to simulate: ");
    scanf("%d", &hours);
    
    simulateTrafficFlow(lanes, hours);
    
    return 0;
}