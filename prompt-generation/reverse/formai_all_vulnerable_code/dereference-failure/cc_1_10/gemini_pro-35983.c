//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    printf("Initiating surrealist ping test on %s.\n", argv[1]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Resolve the hostname
    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Connect to the host
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr = *(struct in_addr *)he->h_addr;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a ping request
    char buf[BUFSIZE];
    memset(buf, 0, sizeof(buf));
    snprintf(buf, sizeof(buf), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    int n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        perror("send");
        return 1;
    }

    // Receive the ping response
    memset(buf, 0, sizeof(buf));
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    // Close the socket
    close(sockfd);

    // Print the ping response
    printf("%s\n", buf);

    return 0;
}