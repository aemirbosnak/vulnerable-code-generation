//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *host, *user, *pass;
    int port;
    char buf[BUF_SIZE];
    int n;

    if (argc < 5) {
        printf("Usage: %s <host> <port> <username> <password>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);
    user = argv[3];
    pass = argv[4];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(buf, "USER %s\r\n", user);
    send(sock, buf, strlen(buf), 0);

    n = recv(sock, buf, BUF_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Received: %s", buf);

    sprintf(buf, "PASS %s\r\n", pass);
    send(sock, buf, strlen(buf), 0);

    n = recv(sock, buf, BUF_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Received: %s", buf);

    close(sock);

    return 0;
}