//FormAI DATASET v1.0 Category: Port Scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 10              //maximum number of threads allowed
#define MAX_PORTS 65535             //maximum number of ports that can be scanned

struct thread_args {
    char *ip;
    int start_port;
    int end_port;
};

void *scan_port(void *args) {
    struct thread_args *portscan = args;
    int sock;
    struct sockaddr_in target;
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(portscan->ip);
    int i;
    for (i = portscan->start_port; i <= portscan->end_port; i++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        target.sin_port = htons(i);
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open\n", i);
        }
        close(sock);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }
    char *ip = argv[1];
    pthread_t threads[MAX_THREADS];
    struct thread_args portscans[MAX_THREADS];
    int num_threads = 0;
    int i;
    for (i = 0; i < MAX_PORTS; i = i + MAX_PORTS/MAX_THREADS) {
        struct thread_args portscan;
        portscan.ip = ip;
        portscan.start_port = i;
        portscan.end_port = i + MAX_PORTS/MAX_THREADS - 1;
        if (pthread_create(&threads[num_threads], NULL, scan_port, (void *)&portscan) != 0) {
            printf("Error creating thread %d\n", num_threads);
            return 1;
        }
        num_threads++;
    }
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("Scan complete.\n");
    return 0;
}