//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: systematic
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Function to send a message to the server
void sendMessage(int sockfd, char *msg) {
    int sent = send(sockfd, msg, strlen(msg), 0);
    if (sent < 0) {
        perror("send error");
        exit(EXIT_FAILURE);
    }
}

// Function to receive a message from the server
void receiveMessage(int sockfd) {
    char buffer[100];
    int len = recv(sockfd, buffer, sizeof(buffer), 0);
    if (len < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }
    printf("Received: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    // Set the address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    portno = htons(5000);
    serv_addr.sin_port = portno;
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    char msg[100];
    sprintf(msg, "Hello, server!");
    sendMessage(sockfd, msg);

    // Receive a message from the server
    receiveMessage(sockfd);

    // Close the socket
    close(sockfd);

    return 0;
}