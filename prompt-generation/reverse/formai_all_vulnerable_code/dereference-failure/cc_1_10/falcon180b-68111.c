//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to send a command to the SMTP server and receive a response
void send_command(int sock, char *command) {
    char buffer[BUFFER_SIZE];
    strcpy(buffer, command);
    strcat(buffer, "\r\n");
    send(sock, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = 0;
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }
}

// Function to connect to the SMTP server and send the HELO command
void connect_to_server(char *server, int port) {
    struct addrinfo hints, *servinfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo(server, "smtp", &hints, &servinfo);

    int sock = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sock, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    send_command(sock, "HELO ");
    close(sock);
}

int main() {
    char server[100] = "smtp.example.com";
    int port = 25;

    connect_to_server(server, port);

    return 0;
}