//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_DATA_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDR "127.0.0.1"
#define BUFFER_SIZE 1024
#define NUM_THREADS 5

int sd;
struct sockaddr_in server_addr;
pthread_t threads[NUM_THREADS];

void *thread_func(void *arg) {
    int thread_num = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(sd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Thread %d: Connection closed\n", thread_num);
            pthread_exit(0);
        }

        printf("Thread %d: Received %d bytes of data\n", thread_num, bytes_received);
        printf("Thread %d: Data: %s\n", thread_num, buffer);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    int opt, thread_num;
    char buffer[MAX_DATA_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <thread_number>\n", argv[0]);
        return 1;
    }

    thread_num = atoi(argv[1]);

    if (thread_num < 1 || thread_num > NUM_THREADS) {
        printf("Invalid thread number\n");
        return 1;
    }

    sd = socket(AF_INET, SOCK_STREAM, 0);

    if (sd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDR, &server_addr.sin_addr);

    if (connect(sd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sd);
        return 1;
    }

    printf("Thread %d: Connected to server\n", thread_num);

    while (1) {
        memset(buffer, 0, MAX_DATA_SIZE);
        fgets(buffer, MAX_DATA_SIZE, stdin);

        if (send(sd, buffer, strlen(buffer), 0) == -1) {
            printf("Error sending data\n");
            close(sd);
            return 1;
        }
    }

    return 0;
}