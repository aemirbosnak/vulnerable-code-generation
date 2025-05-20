//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    int addrlen = sizeof(serv_addr);
    char buf[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&addrlen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        int yes = 1;
        setsockopt(newsockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
        serv_addr.sin_port = htons(portno);

        if (connect(newsockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("ERROR connecting");
            exit(1);
        }

        while (1) {
            if (recv(newsockfd, buf, sizeof(buf), 0) < 0) {
                perror("ERROR receiving");
                exit(1);
            }

            if (send(newsockfd, buf, sizeof(buf), 0) < 0) {
                perror("ERROR sending");
                exit(1);
            }
        }

        close(newsockfd);
    }

    return 0;
}