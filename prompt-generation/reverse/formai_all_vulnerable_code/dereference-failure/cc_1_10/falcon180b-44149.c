//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535

void print_usage(char *progname) {
    fprintf(stderr, "Usage: %s <IP Address> <Start Port> <End Port>\n", progname);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        fprintf(stderr, "Start port cannot be greater than end port\n");
        exit(1);
    }

    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    char buffer[1025];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);
    serv_addr.sin_port = htons(start_port);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sockfd, 5);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, sizeof(cli_addr));

        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        portno = ntohs(cli_addr.sin_port);

        if (portno >= start_port && portno <= end_port) {
            sprintf(buffer, "Port %d is open\n", portno);
            send(newsockfd, buffer, strlen(buffer), 0);
        } else {
            sprintf(buffer, "Port %d is closed\n", portno);
            send(newsockfd, buffer, strlen(buffer), 0);
        }

        close(newsockfd);
    }

    return 0;
}