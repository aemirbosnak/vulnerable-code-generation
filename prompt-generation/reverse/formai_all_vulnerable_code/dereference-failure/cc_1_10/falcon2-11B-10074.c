//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: high level of detail
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, valread, numbytes, i;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        return 1;
    }

    // Set up the server address structure
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        return 1;
    }

    // Read the client address information
    valread = sizeof(cli_addr);
    if (getsockname(sockfd, (struct sockaddr *) &cli_addr, &valread) < 0) {
        perror("getsockname failed");
        return 1;
    }

    printf("Client IP: %s\n", inet_ntoa(cli_addr.sin_addr));
    printf("Client Port: %d\n", ntohs(cli_addr.sin_port));

    // Read data from the server
    while (1) {
        numbytes = read(sockfd, buffer, sizeof(buffer));
        if (numbytes <= 0) {
            break;
        }

        printf("Received: %s\n", buffer);
    }

    // Clean up
    close(sockfd);
    return 0;
}