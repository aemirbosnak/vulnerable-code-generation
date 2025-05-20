//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAX_MSG_LEN 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    // Check if correct number of arguments are provided
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    // Connect to server
    int sockfd, valread;
    struct sockaddr_in serv_addr;
    socklen_t clilen;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("ERROR opening socket");

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Send GET request
    char request[MAX_MSG_LEN];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    send(sockfd, request, strlen(request), 0);

    // Read response
    bzero(request, MAX_MSG_LEN);
    valread = recv(sockfd, request, MAX_MSG_LEN, 0);
    printf("Response: %s\n", request);

    close(sockfd);
    return 0;
}