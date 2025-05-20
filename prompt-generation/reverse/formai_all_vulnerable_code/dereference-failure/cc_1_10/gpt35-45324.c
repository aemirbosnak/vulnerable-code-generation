//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int connect_to_imap_server(const char *ip_addr, int port)
{
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_addr);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to IMAP server");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

void send_command(int sockfd, const char *command)
{
    char buffer[BUF_SIZE] = {0};

    if (write(sockfd, command, strlen(command)) < 0)
    {
        perror("Error writing to IMAP server");
        exit(EXIT_FAILURE);
    }

    if (read(sockfd, buffer, BUF_SIZE) < 0)
    {
        perror("Error reading from IMAP server");
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: ./imap_client IP_ADDRESS PORT\n");
        exit(EXIT_FAILURE);
    }

    const char *ip_addr = argv[1];
    int port = atoi(argv[2]);

    int sockfd = connect_to_imap_server(ip_addr, port);

    send_command(sockfd, "LOGIN username password\n");
    send_command(sockfd, "LIST\n");
    send_command(sockfd, "FETCH 1 BODY[HEADER]\n");
    send_command(sockfd, "LOGOUT\n");

    close(sockfd);

    return 0;
}