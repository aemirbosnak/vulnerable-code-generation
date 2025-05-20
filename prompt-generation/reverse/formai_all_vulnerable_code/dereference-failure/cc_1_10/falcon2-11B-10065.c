//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
    char host[NI_MAXHOST];
    int sockfd, portno, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;

    if (gethostname(host, NI_MAXHOST) < 0) {
        fprintf(stderr, "Error in gethostname()\n");
        exit(1);
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error in gethostbyname()\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error in socket()\n");
        exit(1);
    }

    portno = server->h_addrtype == AF_INET? ntohs(*((unsigned short*)server->h_addr_list[0])) : 0;
    if (portno == 0) {
        fprintf(stderr, "Error in portno\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error in connect()\n");
        exit(1);
    }

    send(sockfd, "PING ", 5, 0);
    send(sockfd, " ", 1, 0);
    send(sockfd, " ", 1, 0);
    send(sockfd, "\r\n", 2, 0);

    bzero(host, NI_MAXHOST);
    n = recv(sockfd, host, NI_MAXHOST, 0);
    if (n <= 0) {
        fprintf(stderr, "Error in recv()\n");
        exit(1);
    }
    printf("Received %d bytes: %s\n", n, host);

    close(sockfd);
    return 0;
}