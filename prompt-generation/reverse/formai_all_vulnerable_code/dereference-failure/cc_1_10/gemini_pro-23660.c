//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUFF_SIZE 1024

typedef struct {
    char *host;
    int port;
    char *username;
    char *password;
} pop3_config;

void usage() {
    printf("Usage: %s <host> <port> <username> <password>\n", __FILE__);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        usage();
    }

    pop3_config config;
    config.host = argv[1];
    config.port = atoi(argv[2]);
    config.username = argv[3];
    config.password = argv[4];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(config.port);
    addr.sin_addr.s_addr = inet_addr(config.host);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char buff[BUFF_SIZE];

    // Receive greeting
    if (recv(sock, buff, BUFF_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("%s", buff);

    // Send username
    sprintf(buff, "USER %s\r\n", config.username);
    if (send(sock, buff, strlen(buff), 0) == -1) {
        perror("send");
        exit(1);
    }
    if (recv(sock, buff, BUFF_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("%s", buff);

    // Send password
    sprintf(buff, "PASS %s\r\n", config.password);
    if (send(sock, buff, strlen(buff), 0) == -1) {
        perror("send");
        exit(1);
    }
    if (recv(sock, buff, BUFF_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("%s", buff);

    // List messages
    if (send(sock, "LIST\r\n", 6, 0) == -1) {
        perror("send");
        exit(1);
    }
    if (recv(sock, buff, BUFF_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("%s", buff);

    // Retrieve message
    char msg_num[10];
    printf("Enter message number to retrieve: ");
    scanf("%s", msg_num);
    sprintf(buff, "RETR %s\r\n", msg_num);
    if (send(sock, buff, strlen(buff), 0) == -1) {
        perror("send");
        exit(1);
    }
    if (recv(sock, buff, BUFF_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("%s", buff);

    // Close connection
    if (send(sock, "QUIT\r\n", 6, 0) == -1) {
        perror("send");
        exit(1);
    }
    if (recv(sock, buff, BUFF_SIZE, 0) == -1) {
        perror("recv");
        exit(1);
    }
    printf("%s", buff);

    close(sock);

    return 0;
}