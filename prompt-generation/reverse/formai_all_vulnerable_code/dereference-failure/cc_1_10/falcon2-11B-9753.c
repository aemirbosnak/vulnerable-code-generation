//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 512

int main(int argc, char *argv[])
{
    int sockfd, new_socket, bytes_read, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[MAX_BUF_SIZE], buffer[MAX_BUF_SIZE], *message;
    struct hostent *server;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    // Bind the socket to a port
    portno = atoi(argv[1]);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    printf("Waiting for a connection...\n");

    // Accept the incoming connection
    new_socket = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
    if (new_socket < 0)
    {
        perror("ERROR on accept");
        exit(1);
    }

    printf("Connected by client with address: ");
    printf("%s\n", inet_ntoa(cli_addr.sin_addr));

    printf("Receiving message...\n");

    // Receive the message from the client
    bytes_read = recv(new_socket, buffer, MAX_BUF_SIZE, 0);
    if (bytes_read < 0)
    {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Print the received message
    printf("Received message: %s\n", buffer);

    // Close the connection with the client
    close(new_socket);

    printf("Sending response...\n");

    // Send a response to the client
    message = malloc(MAX_BUF_SIZE);
    sprintf(message, "Hello, client! Your message was: %s", buffer);
    bytes_read = send(new_socket, message, strlen(message), 0);
    if (bytes_read < 0)
    {
        perror("ERROR sending to socket");
        exit(1);
    }

    // Close the connection with the client
    close(new_socket);

    printf("Connection closed with client.\n");

    // Close the server socket
    close(sockfd);

    return 0;
}