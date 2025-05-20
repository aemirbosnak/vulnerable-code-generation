//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

// HTTP Request example
const char *http_request = "GET / HTTP/1.0\r\nHost: www.example.com\r\n\r\n";

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    const char* domain_name = "www.example.com";
    server = gethostbyname(domain_name);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    n = write(sockfd,http_request,strlen(http_request));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    char buffer[1000];
    bzero(buffer, 1000);
    n = read(sockfd,buffer,999);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n",buffer);
    close(sockfd);
    return 0;
}