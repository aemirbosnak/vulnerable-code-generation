//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <math.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDRESS "speedtest.net"
#define MAX_THREADS 10
#define SLEEP_TIME 1

struct thread_data {
    int sock;
    char buffer[BUFFER_SIZE];
};

void *download_thread(void *arg) {
    struct thread_data *data = arg;
    int bytes_received = 0;
    double start_time = clock();

    while (1) {
        int bytes_read = recv(data->sock, data->buffer, BUFFER_SIZE, 0);
        if (bytes_read <= 0) {
            break;
        }
        bytes_received += bytes_read;
    }

    double end_time = clock();
    double elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;
    double speed = bytes_received / elapsed_time;

    printf("Thread %d received %d bytes in %f seconds (%f bytes/sec)\n",
           data->sock, bytes_received, elapsed_time, speed);

    close(data->sock);
    free(data);
    return NULL;
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct hostent *server = gethostbyname(SERVER_ADDRESS);
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    int num_threads = 0;
    while (num_threads < MAX_THREADS) {
        int thread_sock = accept(server_sock, NULL, NULL);
        if (thread_sock == -1) {
            break;
        }

        struct thread_data *data = malloc(sizeof(struct thread_data));
        data->sock = thread_sock;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, download_thread, data);

        num_threads++;
        usleep(SLEEP_TIME * 1000);
    }

    close(server_sock);
    return 0;
}