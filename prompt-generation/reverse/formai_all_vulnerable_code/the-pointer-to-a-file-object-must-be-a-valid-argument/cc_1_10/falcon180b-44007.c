//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4

// Function prototypes
void *monitor_thread(void *arg);
void print_ram_usage();

int main() {
    pthread_t threads[NUM_THREADS];
    int i;

    // Initialize threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, monitor_thread, NULL);
    }

    // Join threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

// Monitor thread function
void *monitor_thread(void *arg) {
    char *thread_name = (char *) arg;
    int thread_num = atoi(thread_name);
    int count = 0;

    while (1) {
        print_ram_usage();
        printf("Thread %d: RAM usage check %d\n", thread_num, count++);
        sleep(5);
    }

    return NULL;
}

// Print current RAM usage
void print_ram_usage() {
    FILE *fp;
    char command[50];
    char output[100];

    sprintf(command, "free | awk 'NR==2{printf \"Current RAM usage: %%d%%\", $3*100/$2 }'");

    fp = popen(command, "r");
    fgets(output, sizeof(output), fp);
    printf("%s", output);
    pclose(fp);
}