//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define PORT_NUM 8080    // port number
#define BACKLOG 10       // maximum number of pending connections
#define BUFSIZE 1024     // maximum buffer size
#define MAX_CLIENTS 5    // maximum number of clients

typedef struct {
    int socket;
    struct sockaddr_in address;
    int address_length;
    int is_active;
} Client;

typedef struct {
    int total_clients;
    Client clients[MAX_CLIENTS];
} ClientList;

void add_client(ClientList *list, Client client) {
    if (list->total_clients < MAX_CLIENTS) {
        list->clients[list->total_clients] = client;
        list->total_clients++;
    }
}

int remove_client(ClientList *list, int socket) {
    for (int i = 0; i < list->total_clients; i++) {
        if (list->clients[i].socket == socket) {
            for (int j = i; j < list->total_clients - 1; j++) {
                list->clients[j] = list->clients[j + 1];
            }
            list->total_clients--;
            return 1;
        }
    }
    return -1;
}

void print_clients(ClientList list) {
    printf("Total clients: %d\n", list.total_clients);
    for (int i = 0; i < list.total_clients; i++) {
        printf("Client %d: %d\n", i + 1, list.clients[i].socket);
    }
}

void send_to_all_clients(ClientList list, char *message) {
    for (int i = 0; i < list.total_clients; i++) {
        send(list.clients[i].socket, message, strlen(message), 0);
    }
}

int main(int argc, char *argv[]) {
    int server_socket;
    struct sockaddr_in server_address;
    ClientList client_list;

    // create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        fprintf(stderr, "Failed to create server socket: %s\n", strerror(errno));
        exit(1);
    }

    // set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT_NUM);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind socket to address
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Failed to bind server socket: %s\n", strerror(errno));
        exit(1);
    }

    // listen for connections
    if (listen(server_socket, BACKLOG) < 0) {
        fprintf(stderr, "Failed to listen for connections: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server started. Listening on port %d...\n", PORT_NUM);

    // initialize client list
    client_list.total_clients = 0;

    while (1) {
        // wait for incoming connections
        struct sockaddr_in client_address;
        int client_socket;
        socklen_t client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_length);

        if (client_socket < 0) {
            fprintf(stderr, "Failed to accept connection: %s\n", strerror(errno));
            continue;
        }

        // initialize client struct
        Client client;
        client.socket = client_socket;
        client.address = client_address;
        client.address_length = client_address_length;
        client.is_active = 1;

        // add client to list
        add_client(&client_list, client);

        // print list of clients
        print_clients(client_list);

        // send welcome message to client
        char message[BUFSIZE];
        sprintf(message, "Welcome to the server! You are client %d.\n", client_list.total_clients);
        send(client_socket, message, strlen(message), 0);
    }

    // close server socket
    close(server_socket);

    return 0;
}