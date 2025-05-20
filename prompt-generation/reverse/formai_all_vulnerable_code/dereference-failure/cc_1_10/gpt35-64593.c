//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFSIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    fd_set readset;
    FD_ZERO(&readset);
    FD_SET(sockfd, &readset);
    FD_SET(0, &readset);

    printf("Connected to server. Enter 'exit' to close connection.\n");

    while (1) {
        FD_SET(sockfd, &readset);
        FD_SET(0, &readset);
        int nready = select(sockfd + 1, &readset, NULL, NULL, NULL);

        if (nready <= 0) {
            error("Error in select()");
        }
        if (FD_ISSET(0, &readset)) {
            bzero(buffer, BUFSIZE);
            fgets(buffer, BUFSIZE, stdin);
            n = write(sockfd, buffer, strlen(buffer));
            if (n < 0)
                error("ERROR writing to socket");
            if (strstr(buffer, "exit") != NULL) {
                printf("Closing connection.\n");
                break;
            }
        }
        if (FD_ISSET(sockfd, &readset)) {
            bzero(buffer, BUFSIZE);
            n = read(sockfd, buffer, BUFSIZE);
            if (n < 0)
                error("ERROR reading from socket");
            printf("%s", buffer);
        }
    }

    close(sockfd);
    return 0;
}