//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main() {
    struct sockaddr_in server;
    struct hostent *host;
    char response[100];
    int sockfd, len;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    host = gethostbyname("www.google.com");
    if (host == NULL) {
        printf("Error, no such host\n");
        exit(1);
    }

    bzero((char *)&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    bcopy((char *)host->h_addr, (char *)&server.sin_addr.s_addr, host->h_length);

    len = strlen(response);
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Error connecting\n");
        exit(1);
    }

    send(sockfd, "GET / HTTP/1.1\r\n\r\n", strlen("GET / HTTP/1.1\r\n\r\n"), 0);

    len = read(sockfd, response, sizeof(response));
    if (len < 0) {
        printf("Error reading response\n");
        exit(1);
    }

    printf("Response: %s\n", response);

    close(sockfd);
    return 0;
}