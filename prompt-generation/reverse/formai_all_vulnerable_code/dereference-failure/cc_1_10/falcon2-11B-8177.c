//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, valread;
    struct sockaddr_in servaddr;
    struct hostent *server;

    if (argc!= 2) {
        printf("Usage: ping <IP_address>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 2;
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        return 3;
    }

    printf("Pinging %s with 32 bytes of data: ", argv[1]);
    send(sockfd, "GET / HTTP/1.1\r\nHost: ", 21, 0);
    send(sockfd, "\r\n", 2, 0);
    send(sockfd, "\r\n\r\n", 10, 0);

    valread = recv(sockfd, NULL, 1, 0);
    if (valread < 0) {
        perror("ERROR receiving");
        return 4;
    }

    printf("%d bytes from %s\n", valread, argv[1]);
    return 0;
}