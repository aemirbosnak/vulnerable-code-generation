//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int addrlen;
    int opt = 1;
    int addrlen_cli;
    char *hostname = argv[1];
    char *servname = argv[2];
    int max_client = atoi(argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(servname));

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, max_client);

    printf("Server is listening on port %s\n", servname);

    while (1) {
        addrlen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);

        if (newsockfd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s on port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        addrlen_cli = sizeof(cli_addr);
        getsockname(newsockfd, (struct sockaddr *)&cli_addr, &addrlen_cli);

        send(newsockfd, hostname, strlen(hostname), 0);
        send(newsockfd, servname, strlen(servname), 0);

        close(newsockfd);
    }

    close(sockfd);

    return 0;
}