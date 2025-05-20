//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

int main(int argc, char *argv[])
{

    char *host, *file;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, portno, n;
    char buffer[4096];
    FILE *fp;

    if (argc < 3) {
        printf("Usage: %s host file\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    file = argv[2];
    portno = 80;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server = gethostbyname(host);
    if (server == NULL) {
        printf("Error: no such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = *((unsigned long*)server->h_addr_list[0]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    sprintf(buffer, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", file, host);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        printf("Error writing to socket\n");
        exit(1);
    }

    fp = fopen(file, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[n] = '\0';
        fprintf(fp, "%s", buffer);
        printf("%s", buffer);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}