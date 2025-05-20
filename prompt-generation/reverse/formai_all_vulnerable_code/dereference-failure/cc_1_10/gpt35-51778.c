//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 25

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_address;
    char message[1024], buffer[1024];

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server address properties
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Read response from server
    read(client_socket, buffer, 1024);
    printf("%s", buffer);

    // Send HELO message to server
    snprintf(message, sizeof(message), "HELO %s\r\n", argv[1]);
    write(client_socket, message, strlen(message));
    read(client_socket, buffer, 1024);
    printf("%s", buffer);

    // Send MAIL FROM message to server
    snprintf(message, sizeof(message), "MAIL FROM: <%s>\r\n", argv[2]);
    write(client_socket, message, strlen(message));
    read(client_socket, buffer, 1024);
    printf("%s", buffer);

    // Send RCPT TO message to server
    snprintf(message, sizeof(message), "RCPT TO: <%s>\r\n", argv[3]);
    write(client_socket, message, strlen(message));
    read(client_socket, buffer, 1024);
    printf("%s", buffer);

    // Send DATA message to server
    snprintf(message, sizeof(message), "DATA\r\n");
    write(client_socket, message, strlen(message));
    read(client_socket, buffer, 1024);
    printf("%s", buffer);

    // Send message body to server
    snprintf(message, sizeof(message), "From: %s\r\nTo: %s\r\nSubject: %s\r\n%s\r\n.\r\n", argv[2], argv[3], argv[4], argv[5]);
    write(client_socket, message, strlen(message));
    read(client_socket, buffer, 1024);
    printf("%s", buffer);

    // Send QUIT message to server
    snprintf(message, sizeof(message), "QUIT\r\n");
    write(client_socket, message, strlen(message));
    read(client_socket, buffer, 1024);
    printf("%s", buffer);

    // Close socket
    close(client_socket);
    return 0;
}