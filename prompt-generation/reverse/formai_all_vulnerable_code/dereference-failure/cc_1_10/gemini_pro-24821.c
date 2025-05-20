//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "www.example.com"
#define SERVER_PORT 80
#define THREAD_COUNT 5

struct thread_args {
    int sockfd;
    struct timespec start_time;
    struct timespec end_time;
};

void *thread_func(void *args) {
    struct thread_args *arg = (struct thread_args *)args;

    // Send request to server
    const char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    send(arg->sockfd, request, strlen(request), 0);

    // Start timer
    clock_gettime(CLOCK_MONOTONIC, &arg->start_time);

    // Read response from server
    char buffer[4096];
    int bytes_received = 0;
    while ((bytes_received = recv(arg->sockfd, buffer, sizeof(buffer), 0)) > 0) {
        continue;
    }

    // Stop timer
    clock_gettime(CLOCK_MONOTONIC, &arg->end_time);

    close(arg->sockfd);

    return NULL;
}

int main() {
    struct hostent *server = gethostbyname(SERVER_IP);
    if (server == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    // Create client socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    pthread_t threads[THREAD_COUNT];
    struct thread_args args[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        args[i].sockfd = sockfd;
        pthread_create(&threads[i], NULL, thread_func, &args[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    double total_time = 0.0;
    for (int i = 0; i < THREAD_COUNT; i++) {
        double elapsed_time = (args[i].end_time.tv_sec - args[i].start_time.tv_sec) + (args[i].end_time.tv_nsec - args[i].start_time.tv_nsec) / 1e9;
        total_time += elapsed_time;
    }

    double average_speed = (THREAD_COUNT * 8) / total_time; // in Mbps

    printf("Average speed: %.2f Mbps\n", average_speed);

    close(sockfd);

    return 0;
}