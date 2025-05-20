//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address struct
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to server\n");

    while (1)
    {
        printf("SMTP Client: ");
        fgets(buffer, 256, stdin);
        send(sockfd, buffer, strlen(buffer), 0);
        n = recv(sockfd, buffer, 256, 0);
        if (n < 0)
        {
            perror("recv failed");
            exit(EXIT_FAILURE);
        }
        printf("Server: %s\n", buffer);
    }

    return 0;
}