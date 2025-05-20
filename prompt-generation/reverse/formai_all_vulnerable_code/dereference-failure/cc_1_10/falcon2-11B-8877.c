//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char **argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "usage %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    while (1) {
        n = read(sockfd, buffer, 1024);
        if (n <= 0) {
            break;
        }

        printf("%s", buffer);
    }

    return 0;
}