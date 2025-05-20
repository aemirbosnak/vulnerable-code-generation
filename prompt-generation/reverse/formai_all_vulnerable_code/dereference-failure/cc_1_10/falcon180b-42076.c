//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <math.h>

#define MAX_THREADS 10

int num_threads;
pthread_t threads[MAX_THREADS];

void *runner(void *param);

int main(int argc, char **argv) {
    int i;
    char *ip_address = argv[1];
    char *netmask = argv[2];
    char *gateway = argv[3];
    char *dns1 = argv[4];
    char *dns2 = argv[5];

    num_threads = atoi(argv[6]);

    printf("Starting %d threads...\n", num_threads);
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, runner, (void *)i);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *runner(void *param) {
    int thread_id = (int)param;
    char ip_address[16];
    char netmask[16];
    char gateway[16];
    char dns1[16];
    char dns2[16];

    sprintf(ip_address, "192.168.%d.%d", thread_id, 2);
    sprintf(netmask, "255.255.255.0");
    sprintf(gateway, "192.168.%d.1", thread_id);
    sprintf(dns1, "8.8.8.8");
    sprintf(dns2, "8.8.4.4");

    printf("Thread %d settings:\n", thread_id);
    printf("IP Address: %s\n", ip_address);
    printf("Netmask: %s\n", netmask);
    printf("Gateway: %s\n", gateway);
    printf("DNS1: %s\n", dns1);
    printf("DNS2: %s\n", dns2);

    return NULL;
}