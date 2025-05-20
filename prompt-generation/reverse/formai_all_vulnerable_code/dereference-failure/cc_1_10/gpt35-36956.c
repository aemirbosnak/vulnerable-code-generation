//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAXLINE 512

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, port, n;
    char host[MAXLINE], userInput[MAXLINE];
    struct sockaddr_in servAddr;
    struct hostent *servHost;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port number>\n", argv[0]);
        exit(1);
    }

    strcpy(host, argv[1]);
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    servHost = gethostbyname(host);
    if (servHost == NULL) {
        fprintf(stderr, "ERROR: no such host %s\n", host);
        exit(0);
    }

    bzero((void *) &servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    bcopy((void *) servHost->h_addr, (void *) &servAddr.sin_addr.s_addr, servHost->h_length);
    servAddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
        error("ERROR connecting");
    }
    printf("Connected to server!\n");

    printf("Enter FTP commands or 'quit' to exit: ");
    fflush(stdout);

    while (fgets(userInput, MAXLINE, stdin) != NULL) {
        n = write(sockfd, userInput, strlen(userInput) + 1);
        if (n < 0) {
            error("ERROR writing to socket");
        }

        if (strcmp(userInput, "quit\n") == 0) {
            printf("Quitting...\n");
            close(sockfd);
            exit(0);
        }

        char response[MAXLINE];
        bzero(response, MAXLINE);
        n = read(sockfd, response, MAXLINE);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        printf("%s", response);

        printf("\nEnter FTP commands or 'quit' to exit: ");
        fflush(stdout);
    }

    return 0;
}