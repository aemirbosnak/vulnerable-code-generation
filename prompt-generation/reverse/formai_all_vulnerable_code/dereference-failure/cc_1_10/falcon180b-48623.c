//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_REQUESTS 1000
#define MAX_DATA_SIZE 1024

int num_threads;
int num_requests;
int data_size;
char *server_ip;
int server_port;
int *sockets;

void *send_request(void *arg) {
    int sock = *(int *) arg;
    char request[MAX_DATA_SIZE];
    memset(request, 'A', data_size);
    send(sock, request, data_size, 0);
    close(sock);
    return NULL;
}

void *recv_response(void *arg) {
    int sock = *(int *) arg;
    char response[MAX_DATA_SIZE];
    int bytes_received;
    while ((bytes_received = recv(sock, response, MAX_DATA_SIZE, 0)) > 0) {
        printf("Received %d bytes: %s\n", bytes_received, response);
    }
    close(sock);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 6) {
        fprintf(stderr, "Usage: %s <num_threads> <num_requests> <data_size> <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    num_threads = atoi(argv[1]);
    num_requests = atoi(argv[2]);
    data_size = atoi(argv[3]);
    server_ip = argv[4];
    server_port = atoi(argv[5]);

    sockets = malloc(num_threads * sizeof(int));

    for (int i = 0; i < num_threads; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
            return 1;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(server_port);
        inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

        if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
            fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
            close(sock);
            return 1;
        }

        sockets[i] = sock;
    }

    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, send_request, &sockets[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    free(sockets);
    return 0;
}