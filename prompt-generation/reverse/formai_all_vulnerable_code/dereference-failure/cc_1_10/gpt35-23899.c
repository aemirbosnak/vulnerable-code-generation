//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h> 
#include<netinet/in.h> 
#include<string.h> 

int main(int argc, char *argv[]) 
{
    char header[1024];
    char buffer[1024];
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        return 0;
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 0;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        return 0;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 0;
    }

    sprintf(header, "GET / HTTP/1.1\r\nHost: %s:%d\r\nConnection: close\r\n\r\n", argv[1], portno);

    n = write(sockfd, header, strlen(header));
    if (n < 0) {
        perror("ERROR writing to socket");
        return 0;
    }

    while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    if (n < 0) {
        perror("ERROR reading from socket");
        return 0;
    }

    return 0;
}