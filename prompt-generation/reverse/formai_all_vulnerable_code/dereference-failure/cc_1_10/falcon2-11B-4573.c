//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Function to send a message over a TCP socket
int send_message(int sockfd, char *message, int message_len) {
    int bytes_sent = 0;
    while (bytes_sent < message_len) {
        bytes_sent += send(sockfd, message + bytes_sent, message_len - bytes_sent, 0);
    }
    return bytes_sent;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    int sockfd;
    struct sockaddr_in server;
    int port = atoi(argv[2]);

    // Create a TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the message
    char message[256];
    sprintf(message, "Hello, World!\n");
    int message_len = strlen(message);
    send_message(sockfd, message, message_len);

    // Close the socket
    close(sockfd);
    return 0;
}