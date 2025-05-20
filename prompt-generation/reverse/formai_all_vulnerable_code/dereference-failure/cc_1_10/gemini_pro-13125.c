//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char **argv)
{
    int sockfd, new_sockfd;
    struct sockaddr_in serv_addr, cli_addr;
    int port_number;
    char buffer[BUF_SIZE];
    socklen_t cli_len;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port_number>\n", argv[0]);
        exit(1);
    }

    port_number = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port_number);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    cli_len = sizeof(cli_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &cli_len);
    if (new_sockfd < 0) {
        perror("accept");
        exit(1);
    }

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        int n = read(new_sockfd, buffer, BUF_SIZE - 1);
        if (n < 0) {
            perror("read");
            break;
        } else if (n == 0) {
            // client has closed the connection
            break;
        }

        printf("Received from client: %s\n", buffer);

        // echo back the message to the client
        n = write(new_sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("write");
            break;
        }
    }

    close(new_sockfd);
    close(sockfd);

    return 0;
}