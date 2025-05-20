//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_THREADS 100
#define BUFFER_SIZE 1024

int thread_function(void *data) {
    int *port = (int *)data;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server;
    int sockfd;
    int ret;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Thread %d: Error creating socket\n", *port);
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(*port);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server, sizeof(server));
    if (ret == -1) {
        printf("Thread %d: Error connecting to %d\n", *port, *port);
        close(sockfd);
        exit(1);
    }

    printf("Thread %d: Connected to %d\n", *port, *port);
    close(sockfd);
    exit(0);
}

int main(int argc, char *argv[]) {
    int start_port, end_port, i;
    pthread_t threads[MAX_THREADS];

    if (argc!= 4) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    start_port = atoi(argv[1]);
    end_port = atoi(argv[2]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    for (i = start_port; i <= end_port; i++) {
        pthread_create(&threads[i - start_port], NULL, thread_function, (void *)&i);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}