//FormAI DATASET v1.0 Category: Socket programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 5

int client_sockets[MAX_CLIENTS]; // stores client socket file descriptors
pthread_t threads[MAX_CLIENTS]; // stores thread IDs for each client
int server_socket, port;
char buffer[1024];
struct sockaddr_in server_address, client_address;
socklen_t address_len = sizeof(client_address);

void *handle_client(void *client_socket_fd) {
    int socket_fd = *(int *)client_socket_fd;

    while (1) { // loop to receive messages from client
        memset(buffer, 0, sizeof(buffer));
        ssize_t num_bytes = recv(socket_fd, buffer, sizeof(buffer), 0);

        if (num_bytes == -1) {
            perror("Error: recv");
            exit(EXIT_FAILURE);
        } else if (num_bytes == 0) {
            printf("Client with fd %d disconnected\n", socket_fd);
            break;
        } else {
            printf("Received message from client with fd %d: %s", socket_fd, buffer);

            // send back the same message to the client
            if (send(socket_fd, buffer, num_bytes, 0) == -1) {
                perror("Error: send");
                exit(EXIT_FAILURE);
            }
            printf("Sent message back to client with fd %d: %s", socket_fd, buffer);
        }
    }
    close(socket_fd); // close the socket for this client
    pthread_exit(NULL); // exit thread
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    port = atoi(argv[1]);

    // create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error: socket");
        exit(EXIT_FAILURE);
    }

    // bind the socket to the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error: bind");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Error: listen");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections from clients
    int num_clients = 0;
    while (num_clients < MAX_CLIENTS) {
        // accept the connection and get client socket file descriptor
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &address_len);
        if (client_socket == -1) {
            perror("Error: accept");
            exit(EXIT_FAILURE);
        }

        printf("Accepted connection from %s:%d, fd %d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), client_socket);

        // add the client socket file descriptor to the array
        client_sockets[num_clients] = client_socket;

        // create thread to handle this client
        pthread_create(&threads[num_clients], NULL, handle_client, &client_sockets[num_clients]);

        num_clients++;
    }

    // wait for all threads to exit
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        pthread_join(threads[i], NULL);
    }

    // close the server socket
    close(server_socket);

    return 0;
}