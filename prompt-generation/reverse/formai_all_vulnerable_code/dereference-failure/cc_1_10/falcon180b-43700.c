//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 21
#define MAX_LINE 1024
#define USER "anonymous"
#define PASSWORD "anonymous@example.com"

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char send_line[MAX_LINE];
    char recv_line[MAX_LINE];

    if (argc!= 4) {
        printf("Usage: %s <host> <filename> <mode>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error("socket failed");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("connect failed");

    sprintf(send_line, "USER %s\r\n", USER);
    send(sock, send_line, strlen(send_line), 0);

    sprintf(send_line, "PASS %s\r\n", PASSWORD);
    send(sock, send_line, strlen(send_line), 0);

    if (strcmp(argv[3], "put") == 0) {
        FILE *fp;
        char *mode = "STOR";

        fp = fopen(argv[2], "rb");
        if (fp == NULL)
            error("File not found");

        sprintf(send_line, "STOR %s\r\n", argv[2]);
        send(sock, send_line, strlen(send_line), 0);

        while (fgets(recv_line, MAX_LINE, fp)!= NULL) {
            send(sock, recv_line, strlen(recv_line), 0);
        }

        fclose(fp);
    }
    else if (strcmp(argv[3], "get") == 0) {
        sprintf(send_line, "RETR %s\r\n", argv[2]);
        send(sock, send_line, strlen(send_line), 0);
    }
    else {
        error("Invalid mode");
    }

    close(sock);
    return 0;
}