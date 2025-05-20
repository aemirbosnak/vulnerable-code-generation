//MISTRAL-7B DATASET v1.0 Category: Chat server ; Style: accurate
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAXLINE 1024
#define BUFFER_SIZE 512

void error_handling(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int serv_sock, cli_sock, str_len;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char message[MAXLINE];
    int addrlen;
    int msg_len;

    if (argc != 2) {
        printf("Usage : %s <Port>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1) {
        error_handling("Failed to open socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("Failed to bind");
    }

    if (listen(serv_sock, 10) == -1) {
        error_handling("Failed to listen");
    }

    printf("Chat Server is running on port %s\n", argv[1]);

    while (true) {
        addrlen = sizeof(cli_addr);
        cli_sock = accept(serv_sock, (struct sockaddr *)&cli_addr, &addrlen);
        if (cli_sock == -1) {
            error_handling("Accept error");
        }

        printf("New client connected : %s:%d\n",
               inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (true) {
            msg_len = recv(cli_sock, message, MAXLINE, 0);
            if (msg_len <= 0) {
                break;
            }
            printf("Message received : %s\n", message);
            strcpy(buffer, message);
            strcat(buffer, ":");
            strcat(buffer, "Server: ");
            send(cli_sock, buffer, strlen(buffer), 0);
        }

        close(cli_sock);
        printf("Client disconnected\n");
    }

    close(serv_sock);
    return 0;
}