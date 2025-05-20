//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    char hostname[MAX_HOST_NAME];
    char data[MAX_DATA_SIZE];
    struct hostent *host;
    struct sockaddr_in serveraddr;
    int port;

    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage:./ping <hostname> <port>\n");
        return 1;
    }

    // Copy hostname and port from command line arguments
    strcpy(hostname, argv[1]);
    port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address structure
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);

    // Resolve hostname to IP address
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("gethostbyname() failed\n");
        exit(EXIT_FAILURE);
    }

    // Copy IP address to server address structure
    memcpy(&serveraddr.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send data to server
    strcpy(data, "PING");
    numbytes = send(sockfd, data, strlen(data), 0);
    if (numbytes == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    numbytes = recv(sockfd, data, MAX_DATA_SIZE, 0);
    if (numbytes == -1) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    // Print response
    printf("Server response: %s\n", data);

    // Close socket
    close(sockfd);

    return 0;
}