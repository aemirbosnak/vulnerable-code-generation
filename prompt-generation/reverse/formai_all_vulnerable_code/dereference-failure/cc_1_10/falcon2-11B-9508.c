//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    int opt = 1;
    char buf[1024];

    if (argc < 2) {
        fprintf(stderr, "usage: %s port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        sockfd = accept(sockfd, NULL, NULL);

        while (1) {
            bzero(buf, 1024);
            read(sockfd, buf, 1024);

            if (strcmp(buf, "exit\n") == 0) {
                break;
            } else {
                printf("Received: %s\n", buf);
                send(sockfd, "OK\n", strlen("OK\n"), 0);
            }
        }

        close(sockfd);
    }

    close(sockfd);
    return 0;
}