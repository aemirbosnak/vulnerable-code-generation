//FormAI DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;

    // Check for the correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <ip address> <port number>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send a message to the server
    char *sendbuf = "Hello, server!";
    if (send(sockfd, sendbuf, strlen(sendbuf), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive a message from the server and print it
    char recvbuf[1024];
    if (recv(sockfd, recvbuf, sizeof(recvbuf), 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("Received message from server: %s\n", recvbuf);

    // Close the socket
    close(sockfd);

    return 0;
}