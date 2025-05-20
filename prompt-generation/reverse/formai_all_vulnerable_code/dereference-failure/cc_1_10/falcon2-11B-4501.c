//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 110

void sendCommand(int sockfd, const char* command) {
    char buffer[1000];
    sprintf(buffer, "%s\r\n", command);
    int bytesSent = send(sockfd, buffer, strlen(buffer), 0);
    if (bytesSent < 0) {
        perror("send");
        exit(1);
    }
}

void receiveData(int sockfd, char* buffer, int bufferSize) {
    int bytesRecvd = recv(sockfd, buffer, bufferSize, 0);
    if (bytesRecvd < 0) {
        perror("recv");
        exit(1);
    }
    buffer[bytesRecvd] = '\0';
    printf("Received data: %s\n", buffer);
}

void printReceivedData(char* data) {
    printf("Printed received data: %s\n", data);
}

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[1000];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("connect");
        exit(1);
    }

    sendCommand(sockfd, "USER myuser\r\n");
    receiveData(sockfd, buffer, sizeof(buffer));
    printReceivedData(buffer);

    sendCommand(sockfd, "PASS mypassword\r\n");
    receiveData(sockfd, buffer, sizeof(buffer));
    printReceivedData(buffer);

    close(sockfd);
    return 0;
}