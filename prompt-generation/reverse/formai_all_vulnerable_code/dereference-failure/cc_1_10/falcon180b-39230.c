//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n, fd;
    char *host;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];

    // Check if the correct number of arguments are provided
    if (argc!= 4) {
        printf("Usage:./ftp_client <hostname> <port_number> <filename>\n");
        exit(1);
    }

    // Assign values to variables
    host = argv[1];
    portno = atoi(argv[2]);
    strcpy(buffer, argv[3]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket creation failed
    if (sockfd < 0) {
        printf("socket creation failed\n");
        exit(1);
    }

    // Initialize server address structure
    server = gethostbyname(host);

    // Check if host is not found
    if (server == NULL) {
        printf("Host not found\n");
        exit(1);
    }

    // Fill server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    // Connect to remote server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed\n");
        exit(1);
    }

    // Send filename to server
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("Send failed\n");
        exit(1);
    }

    // Receive response from server
    bzero(buffer, BUF_SIZE);
    if (recv(sockfd, buffer, BUF_SIZE, 0) < 0) {
        printf("Receive failed\n");
        exit(1);
    }

    // Print response from server
    printf("Server Response: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}