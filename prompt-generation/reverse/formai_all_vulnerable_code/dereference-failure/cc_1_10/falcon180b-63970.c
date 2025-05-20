//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    struct hostent *host = gethostbyname(server);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname error\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char buf[MAX_LINE];
    sprintf(buf, "USER %s\r\n", username);
    send(sock, buf, strlen(buf), 0);

    char *response = malloc(MAX_LINE);
    int n = recv(sock, response, MAX_LINE, 0);
    if (n <= 0) {
        perror("recv");
        exit(1);
    }

    printf("Response: %s\n", response);

    sprintf(buf, "PASS %s\r\n", password);
    send(sock, buf, strlen(buf), 0);

    n = recv(sock, response, MAX_LINE, 0);
    if (n <= 0) {
        perror("recv");
        exit(1);
    }

    printf("Response: %s\n", response);

    close(sock);
    exit(0);
}