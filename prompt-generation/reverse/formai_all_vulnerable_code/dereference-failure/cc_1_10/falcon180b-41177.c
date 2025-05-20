//Falcon-180B DATASET v1.0 Category: Networking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    char *ip_addr;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];

    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage:./client <ip address> <port number>\n");
        exit(1);
    }

    // Convert the IP address from string to binary format
    ip_addr = argv[1];
    if (inet_pton(AF_INET, ip_addr, &serv_addr.sin_addr) <= 0) {
        error_handling("Invalid address/Address not supported");
    }

    // Convert the port number from string to binary format
    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_handling("socket failed");
    }

    // Connect to the server
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        error_handling("No such host");
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("connect failed");
    }

    // Send data to the server
    send(sockfd, "Hello, World!", strlen("Hello, World! "), 0);

    // Receive data from the server
    if (recv(sockfd, buffer, BUF_SIZE, 0) < 0) {
        error_handling("recv failed");
    }

    // Print the received data
    printf("Received data: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}