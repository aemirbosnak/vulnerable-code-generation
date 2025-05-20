//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define SERVER "localhost"
#define PORT 110
#define USER "your_username"
#define PASSWORD "your_password"
#define BUFSIZE 1024

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Socket creation failed: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Connection failed: %s\n", strerror(errno));
        close(sock);
        return 1;
    }

    char buf[BUFSIZE];
    sprintf(buf, "USER %s\r\n", USER);
    send(sock, buf, strlen(buf), 0);

    char response[BUFSIZE];
    recv(sock, response, BUFSIZE, 0);
    printf("Server response: %s\n", response);

    sprintf(buf, "PASS %s\r\n", PASSWORD);
    send(sock, buf, strlen(buf), 0);

    recv(sock, response, BUFSIZE, 0);
    printf("Server response: %s\n", response);

    char cmd[BUFSIZE];
    while (fgets(cmd, BUFSIZE, stdin)!= NULL) {
        if (strcasecmp(cmd, "QUIT\r\n") == 0) {
            break;
        }
        send(sock, cmd, strlen(cmd), 0);
        recv(sock, response, BUFSIZE, 0);
        printf("Server response: %s\n", response);
    }

    close(sock);
    return 0;
}