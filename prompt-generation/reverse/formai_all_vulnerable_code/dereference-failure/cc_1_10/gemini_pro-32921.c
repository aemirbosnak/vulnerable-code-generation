//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024
#define PORT 5000

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAX_LINE];
    char *host;
    int port;

    // Parse command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }
    host = argv[1];
    port = atoi(argv[2]);

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Resolve the hostname
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr = *(struct in_addr *)he->h_addr_list[0];

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send a message to the server
    strcpy(buffer, "Hello from client");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive a message from the server
    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Print the received message
    printf("%s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}