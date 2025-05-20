//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 110
#define MAX_LINE 1024
#define USER "username"
#define PASS "password"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[MAX_LINE];
    char username[20];
    char password[20];
    char line[MAX_LINE];

    if (argc!= 3) {
        printf("Usage: %s <username> <password>\n", argv[0]);
        exit(1);
    }

    strcpy(username, argv[1]);
    strcpy(password, argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sock, USER, strlen(USER), 0);
    send(sock, "\r\n", 2, 0);

    recv(sock, buffer, MAX_LINE, 0);
    printf("Server response: %s", buffer);

    send(sock, PASS, strlen(PASS), 0);
    send(sock, "\r\n", 2, 0);

    recv(sock, buffer, MAX_LINE, 0);
    printf("Server response: %s", buffer);

    send(sock, "STAT\r\n", 7, 0);

    recv(sock, buffer, MAX_LINE, 0);
    printf("Server response: %s", buffer);

    close(sock);

    return 0;
}