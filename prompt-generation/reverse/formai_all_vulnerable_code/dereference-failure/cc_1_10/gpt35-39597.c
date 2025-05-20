//FormAI DATASET v1.0 Category: Networking ; Style: satisfied
// This program demonstrates a simple TCP client-server communication in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 5555

void client_handler(int socket_fd) {
    char buffer[1024];
    int valread;

    while(1) {
        // read message from server
        valread = read(socket_fd, buffer, 1024);
        if(valread <= 0)
            break;

        // print the received message
        printf("Received: %s\n", buffer);

        // clear buffer
        memset(buffer, 0, sizeof(buffer));
    }
}

void server_handler(int socket_fd) {
    char *message = "Hello, I am your server!";
    int client_socket, val_read;
    struct sockaddr_in client_address;
    int addrlen = sizeof(client_address);

    // wait for and accept incoming client connections
    if((client_socket = accept(socket_fd, (struct sockaddr *)&client_address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        return;
    }

    // send a message to the client
    send(client_socket, message, strlen(message), 0);

    // clear the message
    memset(message, 0, strlen(message));

    // receive messages from the client
    while(1) {
        // read the message from the client
        val_read = read(client_socket, message, 1024);
        if(val_read <= 0)
            break;

        // print the received message
        printf("Received: %s\n", message);

        // clear the message
        memset(message, 0, strlen(message));
    }

    // close the client socket
    close(client_socket);
}

int main() {
    int socket_fd, option = 1;
    struct sockaddr_in address;

    // create a socket
    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if(setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0) {
        perror("error setting socket options");
        exit(EXIT_FAILURE);
    }

    // initialize address struct
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind the socket to a port
    if(bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for connections
    if(listen(socket_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // create child to handle client requests
    if(fork() == 0) {
        // child process, handle client requests
        client_handler(socket_fd);
    }
    else {
        // parent process, handle incoming connections
        server_handler(socket_fd);
    }

    // close the socket
    close(socket_fd);

    return 0;
}