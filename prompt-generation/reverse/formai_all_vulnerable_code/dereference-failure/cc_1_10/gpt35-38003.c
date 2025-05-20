//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <unistd.h>

#define PORT 8080
#define MAX_THREADS 50
#define MAX_HOSTS 1000

int num_hosts;
int available_hosts;
char** hosts;

pthread_mutex_t mutex;

void* scan_hosts(void* arg) {
    int index = *(int*) arg;
    struct sockaddr_in address;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    while (1) {
        pthread_mutex_lock(&mutex);
        if (available_hosts >= num_hosts) {
            pthread_mutex_unlock(&mutex);
            break;
        }
        int host_index = available_hosts;
        available_hosts++;
        pthread_mutex_unlock(&mutex);
        char* host = hosts[host_index];
        inet_pton(AF_INET, host, &address.sin_addr);
        int result = connect(sock, (struct sockaddr*) &address, sizeof(address));
        if (result == 0) {
            printf("%s is alive.\n", host);
        }
        close(sock);
    }
    return NULL;
}

int main(int argc, char** argv) {
    num_hosts = argc - 1;
    available_hosts = 0;
    hosts = malloc(num_hosts * sizeof(char*));
    for (int i = 0; i < num_hosts; i++) {
        hosts[i] = strdup(argv[i + 1]);
    }
    pthread_t threads[MAX_THREADS];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < MAX_THREADS; i++) {
        int* arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&threads[i], NULL, scan_hosts, arg);
    }
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    for (int i = 0; i < num_hosts; i++) {
        free(hosts[i]);
    }
    free(hosts);
    return 0;
}