//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_MAX 1024

void recvMessage(int sock_fd, char* buffer, int buffer_size) {
    int recv_bytes = recv(sock_fd, buffer, buffer_size - 1, 0);
    buffer[recv_bytes] = '\0';
}

void sendCommand(int sock_fd, char* command) {
    printf(">> %s", command);
    send(sock_fd, command, strlen(command), 0);
}

int main() {
    char* hostname = "mail.example.com";
    char* username = "username";
    char* password = "password";

    // Get server IP address
    struct hostent* server = gethostbyname(hostname);
    if (!server) {
        printf("Error: Couldn't resolve hostname");
        return 1;
    }

    // Setup socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Error: Couldn't open socket");
        return 1;
    }

    // Setup server connection
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(110); // POP3 default port
    memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to server
    if (connect(sock_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Error: Couldn't connect to server");
        return 1;
    }

    // Receive server greeting
    char buffer[BUFFER_MAX];
    recvMessage(sock_fd, buffer, BUFFER_MAX);
    printf("<< %s", buffer);

    // Send login commands
    sendCommand(sock_fd, "USER ");
    sendCommand(sock_fd, username);
    sendCommand(sock_fd, "\r\n");
    recvMessage(sock_fd, buffer, BUFFER_MAX);
    printf("<< %s", buffer);

    sendCommand(sock_fd, "PASS ");
    sendCommand(sock_fd, password);
    sendCommand(sock_fd, "\r\n");
    recvMessage(sock_fd, buffer, BUFFER_MAX);
    printf("<< %s", buffer);

    // List mailbox messages
    sendCommand(sock_fd, "LIST\r\n");
    recvMessage(sock_fd, buffer, BUFFER_MAX);
    printf("<< %s", buffer);

    // Disconnect from server
    sendCommand(sock_fd, "QUIT\r\n");
    recvMessage(sock_fd, buffer, BUFFER_MAX);
    printf("<< %s", buffer);

    close(sock_fd);
    return 0;
}