//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_THREADS 10
#define MAX_IPS 256
#define BUFFER_SIZE 1024

typedef struct {
    char *ip_address;
    char *result;
} scan_results;

int total_threads;
int threads_running;
pthread_mutex_t result_mutex = PTHREAD_MUTEX_INITIALIZER;

void *scan(void *arg) {
    char command[BUFFER_SIZE];
    scan_results *res = (scan_results*) arg;
    sprintf(command, "nmap -sT %s", res->ip_address);
    FILE *fp = popen(command, "r");

    char buffer[BUFFER_SIZE];
    res->result = (char*) malloc(BUFFER_SIZE * sizeof(char));
    while(fgets(buffer, BUFFER_SIZE, fp)) {
        strcat(res->result, buffer);
    }

    pclose(fp);

    pthread_mutex_lock(&result_mutex);
    threads_running--;
    pthread_mutex_unlock(&result_mutex);

    return NULL;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: ./mapper <subnet>\n");
        printf("Example: ./mapper 192.168.0\n");
        return 1;
    }

    char subnet[16];
    strcpy(subnet, argv[1]);

    pthread_t threads[MAX_THREADS];
    scan_results results[MAX_IPS];

    total_threads = 0;
    threads_running = 0;

    for(int i = 0; i < 256; i++) {
        char *ip_address = (char*) malloc(16 * sizeof(char));
        sprintf(ip_address, "%s.%d", subnet, i);
        results[i].ip_address = ip_address;
    }

    int done = 0;

    while(!done) {
        if(threads_running < MAX_THREADS && total_threads < MAX_IPS) {
            pthread_create(&threads[total_threads], NULL, scan, (void*) &results[total_threads]);
            total_threads++;
            threads_running++;
        }

        done = 1;
        for(int i = 0; i < total_threads; i++) {
            if(results[i].result == NULL) {
                done = 0;
            }
        }
    }

    for(int i = 0; i < total_threads; i++) {
        pthread_join(threads[i], NULL);
        printf("Results for IP Address: %s\n%s\n\n", results[i].ip_address, results[i].result);
    }

    pthread_mutex_destroy(&result_mutex);

    return 0;
}