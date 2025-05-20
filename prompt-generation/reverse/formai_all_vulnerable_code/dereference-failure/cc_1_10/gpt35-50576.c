//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

void readServerResponse(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
        error("Error reading from server.");
    }

    printf("Server response: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    int sockfd, serverPort;
    char serverIP[16], username[50], password[50], command[100];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <server IP address> <server port number>\n", argv[0]);
        exit(1);
    }

    strcpy(serverIP, argv[1]);
    serverPort = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket.");
    }

    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(serverPort);
    serverAddress.sin_addr.s_addr = inet_addr(serverIP);

    if (connect(sockfd, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        error("Error connecting to server.");
    }

    readServerResponse(sockfd);

    printf("Enter your IMAP username: ");
    scanf("%s", username);

    sprintf(command, "1 LOGIN %s ", username);
    write(sockfd, command, strlen(command));
    readServerResponse(sockfd);

    printf("Enter your IMAP password: ");
    scanf("%s", password);

    sprintf(command, "2 LOGIN %s %s ", username, password);
    write(sockfd, command, strlen(command));
    readServerResponse(sockfd);

    sprintf(command, "3 SELECT INBOX");
    write(sockfd, command, strlen(command));
    readServerResponse(sockfd);

    sprintf(command, "4 FETCH 1 BODY[TEXT]");
    write(sockfd, command, strlen(command));
    readServerResponse(sockfd);

    sprintf(command, "5 LOGOUT");
    write(sockfd, command, strlen(command));
    readServerResponse(sockfd);

    close(sockfd);

    return 0;
}