//FormAI DATASET v1.0 Category: Networking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024 // Maximum size of message to be sent/received
#define PORT 8080    // Port to listen on

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main()
{
    int sockfd, new_socket, clilen, n;
    char buffer[MAXLINE];
    struct sockaddr_in servaddr, cliaddr;
     
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Creating socket file descriptor
    if (sockfd < 0)
        error("Error: Socket creation failed");

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));
     
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY; // Listen on any available interface
    servaddr.sin_port = htons(PORT); // Listening port
     
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        error("Error: Bind failed");
     
    if (listen(sockfd, 5) < 0) // Listening for connections on the bound socket
        error("Error: Listen failed");
     
    printf("Server listening on port %d\n", PORT);

    clilen = sizeof(cliaddr);
    new_socket = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen); // Accepting new connections
    if (new_socket < 0)
        error("Error: Accept failed");

    printf("Connection accepted from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

    while (1) {
        memset(buffer, 0, MAXLINE);
        n = recv(new_socket, buffer, MAXLINE, 0); // Receiving data from client
        if (n <= 0)
            error("Error: Could not receive data");

        printf("Received message: %s", buffer);

        char *message = "Message received successfully\n";
        n = send(new_socket, message, strlen(message), 0); // Sending message to client
        if (n <= 0)
            error("Error: Could not send message");
    }

    close(sockfd);
    return 0;
}