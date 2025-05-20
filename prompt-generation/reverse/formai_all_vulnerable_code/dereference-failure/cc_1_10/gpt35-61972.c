//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5  // number of threads to be created
#define MAX_DATA_SIZE 100  // maximum size of the received data
#define MAX_SSIDs 10  // maximum number of SSIDs to be scanned
#define MAX_SSID_LEN 20  // maximum length of an SSID name

pthread_mutex_t mutex;  // mutex to synchronize access to shared variables

// structure to hold the data of an SSID and its signal strength
typedef struct {
    char name[MAX_SSID_LEN];
    int strength;
} ssid_data_t;

// global variables
ssid_data_t ssids_data[MAX_SSIDs];  // array of all scanned SSIDs and their strength
int num_ssids = 0;  // number of scanned SSIDs

// function of each thread to scan and parse the received data
void *thread_func(void *arg) {
    char *data = (char *) arg;  // received data
    char *ptr;  // pointer for parsing the data
    int i, strength;
    char name[MAX_SSID_LEN];

    // parse data to get SSID name and signal strength
    ptr = strtok(data, ",");
    while (ptr != NULL) {
        strcpy(name, ptr);
        ptr = strtok(NULL, ",");
        strength = atoi(ptr);
        ptr = strtok(NULL, ",");
        
        // update global variables in a critical section
        pthread_mutex_lock(&mutex);
        for (i = 0; i < num_ssids; i++) {
            if (strcmp(ssids_data[i].name, name) == 0) {
                ssids_data[i].strength = strength;
                break;
            }
        }
        if (i == num_ssids) {
            strcpy(ssids_data[num_ssids].name, name);
            ssids_data[num_ssids].strength = strength;
            num_ssids++;
        }
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() {
    int i, j;
    char data[MAX_DATA_SIZE];
    pthread_t threads[NUM_THREADS];

    // create threads to scan and parse the received data concurrently
    for (i = 0; i < NUM_THREADS; i++) {
        fgets(data, MAX_DATA_SIZE, stdin);
        pthread_create(&threads[i], NULL, thread_func, (void *) data);
    }

    // wait for all threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // print the scanned SSIDs and their signal strength
    for (i = 0; i < num_ssids; i++) {
        printf("%s: ", ssids_data[i].name);
        for (j = 0; j < ssids_data[i].strength; j++) {
            printf("-");
        }
        printf("\n");
    }

    return 0;
}