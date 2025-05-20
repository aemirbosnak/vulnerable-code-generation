//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10

// Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *subnet_calculator(void *arg) {
    char *ip_address = (char *) arg;
    int octet1, octet2, octet3, octet4;
    char subnet_mask[16];
    char *token;

    // Convert IP address to integer
    sscanf(ip_address, "%d.%d.%d.%d", &octet1, &octet2, &octet3, &octet4);

    // Calculate subnet mask
    snprintf(subnet_mask, sizeof(subnet_mask), "255.255.255.%d", (255 - octet4) & 255);

    // Print results
    printf("IP Address: %s\n", ip_address);
    printf("Subnet Mask: %s\n", subnet_mask);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i, rc;

    // Get input from user
    char input[100];
    printf("Enter IP addresses (one per line):\n");
    fgets(input, sizeof(input), stdin);

    // Create threads for each IP address
    char *ip_address = strtok(input, "\n");
    while (ip_address!= NULL) {
        if (i >= MAX_THREADS) {
            printf("Maximum number of threads reached.\n");
            break;
        }
        rc = pthread_create(&threads[i], NULL, subnet_calculator, ip_address);
        if (rc) {
            printf("Error creating thread: %d\n", rc);
            break;
        }
        ip_address = strtok(NULL, "\n");
        i++;
    }

    // Join threads
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}