//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set up the sockaddr_in structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    // Bind the socket to the port
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    while (1) {
        printf("Waiting for connection...\n");

        // Accept the incoming connection
        if ((n = accept(sockfd, (struct sockaddr *)NULL, NULL)) < 0) {
            perror("accept failed");
            continue;
        }

        // Receive and print the data sent by the client
        bzero(buffer, sizeof(buffer));
        n = recv(n, buffer, sizeof(buffer), 0);
        printf("Received %d bytes: %s\n", n, buffer);

        // Close the socket
        close(sockfd);
        break;
    }

    return 0;
}