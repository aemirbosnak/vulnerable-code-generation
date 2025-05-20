//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[256];
    int n;

    if (argc!= 2) {
        fprintf(stderr, "Usage %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Bind failed\n");
        exit(1);
    }

    listen(sockfd, 3);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
        if (newsockfd < 0) {
            perror("Accept");
            continue;
        }

        bzero(buffer, sizeof(buffer));
        n = read(newsockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("Read");
            close(newsockfd);
            continue;
        }

        printf("Connection from %s\n", inet_ntoa(cli_addr.sin_addr));
        printf("Message: %s\n", buffer);

        send(newsockfd, "Hello World!", strlen("Hello World!") + 1, 0);
        close(newsockfd);
    }
}