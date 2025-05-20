//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock, port;
    struct hostent *host;
    char *host_name;
    char buffer[BUF_SIZE];
    char *user, *pass;
    char *response;
    int response_code;
    FILE *fp;
    char filename[BUF_SIZE];
    char command[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <hostname> <username>\n", argv[0]);
        exit(1);
    }

    host_name = argv[1];
    user = argv[2];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    host = gethostbyname(host_name);
    if (host == NULL) {
        printf("Host not found\n");
        exit(1);
    }

    port = 21; // FTP port

    if (connect(sock, (struct sockaddr *)host->h_addr, host->h_length) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s\n", host_name);

    sprintf(command, "USER %s\n", user);
    send(sock, command, strlen(command), 0);

    response = recv(sock, buffer, BUF_SIZE, 0);
    response_code = atoi(buffer);

    if (response_code!= 220) {
        printf("Login failed\n");
        exit(1);
    }

    sprintf(command, "PASS %s\n", pass);
    send(sock, command, strlen(command), 0);

    response = recv(sock, buffer, BUF_SIZE, 0);
    response_code = atoi(buffer);

    if (response_code!= 230) {
        printf("Login failed\n");
        exit(1);
    }

    printf("Logged in\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            break;
        }

        send(sock, command, strlen(command), 0);

        response = recv(sock, buffer, BUF_SIZE, 0);

        printf("%s\n", buffer);

        if (strncmp(buffer, "226", 3) == 0) {
            break;
        }
    }

    close(sock);
    exit(0);
}