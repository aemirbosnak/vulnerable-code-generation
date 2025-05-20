//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_PAYLOAD 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the hostname and port number
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Create a sockaddr_in structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send a ping message to the server
    char *payload = "PING";
    int payload_len = strlen(payload);
    int n = send(sockfd, payload, payload_len, 0);
    if (n < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive a pong message from the server
    char recvbuf[MAX_PAYLOAD];
    n = recv(sockfd, recvbuf, MAX_PAYLOAD, 0);
    if (n < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the pong message
    printf("Received: %s\n", recvbuf);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}