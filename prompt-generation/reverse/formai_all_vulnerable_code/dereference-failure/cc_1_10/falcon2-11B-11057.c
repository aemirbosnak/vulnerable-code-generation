//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/tcp.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int listen_socket, conn_socket, portno, charsWritten, charsRead;
    struct sockaddr_in serverAddr, clientAddr;
    char buffer[1024];
    int n;

    // Initialize the server socket
    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket < 0) {
        error("ERROR opening socket");
    }

    // Assign the port number
    portno = atoi(argv[1]);

    // Set up the server address struct
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(portno);

    // Bind to the port
    if (bind(listen_socket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        error("ERROR on binding");
    }

    // Start listening
    listen(listen_socket, 5);

    while (1) {
        // Accept a connection
        conn_socket = accept(listen_socket, (struct sockaddr *)&clientAddr, (socklen_t *)&charsRead);
        if (conn_socket < 0) {
            error("ERROR on accept");
        }

        // Read from the client
        bzero(buffer, sizeof(buffer));
        n = read(conn_socket, buffer, sizeof(buffer));
        if (n < 0) {
            error("ERROR reading from socket");
        }

        // Process the request
        printf("Received request: %s\n", buffer);

        // Send the response
        sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body>This is a test!</body></html>");
        charsWritten = write(conn_socket, buffer, strlen(buffer));
        if (charsWritten < 0) {
            error("ERROR writing to socket");
        }

        // Close the connection
        close(conn_socket);
    }

    close(listen_socket);
    return 0;
}