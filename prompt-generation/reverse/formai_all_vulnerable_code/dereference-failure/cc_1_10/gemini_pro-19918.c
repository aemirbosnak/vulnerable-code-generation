//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80
#define BUFSIZE 1024

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE];

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <request>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: could not connect to host\n");
        exit(1);
    }

    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", argv[2], argv[1]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr, "Error: could not send request\n");
        exit(1);
    }

    memset(buffer, 0, BUFSIZE);
    n = read(sockfd, buffer, BUFSIZE - 1);
    if (n < 0) {
        fprintf(stderr, "Error: could not receive response\n");
        exit(1);
    }

    printf("%s\n", buffer);
    close(sockfd);
    return 0;
}