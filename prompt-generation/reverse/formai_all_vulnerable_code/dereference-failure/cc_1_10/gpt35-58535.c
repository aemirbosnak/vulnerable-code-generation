//FormAI DATASET v1.0 Category: Networking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {

    int sockfd, port;
    struct sockaddr_in serv_addr;
    char *server_ip, message[BUFSIZE];

    // Check for correct argument count
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <Server IP> <Port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server_ip = argv[1];
    port = atoi(argv[2]);

    // Create a TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up address information for server
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Read user's message and send to server
    while (1) {
        printf("Enter message: ");
        fgets(message, BUFSIZE, stdin);
        message[strlen(message) - 1] = '\0';  // remove newline character

        if (strcmp(message, "quit") == 0) {
            break;
        }

        if (send(sockfd, message, strlen(message), 0) < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        // Receive response from server
        memset(message, 0, BUFSIZE);
        if (recv(sockfd, message, BUFSIZE, 0) < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        printf("Server response: %s\n", message);
    }

    // Close socket and exit
    close(sockfd);
    exit(EXIT_SUCCESS);
}