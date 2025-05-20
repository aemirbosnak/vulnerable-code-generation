//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define PORT 21
#define MAX_COMMAND_LENGTH 1024
#define BUFFER_SIZE 1024

void die(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char **argv) {
    int sock = 0;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    char command[MAX_COMMAND_LENGTH];

    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    strcpy(command, argv[1]);
    strcat(command, " ");
    strcat(command, argv[2]);
    strcat(command, " ");
    strcat(command, argv[3]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, command, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        die("connect");
    }

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if (recv(sock, buffer, BUFFER_SIZE, 0) <= 0) {
            break;
        }
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}