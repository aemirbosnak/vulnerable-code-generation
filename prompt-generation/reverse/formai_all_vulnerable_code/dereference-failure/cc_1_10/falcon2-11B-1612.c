//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    int port = 0;
    if (argc == 2) {
        port = atoi(argv[1]);
    } else {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in serv_addr;
    int optval = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    int val = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(int)) < 0) {
        perror("setsockopt");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 1) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        int client_fd = accept(sockfd, NULL, NULL);
        if (client_fd < 0) {
            perror("accept");
            exit(1);
        }

        int status;
        char buf[1024];
        ssize_t bytes_read = read(client_fd, buf, sizeof(buf));

        if (bytes_read < 0) {
            perror("read");
            exit(1);
        }

        status = close(client_fd);
        if (status < 0) {
            perror("close");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}