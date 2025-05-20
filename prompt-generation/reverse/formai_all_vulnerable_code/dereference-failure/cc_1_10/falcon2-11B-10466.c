//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <website URL>\n", argv[0]);
        exit(1);
    }
    struct hostent *host;
    struct sockaddr_in servaddr;
    int sockfd;
    char *url = argv[1];
    char message[100];
    socklen_t len = sizeof(servaddr);
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    if ((host = gethostbyname(url)) == NULL) {
        fprintf(stderr, "gethostbyname() failed\n");
        exit(1);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(53);
    if (inet_pton(AF_INET, host->h_addr_list[0], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton() failed\n");
        exit(1);
    }
    while (1) {
        strcpy(message, "GET / HTTP/1.1\r\n");
        strcat(message, "Host: ");
        strcat(message, url);
        strcat(message, "\r\n\r\n");
        if (sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&servaddr, len) < 0) {
            perror("sendto");
            exit(1);
        }
        if (recv(sockfd, message, 100, 0) <= 0) {
            perror("recv");
            exit(1);
        }
        printf("Received: %s\n", message);
        sleep(1);
    }
    return 0;
}