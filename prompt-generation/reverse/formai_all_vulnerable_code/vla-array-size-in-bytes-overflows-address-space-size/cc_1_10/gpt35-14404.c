//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: satisfied
#include<stdio.h>

//structure representing an elevator
struct Elevator {
    int currentFloor; //current floor of the elevator
    int direction; //1 for up and -1 for down
    int numPassengers; //number of passengers in the elevator
};

//function to simulate elevator operation
void elevatorOperation(struct Elevator *elevator, int numFloors, int *passengerFloors, int numPassengers) {
    int i, j;
    for(i=0; i<numFloors; i++) {
        //move the elevator up or down
        elevator->currentFloor+=elevator->direction;
        printf("Elevator moving to floor %d\n", elevator->currentFloor);
        
        //let passengers board the elevator
        for(j=0; j<numPassengers; j++) {
            if(passengerFloors[j] == elevator->currentFloor) {
                printf("Passenger %d boarded the elevator\n", j+1);
                elevator->numPassengers++;
            }
        }
        
        //let passengers exit the elevator
        for(j=0; j<numPassengers; j++) {
            if(passengerFloors[j] == elevator->currentFloor) {
                printf("Passenger %d exited the elevator\n", j+1);
                elevator->numPassengers--;
            }
        }
        
        //change direction if elevator reaches top or bottom floor
        if(elevator->currentFloor == numFloors) {
            elevator->direction=-1;
        }
        else if(elevator->currentFloor == 1) {
            elevator->direction=1;
        }
    }
}

int main() {
    struct Elevator elevator;
    int numFloors, i, numPassengers;
    
    printf("Enter the number of floors: ");
    scanf("%d", &numFloors);
    
    elevator.currentFloor=1;
    elevator.direction=1;
    elevator.numPassengers=0;
    
    printf("Enter the number of passengers: ");
    scanf("%d", &numPassengers);
    
    int passengerFloors[numPassengers];
    for(i=0; i<numPassengers; i++) {
        printf("Enter the floor for passenger %d: ", i+1);
        scanf("%d", &passengerFloors[i]);
    }
    
    elevatorOperation(&elevator, numFloors, passengerFloors, numPassengers);
    
    return 0;
}