//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    // Connect to the POP3 server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to connect to server\n");
        return 1;
    }

    // Send POP3 commands
    char command[100];
    sprintf(command, "USER username\r\n");
    write(socket_fd, command, strlen(command));
    printf("%s\n", command);

    sprintf(command, "PASS password\r\n");
    write(socket_fd, command, strlen(command));
    printf("%s\n", command);

    sprintf(command, "LIST\r\n");
    write(socket_fd, command, strlen(command));
    printf("%s\n", command);

    // Receive the response
    char response[100];
    read(socket_fd, response, sizeof(response));
    printf("%s\n", response);

    // Close the socket
    close(socket_fd);

    return 0;
}