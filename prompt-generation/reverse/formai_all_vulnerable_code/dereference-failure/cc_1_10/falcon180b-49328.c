//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret, i;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    portno = PORT;
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host.\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to server.\n");

    while (TRUE) {
        bzero(buffer, MAX);
        ret = read(sockfd, buffer, MAX);
        if (ret < 0) {
            perror("read failed");
            exit(1);
        }
        if (ret == 0) {
            printf("Server closed connection.\n");
            break;
        }
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}