//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd, n, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[100];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    while (1) {
        // Accept a connection, store the connection details
        clilen = sizeof(cli_addr);
        if ((n = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connected with %s\n", inet_ntoa(cli_addr.sin_addr));

        // Receive the control command from the client
        bzero(buffer, 100);
        n = recv(sockfd, buffer, 100, 0);
        if (n < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        printf("Received command: %s\n", buffer);

        // Send the control response to the client
        bzero(buffer, 100);
        sprintf(buffer, "Command received: %s", buffer);
        n = send(sockfd, buffer, 100, 0);
        if (n < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }
        printf("Sent response: %s\n", buffer);

        // Close the connection
        close(sockfd);
    }

    return 0;
}