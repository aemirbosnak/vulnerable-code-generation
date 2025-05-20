//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_SIZE 1000

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    char buffer[MAX_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char *host;
    int opt = 1;
    int addrlen = sizeof(cli_addr);

    // check if correct number of arguments
    if (argc!= 3) {
        fprintf(stderr, "Usage:./server <port_number> <message>\n");
        exit(1);
    }

    // set port number
    portno = atoi(argv[1]);

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        error("socket failed");

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // set server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(portno);

    // bind to socket
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("bind failed");

    // listen for incoming connections
    if (listen(sockfd, 5) < 0)
        error("listen");

    while (1) {
        // accept connection
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0)
            error("accept");

        printf("Connection from %s on port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // send message to client
        send(newsockfd, argv[2], strlen(argv[2]), 0);

        // close connection
        close(newsockfd);
    }

    return 0;
}