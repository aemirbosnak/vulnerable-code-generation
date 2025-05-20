//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_MSG_SIZE 1024

void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int socketfd, portno, n;
    struct sockaddr_in server_addr;
    struct hostent *server;

    char buffer[MAX_MSG_SIZE];
    if (argc < 3) {
        error("Usage: ./client <hostname> <portnumber>");
    }
    portno = atoi(argv[2]);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
        error("Error opening socket");
    }
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        error("Error, no such host");
    }
    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy((char *) &server_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    server_addr.sin_port = htons(portno);
    if (connect(socketfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting");
    }
    printf("Connected to server\n");
    char message[MAX_MSG_SIZE];
    printf("Enter message: ");
    fgets(message, MAX_MSG_SIZE, stdin);
    n = send(socketfd, message, strlen(message), 0);
    if (n < 0) {
        error("Error sending message");
    }
    memset(buffer, 0, MAX_MSG_SIZE);
    n = recv(socketfd, buffer, MAX_MSG_SIZE - 1, 0);
    if (n < 0) {
        error("Error receiving message");
    }
    printf("Server Response: %s\n", buffer);
    close(socketfd);
    return 0;
}