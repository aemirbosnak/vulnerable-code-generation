//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int socket_fd, port_number;
    struct sockaddr_in server_address;
    struct hostent *server;
    char buffer[1024];

    if (argc < 3) {
        fprintf(stderr, "Usage: ./smtpclient hostname port\n");
        exit(EXIT_FAILURE);
    }

    port_number = atoi(argv[2]);

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    // Get server info
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: Host not found\n");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port_number);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Receive initial server response
    bzero(buffer, 1024);
    if (read(socket_fd, buffer, 1024) < 0) {
        perror("Error reading from server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send client information
    char *client_info = "HELO myclient\r\n";
    if (send(socket_fd, client_info, strlen(client_info), 0) < 0) {
        perror("Error sending client information");
        exit(EXIT_FAILURE);
    }

    // Receive server response to client information
    bzero(buffer, 1024);
    if (read(socket_fd, buffer, 1024) < 0) {
        perror("Error reading from server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Send email information
    char *email_info = "MAIL FROM: <me@example.com>\r\nRCPT TO: <you@example.com>\r\nDATA\r\nSubject: My Email\r\nHello World\r\n.\r\n";
    if (send(socket_fd, email_info, strlen(email_info), 0) < 0) {
        perror("Error sending email information");
        exit(EXIT_FAILURE);
    }

    // Receive server response to email information
    bzero(buffer, 1024);
    if (read(socket_fd, buffer, 1024) < 0) {
        perror("Error reading from server");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buffer);

    // Close socket
    close(socket_fd);

    return 0;
}