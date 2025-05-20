//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: medieval
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// The knights of the realm
typedef struct {
    int id;
    int strength;
    int speed;
    int endurance;
} Knight;

// The king's court
typedef struct {
    int num_knights;
    Knight *knights;
} Court;

// The jousting field
pthread_mutex_t field_mutex = PTHREAD_MUTEX_INITIALIZER;

// The jousting queue
pthread_cond_t queue_cond = PTHREAD_COND_INITIALIZER;

// The jousting thread
void *joust(void *arg) {
    Court *court = (Court *)arg;

    while (1) {
        // Wait for knights to enter the queue
        pthread_cond_wait(&queue_cond, &field_mutex);

        // Joust the knights
        for (int i = 0; i < court->num_knights; i++) {
            for (int j = i + 1; j < court->num_knights; j++) {
                Knight *knight1 = &court->knights[i];
                Knight *knight2 = &court->knights[j];

                if (knight1->strength > knight2->strength) {
                    knight2->endurance -= 1;
                } else if (knight2->strength > knight1->strength) {
                    knight1->endurance -= 1;
                } else {
                    knight1->endurance -= 1;
                    knight2->endurance -= 1;
                }

                if (knight1->endurance <= 0 || knight2->endurance <= 0) {
                    printf("Knight %d has been slain!\n", (knight1->endurance <= 0) ? knight1->id : knight2->id);
                    court->num_knights -= 1;
                }
            }
        }

        // Signal that the joust is over
        pthread_cond_broadcast(&queue_cond);
    }

    return NULL;
}

// The main function
int main() {
    // Create the king's court
    Court court;
    court.num_knights = 10;
    court.knights = malloc(sizeof(Knight) * court.num_knights);

    // Create the knights
    for (int i = 0; i < court.num_knights; i++) {
        court.knights[i].id = i + 1;
        court.knights[i].strength = rand() % 10 + 1;
        court.knights[i].speed = rand() % 10 + 1;
        court.knights[i].endurance = rand() % 10 + 1;
    }

    // Create the jousting thread
    pthread_t joust_thread;
    pthread_create(&joust_thread, NULL, joust, &court);

    // Wait for the knights to enter the queue
    pthread_cond_wait(&queue_cond, &field_mutex);

    // Signal that the joust is over
    pthread_cond_broadcast(&queue_cond);

    // Join the jousting thread
    pthread_join(joust_thread, NULL);

    // Free the knights
    free(court.knights);

    return 0;
}