//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 65535
#define MAX_THREAD_NAME 16

struct hostent *host;
int target_port, target_ip;
char target_name[64];
int max_threads = MAX_THREADS;
int max_ports = MAX_PORTS;
int thread_count = 0;
int port_count = 0;
pthread_t threads[MAX_THREADS];
int port_range[MAX_PORTS];

void *port_scan(void *arg) {
    int thread_id = *(int *) arg;
    int start_port = thread_id * (max_ports / max_threads);
    int end_port = (thread_id == max_threads - 1)? max_ports : (thread_id + 1) * (max_ports / max_threads);

    for (int i = start_port; i <= end_port; i++) {
        if (port_count >= max_ports) break;
        port_range[port_count++] = i;
    }

    return NULL;
}

void print_open_ports() {
    printf("Open Ports:\n");
    for (int i = 0; i < port_count; i++) {
        printf("%d\n", port_range[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    strcpy(target_name, argv[1]);
    target_port = atoi(argv[2]);

    if ((host = gethostbyname(target_name)) == NULL) {
        printf("Error: Invalid IP Address\n");
        return 1;
    }

    target_ip = *(int *) host->h_addr;

    printf("Scanning %s for open ports...\n", target_name);

    for (int i = 0; i < max_threads; i++) {
        pthread_create(&threads[i], NULL, port_scan, (void *) &i);
    }

    for (int i = 0; i < max_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    print_open_ports();

    return 0;
}