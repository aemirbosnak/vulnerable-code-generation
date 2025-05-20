//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 1024

char* receiveResponse(int sockfd) {
    char* response = (char*) malloc(MAX_LEN * sizeof(char));
    char recvChar = 0;
    int i = 0;
    while(recv(sockfd, &recvChar, sizeof(recvChar), 0) > 0) {
        response[i] = recvChar;
        i++;
        if(recvChar == '\n') {
            break;
        }
    }
    response[i] = '\0';
    printf("%s", response);
    return response;
}

void sendCommand(int sockfd, const char* command, const char* parameter, int loginFlag) {
    char message[MAX_LEN];
    if(loginFlag) {
        snprintf(message, sizeof(message), "%s %s\r\n", command, parameter);
    } else {
        snprintf(message, sizeof(message), "%s\r\n", command);
    }
    send(sockfd, message, strlen(message), 0);
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAX_LEN];
    char* response;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        printf("Socket creation failed!\n");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(110);

    if(inet_pton(AF_INET, "pop3.server.com", &servaddr.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported!\n");
        return -1;
    }

    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Connection failed!\n");
        return -1;
    }
    printf("Connected to POP3 server successfully!\n");

    response = receiveResponse(sockfd);

    sendCommand(sockfd, "USER", "username", 0);
    response = receiveResponse(sockfd);

    sendCommand(sockfd, "PASS", "password", 1);
    response = receiveResponse(sockfd);

    sendCommand(sockfd, "STAT", "", 1);
    response = receiveResponse(sockfd);

    char* token = strtok(response, " ");
    token = strtok(NULL, " ");
    int numOfEmails = atoi(token);

    for(int i = 1; i <= numOfEmails; i++) {
        sendCommand(sockfd, "RETR", "i", 1);
        response = receiveResponse(sockfd);
        printf("%s\n", response);
    }

    sendCommand(sockfd, "QUIT", "", 1);
    response = receiveResponse(sockfd);

    close(sockfd);
    return 0;
}