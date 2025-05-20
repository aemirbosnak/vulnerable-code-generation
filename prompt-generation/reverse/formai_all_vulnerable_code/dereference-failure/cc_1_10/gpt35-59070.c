//FormAI DATASET v1.0 Category: Client Server Application ; Style: light-weight
/* C Client Server Application Example */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 256

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n, pid;

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    /* Create TCP socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    /* Initialize server address structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Bind socket to address */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        error("ERROR on binding");
    }

    /* Listen for connections */
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        /* Accept connection from client */
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            error("ERROR on accept");
        }

        /* Fork process to handle communication with client */
        pid = fork();
        if (pid < 0) {
            error("ERROR on fork");
        }

        if (pid == 0) {
            /* Child process */
            close(sockfd);

            while (1) {
                /* Read message from client */
                bzero(buffer, BUF_SIZE);
                n = read(newsockfd, buffer, BUF_SIZE);
                if (n < 0) {
                    error("ERROR reading from socket");
                }

                /* Print message from client */
                printf("Message from client: %s\n", buffer);

                /* Write response to client */
                n = write(newsockfd, "I got your message", 18);
                if (n < 0) {
                    error("ERROR writing to socket");
                }
            }

            /* Close connection to client */
            close(newsockfd);

            /* Exit child process */
            exit(0);
        }
        else {
            /* Parent process */
            close(newsockfd);
        }
    }

    /* Close server socket */
    close(sockfd);

    return 0;
}