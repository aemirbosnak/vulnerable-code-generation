//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server-address>\n", argv[0]);
        exit(1);
    }

    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd;
    int optval;
    int n;
    struct timeval timeout;
    char buffer[4096];

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Unknown host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(110);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    timeout.tv_sec = 60;
    timeout.tv_usec = 0;
    optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    char *user = "user@example.com";
    char *password = "password";

    int i = 0;
    while (1) {
        i++;
        sleep(1);
        if (i == 10) {
            memset(buffer, 0, sizeof(buffer));
            strcpy(buffer, "USER ");
            strcat(buffer, user);
            strcat(buffer, "\r\n");
            if (write(sockfd, buffer, strlen(buffer)) < 0)
                error("ERROR writing to socket");
            n = read(sockfd, buffer, 4096);
            if (n < 0)
                error("ERROR reading from socket");
            if (strstr(buffer, "235")!= NULL) {
                memset(buffer, 0, sizeof(buffer));
                strcpy(buffer, "PASS ");
                strcat(buffer, password);
                strcat(buffer, "\r\n");
                if (write(sockfd, buffer, strlen(buffer)) < 0)
                    error("ERROR writing to socket");
                n = read(sockfd, buffer, 4096);
                if (n < 0)
                    error("ERROR reading from socket");
                if (strstr(buffer, "257")!= NULL) {
                    printf("Successfully logged in\n");
                    break;
                }
            } else {
                printf("Login failed\n");
                break;
            }
        }
    }
    close(sockfd);
    return 0;
}