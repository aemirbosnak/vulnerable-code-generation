//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car
{
  int x, y, direction, speed;
  struct Car* next;
} Car;

Car* createCar(int x, int y, int direction, int speed)
{
  Car* car = (Car*)malloc(sizeof(Car));
  car->x = x;
  car->y = y;
  car->direction = direction;
  car->speed = speed;
  car->next = NULL;
  return car;
}

void moveCar(Car* car, int direction, int speed)
{
  switch (direction)
  {
    case 0:
      car->x++;
      break;
    case 1:
      car->y++;
      break;
    case 2:
      car->x--;
      break;
    case 3:
      car->y--;
      break;
  }
  car->speed = speed;
}

void simulateTrafficFlow(int numCars)
{
  Car* head = NULL;
  for (int i = 0; i < numCars; i++)
  {
    Car* car = createCar(i, i, i, 1);
    moveCar(car, i, i);
    head = car;
  }

  while (head)
  {
    moveCar(head, head->direction, head->speed);
    head = head->next;
  }
}

int main()
{
  simulateTrafficFlow(5);
  return 0;
}