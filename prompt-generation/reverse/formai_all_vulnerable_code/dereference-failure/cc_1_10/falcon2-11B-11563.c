//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256] = {0};
    char request[] = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n";

    if (argc < 2) {
        printf("Usage: http_client <port>\n");
        exit(0);
    }

    portno = atoi(argv[1]);

    if (portno < 0 || portno > 65535) {
        printf("Invalid port number\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(0);
    }

    write(sockfd, request, sizeof(request));

    printf("Server response:\n");
    while ((n = read(sockfd, buffer, sizeof(buffer))) > 0) {
        printf("%s", buffer);
    }

    return 0;
}