//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 25

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int buffer_len;
    char *domain;

    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    domain = argv[1];
    strcpy(buffer, "EHLO ");
    strcat(buffer, argv[2]);
    strcat(buffer, "\r\n");

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr(domain);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    send(sock, buffer, strlen(buffer), 0);

    while (1) {
        buffer_len = recv(sock, buffer, BUFFER_SIZE, 0);
        if (buffer_len <= 0) {
            printf("Error receiving data\n");
            return 1;
        }
        buffer[buffer_len] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}