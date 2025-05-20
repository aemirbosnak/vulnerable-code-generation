//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MESSAGE_SIZE 1024
#define NUM_THREADS 4

struct thread_args {
    int sockfd;
    struct sockaddr_in server_addr;
    int num_bytes;
    char *buffer;
};

void *thread_func(void *args) {
    struct thread_args *arg = (struct thread_args *)args;

    int sockfd = arg->sockfd;
    struct sockaddr_in server_addr = arg->server_addr;
    int num_bytes = arg->num_bytes;
    char *buffer = arg->buffer;

    int nbytes;
    struct timeval start, end;

    // Start the timer
    gettimeofday(&start, NULL);

    // Send a message to the server
    nbytes = sendto(sockfd, buffer, num_bytes, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (nbytes < 0) {
        perror("sendto");
        exit(1);
    }

    // Receive a message from the server
    nbytes = recvfrom(sockfd, buffer, num_bytes, 0, NULL, NULL);
    if (nbytes < 0) {
        perror("recvfrom");
        exit(1);
    }

    // Stop the timer
    gettimeofday(&end, NULL);

    // Calculate the elapsed time
    long elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

    // Calculate the speed
    double speed = (elapsed_time / 1000000.0) * (num_bytes / 1024.0) * 8;

    // Print the speed
    printf("Speed: %.2f Mbps\n", speed);

    // Close the socket
    close(sockfd);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <num_bytes>\n", argv[0]);
        exit(1);
    }

    char *server_ip = argv[1];
    int num_bytes = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Create the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(5555);

    // Create the thread arguments
    struct thread_args args[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        args[i].sockfd = sockfd;
        args[i].server_addr = server_addr;
        args[i].num_bytes = num_bytes;
        args[i].buffer = malloc(num_bytes);
    }

    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &args[i]);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close the socket
    close(sockfd);

    return 0;
}