//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, ret;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];

    // check if arguments are complete
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <server ip address> <port number>!\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("[-]Error in socket");
        exit(EXIT_FAILURE);
    }

    // set server details
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // connect to server
    ret = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (ret < 0)
    {
        perror("[-]Error in connect");
        exit(EXIT_FAILURE);
    }

    // receive welcome message from server
    memset(buffer, 0, BUF_SIZE);
    ret = recv(sockfd, buffer, BUF_SIZE, 0);
    if (ret < 0)
    {
        perror("[-]Error in recv");
        exit(EXIT_FAILURE);
    }
    printf("[+]Message from server: %s\n", buffer);

    while (1)
    {
        // receive user input
        printf("FTP Client $ ");
        memset(buffer, 0, BUF_SIZE);
        fgets(buffer, BUF_SIZE, stdin);

        // send user input to server
        ret = send(sockfd, buffer, strlen(buffer), 0);
        if (ret < 0)
        {
            perror("[-]Error in send");
            exit(EXIT_FAILURE);
        }

        // check if user wants to quit
        if (!strncmp(buffer, "quit", 4))
        {
            printf("[-]Connection terminated by user.\n");
            break;
        }

        // receive response from server
        memset(buffer, 0, BUF_SIZE);
        ret = recv(sockfd, buffer, BUF_SIZE, 0);
        if (ret < 0)
        {
            perror("[-]Error in recv");
            exit(EXIT_FAILURE);
        }
        printf("[+]Response from server: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}