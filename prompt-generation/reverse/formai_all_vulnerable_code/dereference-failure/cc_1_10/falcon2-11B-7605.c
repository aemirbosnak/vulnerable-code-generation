//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    if (argc < 2) {
        fprintf(stderr, "Usage %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error in creating socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error in binding\n");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        cli_addr.sin_family = AF_INET;
        cli_addr.sin_addr.s_addr = INADDR_ANY;
        cli_addr.sin_port = htons(0);

        n = sizeof(cli_addr);
        sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &n);
        if (sockfd < 0) {
            fprintf(stderr, "Error in accepting\n");
            exit(1);
        }

        memset(buffer, 0, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            fprintf(stderr, "Error in reading\n");
            exit(1);
        }
        printf("%s\n", buffer);
        close(sockfd);
    }

    close(sockfd);
    return 0;
}