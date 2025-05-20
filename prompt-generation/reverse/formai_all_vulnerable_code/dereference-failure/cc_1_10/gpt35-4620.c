//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_MSG_LEN 1024

void error_handling(char *msg);

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;
    char msg[MAX_MSG_LEN];

    if (argc != 2) {
        printf("Usage: %s port\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1) {
        error_handling("socket() error");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("bind() error");
    }

    if (listen(serv_sock, 5) == -1) {
        error_handling("listen() error");
    }

    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1) {
        error_handling("accept() error");
    }

    printf("Connected to client %s:%d\n", inet_ntoa(clnt_addr.sin_addr), ntohs(clnt_addr.sin_port));

    while (1) {
        memset(msg, 0, MAX_MSG_LEN);
        ssize_t recv_len = recv(clnt_sock, msg, MAX_MSG_LEN - 1, 0);
        if (recv_len == -1) {
            error_handling("recv() error");
        }
        else if (recv_len == 0) {
            printf("Connection closed by client\n");
            break;
        }

        printf("Received message: %s\n", msg);

        ssize_t send_len = send(clnt_sock, msg, strlen(msg), 0);
        if (send_len == -1) {
            error_handling("send() error");
        }
    }

    close(clnt_sock);
    close(serv_sock);

    printf("Server closed.\n");

    return 0;
}

void error_handling(char *msg) {
    printf("[ERROR] %s\n", msg);
    exit(1);
}