//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char hostname[256];
    strcpy(hostname, argv[1]);

    int sockfd, valread;
    struct hostent *server;
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(53);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char buf[1024];
    int n;

    while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
        buf[n] = '\0';
        printf("%s\n", buf);
    }

    return 0;
}