//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_CONN 10
#define BUFFER_SIZE 1024

typedef struct {
    char* ip_address;
    int port;
    int socket;
} Connection;

Connection connections[MAX_CONN];
int num_connections = 0;
pthread_mutex_t mutex;

void* client_handler(void* arg) {
    int conn = *(int*) arg;
    char buffer[BUFFER_SIZE];
    while (1) {
        int valread = read(conn, buffer, BUFFER_SIZE);
        if (valread == 0) {
            printf("Client disconnected: %d\n", conn);
            break;
        } else if (valread == -1) {
            printf("Error reading socket: %s\n", strerror(errno));
            break;
        } else {
            // process the command sent by the client
            printf("Received command: %s\n", buffer);
            // send back an acknowledgement
            send(conn, "OK", 2, 0);
        }
        memset(buffer, 0, BUFFER_SIZE);
    }
    close(conn);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    int port = atoi(argv[1]);
    int server_socket, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    // create a TCP socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Error creating socket");
        exit(1);
    }
    // set socket options to allow multiple connections
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Error setting socket options");
        exit(1);
    }
    // bind the socket to a local address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(server_socket, (struct sockaddr*) &address, sizeof(address)) < 0) {
        perror("Error binding to address");
        exit(1);
    }
    // listen for incoming connections
    if (listen(server_socket, MAX_CONN) < 0) {
        perror("Error listening for connections");
        exit(1);
    }
    printf("Server listening on port %d...\n", port);
    // accept incoming connections and handle them in separate threads
    while (1) {
        if ((new_socket = accept(server_socket, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
            perror("Error accepting incoming connection");
            exit(1);
        }
        pthread_t tid;
        if (pthread_create(&tid, NULL, client_handler, &new_socket) != 0) {
            perror("Error creating thread");
            exit(1);
        }
        printf("Client connected: %d\n", new_socket);
        // add the new connection to the list
        if (num_connections < MAX_CONN) {
            Connection conn = {inet_ntoa(address.sin_addr), ntohs(address.sin_port), new_socket};
            pthread_mutex_lock(&mutex);
            connections[num_connections++] = conn;
            pthread_mutex_unlock(&mutex);
        } else {
            printf("Maximum connections reached\n");
        }
    }
    return 0;
}