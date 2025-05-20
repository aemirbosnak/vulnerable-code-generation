//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define SERVER_IP "192.168.1.100"
#define SERVER_PORT 80
#define BUFFER_SIZE 1024
#define TIMEOUT 5000 // 5 seconds

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int timeout_count = 0;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send request
    char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\nConnection: close\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        printf("Error sending request\n");
        exit(1);
    }

    // Receive response
    while (1) {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            if (bytes_received == 0) {
                printf("Connection closed by server\n");
            } else if (errno == EAGAIN) {
                timeout_count++;
                if (timeout_count >= TIMEOUT) {
                    printf("Connection timed out\n");
                    exit(1);
                }
            } else {
                printf("Error receiving response\n");
                exit(1);
            }
            break;
        }
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);
    return 0;
}