//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char hostname[MAX_HOSTNAME];
    int port;
    char data[MAX_DATA];
    int data_len;
    struct timeval timeout;

    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(0);
    }

    strncpy(hostname, argv[1], MAX_HOSTNAME);
    port = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Unable to create socket\n");
        exit(1);
    }

    // Set up server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Unable to connect to server\n");
        close(sockfd);
        exit(1);
    }

    // Set up timeout
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    // Send data
    strcpy(data, "PING");
    data_len = strlen(data);
    if (send(sockfd, data, data_len, 0) == -1) {
        printf("Error: Unable to send data\n");
        close(sockfd);
        exit(1);
    }

    // Receive response
    memset(data, 0, MAX_DATA);
    data_len = recv(sockfd, data, MAX_DATA, 0);
    if (data_len <= 0) {
        printf("Error: Unable to receive response\n");
        close(sockfd);
        exit(1);
    }

    printf("Response: %s\n", data);

    close(sockfd);
    return 0;
}