//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_LINE 100

void check_website_uptime(char *website) {
    struct hostent *host;
    struct sockaddr_in server;
    int sockfd, portno, n;
    char buffer[MAX_LINE];

    if ((host = gethostbyname(website)) == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server.sin_addr.s_addr, host->h_length);
    server.sin_port = htons(80);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    if ((n = recv(sockfd, buffer, MAX_LINE, 0)) < 0) {
        perror("ERROR receiving");
        exit(1);
    }

    printf("Website %s is %s\n", website, buffer);

    close(sockfd);
}

int main() {
    char website[] = "www.example.com";
    check_website_uptime(website);
    return 0;
}