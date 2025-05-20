//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/time.h>

#define MAXLINE 1024
#define TRUE 1
#define FALSE 0

typedef struct {
    char username[MAXLINE];
    char password[MAXLINE];
    char server[MAXLINE];
    int port;
} POP3Config;

int main(int argc, char *argv[]) {
    int sd, ret;
    struct sockaddr_in server_addr;
    char recv_buf[MAXLINE];
    char send_buf[MAXLINE];
    POP3Config config;

    if (argc!= 6) {
        printf("Usage: %s <username> <password> <server> <port>\n", argv[0]);
        return 1;
    }

    strcpy(config.username, argv[1]);
    strcpy(config.password, argv[2]);
    strcpy(config.server, argv[3]);
    config.port = atoi(argv[4]);

    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1) {
        printf("socket() failed: %s\n", strerror(errno));
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(config.port);
    inet_pton(AF_INET, config.server, &server_addr.sin_addr);

    ret = connect(sd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("connect() failed: %s\n", strerror(errno));
        close(sd);
        return 1;
    }

    sprintf(send_buf, "USER %s\r\n", config.username);
    ret = send(sd, send_buf, strlen(send_buf), 0);
    if (ret == -1) {
        printf("send() failed: %s\n", strerror(errno));
        close(sd);
        return 1;
    }

    ret = recv(sd, recv_buf, MAXLINE, 0);
    if (ret <= 0) {
        printf("recv() failed: %s\n", strerror(errno));
        close(sd);
        return 1;
    }

    if (strncmp(recv_buf, "+OK", 3)!= 0) {
        printf("Authentication failed\n");
        close(sd);
        return 1;
    }

    sprintf(send_buf, "PASS %s\r\n", config.password);
    ret = send(sd, send_buf, strlen(send_buf), 0);
    if (ret == -1) {
        printf("send() failed: %s\n", strerror(errno));
        close(sd);
        return 1;
    }

    ret = recv(sd, recv_buf, MAXLINE, 0);
    if (ret <= 0) {
        printf("recv() failed: %s\n", strerror(errno));
        close(sd);
        return 1;
    }

    if (strncmp(recv_buf, "+OK", 3)!= 0) {
        printf("Authentication failed\n");
        close(sd);
        return 1;
    }

    printf("Authentication successful\n");
    close(sd);
    return 0;
}