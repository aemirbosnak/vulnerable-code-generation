//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define NUM_DETECTIVES 3
#define NUM_CASES 5

typedef struct {
    int case_id;
    char description[256];
} Case;

typedef struct {
    Case cases[NUM_CASES];
    pthread_mutex_t lock;
} CaseFile;

void* investigate_case(void* arg) {
    int detective_id = *((int*)arg);
    CaseFile* case_file = (CaseFile*)malloc(sizeof(CaseFile));
    pthread_mutex_init(&case_file->lock, NULL);

    // Dummy cases for the detectives to solve
    for (int i = 0; i < NUM_CASES; i++) {
        case_file->cases[i].case_id = i + 1;
        sprintf(case_file->cases[i].description, "Case %d: Mysterious disappearance of the baker.", i + 1);
    }

    for (int i = 0; i < NUM_CASES; i++) {
        pthread_mutex_lock(&case_file->lock);
        
        printf("Detective %d investigating %s...\n", detective_id, case_file->cases[i].description);
        // Simulate some investigation time
        sleep(rand() % 3 + 1);
        printf("Detective %d has solved %s!\n", detective_id, case_file->cases[i].description);

        pthread_mutex_unlock(&case_file->lock);
    }

    pthread_mutex_destroy(&case_file->lock);
    free(case_file);
    return NULL;
}

int main() {
    pthread_t detectives[NUM_DETECTIVES];
    int detective_ids[NUM_DETECTIVES];

    srand(time(NULL)); // Seed the random number generator

    printf("Sherlock Holmes and the Case of the Missing Baker...\n");

    // Create each detective thread
    for (int i = 0; i < NUM_DETECTIVES; i++) {
        detective_ids[i] = i + 1; // Detective IDs start from 1
        if (pthread_create(&detectives[i], NULL, investigate_case, &detective_ids[i]) != 0) {
            fprintf(stderr, "Error creating detective thread %d\n", i + 1);
            return EXIT_FAILURE;
        }
    }

    // Join each detective thread
    for (int i = 0; i < NUM_DETECTIVES; i++) {
        pthread_join(detectives[i], NULL);
    }

    printf("The investigation is complete. All cases have been solved!\n");
    return EXIT_SUCCESS;
}