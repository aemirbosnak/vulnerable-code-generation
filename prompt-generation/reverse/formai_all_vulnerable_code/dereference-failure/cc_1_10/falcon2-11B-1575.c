//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, nbytes, addrlen;
    struct sockaddr_in serv_addr;
    char recv_buff[1024];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    if (send(sockfd, "PING ", 5, 0) < 0) {
        perror("send failed");
        exit(1);
    }

    if (recv(sockfd, recv_buff, sizeof(recv_buff), 0) < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("Received: %s\n", recv_buff);

    if (close(sockfd) < 0) {
        perror("close failed");
        exit(1);
    }

    return 0;
}