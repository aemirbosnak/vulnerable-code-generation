//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void readResponse(int socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    recv(socket, buffer, BUFFER_SIZE - 1, 0);
    printf("%s", buffer);
}

void sendCommand(int socket, const char *command) {
    send(socket, command, strlen(command), 0);
    // Adding CRLF at the end to signal end of command
    send(socket, "\r\n", 2, 0);
    readResponse(socket);
}

int connectToServer(const char *hostname) {
    struct hostent *server;
    struct sockaddr_in serv_addr;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(POP3_PORT);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

void listMessages(int socket) {
    sendCommand(socket, "LIST");
}

void retrieveMessage(int socket, int messageNumber) {
    char command[16];
    snprintf(command, sizeof(command), "RETR %d", messageNumber);
    sendCommand(socket, command);
}

void quitServer(int socket) {
    sendCommand(socket, "QUIT");
    close(socket);
    printf("Connection closed.\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int socket = connectToServer(hostname);

    readResponse(socket);  // Read initial server greeting

    // Send username and password
    char userCommand[256];
    snprintf(userCommand, sizeof(userCommand), "USER %s", username);
    sendCommand(socket, userCommand);

    char passCommand[256];
    snprintf(passCommand, sizeof(passCommand), "PASS %s", password);
    sendCommand(socket, passCommand);

    // List messages
    listMessages(socket);

    // Retrieve the first message for testing
    retrieveMessage(socket, 1);

    // Quit the session
    quitServer(socket);

    return 0;
}