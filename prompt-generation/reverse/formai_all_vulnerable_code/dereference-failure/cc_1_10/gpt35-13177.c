//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

//Function to initialize a socket and connect to the SMTP server
int createSocket(char *serverName, int port) {
    struct sockaddr_in serverAddr;
    struct hostent *host = gethostbyname(serverName);

    int socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if(socketFd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    bcopy((char *)host->h_addr, (char *)&serverAddr.sin_addr.s_addr, host->h_length);

    if(connect(socketFd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        printf("Error connecting to SMTP server\n");
        exit(1);
    }

    return socketFd;
}

//Function to receive the response from the SMTP server
int receiveResponse(int sockfd) {
    char buffer[BUFFER_SIZE] = {0};
    int receiveSize = recv(sockfd, buffer, BUFFER_SIZE, 0);

    printf("%s", buffer);
    return receiveSize;
}

//Function to send a command to the SMTP server
void sendCommand(int sockfd, char* command) {
    printf("%s", command);
    write(sockfd, command, strlen(command));
}

//Function to send an email using SMTP
void sendEmail(char *to, char *from, char *subject, char *body) {
    int port = 25;
    char serverName[] = "smtp.gmail.com";
    char buffer[BUFFER_SIZE] = {0};
    int sockfd = createSocket(serverName, port);

    receiveResponse(sockfd);

    sprintf(buffer, "HELO %s\r\n", serverName);
    sendCommand(sockfd, buffer);
    receiveResponse(sockfd);

    sprintf(buffer, "MAIL FROM:<%s>\r\n", from);
    sendCommand(sockfd, buffer);
    receiveResponse(sockfd);

    sprintf(buffer, "RCPT TO:<%s>\r\n", to);
    sendCommand(sockfd, buffer);
    receiveResponse(sockfd);

    sprintf(buffer, "DATA\r\n");
    sendCommand(sockfd, buffer);
    receiveResponse(sockfd);

    sprintf(buffer, "Subject:%s\r\n", subject);
    sendCommand(sockfd, buffer);
    sprintf(buffer, "\r\n%s\r\n", body);
    sendCommand(sockfd, buffer);
    sprintf(buffer, "\r\n.\r\n");
    sendCommand(sockfd, buffer);
    receiveResponse(sockfd);

    sprintf(buffer, "QUIT\r\n");
    sendCommand(sockfd, buffer);
    receiveResponse(sockfd);

    close(sockfd);
}

int main() {
    char to[100] = "example@example.com";
    char from[100] = "youremail@gmail.com";
    char subject[100] = "Testing SMTP Client Example Program";
    char body[100] = "Hello from SMTP Client!";

    sendEmail(to, from, subject, body);
    return 0;
}