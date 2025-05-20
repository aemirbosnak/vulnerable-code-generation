//FormAI DATASET v1.0 Category: Email Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_LENGTH 1024

void error_handler(const char *message);

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;

    if (argc != 3) {
        printf("Usage: %s <server ip> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handler("socket() error");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handler("connect() error");
    }

    char message[MAX_MSG_LENGTH+1];

    while(1) {
        printf("Enter message (q to quit): ");
        fgets(message, sizeof(message), stdin);

        if (!strcmp(message, "q\n") || !strcmp(message, "Q\n")) {
            break;
        }

        write(sock, message, strlen(message));

        int len = read(sock, message, MAX_MSG_LENGTH);
        if (len == -1) {
            error_handler("read() error");
        }

        message[len] = 0;
        printf("Server returned: %s", message);
    }

    close(sock);
    return 0;
}

void error_handler(const char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}