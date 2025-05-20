//MISTRAL-7B DATASET v1.0 Category: Building a FTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 4096

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <filename>\n", argv[0]);
        exit(1);
    }

    const char *host = argv[1];
    int port = atoi(argv[2]);
    const char *filename = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) die("socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) die("inet_pton");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) die("connect");

    const char *user = "anonymous";
    const char *pass = "anonymous@example.com";

    send(sockfd, "USER ", 5, 0);
    send(sockfd, user, strlen(user), 0);
    send(sockfd, "\r\n", 2, 0);

    send(sockfd, "PASS ", 5, 0);
    send(sockfd, pass, strlen(pass), 0);
    send(sockfd, "\r\n", 2, 0);

    char cmd[8] = "RETR ";
    strcat(cmd, filename);

    send(sockfd, cmd, strlen(cmd), 0);

    char buffer[BUFFER_SIZE];
    int bytes_received;
    FILE *fp = fopen(filename, "wb");

    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, bytes_received, 1, fp);
    }

    if (bytes_received == -1) die("recv");

    fclose(fp);
    close(sockfd);

    printf("File %s downloaded successfully.\n", filename);
}