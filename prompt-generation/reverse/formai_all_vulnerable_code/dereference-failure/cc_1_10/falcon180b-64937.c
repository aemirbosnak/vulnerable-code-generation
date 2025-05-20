//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, opt = 1;
    struct sockaddr_in server_addr;
    char *host = argv[1];
    char *port = argv[2];
    char buffer[BUF_SIZE];
    int len;
    int err;

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set options on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // connect to server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // send request
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive response
    while ((len = recv(sockfd, buffer, BUF_SIZE, 0)) > 0) {
        buffer[len] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}