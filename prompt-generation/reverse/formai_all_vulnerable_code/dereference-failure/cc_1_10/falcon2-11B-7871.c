//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    if (argc!= 3) {
        fprintf(stderr, "Usage %s port_num file\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);
    if (portno < 1024 || portno > 65535) {
        fprintf(stderr, "Invalid port number\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);
    cli_addr.sin_family = AF_INET;
    cli_addr.sin_addr.s_addr = INADDR_ANY;
    cli_addr.sin_port = 0;

    while (1) {
        cli_addr.sin_port = htons(portno);
        cli_addr.sin_addr.s_addr = INADDR_ANY;

        if ((sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen)) < 0) {
            perror("accept");
            continue;
        }

        printf("Connected by %s\n", inet_ntoa(cli_addr.sin_addr));
        recv(sockfd, buffer, sizeof(buffer), 0);
        send(sockfd, buffer, strlen(buffer), 0);
        close(sockfd);
    }

    return 0;
}