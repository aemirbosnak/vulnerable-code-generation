//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void sendCommand(int sockfd, char* message);
void receiveResponse(int sockfd, char* buffer);
void parseResponse(char* buffer, char* result);
void login(int sockfd);
void listEmails(int sockfd);
void readEmail(int sockfd, int emailNum);

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    receiveResponse(sockfd, buffer);
    printf("%s", buffer);
    login(sockfd);
    listEmails(sockfd);
    readEmail(sockfd, 1);
    close(sockfd);
    return 0;
}

void sendCommand(int sockfd, char* message) {
    char buffer[BUFFER_SIZE];
    sprintf(buffer, "%s\n", message);
    printf("Sending command: %s", buffer);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error sending command");
        exit(1);
    }
}

void receiveResponse(int sockfd, char* buffer) {
    int n;
    do {
        bzero(buffer, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE-1, 0);
        if (n == -1) {
            perror("Error receiving response");
            exit(1);
        }
    } while (strstr(buffer, "\r\n") == NULL);
}

void parseResponse(char* buffer, char* result) {
    char* start = strstr(buffer, "\r\n") + strlen("\r\n");
    char* end = strstr(start, "\r\n") - strlen("\r\n");
    strncpy(result, start, end - start);
    result[end - start] = '\0';
}

void login(int sockfd) {
    char buffer[BUFFER_SIZE];
    char result[BUFFER_SIZE];
    sendCommand(sockfd, "USER username");
    receiveResponse(sockfd, buffer);
    parseResponse(buffer, result);
    printf("%s\n", result);
    sendCommand(sockfd, "PASS password");
    receiveResponse(sockfd, buffer);
    parseResponse(buffer, result);
    printf("%s\n", result);
}

void listEmails(int sockfd) {
    char buffer[BUFFER_SIZE];
    char result[BUFFER_SIZE];
    sendCommand(sockfd, "LIST");
    receiveResponse(sockfd, buffer);
    parseResponse(buffer, result);
    printf("%s\n", result);
    while(1) {
        receiveResponse(sockfd, buffer);
        parseResponse(buffer, result);
        if (result[0] == '.') {
            break;
        }
        printf("%s\n", result);
    }
}

void readEmail(int sockfd, int emailNum) {
    char buffer[BUFFER_SIZE];
    char result[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    sprintf(command, "RETR %d", emailNum);
    sendCommand(sockfd, command);
    receiveResponse(sockfd, buffer);
    parseResponse(buffer, result);
    printf("%s\n", result);
    while(1) {
        receiveResponse(sockfd, buffer);
        parseResponse(buffer, result);
        if (result[0] == '.') {
            break;
        }
        printf("%s\n", result);
    }
}