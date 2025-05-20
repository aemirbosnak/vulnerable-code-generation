//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUF_SIZE 1024

// Function to handle client requests
void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUF_SIZE];
    while (1) {
        memset(buffer, 0, BUF_SIZE);
        int bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(client_socket);
    pthread_exit(0);
}

// Function to listen for incoming connections
void *listen_for_connections(void *arg) {
    int server_socket = *(int *) arg;
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            break;
        }
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }
    close(server_socket);
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    int server_socket, port;
    if (argc!= 3) {
        printf("Usage: %s <port_number> <ip_address>\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);
    char *ip_address = argv[2];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 10) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, listen_for_connections, (void *) &server_socket);

    while (1) {
        sleep(1000);
    }

    close(server_socket);
    return 0;
}