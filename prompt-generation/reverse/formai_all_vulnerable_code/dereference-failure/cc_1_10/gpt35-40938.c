//FormAI DATASET v1.0 Category: Socket programming ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    int sockfd, serv_port, client_port;
    char *serv_ip;
    char buffer[BUFSIZE];
    struct sockaddr_in serv_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    if(argc != 4)
    {
        printf("Usage: %s <server ip> <server port> <client port>\n", argv[0]);
        exit(-1);
    }

    serv_ip = argv[1];
    serv_port = atoi(argv[2]);
    client_port = atoi(argv[3]);

    if((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        perror("Error creating socket");
        exit(-1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(serv_ip);
    serv_addr.sin_port = htons(serv_port);

    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_addr.sin_port = htons(client_port);

    if(bind(sockfd, (struct sockaddr *) &client_addr, sizeof(client_addr)) < 0)
    {
        perror("Error binding socket");
        exit(-1);
    }

    printf("Client is listening on port %d...\n", client_port);

    while(1)
    {
        memset(buffer, 0, BUFSIZE);

        printf("Enter message to send to server: ");
        fgets(buffer, BUFSIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        if(sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        {
            perror("Error sending message");
            exit(-1);
        }

        memset(buffer, 0, BUFSIZE);

        if(recvfrom(sockfd, buffer, BUFSIZE, 0, (struct sockaddr *) &client_addr, &client_len) < 0)
        {
            perror("Error receiving message");
            exit(-1);
        }

        printf("Server says: %s\n", buffer);
    }

    return 0;
}