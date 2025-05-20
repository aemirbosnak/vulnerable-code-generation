//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define SERVER_IP "smtp.gmail.com"
#define SERVER_PORT "587"
#define EMAIL_USER "your_email@gmail.com"
#define EMAIL_PASSWORD "your_password"
#define RECIPIENT "recipient@example.com"

int main(int argc, char **argv)
{
    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        fprintf(stderr, "Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Resolve server address
    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(SERVER_IP, SERVER_PORT, &hints, &servinfo)!= 0) {
        fprintf(stderr, "Failed to resolve server address\n");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(socket_fd, servinfo->ai_addr, servinfo->ai_addrlen)!= 0) {
        fprintf(stderr, "Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Login to the server
    char login[1024];
    sprintf(login, "LOGIN %s %s", EMAIL_USER, EMAIL_PASSWORD);
    send(socket_fd, login, strlen(login), 0);

    // Send email
    char email[1024];
    sprintf(email, "FROM: %s\r\nTO: %s\r\nSUBJECT: Test Email\r\n\r\nHello World!", EMAIL_USER, RECIPIENT);
    send(socket_fd, email, strlen(email), 0);

    // Logout from the server
    char logout[1024];
    sprintf(logout, "QUIT");
    send(socket_fd, logout, strlen(logout), 0);

    // Close the socket
    close(socket_fd);

    return 0;
}