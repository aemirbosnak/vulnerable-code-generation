//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX 1024

void error_handling(char* message);

int main(int argc, char *argv[]) {

    int sockfd, newsockfd, portno, clilen, sd;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error_handling("socket failed");
        exit(1);
    }

    server = gethostbyname("127.0.0.1");

    if (server == NULL) {
        printf("No such host");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(8888);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0) {
        error_handling("connect failed");
        exit(1);
    }

    while(1) {
        bzero(buffer, MAX);
        fgets(buffer, MAX, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);

    return 0;
}

void error_handling(char* message) {
    perror(message);
    exit(1);
}