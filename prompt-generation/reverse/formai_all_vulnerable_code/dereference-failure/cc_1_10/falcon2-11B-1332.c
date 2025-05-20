//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

int main(int argc, char **argv) {
    int sockfd, portno, newsockfd, pid, valread;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];
    int n;

    if (argc < 3) {
        fprintf(stderr, "Usage %s hostname port\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    pid = fork();
    if (pid < 0) {
        perror("ERROR forking");
        exit(1);
    } else if (pid == 0) {
        close(sockfd);

        n = recv(sockfd, buffer, 1024, 0);
        if (n < 0) {
            perror("ERROR receiving");
            exit(1);
        }

        printf("Message received: %s\n", buffer);

        close(sockfd);
        exit(0);
    } else {
        close(sockfd);

        n = read(sockfd, buffer, 1024);
        if (n < 0) {
            perror("ERROR reading");
            exit(1);
        }

        printf("Message sent: %s\n", buffer);

        close(sockfd);
        exit(0);
    }
}