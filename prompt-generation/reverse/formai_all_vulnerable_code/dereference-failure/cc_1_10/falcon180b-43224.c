//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        return 1;
    }

    strcpy(server_addr.sin_zero, "");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect");
    }

    char login[100];
    sprintf(login, "USER %s\r\n", argv[2]);
    send(sock, login, strlen(login), 0);

    char pass[100];
    sprintf(pass, "PASS %s\r\n", argv[3]);
    send(sock, pass, strlen(pass), 0);

    char reply[BUFFER_SIZE];
    memset(reply, 0, BUFFER_SIZE);
    recv(sock, reply, BUFFER_SIZE, 0);

    printf("%s\n", reply);

    close(sock);
    return 0;
}