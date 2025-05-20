//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 21
#define MAX_COMMAND_LENGTH 512
#define USER_NAME "anonymous"
#define PASS_WORD "anonymous@example.com"

int main() {
    int sock = 0;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    char command[MAX_COMMAND_LENGTH];
    char *ptr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("socket failed: %s\n", strerror(errno));
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "example.com", &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("connect failed: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to FTP server.\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (strncmp(command, "quit", 4) == 0) {
            break;
        }

        send(sock, command, strlen(command), 0);
        memset(buffer, 0, BUFFER_SIZE);
        recv(sock, buffer, BUFFER_SIZE, 0);

        printf("Server response:\n%s\n", buffer);
    }

    close(sock);
    return 0;
}