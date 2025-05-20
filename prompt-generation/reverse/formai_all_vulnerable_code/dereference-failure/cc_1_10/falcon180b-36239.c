//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    char buffer[BUFFER_SIZE];
    int nbytes;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    // Look up server host name
    host_info = gethostbyname("localhost");
    if (host_info == NULL) {
        printf("Error looking up host\n");
        exit(1);
    }

    // Copy server address to struct
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send request to server
    strcpy(buffer, "GET /index.html HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n");
    nbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (nbytes == -1) {
        printf("Error sending request\n");
        exit(1);
    }

    // Receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (nbytes == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    // Print response
    printf("Response:\n%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}