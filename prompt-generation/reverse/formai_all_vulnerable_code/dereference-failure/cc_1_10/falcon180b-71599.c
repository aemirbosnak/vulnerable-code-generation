//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    int addrlen = sizeof(cli_addr);
    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        printf("Usage: %s <port> <file>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);
    char *filename = argv[2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        exit(0);
    }

    listen(sockfd, 5);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);
        if (newsockfd < 0) {
            printf("Error accepting connection\n");
            exit(0);
        }

        FILE *fp = fopen(filename, "rb");
        if (fp == NULL) {
            printf("Error opening file\n");
            exit(0);
        }

        int bytes_sent = 0;
        while (fgets(buffer, BUFFER_SIZE, fp)!= NULL) {
            send(newsockfd, buffer, strlen(buffer), 0);
            bytes_sent += strlen(buffer);
        }

        fclose(fp);
        close(newsockfd);
    }

    return 0;
}