//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 1024

int threads[MAX_THREADS];
int num_threads = 0;

void *scanner(void *arg) {
    int port = *(int *) arg;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server;

    memset(&server, 0, sizeof(struct sockaddr_in));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return NULL;
    }

    int result = connect(sock, (struct sockaddr *) &server, sizeof(server));
    if (result == -1) {
        printf("Port %d is closed\n", port);
        close(sock);
        return NULL;
    } else {
        printf("Port %d is open\n", port);
        close(sock);
    }

    return NULL;
}

int main() {
    int start_port = 1;
    int end_port = 1024;

    for (int i = start_port; i <= end_port; i++) {
        pthread_t thread_id;
        int ret = pthread_create(&thread_id, NULL, scanner, (void *) &i);
        if (ret!= 0) {
            printf("Error creating thread: %s\n", strerror(errno));
            exit(1);
        }
        num_threads++;
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}