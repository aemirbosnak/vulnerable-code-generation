//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int server_fd, new_socket, bytes_read, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];
    char *hostname = "localhost";
    char *service = "tcp-chat";
    int yes = 1;

    // Create a socket for the server
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Create the address structure for the server socket
    memset((char *)&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    // Bind the socket to the address structure
    if (bind(server_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) < 0) {
        perror("ERROR on listening");
        exit(1);
    }

    while (1) {
        // Accept a connection, blocking if no one is trying to connect
        if ((new_socket = accept(server_fd, (struct sockaddr *)&cli_addr, (socklen_t*)&n)) < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        // Receive data from the client
        bytes_read = recv(new_socket, buffer, 255, 0);
        if (bytes_read < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        // Send data back to the client
        send(new_socket, buffer, bytes_read, 0);

        // Close the connection
        close(new_socket);
    }

    close(server_fd);
    return 0;
}