//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXLINE 1024

char* pop3_receive(int sockfd)
{
    char* response = (char*)malloc(sizeof(char) * MAXLINE);
    memset(response, 0, MAXLINE);

    read(sockfd, response, MAXLINE);

    return response;
}

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        printf("Usage: %s <server_address> <port>\n", argv[0]);
        exit(1);
    }

    char* server_address = argv[1];
    int port = atoi(argv[2]);

    struct hostent* host = gethostbyname(server_address);
    struct sockaddr_in servaddr;

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    memcpy((char*)&servaddr.sin_addr.s_addr, (char*)host->h_addr, host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("Failed to connect to server.\n");
        exit(1);
    }

    char* welcome_msg = pop3_receive(sockfd);
    printf("Response: %s\n", welcome_msg);

    // Add your POP3 commands here

    free(welcome_msg);
    close(sockfd);

    return 0;
}