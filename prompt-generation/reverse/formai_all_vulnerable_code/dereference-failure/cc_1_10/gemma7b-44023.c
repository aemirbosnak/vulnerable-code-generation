//Gemma-7B DATASET v1.0 Category: Table Game ; Style: brave
#include <stdlib.h>
#include <time.h>

#define NUM_CARS 5
#define TRACK_LENGTH 20

typedef struct RaceCar
{
    int position;
    int speed;
    char color;
} RaceCar;

void initializeRaceCars(RaceCar *cars)
{
    for (int i = 0; i < NUM_CARS; i++)
    {
        cars[i].position = 0;
        cars[i].speed = 1;
        cars[i].color = 'A' + i;
    }
}

void race(RaceCar *cars)
{
    for (int i = 0; i < TRACK_LENGTH; i++)
    {
        for (int j = 0; j < NUM_CARS; j++)
        {
            cars[j].position++;

            if (cars[j].position >= TRACK_LENGTH)
            {
                cars[j].position = TRACK_LENGTH - 1;
                cars[j].speed = 0;
            }
        }

        sleep(1);
    }
}

int main()
{
    RaceCar *cars = malloc(NUM_CARS * sizeof(RaceCar));

    initializeRaceCars(cars);
    race(cars);

    free(cars);

    return 0;
}