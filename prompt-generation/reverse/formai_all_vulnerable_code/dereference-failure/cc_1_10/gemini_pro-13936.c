//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 3490  // The port the client will connect to

// Get a socket descriptor
int get_socket_descriptor() {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Get the server's IP address
    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    // Fill in the server's address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    return sockfd;
}

// Send a message to the server
void send_message(int sockfd, char *message) {
    int n;

    // Send the message
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}

// Receive a message from the server
char *receive_message(int sockfd) {
    int n;
    char *buffer = malloc(256);

    // Receive the message
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // Null-terminate the message
    buffer[n] = '\0';

    return buffer;
}

// Close the socket
void close_socket(int sockfd) {
    close(sockfd);
}

int main() {
    int sockfd;
    char *message;

    // Get a socket descriptor
    sockfd = get_socket_descriptor();

    // Send a message to the server
    message = "Hello from the client!";
    send_message(sockfd, message);

    // Receive a message from the server
    message = receive_message(sockfd);
    printf("Message from the server: %s\n", message);

    // Close the socket
    close_socket(sockfd);

    return 0;
}