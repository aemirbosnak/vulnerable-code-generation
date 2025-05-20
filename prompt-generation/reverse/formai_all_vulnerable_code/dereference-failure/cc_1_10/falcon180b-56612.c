//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_RESPONSE_LENGTH 4096

int main(int argc, char *argv[]) {
    int sock = 0;
    struct sockaddr_in server;
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];

    if (argc!= 4) {
        printf("Usage: %s <server_address> <port_number> <username>\n", argv[0]);
        return 1;
    }

    strcpy(command, "USER ");
    strcat(command, argv[3]);
    strcat(command, "\r\n");

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server))!= 0) {
        printf("Error connecting to server\n");
        close(sock);
        return 1;
    }

    send(sock, command, strlen(command), 0);
    memset(response, 0, sizeof(response));

    if (recv(sock, response, sizeof(response), 0) <= 0) {
        printf("Error receiving response\n");
        close(sock);
        return 1;
    }

    printf("Response: %s", response);

    close(sock);
    return 0;
}