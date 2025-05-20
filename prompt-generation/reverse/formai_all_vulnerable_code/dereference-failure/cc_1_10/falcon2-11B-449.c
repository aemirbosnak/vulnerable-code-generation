//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char **argv)
{
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    int addrlen;
    char buffer[1024];
    int optval = 1;

    // Create a TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(1);
    }

    // Set the socket option
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Assign the port number
    portno = atoi(argv[1]);

    // Set up server address structure
    memset((char *)&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Waiting for incoming connections...\n");

    while (1) {
        // Accept the incoming connection
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen)) == -1) {
            perror("accept");
            exit(1);
        }

        // Get the client address
        bzero(buffer, sizeof(buffer));
        recv(newsockfd, buffer, sizeof(buffer), 0);

        // Check if the client is allowed to connect
        if (strcmp(buffer, "allowed") == 0) {
            printf("Connection from %s allowed\n", inet_ntoa(cli_addr.sin_addr));
            close(newsockfd);
        } else {
            printf("Connection from %s denied\n", inet_ntoa(cli_addr.sin_addr));
            close(newsockfd);
        }
    }

    close(sockfd);
    return 0;
}