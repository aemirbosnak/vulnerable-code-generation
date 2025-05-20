//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: happy
// Hello there! Welcome to my unique HTTP proxy program.
// This proxy program will create a happy server-client relationship :)
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXBUF 1024

// This function will forward the data from client to server and vice versa
int forward_data(int client_fd, int server_fd) {
    int max_fd = (client_fd > server_fd) ? client_fd : server_fd;
    int fds_ready;
    fd_set read_set, write_set;

    char buffer[MAXBUF];
    int nbytes;

    while (1) {
        FD_ZERO(&read_set);
        FD_ZERO(&write_set);

        FD_SET(client_fd, &read_set);
        FD_SET(server_fd, &read_set);

        if (select(max_fd + 1, &read_set, &write_set, NULL, NULL) == -1) {
            perror("Error in select()");
            return -1;
        }

        if (FD_ISSET(client_fd, &read_set)) {
            if ((nbytes = recv(client_fd, buffer, sizeof(buffer), 0)) == -1) {
                perror("Error in recv() from client");
                return -1;
            }
           
            if (nbytes == 0) {
                printf("Closed connection from client\n");
                return 0;
            }
           
            if (send(server_fd, buffer, nbytes, 0) == -1) {
                perror("Error in send() to server");
                return -1;
            }
        }

        if (FD_ISSET(server_fd, &read_set)) {
            if ((nbytes = recv(server_fd, buffer, sizeof(buffer), 0)) == -1) {
                perror("Error in recv() from server");
                return -1;
            }

            if (nbytes == 0) {
                printf("Closed connection from server\n");
                return 0;
            }

            if (send(client_fd, buffer, nbytes, 0) == -1) {
                perror("Error in send() to client");
                return -1;
            }
        }
    }

    return 0;
}

// Main function will set up the socket and start listening to client connections
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server_ip> <port_number>\n", argv[0]);
        return -1;
    }

    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    int server_len, client_len;

    // Creating server socket
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error in creating server socket");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    server_len = sizeof(server_addr);

    // Binding server socket to the given IP address and port number
    if (bind(server_sockfd, (struct sockaddr *) &server_addr, server_len) == -1) {
        perror("Error in binding server socket");
        return -1;
    }

    // Start listening to client connections
    if (listen(server_sockfd, 5) == -1) {
        perror("Error in listening to client connections");
        return -1;
    } 

    printf("Proxy server listening on port %s...\n", argv[2]);
    printf("Proxy server started with a smile :) !\n");

    while (1) {
        client_len = sizeof(client_addr);

        // Accept client connection and create new client socket
        if ((client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_len)) == -1) {
            perror("Error in accepting client connection");
            continue;
        }

        printf("Accepted connection from %s\n", inet_ntoa(client_addr.sin_addr));

        // Create new server socket
        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        struct hostent *host = gethostbyname("www.google.com");
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_addr = *((struct in_addr*)host->h_addr_list[0]);
        server_address.sin_port = htons(80);

        // Connect to server
        if (connect(server_sockfd, (struct sockaddr *)&server_address, sizeof(struct sockaddr)) == -1) {
            perror("Error in connecting to server");
            continue;
        }

        printf("Connected to server\n");

        // Forward data from client to server and vice versa
        forward_data(client_sockfd,server_sockfd);

        // Close client and server sockets
        close(client_sockfd);
        close(server_sockfd);
    }

    return 0;
}