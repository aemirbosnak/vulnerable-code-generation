//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;
    char *username = "username";
    char *password = "password";
    char *hostname = "imap.example.com";
    int port = 993; // IMAP over SSL

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char *login_command = "LOGIN ";
    strcat(login_command, username);
    strcat(login_command, " ");
    strcat(login_command, password);
    send(sock, login_command, strlen(login_command), 0);

    char *select_command = "SELECT INBOX\r\n";
    send(sock, select_command, strlen(select_command), 0);

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = recv(sock, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving data\n");
            break;
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}