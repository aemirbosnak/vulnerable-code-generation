//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX_ELEVATORS 4
#define NUM_FLOORS 10

struct Elevator {
  int id;
  int currentFloor;
  int targetFloor;
  int direction; // 1 for up, -1 for down, 0 for stationary
};

struct Floor {
  int id;
  int waiting; //number of passengers waiting
  pthread_mutex_t floor_mutex;
  pthread_cond_t floor_cond;
};

struct Floor floors[NUM_FLOORS];
struct Elevator elevators[MAX_ELEVATORS];

//function to move the elevator
void *moveElevator(void *arg);

//function to handle passenger requests
void *requestHandler(void *arg);

int main(int argc, char *argv[]) {
  int numPassengers = atoi(argv[1]);

  //initialize floors
  for(int i=0; i<NUM_FLOORS; i++) {
    floors[i].id = i;
    floors[i].waiting = 0;
    pthread_mutex_init(&floors[i].floor_mutex, NULL);
    pthread_cond_init(&floors[i].floor_cond, NULL);
  }

  //initialize elevators
  for(int i=0; i<MAX_ELEVATORS; i++) {
    elevators[i].id = i;
    elevators[i].currentFloor = 0;
    elevators[i].targetFloor = -1;
    elevators[i].direction = 0;
  }

  //create passenger request threads
  pthread_t requestThread[numPassengers];
  for(int i=0; i<numPassengers; i++) {
    pthread_create(&requestThread[i], NULL, requestHandler, NULL);
  }

  //create elevator threads
  pthread_t elevatorThread[MAX_ELEVATORS];
  for(int i=0; i<MAX_ELEVATORS; i++) {
    pthread_create(&elevatorThread[i], NULL, moveElevator, &elevators[i].id);
  }

  //join passenger request threads
  for(int i=0; i<numPassengers; i++) {
    pthread_join(requestThread[i], NULL);
  }

  //join elevator threads
  for(int i=0; i<MAX_ELEVATORS; i++) {
    pthread_join(elevatorThread[i], NULL);
  }

  return 0;
}

void *moveElevator(void *arg) {
  int elevatorID = *((int*)arg);
  struct Elevator *myElevator = &elevators[elevatorID];

  while(1) {
    if(myElevator->targetFloor != -1) {
      //elevator has a target floor
      if(myElevator->currentFloor < myElevator->targetFloor) {
        myElevator->direction = 1;
        myElevator->currentFloor++;
      }
      else if(myElevator->currentFloor > myElevator->targetFloor) {
        myElevator->direction = -1;
        myElevator->currentFloor--;
      }
      else {
        myElevator->direction = 0;
        myElevator->targetFloor = -1;
      }
    }
    else {
      //elevator is idle
      myElevator->direction = 0;
    }

    //check if elevator needs to stop at current floor
    pthread_mutex_lock(&floors[myElevator->currentFloor].floor_mutex);
    if(myElevator->direction == 1 && floors[myElevator->currentFloor].waiting > 0) {
      //stop elevator and let passengers enter
      printf("Elevator %d stopping at floor %d\n", myElevator->id, myElevator->currentFloor);
      myElevator->targetFloor = -1;
      floors[myElevator->currentFloor].waiting = 0;
      pthread_cond_broadcast(&floors[myElevator->currentFloor].floor_cond);
    }
    else if(myElevator->direction == -1 && floors[myElevator->currentFloor].waiting < 0) {
      //stop elevator and let passengers exit
      printf("Elevator %d stopping at floor %d\n", myElevator->id, myElevator->currentFloor);
      myElevator->targetFloor = -1;
      floors[myElevator->currentFloor].waiting = 0;
      pthread_cond_broadcast(&floors[myElevator->currentFloor].floor_cond);
    }
    pthread_mutex_unlock(&floors[myElevator->currentFloor].floor_mutex);

    //wait for some time before moving to next floor
    usleep(10000);
  }
}

void *requestHandler(void *arg) {
  int sourceFloor = rand() % 10;
  int destinationFloor = rand() % 10;
  while(destinationFloor == sourceFloor) {
    destinationFloor = rand() % 10;
  }
  printf("Passenger requested elevator from floor %d to floor %d\n", sourceFloor, destinationFloor);

  //wait for elevator
  pthread_mutex_lock(&floors[sourceFloor].floor_mutex);
  floors[sourceFloor].waiting++;
  pthread_cond_wait(&floors[sourceFloor].floor_cond, &floors[sourceFloor].floor_mutex);
  pthread_mutex_unlock(&floors[sourceFloor].floor_mutex);

  //board elevator
  printf("Passenger boarded elevator at floor %d\n", sourceFloor);

  //wait for destination floor
  pthread_mutex_lock(&floors[destinationFloor].floor_mutex);
  floors[destinationFloor].waiting--;
  pthread_cond_wait(&floors[destinationFloor].floor_cond, &floors[destinationFloor].floor_mutex);
  pthread_mutex_unlock(&floors[destinationFloor].floor_mutex);

  //arrive at destination floor
  printf("Passenger arrived at destination floor %d\n", destinationFloor);

  return NULL;
}