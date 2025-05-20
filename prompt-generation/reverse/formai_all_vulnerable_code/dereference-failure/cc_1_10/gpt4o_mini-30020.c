//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 100
#define START_PORT 1
#define END_PORT 65535

int active_threads = 0;
pthread_mutex_t mutex;

typedef struct {
    char *ip;
    int port;
} scan_task_t;

void *scan_port(void *arg) {
    scan_task_t *task = (scan_task_t *) arg;
    int sock;
    struct sockaddr_in server;
    int result;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return NULL;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(task->port);
    server.sin_addr.s_addr = inet_addr(task->ip);

    result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result == 0) {
        printf("Port %d on %s is OPEN\n", task->port, task->ip);
    } else {
        // Uncomment the next line for more verbose output
        // printf("Port %d on %s is CLOSED\n", task->port, task->ip);
    }

    close(sock);
    free(task);
    
    pthread_mutex_lock(&mutex);
    active_threads--;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void print_usage() {
    printf("Usage: ./port_scanner <IP_ADDRESS>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    char *ip_address = argv[1];
    pthread_t thread[MAX_THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int port = START_PORT; port <= END_PORT; port++) {
        // Create a new scan task
        scan_task_t *task = (scan_task_t *) malloc(sizeof(scan_task_t));
        task->ip = ip_address;
        task->port = port;

        pthread_mutex_lock(&mutex);
        active_threads++;
        pthread_mutex_unlock(&mutex);
        
        // Create a new thread to scan the port
        if (pthread_create(&thread[port % MAX_THREADS], NULL, scan_port, (void *) task) != 0) {
            fprintf(stderr, "Failed to create thread for port %d\n", port);
            free(task);
        }

        // Join threads if we have reached maximum allowed threads
        if (active_threads >= MAX_THREADS) {
            for (int j = 0; j < MAX_THREADS; j++) {
                pthread_join(thread[j], NULL);
            }
            active_threads = 0; // Reset for next batch
        }
    }

    // Join remaining threads if any
    for (int j = 0; j < active_threads; j++) {
        pthread_join(thread[j], NULL);
    }

    pthread_mutex_destroy(&mutex);
    printf("Port scanning completed for %s\n", ip_address);
    return 0;
}