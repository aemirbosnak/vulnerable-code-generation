//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct hostent *host;
    if ((host = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZE];
    int nbytes;

    while ((nbytes = read(sockfd, buf, BUFSIZE)) > 0) {
        printf("Received %d bytes: %s\n", nbytes, buf);
    }

    if (nbytes < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}