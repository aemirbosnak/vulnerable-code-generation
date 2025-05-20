//FormAI DATASET v1.0 Category: Email Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

#define SERVER "mail.example.com"
#define PORT 110

struct sockaddr_in server;

int createSocket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    return sock;
}

void connectSocket(int sock) {
    if(connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }
}

void receiveResponse(int sock) {
    char response[1024];
    int n = recv(sock, response, sizeof(response)-1, 0);
    if(n < 0) {
        perror("Failed to receive response");
        exit(EXIT_FAILURE);
    }
    response[n] = '\0';
    printf("%s", response);
}

void sendCommand(int sock, char *command) {
    if(send(sock, command, strlen(command), 0) < 0) {
        perror("Failed to send command");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int sock = createSocket();
    struct hostent *he;
    struct in_addr **addr_list;
    if((he = gethostbyname(SERVER)) == NULL) {
        herror("Failed to get server hostname");
        exit(EXIT_FAILURE);
    }
    addr_list = (struct in_addr **)he->h_addr_list;
    server.sin_addr = *addr_list[0];
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    connectSocket(sock);
    while(1) {
        char command[1024];
        printf("Enter email command: ");
        scanf("%s", command);
        sendCommand(sock, command);
        receiveResponse(sock);
        if(strncmp(command, "QUIT", 4) == 0) {
            close(sock);
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}