//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: secure
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int sockfd, numbytes, n;
    struct sockaddr_in serveraddr, clientaddr;
    struct hostent *server, *client;
    char buffer[256];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the server address
    server = gethostbyname("router");
    if (server == NULL) {
        perror("ERROR resolving server address");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(80);
    bcopy((char *) server->h_addr, (char *) &serveraddr.sin_addr.s_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("ERROR connecting to server");
        exit(EXIT_FAILURE);
    }

    // Resolve the client address
    bzero((char *) &clientaddr, sizeof(clientaddr));
    clientaddr.sin_family = AF_INET;
    clientaddr.sin_port = htons(0);
    bcopy((char *) server->h_addr, (char *) &clientaddr.sin_addr.s_addr, server->h_length);

    // Send the hostname and IP address of each node in the network topology
    for (int i = 0; i < 10; i++) {
        sprintf(buffer, "Node%d", i);
        send(sockfd, buffer, strlen(buffer), 0);

        printf("Hostname: %s\n", inet_ntoa(clientaddr.sin_addr));
        printf("IP Address: %s\n", inet_ntoa(clientaddr.sin_addr));
    }

    // Close the socket
    close(sockfd);

    return 0;
}