//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define POP3_PORT 110
#define POP3_TIMEOUT 5

int main() {
    struct sockaddr_in server_addr;
    int sockfd;
    int opt = 1;
    struct timeval timeout;

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    timeout.tv_sec = POP3_TIMEOUT;
    timeout.tv_usec = 0;

    // Assign server address
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Send POP3 command
    char *command = "USER test\r\n";
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Error sending command");
        exit(EXIT_FAILURE);
    }

    // Receive response
    int response_len = sizeof(command);
    char response[response_len];
    if (recv(sockfd, response, response_len, 0) < 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }

    // Parse response
    if (strstr(response, "+OK")!= NULL) {
        printf("Authentication successful!\n");
    } else {
        printf("Authentication failed!\n");
    }

    // Close socket
    close(sockfd);

    return 0;
}