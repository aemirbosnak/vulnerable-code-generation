//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: distributed
/* C Network Ping Test Example Program */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTNAME_LEN 64
#define MAX_DATA_SIZE 64
#define TIMEOUT_SEC 5

int main(int argc, char *argv[]) {

    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LEN];
    strcpy(hostname, argv[1]);

    int port = atoi(argv[2]);

    int sockfd;
    struct sockaddr_in servaddr;
    char senddata[MAX_DATA_SIZE];
    char recvdata[MAX_DATA_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        return 1;
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &servaddr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    // Send data
    strcpy(senddata, "PING");
    send(sockfd, senddata, strlen(senddata), 0);

    // Receive data
    memset(recvdata, 0, MAX_DATA_SIZE);
    int bytes_received = recv(sockfd, recvdata, MAX_DATA_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving data\n");
        close(sockfd);
        return 1;
    }

    // Check response
    if (strcmp(recvdata, "PONG")!= 0) {
        printf("Error: Invalid response\n");
        close(sockfd);
        return 1;
    }

    printf("Ping successful\n");
    close(sockfd);
    return 0;
}