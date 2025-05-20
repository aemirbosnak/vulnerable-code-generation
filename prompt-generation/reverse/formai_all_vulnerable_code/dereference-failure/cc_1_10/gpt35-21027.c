//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

//Function to handle client requests
void handle_client_request(int client_socket, char* remote_ip, int remote_port) {
    //Create a buffer to read client requests
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    //Read client request
    ssize_t n = read(client_socket, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Read error");
        exit(1);
    }
    //Print client request
    printf("[%s:%d] Request:\n%s", inet_ntoa((struct in_addr){client_socket}), ntohs(client_socket), buffer);

    //Open socket to remote server
    int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (remote_socket < 0) {
        perror("Socket error");
        exit(1);
    }

    //Resolve remote server IP address
    struct hostent *remote_server = gethostbyname(remote_ip);
    if (remote_server == NULL) {
        perror("Error resolving remote server");
        exit(1);
    }

    //Connect to remote server
    struct sockaddr_in remote_address;
    bzero(&remote_address, sizeof(remote_address));
    remote_address.sin_family = AF_INET;
    remote_address.sin_addr = *((struct in_addr *) remote_server->h_addr);
    remote_address.sin_port = htons(remote_port);
    if (connect(remote_socket, (const struct sockaddr *) &remote_address, sizeof(remote_address)) < 0) {
        perror("Error connecting to remote server");
        exit(1);
    }

    //Forward client request to remote server
    if (write(remote_socket, buffer, n) < 0) {
        perror("Error sending request to remote server");
        exit(1);
    }

    //Create a buffer to read response from remote server
    bzero(buffer, BUFFER_SIZE);
    //Read response from remote server
    n = read(remote_socket, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error reading response from remote server");
        exit(1);
    }
    //Print response from remote server
    printf("[%s:%d] Response:\n%s", inet_ntoa((struct in_addr){client_socket}), ntohs(client_socket), buffer);

    //Forward response to client
    if (write(client_socket, buffer, n) < 0) {
        perror("Error forwarding response to client");
        exit(1);
    }

    //Close sockets
    close(remote_socket);
    close(client_socket);
}

int main(int argc, char *argv[]) {
    //Check arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <listen_port> <remote_ip> <remote_port>\n", argv[0]);
        exit(1);
    }

    //Parse parameters
    const char *listen_port_str = argv[1];
    const char *remote_ip_str = argv[2];
    const char *remote_port_str = argv[3];

    int listen_port = atoi(listen_port_str);
    if (listen_port <= 0) {
        fprintf(stderr, "%s: Invalid listen port number: %s\n", argv[0], listen_port_str);
        exit(1);
    }

    int remote_port = atoi(remote_port_str);
    if (remote_port <= 0) {
        fprintf(stderr, "%s: Invalid remote port number: %s\n", argv[0], remote_port_str);
        exit(1);
    }

    //Create listening socket
    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket < 0) {
        perror("Socket error");
        exit(1);
    }

    //Bind socket to listen port
    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(listen_port);
    if (bind(listen_socket, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("Bind error");
        exit(1);
    }

    //Listen for incoming connections
    if (listen(listen_socket, 5) < 0) {
        perror("Listen error");
        exit(1);
    }

    //Print server status
    printf("Proxy server running on port %d\n", listen_port);

    while (true) {
        //Accept incoming connection
        struct sockaddr_in client_address;
        socklen_t address_length = sizeof(client_address);
        int client_socket = accept(listen_socket, (struct sockaddr *) &client_address, &address_length);
        if (client_socket < 0) {
            perror("Accept error");
            continue;
        }

        //Handle client request
        handle_client_request(client_socket, remote_ip_str, remote_port);
    }
    return 0;
}