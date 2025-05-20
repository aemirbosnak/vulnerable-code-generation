//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[256];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    portno = atoi(argv[2]);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a message to the server
    const char *message = "GET / HTTP/1.1\r\n\r\n";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("Error sending message to server");
        exit(1);
    }

    // Receive a response from the server
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("Error receiving response from server");
        exit(1);
    }

    // Print the response from the server
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}