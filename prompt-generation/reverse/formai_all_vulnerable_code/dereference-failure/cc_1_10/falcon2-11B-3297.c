//Falcon2-11B DATASET v1.0 Category: Building a IMAP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 143
#define MAX_MSG 1024

int main(int argc, char *argv[]) {
    struct sockaddr_in server;
    int sockfd, numbytes;
    char buf[MAX_MSG];
    char *msg = "HELO Example\r\n";
    char *response;
    struct hostent *serverhost;
    int n;

    if (argc!= 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    serverhost = gethostbyname(argv[1]);
    if (serverhost == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    bcopy((char *)serverhost->h_addr, (char *)&server.sin_addr.s_addr, serverhost->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    numbytes = send(sockfd, msg, strlen(msg), 0);
    if (numbytes < 0) {
        fprintf(stderr, "Error sending command\n");
        exit(1);
    }

    response = (char *)malloc(MAX_MSG);
    numbytes = recv(sockfd, response, MAX_MSG, 0);
    if (numbytes < 0) {
        fprintf(stderr, "Error receiving response\n");
        exit(1);
    }

    printf("%s\n", response);

    close(sockfd);

    return 0;
}