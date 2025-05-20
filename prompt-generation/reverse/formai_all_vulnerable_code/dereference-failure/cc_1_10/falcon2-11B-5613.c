//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFF_SIZE 1024

int main() {
    int sockfd, portno, n;
    char buffer[BUFF_SIZE];
    char* send_buffer = "HELO localhost\r\n";
    char* recv_buffer = (char*) malloc(BUFF_SIZE);

    struct hostent *server;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        return 1;
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(25);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        return 1;
    }

    if (send(sockfd, send_buffer, strlen(send_buffer), 0) < 0) {
        perror("send failed");
        return 1;
    }

    if (recv(sockfd, recv_buffer, BUFF_SIZE, 0) < 0) {
        perror("recv failed");
        return 1;
    }

    printf("%s\n", recv_buffer);

    free(recv_buffer);
    close(sockfd);

    return 0;
}