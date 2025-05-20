//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define BAGGAGE_COUNT 10
#define MAX_CAPACITY 5
#define TIME_DELAY 1

typedef struct {
    int id;
    char *description;
    int weight;
} Baggage;

Baggage baggage[BAGGAGE_COUNT];

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void *baggage_generator(void *arg) {
    for (int i = 0; i < BAGGAGE_COUNT; i++) {
        sleep(rand() % 3);
        Baggage new_baggage;
        new_baggage.id = i;
        new_baggage.description = (char *)malloc(30 * sizeof(char));
        sprintf(new_baggage.description, "Cyber Gear %d", i);
        new_baggage.weight = rand() % 20 + 1; // Weight between 1 and 20
        printf("🚀 Generating baggage: %s (Weight: %dkg)\n", new_baggage.description, new_baggage.weight);

        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        baggage[i] = new_baggage;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }

    return NULL;
}

void *baggage_handler(void *arg) {
    for (int i = 0; i < BAGGAGE_COUNT; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        Baggage current_baggage = baggage[i];
        printf("🤖 Processing baggage: %s (Weight: %dkg)\n", current_baggage.description, current_baggage.weight);
        
        // Simulate handling time
        sleep(TIME_DELAY);

        printf("🎒 Baggage processed: %s is on route to destination!\n", current_baggage.description);
        
        free(current_baggage.description);
        
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }

    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t generator_thread;
    pthread_t handler_thread;

    sem_init(&empty, 0, MAX_CAPACITY);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    printf("📦 Starting Baggage Handling Simulation... 💼\n");

    pthread_create(&generator_thread, NULL, baggage_generator, NULL);
    pthread_create(&handler_thread, NULL, baggage_handler, NULL);

    pthread_join(generator_thread, NULL);
    pthread_join(handler_thread, NULL);

    printf("✅ All baggage processed! Simulation Complete. 🥳\n");

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}