//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int target_port;
char target_ip[16];
int num_threads;

void *scan_port(void *arg) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, target_ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(target_port);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == 0) {
        close(sock);
        printf("Port %d is open\n", target_port);
    } else {
        close(sock);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <target_ip> <target_port> <num_threads>\n", argv[0]);
        return 1;
    }

    strcpy(target_ip, argv[1]);
    target_port = atoi(argv[2]);
    num_threads = atoi(argv[3]);

    pthread_t threads[MAX_THREADS];
    int i;

    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, scan_port, NULL);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}