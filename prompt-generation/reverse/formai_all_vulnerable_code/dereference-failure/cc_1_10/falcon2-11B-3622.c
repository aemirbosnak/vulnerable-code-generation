//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int sockfd, portno, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];

    if (argc < 2) {
        fprintf(stderr,"usage %s hostname\n", argv[0]);
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(0);
    }

    printf("Connection established\n");

    for (;;) {
        bzero(buffer, sizeof(buffer));
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&portno);
        if (newsockfd < 0) {
            perror("ERROR accepting connection");
            exit(0);
        }
        printf("New connection: %s, %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        while (1) {
            bzero(buffer, sizeof(buffer));
            if (recv(newsockfd, buffer, sizeof(buffer), 0) < 0) {
                perror("ERROR reading from socket");
                exit(0);
            }
            buffer[strlen(buffer)-1] = '\0';
            printf("%s\n", buffer);
            printf("Send message: ");
            fgets(buffer, sizeof(buffer), stdin);
            send(newsockfd, buffer, strlen(buffer), 0);
            fflush(stdout);
        }
    }

    close(sockfd);
    return 0;
}