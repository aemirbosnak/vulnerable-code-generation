//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 80
#define MAX_MSG_LEN 50

int main() {
    int sockfd, valread;
    struct sockaddr_in server;
    char buffer[MAX_MSG_LEN];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/mask\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send ping message
    sprintf(buffer, "PING %s HTTP/1.1\r\n\r\n", "google.com");
    valread = write(sockfd, buffer, strlen(buffer));
    if (valread < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    // Read response
    memset(buffer, 0, MAX_MSG_LEN);
    valread = read(sockfd, buffer, MAX_MSG_LEN);
    if (valread < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    // Close socket
    close(sockfd);

    // Print response
    printf("%s\n", buffer);

    return 0;
}