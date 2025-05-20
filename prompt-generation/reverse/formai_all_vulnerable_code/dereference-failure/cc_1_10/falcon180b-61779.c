//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 80
#define SERVER_NAME "www.google.com"
#define THREAD_COUNT 10

typedef struct {
    char *data;
    int size;
} Buffer;

void *download_thread(void *arg) {
    int sock = *(int *)arg;
    char *buffer = (char *)malloc(BUFFER_SIZE);
    memset(buffer, 0, BUFFER_SIZE);

    while (1) {
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("%s", buffer);
    }

    free(buffer);
    close(sock);
    return NULL;
}

double get_time_diff(struct timespec start, struct timespec end) {
    double diff_sec = (end.tv_sec - start.tv_sec);
    double diff_nsec = (end.tv_nsec - start.tv_nsec);
    return (diff_sec + (diff_nsec / 1000000000.0));
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_NAME, &server_addr.sin_addr);

    connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    pthread_t threads[THREAD_COUNT];
    int sock[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        sock[i] = socket(AF_INET, SOCK_STREAM, 0);
        connect(sock[i], (struct sockaddr *)&server_addr, sizeof(server_addr));
        pthread_create(&threads[i], NULL, download_thread, (void *)&sock[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    close(server_sock);
    return 0;
}