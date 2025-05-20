//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 5000

void handle_client(int sockfd, char* msg) {
    printf("Message from client: %s\n", msg);
}

int main(int argc, char* argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
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

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        printf("Waiting for connection...\n");
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
        if (newsockfd < 0) {
            perror("accept failed");
            exit(1);
        }

        printf("Got connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while (1) {
            bzero(buffer, 1024);
            n = read(newsockfd, buffer, 1024);
            if (n < 0) {
                perror("read failed");
                exit(1);
            }
            buffer[n] = '\0';
            printf("Message from client: %s\n", buffer);

            handle_client(newsockfd, buffer);
        }
    }

    return 0;
}