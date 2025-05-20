//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int scan_port(int sock, int port);
void *thread_func(void *arg);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + 100;

    int num_threads = 0;
    pthread_t threads[MAX_THREADS];
    int ports[MAX_THREADS];

    for (int i = start_port; i <= end_port && num_threads < MAX_THREADS; i++) {
        ports[num_threads] = i;
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)&ports[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

int scan_port(int sock, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    int result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (result == 0) {
        printf("Port %d is open\n", port);
    } else if (errno == ECONNREFUSED) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Error scanning port %d: %s\n", port, strerror(errno));
    }

    close(sock);
    return 0;
}

void *thread_func(void *arg) {
    int port = *((int *)arg);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return NULL;
    }

    scan_port(sock, port);
    close(sock);

    return NULL;
}