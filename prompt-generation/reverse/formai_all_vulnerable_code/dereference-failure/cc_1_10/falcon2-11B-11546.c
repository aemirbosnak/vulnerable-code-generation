//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 10
#define MAX_APPOINTMENTS 5

typedef struct {
    int id;
    int appointments[MAX_APPOINTMENTS];
} Appointment;

typedef struct {
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} Scheduler;

void *thread_func(void *arg) {
    int id = *(int *)arg;
    Scheduler *scheduler = (Scheduler *)malloc(sizeof(Scheduler));
    pthread_mutex_init(&scheduler->mutex, NULL);
    pthread_cond_init(&scheduler->cond, NULL);
    int appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;

    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        appointments[i] = -1;
        num_appointments++;
    }

    while (num_appointments > 0) {
        pthread_mutex_lock(&scheduler->mutex);
        if (appointments[id] == -1) {
            appointments[id] = num_appointments;
            pthread_cond_broadcast(&scheduler->cond);
            num_appointments--;
        }
        pthread_mutex_unlock(&scheduler->mutex);
        pthread_cond_wait(&scheduler->cond, &scheduler->mutex);
    }

    pthread_mutex_destroy(&scheduler->mutex);
    pthread_cond_destroy(&scheduler->cond);
    free(scheduler);
}

int main() {
    Appointment appointments[NUM_THREADS];
    int num_appointments = 0;

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, thread_func, (void *)&i);
        appointments[i].id = i;
        appointments[i].appointments[num_appointments] = i;
        num_appointments++;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(appointments[i].appointments[i], NULL);
    }

    printf("Appointments:\n");
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("%d -> ", appointments[i].id);
        for (int j = 0; j < MAX_APPOINTMENTS; j++) {
            if (appointments[i].appointments[j]!= -1) {
                printf("%d ", appointments[i].appointments[j]);
            }
        }
        printf("\n");
    }

    return 0;
}