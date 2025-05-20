//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/select.h>

int main(int argc, char *argv[]) {
    int server_fd, new_socket, portno;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    int addrlen = sizeof(cli_addr);
    char buffer[256];
    char client_name[256];

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Assign the socket to the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    // Bind the socket to a port
    if (bind(server_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for connections
    if (listen(server_fd, 5) < 0) {
        perror("ERROR on listen");
        exit(1);
    }

    while (1) {
        // Accept a connection
        if ((new_socket = accept(server_fd, (struct sockaddr *) &cli_addr, &addrlen)) < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        // Get the client name
        if (getsockname(new_socket, (struct sockaddr *) &cli_addr, &addrlen) < 0) {
            perror("ERROR on getsockname");
            exit(1);
        }
        strcpy(client_name, inet_ntoa(cli_addr.sin_addr));

        // Send a welcome message to the client
        printf("Client %s connected\n", client_name);

        // Receive a message from the client
        if (recv(new_socket, buffer, sizeof(buffer), 0) < 0) {
            perror("ERROR on recv");
            exit(1);
        }
        printf("Received message from client %s: %s\n", client_name, buffer);

        // Send a response to the client
        sprintf(buffer, "Thank you for connecting to the server, %s!\n", client_name);
        if (send(new_socket, buffer, strlen(buffer), 0) < 0) {
            perror("ERROR on send");
            exit(1);
        }

        // Close the connection
        close(new_socket);
    }

    return 0;
}