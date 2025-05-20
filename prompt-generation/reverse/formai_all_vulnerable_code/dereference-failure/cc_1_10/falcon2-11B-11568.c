//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char sendbuf[1000], recvbuf[1000];

    if (argc!= 3) {
        fprintf(stderr, "Usage %s hostname port\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(0);
    }

    printf("Pinging %s through port %s\n", argv[1], argv[2]);

    sprintf(sendbuf, "PING %s %s\r\n", argv[1], argv[2]);
    write(sockfd, sendbuf, strlen(sendbuf));

    n = read(sockfd, recvbuf, 1000);
    if (n > 0) {
        printf("Received %d bytes: %s\n", n, recvbuf);
    } else {
        perror("ERROR reading from socket");
    }

    printf("Ping finished in %d seconds\n", n);

    close(sockfd);
    return 0;
}