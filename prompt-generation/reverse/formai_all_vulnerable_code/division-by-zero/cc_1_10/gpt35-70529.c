//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_DEVICES 10
#define MAX_THREADS 5

typedef struct device {
    char* ip_address;
    char* name;
    int status;
} Device;

typedef struct thread_data {
    int id;
    Device* devices;
    int num_devices;
} ThreadData;

void* map_topology(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    int i, j;

    printf("Thread %d started mapping topology\n", data->id);

    for (i = 0; i < data->num_devices; i++) {
        printf("Device %s: \n", data->devices[i].name);
        for (j = 0; j < data->num_devices; j++) {
            if (i != j) {
                printf("    - connected to %s\n", data->devices[j].name);
            }
        }
    }

    printf("Thread %d finished mapping topology\n", data->id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];
    Device devices[MAX_DEVICES];
    int num_devices, num_threads;
    int i, j;

    printf("Enter the number of devices (up to %d):\n", MAX_DEVICES);
    scanf("%d", &num_devices);

    if (num_devices > MAX_DEVICES) {
        printf("Error: too many devices, maximum is %d\n", MAX_DEVICES);
        return 1;
    }

    for (i = 0; i < num_devices; i++) {
        devices[i].ip_address = (char*) malloc(sizeof(char) * 16);
        devices[i].name = (char*) malloc(sizeof(char) * 30);

        printf("Enter IP address for device %d:\n", i+1);
        scanf("%s", devices[i].ip_address);

        printf("Enter name for device %d:\n", i+1);
        scanf("%s", devices[i].name);

        devices[i].status = 1;
    }

    printf("Enter the number of threads to use (up to %d):\n", MAX_THREADS);
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS) {
        printf("Error: too many threads, maximum is %d\n", MAX_THREADS);
        return 1;
    }

    int devices_per_thread = num_devices / num_threads;

    for (i = 0; i < num_threads; i++) {
        thread_data[i].id = i;
        thread_data[i].devices = &devices[i * devices_per_thread];
        thread_data[i].num_devices = devices_per_thread;

        if (i == num_threads - 1) {
            // last thread gets any remaining devices
            thread_data[i].num_devices = num_devices - i*devices_per_thread;
        }

        pthread_create(&threads[i], NULL, map_topology, (void*) &thread_data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}