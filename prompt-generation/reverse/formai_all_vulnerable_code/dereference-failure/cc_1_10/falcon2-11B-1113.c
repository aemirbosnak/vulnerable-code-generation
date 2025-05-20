//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 256
#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "usage : %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "no such host\n");
        exit(2);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(3);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(4);
    }

    printf("Connected to %s on port %d\n", argv[1], PORT);

    char buffer[MAXLINE];
    while (1) {
        printf("Enter your command: ");
        fgets(buffer, MAXLINE, stdin);

        if (strncmp(buffer, "exit", 4) == 0) {
            printf("Exiting...\n");
            close(sockfd);
            return 0;
        }

        n = write(sockfd, buffer, strlen(buffer));
        if (n == -1) {
            perror("write");
            exit(5);
        }

        if (read(sockfd, buffer, MAXLINE) == -1) {
            perror("read");
            exit(6);
        }

        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}