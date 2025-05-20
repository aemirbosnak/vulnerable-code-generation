//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024

typedef struct {
    int sock;
    struct sockaddr_in server_addr;
} client_t;

void *thread_func(void *arg) {
    client_t *client = (client_t *) arg;
    char data[MAX_DATA_SIZE];

    while (1) {
        memset(data, 0, MAX_DATA_SIZE);
        int bytes_received = recv(client->sock, data, MAX_DATA_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Received data: %s\n", data);
    }

    close(client->sock);
    free(client);
    pthread_exit(NULL);
}

int main() {
    int num_clients = 5;
    pthread_t clients[num_clients];

    struct addrinfo hints, *server_info;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo("localhost", "8080", &hints, &server_info);

    int server_sock = socket(server_info->ai_family, server_info->ai_socktype, 0);

    if (server_sock == -1) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        return 1;
    }

    if (bind(server_sock, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        fprintf(stderr, "Failed to bind socket: %s\n", strerror(errno));
        return 1;
    }

    if (listen(server_sock, 5) == -1) {
        fprintf(stderr, "Failed to listen on socket: %s\n", strerror(errno));
        return 1;
    }

    printf("Server started on port 8080\n");

    for (int i = 0; i < num_clients; i++) {
        pthread_create(&clients[i], NULL, thread_func, (void *) &clients[i]);
    }

    for (int i = 0; i < num_clients; i++) {
        pthread_join(clients[i], NULL);
    }

    close(server_sock);
    freeaddrinfo(server_info);

    return 0;
}