//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *host, *path;
    char buffer[4096];
    int n, fd;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host = argv[1];
    portno = atoi(argv[2]);
    path = argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: socket()");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "ERROR: gethostbyname()\n");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: connect()");
        exit(EXIT_FAILURE);
    }

    fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("ERROR: open()");
        exit(EXIT_FAILURE);
    }

    while ((n = read(fd, buffer, sizeof(buffer))) > 0) {
        if (write(sockfd, buffer, n) < 0) {
            perror("ERROR: write()");
            exit(EXIT_FAILURE);
        }
    }

    if (n < 0) {
        perror("ERROR: read()");
        exit(EXIT_FAILURE);
    }

    close(sockfd);
    close(fd);

    return 0;
}