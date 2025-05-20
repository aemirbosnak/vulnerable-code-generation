//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <pthread.h>

int main() {
    int sockfd, valread, valwrite, portno, newsockfd, count;
    struct sockaddr_in serv_addr, cli_addr;
    char buf[1024], line[1024], *ptr;
    FILE *fp;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8888);

    bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    listen(sockfd, 5);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &valread);
        if (newsockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        portno = cli_addr.sin_port;
        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        fp = fdopen(newsockfd, "r");
        while ((count = getline(&line, &count, fp))!= -1) {
            ptr = strtok(line, "\r\n");
            while (ptr!= NULL) {
                send(newsockfd, line, strlen(line), 0);
                printf("Sent: %s\n", line);
                ptr = strtok(NULL, "\r\n");
            }
        }
        close(newsockfd);
    }
    close(sockfd);
    return 0;
}