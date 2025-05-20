//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

typedef struct
{
    int id;
    int *baggage;
} PassengerData;

pthread_mutex_t mutex;
int conveyorBelt[20];
int nextBeltSlot = 0;
int numCheckedBags = 0;
int numLostBags = 0;
int numPassengers = 0;

void * passenger(void *arg)
{
    PassengerData passengerData = *((PassengerData*) arg);

    // Generate random number of bags (1-3 bags)
    int numBags = rand() % 3 + 1;
    passengerData.baggage = (int*)calloc(numBags, sizeof(int));
    for (int i = 0; i < numBags; i++)
    {
        passengerData.baggage[i] = rand() % 500 + 1; // bag weight between 1-500 lbs
    }

    // Passenger adds bags to conveyor belt
    pthread_mutex_lock(&mutex);
    printf("Passenger %d places %d bags on the conveyor belt.\n", passengerData.id, numBags);
    for (int i = 0; i < numBags; i++)
    {
        if (nextBeltSlot >= 20)
        {
            numLostBags++;
            printf("No more space on conveyor belt, bag %d of passenger %d is lost.\n", i+1, passengerData.id);
        }
        else
        {
            conveyorBelt[nextBeltSlot] = passengerData.baggage[i];
            nextBeltSlot++;
        }
    }
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

void * securityScan(void *arg)
{
    while (numCheckedBags < numPassengers * 2) // all checked bags go through twice
    {
        pthread_mutex_lock(&mutex);
        if (nextBeltSlot == 0)
        {
            pthread_mutex_unlock(&mutex);
            continue; // skip if conveyor belt is empty
        }

        int bag = conveyorBelt[0];
        for (int i = 0; i < nextBeltSlot; i++)
        {
            conveyorBelt[i] = conveyorBelt[i+1];
        }
        nextBeltSlot--;

        printf("Security scan detects %d lb bag.\n", bag);
        if (bag > 50)
        {
            printf("Bag is overweight and will be removed.\n");
            numLostBags++;
        }
        else
        {
            numCheckedBags++;
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);

    printf("Enter number of passengers: ");
    scanf("%d", &numPassengers);

    PassengerData passengerData[numPassengers];

    // create passenger threads
    for (int i = 0; i < numPassengers; i++)
    {
        passengerData[i].id = i + 1;
        pthread_create(&threads[i], NULL, passenger, (void *)&passengerData[i]);
    }

    // create security scan threads
    for (int i = numPassengers; i < numPassengers * 2; i++)
    {
        pthread_create(&threads[i], NULL, securityScan, NULL);
    }

    // wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Number of bags lost: %d\n", numLostBags);
    printf("Number of bags checked: %d\n", numCheckedBags);

    pthread_mutex_destroy(&mutex);
    return 0;
}