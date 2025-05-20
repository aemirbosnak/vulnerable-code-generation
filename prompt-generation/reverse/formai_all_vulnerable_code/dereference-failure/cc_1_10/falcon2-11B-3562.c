//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char send_buf[1024] = "GET / HTTP/1.1\r\nHost: ";
    char recv_buf[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    n = write(sockfd, send_buf, strlen(send_buf));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    memset(recv_buf, '\0', sizeof(recv_buf));
    n = read(sockfd, recv_buf, sizeof(recv_buf));
    printf("%s", recv_buf);

    close(sockfd);
    return 0;
}