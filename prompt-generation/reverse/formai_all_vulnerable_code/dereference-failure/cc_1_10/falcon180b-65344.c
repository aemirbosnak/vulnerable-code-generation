//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char *ptr;
    int n;

    if (argc < 4) {
        printf("Usage: %s <server> <port> <command>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    printf("Connected to server\n");

    sprintf(command, "USER %s\r\n", argv[3]);
    send(sock, command, strlen(command), 0);

    while (1) {
        n = recv(sock, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            break;
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}