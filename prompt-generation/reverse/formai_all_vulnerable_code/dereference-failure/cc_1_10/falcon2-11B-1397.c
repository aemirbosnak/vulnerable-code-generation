//Falcon2-11B DATASET v1.0 Category: Networking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>

// Function to connect to the server
int connectToServer(const char* serverName, const int port) {
    int sockfd = -1;
    struct sockaddr_in serverAddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(serverName);

    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("connection failed");
        exit(1);
    }

    return sockfd;
}

// Function to send data to the server
void sendDataToServer(int sockfd, const char* data) {
    if (send(sockfd, data, strlen(data), 0) == -1) {
        perror("send failed");
        exit(1);
    }
}

// Function to receive data from the server
char* receiveDataFromServer(int sockfd) {
    char* buffer = NULL;
    int bytesReceived = 0;

    if ((bytesReceived = recv(sockfd, buffer, 100, 0)) == -1) {
        perror("receive failed");
        exit(1);
    }

    buffer[bytesReceived] = '\0';

    return buffer;
}

// Function to close the socket
void closeSocket(int sockfd) {
    if (close(sockfd) == -1) {
        perror("close failed");
        exit(1);
    }
}

int main() {
    int sockfd = -1;
    char buffer[100];
    char* data = "Hello, world!";

    if ((sockfd = connectToServer("localhost", 8080)) == -1) {
        perror("Connection failed");
        exit(1);
    }

    printf("Connected to server!\n");

    sendDataToServer(sockfd, data);
    printf("Data sent to server: %s\n", receiveDataFromServer(sockfd));

    closeSocket(sockfd);

    return 0;
}