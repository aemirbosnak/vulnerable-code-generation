//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>

//structure to define a car
struct car {
   int id;
   int speed;
   int position;
   int distance;
};

//function to generate a random integer between min and max
int randomInt(int min, int max) {
   return (rand() % (max - min + 1)) + min;
}

int main() {
   int numCars, timeLimit, timeStep, i;

   //get user input for number of cars, time limit, and time step
   printf("Enter the number of cars: ");
   scanf("%d", &numCars);

   printf("Enter the time limit (in seconds): ");
   scanf("%d", &timeLimit);

   printf("Enter the time step (in seconds): ");
   scanf("%d", &timeStep);

   //allocate memory for array of car structures
   struct car *cars = malloc(numCars * sizeof(struct car));

   //initialize each car's id, speed, position, and distance
   for(i = 0; i < numCars; i++) {
      cars[i].id = i+1;
      cars[i].speed = randomInt(30, 100);
      cars[i].position = randomInt(0, 600);
      cars[i].distance = 0;
   }

   //simulate traffic flow for the specified time limit
   for(i = 0; i < timeLimit; i += timeStep) {
      printf("Time: %d seconds\n", i);

      //update each car's position and distance
      for(int j = 0; j < numCars; j++) {
         cars[j].distance += cars[j].speed * timeStep;
         cars[j].position += cars[j].speed * timeStep;

         //check if car has reached the end of the road
         if(cars[j].position >= 1000) {
            printf("Car %d has reached its destination!\n", cars[j].id);
            cars[j].speed = 0;
            cars[j].position = 1000;
            cars[j].distance = 1000;
         }
      }

      //check for collisions
      for(int j = 0; j < numCars; j++) {
         for(int k = j + 1; k < numCars; k++) {
            if(cars[j].position == cars[k].position) {
               printf("Car %d has collided with car %d!\n", cars[j].id, cars[k].id);
               cars[j].speed = 0;
               cars[k].speed = 0;
            }
         }
      }
   }

   //free memory allocated for cars array
   free(cars);

   printf("\nSimulation complete.\n");

   return 0;
}