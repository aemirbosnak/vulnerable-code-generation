//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define SERVER_IP "192.168.1.100"
#define SERVER_PORT 110

int main() {
    int server_fd, port, len;
    struct sockaddr_in server_addr;
    char message[1024];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        printf("Error opening socket: %s\n", strerror(errno));
        return 1;
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        printf("Error converting IP address: %s\n", strerror(errno));
        return 1;
    }

    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    printf("Connected to server!\n");

    // Send POP3 command
    printf("Sending POP3 command...\n");
    bzero(message, 1024);
    snprintf(message, sizeof(message), "USER testuser\r\n");
    send(server_fd, message, strlen(message), 0);

    // Receive POP3 response
    bzero(message, 1024);
    if (recv(server_fd, message, sizeof(message) - 1, 0) < 0) {
        printf("Error receiving response: %s\n", strerror(errno));
        return 1;
    }
    message[sizeof(message) - 1] = '\0';
    printf("Response: %s\n", message);

    // Send POP3 command
    printf("Sending POP3 command...\n");
    bzero(message, 1024);
    snprintf(message, sizeof(message), "PASS testpassword\r\n");
    send(server_fd, message, strlen(message), 0);

    // Receive POP3 response
    bzero(message, 1024);
    if (recv(server_fd, message, sizeof(message) - 1, 0) < 0) {
        printf("Error receiving response: %s\n", strerror(errno));
        return 1;
    }
    message[sizeof(message) - 1] = '\0';
    printf("Response: %s\n", message);

    // Close the connection
    printf("Closing connection...\n");
    close(server_fd);

    return 0;
}