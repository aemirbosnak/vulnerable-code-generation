//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <string.h>

// Function to print the details of the network topology
void print_network_topology() {
    struct sockaddr_in server_addr;
    struct hostent *server;
    struct sockaddr_in client_addr;
    int client_sockfd, server_sockfd, addr_len, port_num, optval;
    char buffer[1024];

    // Creating a socket
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Resolving the server IP address and port number
    if ((server = gethostbyname("localhost")) == NULL) {
        fprintf(stderr, "Hostname not found\n");
        exit(EXIT_FAILURE);
    }

    port_num = htons(80); // Port number for HTTP server

    // Initializing the server address structure
    memset((char *)&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_num);
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    // Connecting to the server
    if (connect(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Sending a request to the server
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n");
    if (send(server_sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receiving the response from the server
    if (recv(server_sockfd, buffer, 1024, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    // Closing the socket
    close(server_sockfd);

    // Resolving the client IP address and port number
    if ((client_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    port_num = htons(80); // Port number for HTTP server

    // Initializing the client address structure
    memset((char *)&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(port_num);
    client_addr.sin_addr.s_addr = INADDR_ANY;

    // Binding the socket to a local address
    if (bind(client_sockfd, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(client_sockfd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accepting the connection
    if ((addr_len = sizeof(client_addr)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    if ((client_sockfd = accept(client_sockfd, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Sending a request to the client
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n");
    if (send(client_sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receiving the response from the client
    if (recv(client_sockfd, buffer, 1024, 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    // Closing the socket
    close(client_sockfd);

    return;
}

int main() {
    print_network_topology();
    return 0;
}