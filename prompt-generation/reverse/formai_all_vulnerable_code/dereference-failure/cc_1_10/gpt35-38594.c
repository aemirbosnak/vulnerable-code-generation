//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *ship_simulation(void *arg);

int main()
{
    int num_ships = 5;
    pthread_t *threads = malloc(num_ships * sizeof(pthread_t));
    int *args = malloc(num_ships * sizeof(int));
    int i;

    printf("Welcome to the Space Adventure Game!\n");

    for(i=0;i<num_ships;i++){
        args[i] = i+1;
        pthread_create(&threads[i], NULL, ship_simulation, &args[i]);
    }

    for(i=0;i<num_ships;i++){
        pthread_join(threads[i], NULL);
    }

    printf("Thank you for playing the Space Adventure Game!\n");

    free(threads);
    free(args);
    return 0;
}

void *ship_simulation(void *arg)
{
    int ship_number = *(int*)arg;
    int fuel = 100;
    int distance_left = 1000;
    int encountered_planets = 0;
    int i;

    printf("Spaceship %d: Ready for launch! Fuel: %d, Distance remaining: %d\n", ship_number, fuel, distance_left);

    while(distance_left > 0)
    {
        fuel -= 10;
        distance_left -= 100;
        if(distance_left <= 0)
        {
            printf("Spaceship %d has reached its destination!\n", ship_number);
            break;
        }
        else if(fuel <= 0)
        {
            printf("Spaceship %d has run out of fuel and crashed on planet %d!\n", ship_number, encountered_planets);
            break;
        }
        else if(distance_left < 500 && fuel < 50)
        {
            printf("Spaceship %d is low on fuel and may not make it to its destination!\n", ship_number);
        }
        else if(distance_left % 250 == 0)
        {
            printf("Spaceship %d has encountered planet %d on its journey!\n", ship_number, encountered_planets);
            encountered_planets++;
        }
    }

    pthread_exit(NULL);
}