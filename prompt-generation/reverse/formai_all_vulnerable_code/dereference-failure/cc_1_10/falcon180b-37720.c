//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX 100
#define PORT 8080
#define SA struct sockaddr

void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    int maxsd;

    if(argc < 3) {
        printf("USAGE :./a.out <IP_Address> <No_of_Connections>\n");
        exit(0);
    }

    portno = PORT;
    maxsd = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        die("socket failed");

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if(bind(sockfd, (SA *)&serv_addr, sizeof(serv_addr))<0)
        die("bind failed");

    listen(sockfd, maxsd);

    while(1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (SA *)&cli_addr, &clilen);

        if(newsockfd < 0)
            die("accept failed");

        printf("New connection from : %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        send(newsockfd, "Welcome to the Server\n", strlen("Welcome to the Server\n"), 0);
    }

    return 0;
}