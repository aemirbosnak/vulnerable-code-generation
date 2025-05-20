//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main() {
    int sockfd, newfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];

    if ((server = gethostbyname("localhost")) == NULL) {
        fprintf(stderr, "gethostbyname() failed\n");
        exit(1);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = *((unsigned long *)server->h_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "socket() failed\n");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "bind() failed\n");
        exit(1);
    }

    if (listen(sockfd, 1) < 0) {
        fprintf(stderr, "listen() failed\n");
        exit(1);
    }

    while (1) {
        newfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&portno);
        if (newfd < 0) {
            fprintf(stderr, "accept() failed\n");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        if (read(newfd, buffer, 1024) < 0) {
            fprintf(stderr, "read() failed\n");
            exit(1);
        }
        printf("Received message: %s\n", buffer);
        if (write(newfd, "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n", 65) < 0) {
            fprintf(stderr, "write() failed\n");
            exit(1);
        }
        printf("Sent response\n");
        close(newfd);
    }

    return 0;
}