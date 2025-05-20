//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ctype.h>

#define FTP_PORT 21
#define MAX_COMMAND_SIZE 1024
#define MAX_DATA_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Convert the hostname and port to network byte order.
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    struct addrinfo *result;
    int status = getaddrinfo(argv[1], argv[2], &hints, &result);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    // Create a socket.
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the FTP server.
    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        perror("connect");
        return 1;
    }

    // Free the address information.
    freeaddrinfo(result);

    // Send the FTP commands.
    char command[MAX_COMMAND_SIZE];
    while (1) {
        // Get the command from the user.
        printf("ftp> ");
        fgets(command, MAX_COMMAND_SIZE, stdin);

        // Remove the newline character from the command.
        command[strlen(command) - 1] = '\0';

        // Send the command to the FTP server.
        send(sockfd, command, strlen(command), 0);

        // Receive the response from the FTP server.
        char data[MAX_DATA_SIZE];
        int bytes_received = recv(sockfd, data, MAX_DATA_SIZE, 0);
        if (bytes_received == -1) {
            perror("recv");
            return 1;
        }

        // Print the response to the user.
        printf("%s", data);

        // Check if the user wants to quit.
        if (strcmp(command, "quit") == 0) {
            break;
        }
    }

    // Close the socket.
    close(sockfd);

    return 0;
}