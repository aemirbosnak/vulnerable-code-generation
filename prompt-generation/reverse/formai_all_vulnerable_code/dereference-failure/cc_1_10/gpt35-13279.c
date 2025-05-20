//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s http://[hostname]/[path]\n",argv[0]);
        exit(1);
    }

    char *url = argv[1];
    char hostname[256];
    char path[1024];
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, portno = 80;
    char buffer[1024];

    sscanf(url, "http://%255[^/]/%1023s", hostname, path);
    printf("Hostname: %s\n", hostname);
    printf("Path: %s\n", path);

    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: could not resolve hostname\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    sprintf(buffer, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    write(sockfd, buffer, strlen(buffer));

    bzero(buffer, sizeof(buffer));
    while (read(sockfd, buffer, sizeof(buffer)-1) > 0) {
        printf("%s",buffer);
        bzero(buffer, sizeof(buffer));
    }

    close(sockfd);
    return 0;
}