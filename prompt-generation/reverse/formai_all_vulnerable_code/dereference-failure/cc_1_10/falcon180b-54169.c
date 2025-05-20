//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, socklen, client_fd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    char *host = "localhost";
    int host_len = strlen(host);
    int opt = 1;
    int addrlen = sizeof(cli_addr);

    if (argc!= 3) {
        printf("Usage: %s <port_number> <message>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[1]);
    strncpy(buffer, argv[2], BUFFER_SIZE);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        error_handling("socket failed");

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
        error_handling("setsockopt");

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error_handling("bind failed");

    listen(sockfd, 5);
    printf("Server is listening on port %d\n", portno);

    while (1) {
        clilen = sizeof(cli_addr);
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &socklen)) < 0)
            error_handling("accept");

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        send(newsockfd, buffer, strlen(buffer), 0);
        close(newsockfd);
    }

    return 0;
}