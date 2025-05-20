//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_DATA_SIZE 1024
#define BUFFER_SIZE 100000
#define NUM_THREADS 5
#define NUM_REQUESTS 10
#define SERVER_PORT 80
#define SERVER_IP "www.google.com"

typedef struct {
    char *data;
    size_t size;
} buffer_t;

typedef struct {
    int sock;
    struct sockaddr_in addr;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = arg;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }
    if (connect(sock, (struct sockaddr *)&data->addr, sizeof(data->addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        exit(1);
    }
    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", SERVER_IP);
    send(sock, request, strlen(request), 0);
    buffer_t buffer;
    buffer.data = malloc(MAX_DATA_SIZE);
    buffer.size = 0;
    while (buffer.size < MAX_DATA_SIZE) {
        int bytes_received = recv(sock, buffer.data + buffer.size, MAX_DATA_SIZE - buffer.size, 0);
        if (bytes_received == 0) {
            break;
        }
        if (bytes_received == -1) {
            printf("Error receiving data\n");
            close(sock);
            exit(1);
        }
        buffer.size += bytes_received;
    }
    close(sock);
    double speed = (double)buffer.size / ((double)NUM_REQUESTS * (double)NUM_THREADS);
    printf("Thread %d completed. Speed: %.2f bytes/sec\n", data->sock, speed);
    free(buffer.data);
}

int main() {
    int i;
    pthread_t threads[NUM_THREADS];
    thread_data_t data[NUM_THREADS];
    for (i = 0; i < NUM_THREADS; i++) {
        data[i].sock = socket(AF_INET, SOCK_STREAM, 0);
        if (data[i].sock == -1) {
            printf("Error creating socket\n");
            exit(1);
        }
        data[i].addr.sin_family = AF_INET;
        data[i].addr.sin_port = htons(SERVER_PORT);
        inet_pton(AF_INET, SERVER_IP, &data[i].addr.sin_addr);
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}