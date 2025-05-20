//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#define MAX_SIZE 4096

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server, client;
    char command[MAX_SIZE], response[MAX_SIZE];
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket Error: ");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection Error: ");
        exit(1);
    }

    printf("FTP Client\n");

    while(1) {
        printf("FTP> ");
        fgets(command, MAX_SIZE, stdin);
        send(sock, command, strlen(command), 0);

        memset(response, 0, MAX_SIZE);
        if (recv(sock, response, MAX_SIZE, 0) < 0) {
            perror("Error Receiving Data: ");
            exit(1);
        }

        printf("%s", response);
    }

    close(sock);
    return 0;
}