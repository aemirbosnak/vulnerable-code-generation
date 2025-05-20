//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define RED 0
#define GREEN 1
#define YELLOW 2

bool running = true;
int current_light = RED;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void* traffic_light_controller(void* arg)
{
    while(running)
    {
        pthread_mutex_lock(&mutex);

        if(current_light == RED)
        {
            printf("RED light is on\n");
            sleep(4);
            current_light = GREEN;
            pthread_cond_signal(&cond);
        }
        else if(current_light == GREEN)
        {
            printf("GREEN light is on\n");
            sleep(6);
            current_light = YELLOW;
            pthread_cond_signal(&cond);
        }
        else
        {
            printf("YELLOW light is on\n");
            sleep(2);
            current_light = RED;
            pthread_cond_signal(&cond);
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

void* car(void* arg)
{
    int car_id = *(int*)arg;

    while(running)
    {
        pthread_mutex_lock(&mutex);

        if(current_light == RED)
        {
            printf("Car %d is waiting at the red light\n", car_id);
            pthread_cond_wait(&cond, &mutex);
        }
        else if(current_light == GREEN)
        {
            printf("Car %d is passing through the green light\n", car_id);
            sleep(1);
        }
        else
        {
            printf("Car %d is stopping for the yellow light\n", car_id);
            sleep(1);
            printf("Car %d is passing through the yellow light\n", car_id);
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main()
{
    int num_cars = 10;
    pthread_t controller, car_threads[num_cars];

    pthread_create(&controller, NULL, traffic_light_controller, NULL);

    for(int i=0; i<num_cars; i++)
    {
        int* car_id = malloc(sizeof(int));
        *car_id = i+1;
        pthread_create(&car_threads[i], NULL, car, car_id);
    }

    printf("Traffic light simulator started\n");

    sleep(30);
    running = false;

    pthread_join(controller, NULL);

    for(int i=0; i<num_cars; i++)
    {
        pthread_join(car_threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    printf("Traffic light simulator stopped\n");

    return 0;
}