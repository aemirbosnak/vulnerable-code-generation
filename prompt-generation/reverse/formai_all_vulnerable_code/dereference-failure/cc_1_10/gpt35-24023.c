//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, n, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s hostname port filepath\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "Error getting host by name: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }

    char message[BUFFER_SIZE];
    sprintf(message, "RETR %s\n", argv[3]);
    n = write(sockfd, message, strlen(message));
    if (n < 0)
    {
        perror("Error writing to socket");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[3], "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0)
    {
        if (fwrite(buffer, sizeof(char), n, fp) != n)
        {
            fprintf(stderr, "Error writing to file: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    if (n < 0)
    {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }

    printf("File downloaded successfully.\n");

    fclose(fp);
    close(sockfd);
    return 0;
}