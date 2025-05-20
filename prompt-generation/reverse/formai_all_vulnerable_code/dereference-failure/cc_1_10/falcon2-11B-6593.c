//Falcon2-11B DATASET v1.0 Category: Error handling ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    char *argv[] = {"server.txt", NULL};

    if (fork() == 0) { // child process
        close(0);
        close(1);
        close(2);
        dup2(sockfd, 0);
        dup2(sockfd, 1);
        dup2(sockfd, 2);

        int ret = execve(argv[0], argv, NULL);
        if (ret == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else { // parent process
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket");
            exit(EXIT_FAILURE);
        }

        portno = atoi(argv[1]);
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(portno);
        serv_addr.sin_addr.s_addr = INADDR_ANY;

        if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
            perror("bind");
            exit(EXIT_FAILURE);
        }

        if (listen(sockfd, 1) == -1) {
            perror("listen");
            exit(EXIT_FAILURE);
        }

        socklen_t clientlen = sizeof(struct sockaddr_in);
        int newsockfd = accept(sockfd, (struct sockaddr*)&serv_addr, &clientlen);
        if (newsockfd == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        char c;
        while ((n = read(newsockfd, &c, 1)) > 0) {
            if (n == 1) {
                write(newsockfd, &c, 1);
            }
        }
        close(newsockfd);
    }

    return 0;
}