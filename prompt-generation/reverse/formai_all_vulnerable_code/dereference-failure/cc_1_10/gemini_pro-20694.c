//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_PORTS 65535
#define MAX_THREADS 100

typedef struct {
    int port;
    int status;
} PortInfo;

typedef struct {
    int start;
    int end;
} ThreadArgs;

void *scan_ports(void *args) {
    ThreadArgs *ta = (ThreadArgs *)args;
    for (int port = ta->start; port <= ta->end; port++) {
        struct sockaddr_in addr;
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            return NULL;
        }
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = INADDR_ANY;
        addr.sin_port = htons(port);
        int status = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
        if (status == 0) {
            printf("Port %d is open!\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }
        close(sockfd);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip address> <number of threads>\n", argv[0]);
        return 1;
    }
    char *ip_address = argv[1];
    int num_threads = atoi(argv[2]);
    if (num_threads < 1 || num_threads > MAX_THREADS) {
        printf("Number of threads must be between 1 and %d.\n", MAX_THREADS);
        return 1;
    }
    int ports_per_thread = MAX_PORTS / num_threads;
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        ThreadArgs *ta = malloc(sizeof(ThreadArgs));
        ta->start = i * ports_per_thread + 1;
        ta->end = (i + 1) * ports_per_thread;
        pthread_create(&threads[i], NULL, scan_ports, (void *)ta);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}