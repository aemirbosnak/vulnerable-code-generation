//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define MAX_THREADS 10

// Thread data structure
typedef struct {
    int sockfd;
    char *buf;
    int buf_size;
    int bytes_sent;
    int bytes_received;
    struct timeval start_time;
    struct timeval end_time;
} thread_data;

// Thread function
void *thread_func(void *arg) {
    thread_data *data = (thread_data *)arg;

    // Send data to the server
    int bytes_sent = send(data->sockfd, data->buf, data->buf_size, 0);
    if (bytes_sent < 0) {
        perror("send");
        exit(1);
    }
    data->bytes_sent = bytes_sent;

    // Get the current time
    gettimeofday(&data->start_time, NULL);

    // Receive data from the server
    int bytes_received = recv(data->sockfd, data->buf, data->buf_size, 0);
    if (bytes_received < 0) {
        perror("recv");
        exit(1);
    }
    data->bytes_received = bytes_received;

    // Get the current time
    gettimeofday(&data->end_time, NULL);

    // Close the socket
    close(data->sockfd);

    return NULL;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Create the thread pool
    pthread_t threads[MAX_THREADS];
    thread_data data[MAX_THREADS];

    // Allocate the buffer
    char *buf = malloc(BUF_SIZE);
    if (buf == NULL) {
        perror("malloc");
        exit(1);
    }

    // Create the threads
    for (int i = 0; i < MAX_THREADS; i++) {
        data[i].sockfd = sockfd;
        data[i].buf = buf;
        data[i].buf_size = BUF_SIZE;
        data[i].bytes_sent = 0;
        data[i].bytes_received = 0;
        gettimeofday(&data[i].start_time, NULL);
        if (pthread_create(&threads[i], NULL, thread_func, &data[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Wait for the threads to finish
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Calculate the average speed
    int total_bytes_sent = 0;
    int total_bytes_received = 0;
    double total_time = 0;
    for (int i = 0; i < MAX_THREADS; i++) {
        total_bytes_sent += data[i].bytes_sent;
        total_bytes_received += data[i].bytes_received;
        total_time += (data[i].end_time.tv_sec - data[i].start_time.tv_sec) + (data[i].end_time.tv_usec - data[i].start_time.tv_usec) / 1000000.0;
    }
    double avg_speed = (total_bytes_sent + total_bytes_received) / total_time / 1024 / 1024;

    // Print the results
    printf("Average speed: %.2f Mbps\n", avg_speed);

    // Free the buffer
    free(buf);

    // Close the socket
    close(sockfd);

    return 0;
}