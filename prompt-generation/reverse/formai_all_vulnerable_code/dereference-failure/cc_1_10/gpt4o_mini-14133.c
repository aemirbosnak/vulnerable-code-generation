//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define NUM_SERVERS 2
#define NUM_GUESTS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    int id;
    char *name;
} Guest;

Guest *guestList[NUM_GUESTS];
pthread_t threads[NUM_GUESTS];

void* serenade(void* arg) {
    Guest *guest = (Guest *)arg;

    pthread_mutex_lock(&mutex);
    printf("%s, of the noble house of Capulet, enters the gathering.\n", guest->name);
    printf("A song of love fills the air, as %s stands ready to serenade.\n", guest->name);
    sleep(1); // Simulating the time taken to serenade
    printf("%s finishes the serenade and seeks a reply.\n\n", guest->name);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* plot_twist(void* arg) {
    int id = *((int*)arg);
    
    pthread_mutex_lock(&mutex);
    if (id == 0) {
        printf("As the clock strikes midnight, a forbidden love blooms.\n");
    } else {
        printf("Amidst the dance, a hidden feud reawakens.\n");
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    printf("A tale of Romeo and Juliet, set in the midst of a grand festivity...\n\n");

    char *names[NUM_GUESTS] = {"Romeo", "Juliet", "Mercutio", "Tybalt", "Benvolio"};
    int ids[NUM_GUESTS];

    // Initialize guests
    for (int i = 0; i < NUM_GUESTS; i++) {
        guestList[i] = (Guest *)malloc(sizeof(Guest));
        guestList[i]->id = i;
        guestList[i]->name = names[i];
        ids[i] = i;
    }

    // Create threads for serenading guests
    for (int i = 0; i < NUM_GUESTS; i++) {
        pthread_create(&threads[i], NULL, serenade, (void*)guestList[i]);
    }

    // Create threads for plot twists
    for (int i = 0; i < NUM_SERVERS; i++) {
        pthread_create(&threads[i + NUM_GUESTS], NULL, plot_twist, (void*)&ids[i]);
    }

    // Join all threads
    for (int i = 0; i < NUM_GUESTS + NUM_SERVERS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up and release resources
    for (int i = 0; i < NUM_GUESTS; i++) {
        free(guestList[i]);
    }

    printf("The festival ends, but the tale of Romeo and Juliet shall echo forever...\n");

    return 0;
}