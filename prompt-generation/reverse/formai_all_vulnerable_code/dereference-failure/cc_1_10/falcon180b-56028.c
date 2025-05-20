//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX 100
#define SERVER "127.0.0.1"
#define PORT 8888
#define SA struct sockaddr

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, sd;
    char buffer[MAX];
    char *message = "Romeo, Romeo! wherefore art thou Romeo?\n";
    struct hostent *server;
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(SERVER);

    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    portno = PORT;

    if (connect(sockfd, (SA *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while(1) {
        puts("Enter message:");
        fgets(buffer, MAX, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        bzero(buffer, MAX);
        n = read(sockfd, buffer, MAX);
        buffer[n] = '\0';
        printf("From server: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}