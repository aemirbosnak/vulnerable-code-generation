//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_CLIENT_DATA_SIZE 2048
#define MAX_SERVER_DATA_SIZE 4096

// function declarations
void handle_client(int client_socket);
void handle_server(int client_socket, char *server_ip, int server_port);

int main(int argc, char *argv[]) {
    // parsing command line arguments
    if (argc != 3) {
        printf("Usage: %s <server_address> <server_port>\n", argv[0]);
        exit(1);
    }
    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    // creating server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // setting socket options
    int reuse = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("Error setting socket options");
        exit(1);
    }

    // binding server socket to port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(server_port);
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket");
        exit(1);
    }

    // listening for incoming connections
    if (listen(server_socket, SOMAXCONN) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Server running on %s:%d\n", inet_ntoa(server_address.sin_addr), server_port);

    // accepting incoming connections
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Error accepting incoming connection");
            continue;
        }
        printf("Accepted new client connection\n");

        // forking a child process to handle client request
        int pid = fork();
        if (pid < 0) {
            perror("Error forking child process");
            continue;
        }
        if (pid == 0) {
            close(server_socket);
            handle_client(client_socket);
            close(client_socket);
            exit(0);
        }
        close(client_socket);
    }
}

// function to handle client request
void handle_client(int client_socket) {
    // reading client request
    char client_data[MAX_CLIENT_DATA_SIZE];
    int client_data_size = read(client_socket, client_data, MAX_CLIENT_DATA_SIZE);
    if (client_data_size < 0) {
        perror("Error reading client request");
        return;
    }
    client_data[client_data_size] = '\0';
    printf("Received client request: %s\n", client_data);

    // parsing client request
    char method[MAX_CLIENT_DATA_SIZE], url[MAX_CLIENT_DATA_SIZE], version[MAX_CLIENT_DATA_SIZE];
    sscanf(client_data, "%s %s %s", method, url, version);

    // checking if client is requesting CONNECT method
    if (strcmp(method, "CONNECT") == 0) {
        char *server_ip;
        int server_port;
        sscanf(url, "%[^:]:%d", server_ip, &server_port);
        printf("Connecting to server: %s:%d\n", server_ip, server_port);
        handle_server(client_socket, server_ip, server_port);
    } else {
        // handling GET method
        // TODO
    }
}

// function to handle server request
void handle_server(int client_socket, char *server_ip, int server_port) {
    // creating server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        return;
    }

    // connecting to server
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);
    if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        return;
    }

    printf("Connected to server\n");

    // forwarding client request to server
    char client_data[MAX_CLIENT_DATA_SIZE];
    int client_data_size = read(client_socket, client_data, MAX_CLIENT_DATA_SIZE);
    if (client_data_size < 0) {
        perror("Error reading client request");
        return;
    }
    client_data[client_data_size] = '\0';
    printf("Forwarding client request to server: %s\n", client_data);
    write(server_socket, client_data, client_data_size);

    // receiving server response
    char server_data[MAX_SERVER_DATA_SIZE];
    int server_data_size = read(server_socket, server_data, MAX_SERVER_DATA_SIZE);
    if (server_data_size < 0) {
        perror("Error receiving server response");
        return;
    }
    server_data[server_data_size] = '\0';
    printf("Received server response: %s\n", server_data);

    // forwarding server response to client
    printf("Forwarding server response to client\n");
    write(client_socket, server_data, server_data_size);

    close(server_socket);
}