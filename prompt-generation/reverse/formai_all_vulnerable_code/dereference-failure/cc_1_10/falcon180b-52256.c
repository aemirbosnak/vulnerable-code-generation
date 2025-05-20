//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_HOST_NAME 256
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct hostent *host;
    struct sockaddr_in serveraddr;
    char hostname[MAX_HOST_NAME];
    char data[MAX_DATA_SIZE];

    // Check arguments
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    // Convert hostname to IP address
    if ((host = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error: %s\n", hstrerror(h_errno));
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    // Set up server address
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    memcpy(&serveraddr.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    // Send data
    strcpy(data, "PING");
    ret = send(sockfd, data, strlen(data), 0);
    if (ret < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    // Receive response
    ret = recv(sockfd, data, MAX_DATA_SIZE, 0);
    if (ret < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }
    data[ret] = '\0';

    // Print response
    printf("Response: %s\n", data);

    // Close socket
    close(sockfd);

    return 0;
}