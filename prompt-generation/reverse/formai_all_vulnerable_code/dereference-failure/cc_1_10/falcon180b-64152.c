//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[]) {
    int sockfd, portno, max_sd, sd, ret, i, j;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    fd_set readfds;

    if (argc!= 3) {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket creation failed\n");
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: host not found\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        printf("Error: connection failed\n");
        exit(0);
    }

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    max_sd = sockfd;

    for (i = 1; i <= MAX_PORTS; i++) {
        sd = socket(AF_INET, SOCK_STREAM, 0);
        if (sd == -1) {
            printf("Error: socket creation failed\n");
            exit(0);
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(i);
        serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

        ret = connect(sd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
        if (ret == -1) {
            printf("Port %d is closed\n", i);
            close(sd);
        } else {
            printf("Port %d is open\n", i);
            close(sd);
        }
    }

    close(sockfd);

    return 0;
}