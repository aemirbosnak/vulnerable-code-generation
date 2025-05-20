//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to create a TCP socket
int createSocket(int port) {
    int sockfd;
    struct sockaddr_in serverAddr;
    struct hostent *server;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("gethostbyname failed");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    bcopy((char *) server->h_addr, (char *) &serverAddr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send data over TCP socket
void sendData(int sockfd, char *data) {
    ssize_t n;
    while ((n = send(sockfd, data, strlen(data), 0)) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
}

// Function to receive data over TCP socket
char *receiveData(int sockfd) {
    char *data = NULL;
    ssize_t n;
    n = recv(sockfd, &data, sizeof(data), 0);
    if (n < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    return data;
}

// Function to close TCP socket
void closeSocket(int sockfd) {
    close(sockfd);
}

int main() {
    int sockfd;
    char data[1024];

    sockfd = createSocket(8080);
    sendData(sockfd, "Hello, TCP/IP world!");
    printf("Received: %s\n", receiveData(sockfd));
    closeSocket(sockfd);

    return 0;
}