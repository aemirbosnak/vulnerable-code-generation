//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        herror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the FTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the RETR command
    char command[MAX_BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s\r\n", argv[3]);

    if (send(sockfd, command, strlen(command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the file data
    char buffer[MAX_BUFFER_SIZE];
    FILE *fp = fopen(argv[3], "w");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    while (1) {
        int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            perror("recv");
            return EXIT_FAILURE;
        } else if (bytes_received == 0) {
            break;
        }

        fwrite(buffer, 1, bytes_received, fp);
    }

    fclose(fp);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}