//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

void proxy_server(int client_socket_fd);

int main(int argc, char *argv[]) {
    int server_socket_fd, client_socket_fd, port_number;
    struct sockaddr_in server_address, client_address;
    char buffer[1024];

    // Creating the server socket
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        printf("Error: Could not create server socket.\n");
        return 1;
    }

    // Configuring the server address structure
    memset(&server_address, 0, sizeof(server_address));
    port_number = atoi(argv[1]);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port_number);

    // Binding the server socket to the server address
    if (bind(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) != 0) {
        printf("Error: Could not bind server socket.\n");
        return 1;
    }

    // Listening to incoming requests
    if (listen(server_socket_fd, 5) != 0) {
        printf("Error: Could not listen for incoming requests.\n");
        return 1;
    }

    printf("Proxy server running on port %d...\n", port_number);

    // Accepting incoming requests and handling them
    while (1) {
        unsigned int client_address_length = sizeof(client_address);
        client_socket_fd = accept(server_socket_fd, (struct sockaddr*)&client_address, &client_address_length);
        if (client_socket_fd == -1) {
            printf("Error: Could not accept incoming request.\n");
            continue;
        }
        printf("Request received from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        if (fork() == 0) {
            proxy_server(client_socket_fd);
            exit(0);
        }
    }

    return 0;
}

void proxy_server(int client_socket_fd) {
    int server_socket_fd, port_number;
    struct sockaddr_in server_address;
    char buffer[1024];

    // Reading the request from the client
    memset(buffer, 0, sizeof(buffer));
    read(client_socket_fd, buffer, sizeof(buffer));
    printf("Request:\n%s\n", buffer);

    // Extracting the requested host and port number
    char *tmp1, *tmp2;
    tmp1 = strstr(buffer, "Host: ") + 6;
    tmp2 = strstr(tmp1, "\r\n");
    *tmp2 = '\0';
    char *host = tmp1;
    if ((tmp1 = strstr(host, ":")) != NULL) {
        *tmp1 = '\0';
        port_number = atoi(tmp1 + 1);
    } else {
        port_number = 80;
    }

    // Creating the server socket
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        printf("Error: Could not create server socket.\n");
        return;
    }

    // Configuring the server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(host);
    server_address.sin_port = htons(port_number);

    // Connecting to the requested server
    if (connect(server_socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) != 0) {
        printf("Error: Could not connect to server.\n");
        return;
    }

    // Forwarding the request to the server
    write(server_socket_fd, buffer, strlen(buffer));

    // Forwarding the server's response to the client
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int n = read(server_socket_fd, buffer, sizeof(buffer));
        if (n == 0) {
            break;
        }
        write(client_socket_fd, buffer, n);
    }

    // Closing the sockets
    close(server_socket_fd);
    close(client_socket_fd);
}