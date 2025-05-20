//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: protected
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define PORT 8080

int main() {
    int sockfd, new_fd, addrlen, ch;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[100];
    struct timeval start, end;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error in creating socket");
        return 1;
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("Error in getting localhost");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error in connecting to server");
        return 1;
    }

    gettimeofday(&start, NULL);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        new_fd = accept(sockfd, (struct sockaddr *) &cli_addr, &addrlen);
        if (new_fd < 0) {
            perror("Error in accepting new connection");
            return 1;
        }

        gettimeofday(&end, NULL);
        time_t time_diff = difftime(end.tv_sec, start.tv_sec);

        if (time_diff < 1) {
            printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
            printf("Time taken: %ld seconds\n", time_diff);
        } else {
            printf("Connection from %s:%d timed out\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        }

        close(new_fd);
    }

    close(sockfd);
    return 0;
}