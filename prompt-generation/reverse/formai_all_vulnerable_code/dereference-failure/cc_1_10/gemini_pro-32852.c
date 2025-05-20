//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>

int main() {
    char *hostname = "google.com";
    int port = 80;
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return -1;
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"Error: could not resolve hostname\n");
        return -1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return -1;
    }

    char *message = "GET / HTTP/1.1\r\nHost: google.com\r\n\r\n";
    int sent = send(sockfd, message, strlen(message), 0);
    if (sent < 0) {
        perror("Error sending message");
        return -1;
    }

    char buffer[1024];
    int received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (received < 0) {
        perror("Error receiving message");
        return -1;
    }

    printf("%s", buffer);

    close(sockfd);
    return 0;
}