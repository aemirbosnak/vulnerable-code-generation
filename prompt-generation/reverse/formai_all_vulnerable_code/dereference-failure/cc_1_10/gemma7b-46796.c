//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_CARS 10
#define MAX_LANE 3

typedef struct Car
{
    int lane;
    int position;
    int speed;
    int direction;
    struct Car* next;
} Car;

Car* createCar(int lane, int position, int speed, int direction)
{
    Car* newCar = (Car*)malloc(sizeof(Car));
    newCar->lane = lane;
    newCar->position = position;
    newCar->speed = speed;
    newCar->direction = direction;
    newCar->next = NULL;
    return newCar;
}

void simulateTrafficFlow()
{
    Car* head = createCar(1, 0, 5, 1);
    head->next = createCar(2, 10, 3, -1);
    head->next->next = createCar(0, 20, 4, 1);
    head->next->next->next = createCar(1, 30, 3, -1);

    time_t t = time(NULL);
    while (time(NULL) - t < 10)
    {
        for (Car* car = head; car; car = car->next)
        {
            switch (car->direction)
            {
                case 1:
                    car->position++;
                    break;
                case -1:
                    car->position--;
                    break;
            }

            if (car->position >= MAX_LANE * car->lane)
            {
                car->direction *= -1;
            }
            else if (car->position <= 0)
            {
                car->direction *= -1;
            }
        }

        sleep(1);
    }

    free(head);
}

int main()
{
    simulateTrafficFlow();
    return 0;
}