//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define GET_REQUEST "GET / HTTP/1.0\r\nHost: %s\r\nUser-Agent: %s\r\n\r\n"

void parse_url(char *url, char **hostname, char **path){
    char *ptr = strstr(url,"//");

    *hostname = ptr + 2;
    ptr = strchr(*hostname, '/');

    if (ptr != NULL) {
        *ptr = '\0';
        *path = ptr + 1;
    }
    else {
        *path = "/";
    }
}

int main(int argc, char **argv)
{
    char *url_str, *hostname, *path, *response;
    int sockfd, portno = 80, bytes, total= 0;

    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(-1);
    }

    url_str = argv[1];
    response = malloc(999999 * sizeof(char));

    parse_url(url_str, &hostname, &path);

    struct hostent *server;
    struct sockaddr_in serv_addr;

    server = gethostbyname(hostname);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (server == NULL) {
        fprintf(stderr,"No such host found.\n");
        exit(1);
    }

    memset(&serv_addr,0,sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
        perror("Could not connect to server.\n");
        exit(-1);
    }

    char useragent[100] = "Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:70.0) Gecko/20100101 Firefox/70.0";
    char getreq[1000];
    sprintf(getreq, GET_REQUEST, hostname, useragent);

    send(sockfd, getreq, strlen(getreq), 0);

    while(1){
        bytes = recv(sockfd, response+total, 999999-total, 0);
        if (bytes <= 0){
            break;
        }
        total += bytes;
    }

    printf("%s", response);

    close(sockfd);
    return 0;
}