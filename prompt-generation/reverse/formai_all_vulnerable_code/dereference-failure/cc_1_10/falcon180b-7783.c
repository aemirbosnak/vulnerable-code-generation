//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <pthread.h>

#define SERVER "speedtest.net"
#define PORT 80

struct sockaddr_in server_addr;
int sockfd, newsockfd, portno, clilen, recv_len;
char buffer[1024];

void *thread_send(void *arg) {
    int *data = (int *) arg;
    send(*data, buffer, strlen(buffer), 0);
    close(*data);
}

int main(int argc, char **argv) {
    int opt = 1;
    int addrlen = sizeof(server_addr);
    char host[256];
    int port = 80;

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    if (argc > 2) {
        strcpy(host, argv[2]);
    } else {
        strcpy(host, SERVER);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", host, port);

    while (1) {
        char *token = strtok(buffer, "\r\n");
        if (token == NULL) {
            break;
        }
        printf("%s", token);
    }

    close(sockfd);
    return 0;
}