//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the surrealist struct
typedef struct surrealist {
    char name[50];
    int dream_level;
    pthread_t thread_id;
} surrealist_t;

// Create surrealist function
void *surrealist_dream(void *arg) {
    surrealist_t *surrealist = (surrealist_t *) arg;
    int i;

    // Dream sequence
    for (i = 0; i < surrealist->dream_level; i++) {
        printf("%s is dreaming of %d melting clocks.\n", surrealist->name, i);
        sleep(1);
    }

    // Wake up
    printf("%s has woken up from their dream.\n", surrealist->name);

    return NULL;
}

// Main function
int main() {
    int i, num_surrealists;
    surrealist_t *surrealists;
    pthread_t threads[10];

    // Ask user for number of surrealists
    printf("How many surrealists would you like to create? ");
    scanf("%d", &num_surrealists);

    // Create surrealists
    surrealists = (surrealist_t *) malloc(num_surrealists * sizeof(surrealist_t));
    for (i = 0; i < num_surrealists; i++) {
        surrealists[i].dream_level = i + 1;
        sprintf(surrealists[i].name, "Surrealist %d", i + 1);

        // Create thread for each surrealist
        pthread_create(&threads[i], NULL, surrealist_dream, (void *) &surrealists[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < num_surrealists; i++) {
        pthread_join(threads[i], NULL);
    }

    free(surrealists);

    return 0;
}