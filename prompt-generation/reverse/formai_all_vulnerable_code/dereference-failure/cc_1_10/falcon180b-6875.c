//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <sys/time.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char *host;
    int port;
    char username[BUF_SIZE];
    char password[BUF_SIZE];
    int sock;
    struct hostent *server;
    struct sockaddr_in serv_addr;

    if (argc!= 5) {
        printf("Usage: %s <host> <port> <username> <password>\n", argv[0]);
        return 1;
    }

    host = argv[1];
    port = atoi(argv[2]);
    strcpy(username, argv[3]);
    strcpy(password, argv[4]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("socket failed\n");
        exit(0);
    }

    server = gethostbyname(host);
    if (server == NULL) {
        printf("no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        printf("connect failed\n");
        exit(0);
    }

    char buf[BUF_SIZE];
    sprintf(buf, "USER %s\r\n", username);
    send(sock, buf, strlen(buf), 0);

    char response[BUF_SIZE];
    recv(sock, response, BUF_SIZE, 0);
    printf("Server response: %s\n", response);

    sprintf(buf, "PASS %s\r\n", password);
    send(sock, buf, strlen(buf), 0);

    recv(sock, response, BUF_SIZE, 0);
    printf("Server response: %s\n", response);

    close(sock);
    return 0;
}