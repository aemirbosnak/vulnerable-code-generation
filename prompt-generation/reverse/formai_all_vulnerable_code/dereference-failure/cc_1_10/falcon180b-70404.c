//Falcon-180B DATASET v1.0 Category: Networking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, recv_len;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];

    if(argc!= 3) {
        printf("Usage:./server <port_number> <message>\n");
        exit(0);
    }

    portno = atoi(argv[1]);
    strcpy(buffer, argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error_handling("socket failed");

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error_handling("bind failed");

    if (listen(sockfd, 5) < 0)
        error_handling("listen");

    printf("Server is listening on port %d\n", portno);

    while(1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0)
            error_handling("accept");

        printf("Connection with client established\n");

        while(1) {
            bzero(buffer, BUFFER_SIZE);
            recv_len = recv(newsockfd, buffer, BUFFER_SIZE, 0);
            if(recv_len <= 0)
                break;

            printf("Received message from client: %s\n", buffer);

            send(newsockfd, buffer, strlen(buffer), 0);
        }

        close(newsockfd);
        printf("Connection with client closed\n");
    }

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(0);
}