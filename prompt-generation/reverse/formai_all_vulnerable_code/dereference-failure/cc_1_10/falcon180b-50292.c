//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define MAX_THREADS 100

int ports[MAX_PORTS];
int num_ports;
pthread_mutex_t mutex;

void *scan_ports(void *arg) {
    int thread_id = (int) arg;
    int start_port = thread_id * (MAX_PORTS / MAX_THREADS) + 1;
    int end_port = start_port + (MAX_PORTS / MAX_THREADS) - 1;

    for (int i = start_port; i <= end_port; i++) {
        pthread_mutex_lock(&mutex);
        if (ports[i] == 0) {
            ports[i] = 1;
        }
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port;

    if (end_port > MAX_PORTS) {
        end_port = MAX_PORTS;
    }

    num_ports = end_port - start_port + 1;

    pthread_t threads[MAX_THREADS];
    int rc;
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, scan_ports, (void *)i);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: unable to join thread, %d\n", rc);
            exit(-1);
        }
    }

    printf("Port Scanning Completed!\n");

    for (i = start_port; i <= end_port; i++) {
        if (ports[i] == 1) {
            printf("Port %d is open.\n", i);
        }
    }

    return 0;
}