//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char server_name[64];
    char buffer[BUF_SIZE];
    int n;

    if (argc < 4) {
        printf("Usage: %s <server> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    strcpy(server_name, argv[1]);
    int port = atoi(argv[2]);
    char *username = argv[3];
    char *password = argv[4];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server_name);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    printf("Connected to server: %s:%d\n", server_name, port);

    char *auth_str = "AUTH LOGIN\r\n";
    write(sock, auth_str, strlen(auth_str));

    char *user_str = "USER ";
    strcat(user_str, username);
    strcat(user_str, "\r\n");
    write(sock, user_str, strlen(user_str));

    char *pass_str = "PASS ";
    strcat(pass_str, password);
    strcat(pass_str, "\r\n");
    write(sock, pass_str, strlen(pass_str));

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        n = read(sock, buffer, BUF_SIZE);
        if (n <= 0) {
            printf("Disconnected from server\n");
            break;
        }
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}