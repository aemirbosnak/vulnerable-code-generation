//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_MSG_LEN 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server IP address> <server port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Get the user's input
    char msg[MAX_MSG_LEN];
    printf("Enter your message: ");
    fgets(msg, MAX_MSG_LEN, stdin);

    // Send the message to the server
    if (send(sockfd, msg, strlen(msg), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the server's response
    char response[MAX_MSG_LEN];
    if (recv(sockfd, response, MAX_MSG_LEN, 0) == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Print the server's response
    printf("Server response: %s\n", response);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}