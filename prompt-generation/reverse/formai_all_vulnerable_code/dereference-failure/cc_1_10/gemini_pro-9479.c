//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    int client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char buf[BUF_SIZE];
    while (1) {
        printf("Enter a message to send to the server (or 'quit' to exit): ");
        fgets(buf, BUF_SIZE, stdin);

        if (strcmp(buf, "quit\n") == 0) {
            break;
        }

        if (send(client_sock, buf, strlen(buf), 0) == -1) {
            perror("send");
            exit(1);
        }

        if (recv(client_sock, buf, BUF_SIZE, 0) == -1) {
            perror("recv");
            exit(1);
        }

        printf("Received from the server: %s", buf);
    }

    close(client_sock);
    return 0;
}