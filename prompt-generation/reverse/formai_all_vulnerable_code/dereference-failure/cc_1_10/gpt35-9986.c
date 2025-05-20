//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>

#define BUF_SIZE 1024

void print_response(int sock_fd) {
    char buffer[BUF_SIZE + 1] = {0};
    int recv_bytes;

    while ((recv_bytes = recv(sock_fd, buffer, BUF_SIZE, 0)) > 0) {
        buffer[recv_bytes] = '\0';
        printf("%s", buffer);
        memset(buffer, 0, BUF_SIZE);
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <host> <port> <command>\n", argv[0]);
        return -1;
    }

    char *host = argv[1];
    int port = atoi(argv[2]);
    char *command = argv[3];

    struct hostent *server;
    struct sockaddr_in server_addr;

    server = gethostbyname(host);

    if (server == NULL) {
        fprintf(stderr, "Could not resolve hostname %s\n", host);
        return -1;
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd == -1) {
        perror("socket");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return -1;
    }

    char *message = malloc(BUF_SIZE + strlen(command) + 3);
    sprintf(message, "%s\r\n", command);

    if (send(sock_fd, message, strlen(message), 0) == -1) {
        perror("send");
        return -1;
    }

    free(message);
    print_response(sock_fd);
    close(sock_fd);

    return 0;
}