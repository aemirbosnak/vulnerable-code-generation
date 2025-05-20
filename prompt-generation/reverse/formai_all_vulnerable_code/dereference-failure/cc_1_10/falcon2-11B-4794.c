//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get hostname
    char hostname[1024] = "";
    int length = sizeof(hostname);
    gethostname(hostname, &length);

    // Convert hostname to IPv4 address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(EXIT_FAILURE);
    }
    struct in_addr *addr = (struct in_addr *) host->h_addr_list[0];

    // Create a socket address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25); // port 25 is the default for SMTP
    memcpy(&server_addr.sin_addr.s_addr, addr->s_addr, sizeof(struct in_addr));

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send SMTP command to start TLS encryption
    if (send(socket_fd, "EHLO localhost\r\n", 12, 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    char buffer[1024];
    int bytes_read = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (bytes_read < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_read] = '\0'; // null-terminate the string

    // Print server response
    printf("Server response: %s\n", buffer);

    // Send SMTP command to login
    if (send(socket_fd, "MAIL FROM:<user@example.com>\r\n", 26, 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    bytes_read = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (bytes_read < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_read] = '\0'; // null-terminate the string

    // Print server response
    printf("Server response: %s\n", buffer);

    // Send SMTP command to logout
    if (send(socket_fd, "QUIT\r\n", 6, 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive server response
    bytes_read = recv(socket_fd, buffer, sizeof(buffer), 0);
    if (bytes_read < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[bytes_read] = '\0'; // null-terminate the string

    // Print server response
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(socket_fd);

    return 0;
}