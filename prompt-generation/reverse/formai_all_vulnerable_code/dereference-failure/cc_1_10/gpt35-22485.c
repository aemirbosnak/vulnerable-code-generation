//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void error(char* message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, client_sockfd, portno, clilen, n;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    printf("Server listening on port %d\n", portno);

    while (1) {
        client_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (client_sockfd < 0)
            error("ERROR on accept");

        printf("Client connected: %s\n", inet_ntoa(cli_addr.sin_addr));

        pid_t pid = fork();

        if (pid < 0)
           error("ERROR on fork");

        if (pid == 0) {
            // child process
            close(sockfd);

            while (1) {
                bzero(buffer, 256);
                n = read(client_sockfd, buffer, 255);
                if (n < 0)
                    error("ERROR reading from socket");

                if (strcmp(buffer, "quit") == 0) {
                    printf("Client disconnected: %s\n", inet_ntoa(cli_addr.sin_addr));
                    break;
                }

                printf("[%s]: %s", inet_ntoa(cli_addr.sin_addr), buffer);
                n = write(client_sockfd, "Message Received\n", 18);
                if (n < 0)
                    error("ERROR writing to socket");
            }
            close(client_sockfd);
            exit(0);
        } else {
            // parent process
            close(client_sockfd);
        }
    }
    close(sockfd);
    return 0;
}