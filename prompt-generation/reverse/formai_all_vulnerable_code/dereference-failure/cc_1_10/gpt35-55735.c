//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_REQUEST_SIZE 2048

int main(int argc, char *argv[]) {
    // parse command line arguments to get URL
    if(argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        exit(1);
    }
    char *url = argv[1];
    
    // parse URL to get host, port and path
    char *host, *path;
    long port = 80;  // default port is 80 for HTTP
    if(strncmp(url, "http://", 7) == 0) {
        url += 7;  // skip http://
        host = strsep(&url, "/");
        if(strchr(host, ':')) {
            port = strtol(strchr(host, ':') + 1, NULL, 10);
            *strchr(host, ':') = '\0';
        }
        path = url;
    } else {
        printf("Invalid URL: %s\n", url);
        exit(1);
    }
    
    // create socket to connect to host
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket");
        exit(1);
    }
    struct hostent *hent = gethostbyname(host);
    if(hent == NULL) {
        printf("Error: unknown host %s\n", host);
        exit(1);
    }
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *(struct in_addr *)hent->h_addr;
    if(connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(1);
    }
    
    // send HTTP GET request to server
    char request[MAX_REQUEST_SIZE];
    snprintf(request, MAX_REQUEST_SIZE, "GET /%s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    if(send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        exit(1);
    }
    
    // receive response from server and print to stdout
    char buffer[4096];
    int recvlen;
    while((recvlen = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, 1, recvlen, stdout);
    }
    
    // close socket and exit
    close(sockfd);
    return 0;
}