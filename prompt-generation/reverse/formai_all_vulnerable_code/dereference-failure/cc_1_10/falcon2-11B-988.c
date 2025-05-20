//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage : %s port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(0);
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        fprintf(stderr, "gethostbyname failed\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(0);
    }

    while (1) {
        char buf[1024];
        n = read(sockfd, buf, sizeof(buf));

        if (n <= 0)
            break;

        printf("%s", buf);
    }

    return 0;
}