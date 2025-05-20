//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_TECHNICIANS 5
#define MAX_HOLOGRAMS 10

typedef struct {
    int technician_id;
    int hologram_id;
    time_t completion_time;
} Hologram;

typedef struct {
    pthread_mutex_t lock;
    pthread_cond_t condition;
    Hologram holograms[MAX_HOLOGRAMS];
    int hologram_count;
} HolographicLab;

HolographicLab lab;

void *create_hologram(void *arg) {
    int technician_id = *(int *)arg;
    free(arg);

    while (1) {
        pthread_mutex_lock(&lab.lock);

        if (lab.hologram_count >= MAX_HOLOGRAMS) {
            printf("Technician %d: Lab is full, waiting for space...\n", technician_id);
            pthread_cond_wait(&lab.condition, &lab.lock);
        }

        int hologram_id = lab.hologram_count++;
        time(&lab.holograms[hologram_id].completion_time);
        lab.holograms[hologram_id].technician_id = technician_id;
        lab.holograms[hologram_id].hologram_id = hologram_id;

        printf("Technician %d: Created Hologram %d at %s", technician_id, hologram_id, ctime(&lab.holograms[hologram_id].completion_time));

        pthread_mutex_unlock(&lab.lock);

        // Simulate work time to create hologram
        sleep(rand() % 3 + 1); // Random sleep between 1 to 3 seconds

        pthread_mutex_lock(&lab.lock);
        printf("Technician %d: Finalizing Hologram %d\n", technician_id, hologram_id);
        pthread_mutex_unlock(&lab.lock);
    }
    return NULL;
}

void *clear_hologram(void *arg) {
    while (1) {
        pthread_mutex_lock(&lab.lock);

        if (lab.hologram_count > 0) {
            lab.hologram_count--;
            Hologram h = lab.holograms[lab.hologram_count];
            time(&h.completion_time);
            printf("Clear Technician: Cleared Hologram %d created by Technician %d at %s", 
                    h.hologram_id, h.technician_id, ctime(&h.completion_time));
        }

        pthread_cond_signal(&lab.condition);
        pthread_mutex_unlock(&lab.lock);

        // Simulate clearing time
        sleep(rand() % 3 + 1); // Random sleep between 1 to 3 seconds
    }
    return NULL;
}

int main() {
    srand(time(0));
    pthread_t technicians[MAX_TECHNICIANS];
    pthread_t clear_technician;

    // Initialize the holographic lab
    pthread_mutex_init(&lab.lock, NULL);
    pthread_cond_init(&lab.condition, NULL);
    lab.hologram_count = 0;

    // Create Technicians
    for (int i = 0; i < MAX_TECHNICIANS; i++) {
        int *tech_id = malloc(sizeof(int));
        *tech_id = i;
        pthread_create(&technicians[i], NULL, create_hologram, tech_id);
    }

    // Create Clear Technician
    pthread_create(&clear_technician, NULL, clear_hologram, NULL);

    // Wait for the technicians to finish their work (not in this program, let it run indefinitely)
    for (int i = 0; i < MAX_TECHNICIANS; i++)
        pthread_join(technicians[i], NULL);
    pthread_join(clear_technician, NULL);

    // Cleanup
    pthread_mutex_destroy(&lab.lock);
    pthread_cond_destroy(&lab.condition);
    return 0;
}