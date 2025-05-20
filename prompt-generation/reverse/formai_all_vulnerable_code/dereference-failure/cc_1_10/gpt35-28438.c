//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define CMD_SIZE 256
#define RESP_SIZE 1024

void handle_error(const char *msg);

int main(int argc, char **argv)
{
    int sockfd, data_sockfd;
    struct sockaddr_in servaddr, data_servaddr;
    char cmd[CMD_SIZE];
    char resp[RESP_SIZE];
    char buf[BUF_SIZE];
    char *host, *file;
    int port, data_port, n;

    if (argc != 4) {
        printf("Usage: %s <hostname> <port> <filename>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);
    file = argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        handle_error("ERROR: Could not create socket");

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);

    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0)
        handle_error("ERROR: Invalid hostname");

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
        handle_error("ERROR: Could not connect");

    sprintf(cmd, "RETR %s\r\n", file);

    if (send(sockfd, cmd, strlen(cmd), 0) < 0)
        handle_error("ERROR: Failed to send command");

    memset(resp, 0, RESP_SIZE);

    if (recv(sockfd, resp, RESP_SIZE, 0) < 0)
        handle_error("ERROR: Failed to receive response");

    if (strncmp(resp, "150", 3) != 0)
        handle_error("ERROR: Invalid response");

    data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sockfd < 0)
        handle_error("ERROR: Could not create data socket");

    memset(&data_servaddr, 0, sizeof(data_servaddr));
    data_servaddr.sin_family = AF_INET;
    data_port = atoi(strchr(resp, '(') + 1);
    data_servaddr.sin_port = htons(data_port);

    if (inet_pton(AF_INET, host, &data_servaddr.sin_addr) <= 0)
        handle_error("ERROR: Invalid hostname");

    if (connect(data_sockfd, (struct sockaddr *)&data_servaddr, sizeof(data_servaddr)) < 0)
        handle_error("ERROR: Could not connect data socket");

    int file_fd = open(file, O_WRONLY | O_CREAT, 0777);

    while ((n = recv(data_sockfd, buf, BUF_SIZE, 0)) > 0) {
        if (write(file_fd, buf, n) < 0) {
            handle_error("ERROR: Failed to write to file");
        }
    }

    if (n < 0) {
        handle_error("ERROR: Failed to read from data socket");
    }

    sprintf(cmd, "QUIT\r\n");

    if (send(sockfd, cmd, strlen(cmd), 0) < 0)
        handle_error("ERROR: Failed to send command");

    close(data_sockfd);
    close(sockfd);

    printf("Downloaded file %s successfully\n", file);

    return 0;
}

void handle_error(const char *msg)
{
    perror(msg);
    exit(1);
}