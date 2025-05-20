//MISTRAL-7B DATASET v1.0 Category: Building a HTTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUFFER 1024
#define PORT 80

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER];
    int read_size;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host: %s\n", argv[1]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("ERROR opening socket");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, server->h_addr_list[0], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        die("ERROR connecting");
    }

    send(sockfd, "GET / HTTP/1.0\r\nHost: localhost\r\nUser-Agent: Retro-HTTP-Client/1.0\r\nAccept: */*\r\n\r\n", strlen("GET / HTTP/1.0\r\nHost: localhost\r\nUser-Agent: Retro-HTTP-Client/1.0\r\nAccept: */*\r\n\r\n"), 0);

    while ((read_size = recv(sockfd, buffer, MAX_BUFFER, 0)) > 0) {
        printf("%.*s", read_size, buffer);
        fflush(stdout);
        memset(buffer, 0, MAX_BUFFER);
    }

    close(sockfd);
    return 0;
}